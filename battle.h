#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"
#include "enemy.h"

typedef void (*AttackFunc)(Player*, Enemy*);

void battle(Player *p, Enemy *e);
void print_health_bar(const char *name, int hp, int max_hp);

#endif
