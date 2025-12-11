#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "player.h"

void save_game(const Player *p);
Player load_game_for_name(const char *name);

#endif
