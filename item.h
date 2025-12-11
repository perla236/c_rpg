#ifndef ITEM_H
#define ITEM_H

#include "player.h"

typedef void (*ItemEffect)(Player*);

typedef struct {
    char name[50];
    ItemEffect effect;
} Item;

void heal_potion(Player *p);
void attack_buff(Player *p);

#endif
