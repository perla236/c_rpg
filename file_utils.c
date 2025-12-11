#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_utils.h"

#define MAX_SAVED_PLAYERS 100

void save_game(const Player *p) {
    Player players[MAX_SAVED_PLAYERS];
    int count = 0;

    FILE *f = fopen("save.dat", "rb");
    if(f) {
        // Učitaj sve postojeće igrače
        while(count < MAX_SAVED_PLAYERS && fread(&players[count], sizeof(Player), 1, f)) {
            count++;
        }
        fclose(f);
    }

    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp(players[i].name, p->name) == 0) {
            players[i] = *p; // ažuriraj igrača
            found = 1;
            break;
        }
    }

    if(!found) {
        if(count < MAX_SAVED_PLAYERS) {
            players[count++] = *p; // dodaj novog igrača
        } else {
            printf("Previše sačuvanih igrača!\n");
            return;
        }
    }

    f = fopen("save.dat", "wb");
    if(!f) { printf("Greška pri spremanju!\n"); return; }
    fwrite(players, sizeof(Player), count, f);
    fclose(f);

    printf("Igra je spasena!\n");
}

Player load_game_for_name(const char *name) {
    FILE *f = fopen("save.dat", "rb");
    Player p;

    if(!f) return create_player(name);

    while(fread(&p, sizeof(Player), 1, f)) {
        if(strcmp(p.name, name) == 0) {
            fclose(f);
            return p;
        }
    }

    fclose(f);
    return create_player(name); // ako nije pronađen
}
