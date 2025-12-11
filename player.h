#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[50];
    int hp;
    int max_hp;
    int level;
    int xp;
    int attack;
} Player;

Player create_player(const char *name);
void level_up(Player *p);
void print_player_stats(const Player *p);

#endif
