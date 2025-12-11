#include <stdio.h>
#include <string.h>
#include "player.h"

Player create_player(const char *name) {
    Player p;
    strcpy(p.name, name);
    p.level = 1;
    p.hp = p.max_hp = 100;
    p.xp = 0;
    p.attack = 10;
    return p;
}

void level_up(Player *p) {
    p->level++;
    p->max_hp += 20;
    p->hp = p->max_hp;
    p->attack += 5;
    printf("%s je sada level %d!\n", p->name, p->level);
}

void print_player_stats(const Player *p){
    int bar_width = 20;
    int filled = (p->hp * bar_width) / p->max_hp;
    printf("\033[1;32m%s: [", p->name); // zelena boja
    for(int i=0;i<filled;i++) printf("■");
    for(int i=filled;i<bar_width;i++) printf(" ");
    printf("] %d/%d HP\033[0m\n", p->hp, p->max_hp);
}
