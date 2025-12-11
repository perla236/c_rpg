#include <stdio.h>
#include "item.h"

void heal_potion(Player *p) {
    int heal = 30;
    p->hp += heal;
    if(p->hp > p->max_hp) p->hp = p->max_hp;
    printf("%s koristi Health Potion i obnavlja %d HP. Trenutni HP: %d\n", p->name, heal, p->hp);
}

void attack_buff(Player *p) {
    int buff = 5;
    p->attack += buff;
    printf("%s koristi Attack Potion i povecava attack za %d. Trenutni attack: %d\n", p->name, buff, p->attack);
}
