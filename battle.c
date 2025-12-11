#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "battle.h"
#include "enemy.h"
#include "item.h"
#include "player.h"
#include "leaderboard.h"


void basic_attack(Player *p, Enemy *e){ 
    int dmg = p->attack + rand()%6; 
    e->hp -= dmg; if(e->hp<0) e->hp=0;
    printf("%s udara %s za %d dmg\n",p->name,e->name,dmg);
}
void power_attack(Player *p, Enemy *e){ 
    int dmg = p->attack + rand()%11; 
    if(rand()%100<25)dmg*=2; 
    e->hp -= dmg; if(e->hp<0) e->hp=0;
    printf("%s jaci napad na %s %d dmg\n",p->name,e->name,dmg);
}
void paralysis_attack(Player *p, Enemy *e){ 
    int dmg = p->attack + rand()%4; 
    e->hp -= dmg; if(e->hp<0) e->hp=0;
    printf("%s paralizira %s %d dmg\n",p->name,e->name,dmg); 
    if(rand()%100<50)e->attack=0;
}
void poison_attack(Player *p, Enemy *e){ 
    int dmg = p->attack/2; 
    e->hp -= dmg; if(e->hp<0) e->hp=0;
    printf("%s otrovava %s %d dmg\n",p->name,e->name,dmg);
}


void enemy_attack_ai(Enemy *e, Player *p){ 
    EnemyAttackFunc attacks[2]={enemy_basic_attack,enemy_power_attack}; 
    attacks[rand()%2](e,p); 
    if(e->attack==0)e->attack=e->base_attack;
}

void battle(Player *p, Enemy *e){
    AttackFunc player_attacks[4]={basic_attack,power_attack,paralysis_attack,poison_attack};
    const char *attack_names[4]={"Basic","Power","Paralysis","Poison"};
    Item items[2]={{"Health Potion",heal_potion},{"Attack Potion",attack_buff}};
    int num_attacks=4,num_items=2;

    printf("Borba: %s vs %s!\n",p->name,e->name);
    while(p->hp>0 && e->hp>0){

        print_player_stats(p);
        print_enemy_stats(e);

        printf("\n1.Napad 2.Item\nIzbor: ");
        int move; scanf("%d",&move); getchar();
        if(move==1){
            printf("Izaberi napad:\n"); 
            for(int i=0;i<num_attacks;i++)printf("%d.%s\n",i+1,attack_names[i]);
            int choice; scanf("%d",&choice); getchar(); 
            if(choice<1||choice>num_attacks) choice=1;
            player_attacks[choice-1](p,e);
            if(choice==4){ int dmg=2+p->level; e->hp-=dmg; if(e->hp<0)e->hp=0; 
            printf("%s pati od otrova %d dmg!\n",e->name,dmg);}
        } else { 
            printf("Izaberi item:\n"); 
            for(int i=0;i<num_items;i++)printf("%d.%s\n",i+1,items[i].name);
            int choice; scanf("%d",&choice); getchar(); 
            if(choice<1||choice>num_items) choice=1; 
            items[choice-1].effect(p);
        }
        if(e->hp<=0) break;
        enemy_attack_ai(e,p);
    }

    if(p->hp>0){ 
        printf("%s je pobjedio %s!\n",p->name,e->name); 
        p->xp+=20; 
        if(p->xp>=p->level*50) level_up(p);
    }
    else{ 
        printf("%s je izgubio...\n",p->name); 
        update_leaderboard(p->name,p->xp); 
        p->xp=0;
    }
}
