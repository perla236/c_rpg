#include <stdio.h>
#include <string.h>
#include "leaderboard.h"

LeaderboardEntry leaderboard[MAX_PLAYERS];
int num_players = 0;

void load_leaderboard() {
    FILE *f = fopen("leaderboard.dat", "rb");
    if(!f) return;
    fread(&num_players, sizeof(int), 1, f);
    fread(leaderboard, sizeof(LeaderboardEntry), num_players, f);
    fclose(f);
}

void save_leaderboard() {
    FILE *f = fopen("leaderboard.dat", "wb");
    if(!f) return;
    fwrite(&num_players, sizeof(int), 1, f);
    fwrite(leaderboard, sizeof(LeaderboardEntry), num_players, f);
    fclose(f);
}

void update_leaderboard(const char *name, int score) {
    int found=-1;
    for(int i=0;i<num_players;i++)
        if(strcmp(leaderboard[i].name,name)==0) found=i;

    if(found!=-1){
        if(score>leaderboard[found].high_score)
            leaderboard[found].high_score=score;
    } else {
        if(num_players<MAX_PLAYERS){
            strcpy(leaderboard[num_players].name,name);
            leaderboard[num_players].high_score=score;
            num_players++;
        }
    }
    save_leaderboard();
}

void print_leaderboard() {
    printf("\n--- Leaderboard ---\n");
    for(int i=0;i<num_players;i++)
        printf("%d. %s - %d XP\n", i+1, leaderboard[i].name, leaderboard[i].high_score);
    printf("------------------\n");
}
