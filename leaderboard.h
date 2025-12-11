#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#define MAX_PLAYERS 10
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int high_score;
} LeaderboardEntry;

extern LeaderboardEntry leaderboard[MAX_PLAYERS];
extern int num_players;

void load_leaderboard();
void save_leaderboard();
void update_leaderboard(const char *name, int score);
void print_leaderboard();

#endif
