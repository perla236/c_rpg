#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"

Enemy create_enemy(int level) {
    Enemy e;
    snprintf(e.name, 50, "Neprijatelj L%d", level);
    e.hp = e.max_hp = 50 + level*20; // dodano max_hp
    e.base_attack = 5 + level*3;
    e.attack = e.base_attack;
    e.level = level;
    return e;
}

void print_enemy_stats(const Enemy *e){
    int bar_width = 20;
    int filled = (e->hp * bar_width) / e->max_hp;
    printf("\033[1;31m%s: [", e->name); // crvena boja
    for(int i=0;i<filled;i++) printf("■");
    for(int i=filled;i<bar_width;i++) printf(" ");
    printf("] %d/%d HP\033[0m\n", e->hp, e->max_hp);
}

void enemy_basic_attack(Enemy *e, Player *p) {
    int dmg = e->attack + rand()%4;
    p->hp -= dmg;
    if(p->hp < 0) p->hp = 0;
    printf("%s udara %s za %d dmg\n", e->name, p->name, dmg);
}

void enemy_power_attack(Enemy *e, Player *p) {
    int dmg = e->attack + rand()%7;
    if(rand()%100 < 20) dmg *= 2;
    p->hp -= dmg;
    if(p->hp < 0) p->hp = 0;
    printf("%s izvrsava jaci napad na %s za %d dmg\n", e->name, p->name, dmg);
}
