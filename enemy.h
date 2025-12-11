#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"

typedef struct {
    char name[50];
    int hp;
    int max_hp;
    int attack;
    int base_attack;
    int level;
} Enemy;

typedef void (*EnemyAttackFunc)(Enemy*, Player*);

Enemy create_enemy(int level);
void print_enemy_stats(const Enemy *e);
void enemy_basic_attack(Enemy *e, Player *p);
void enemy_power_attack(Enemy *e, Player *p);

#endif
