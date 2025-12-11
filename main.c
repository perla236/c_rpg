#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "file_utils.h"
#include "leaderboard.h"

int main(){
    srand(time(NULL));
    load_leaderboard();
    printf("Postojeci igraci:\n"); 
    print_leaderboard();

    printf("1.Nova igra 2.Nastavi 3.Izlaz\nIzbor: "); 
    int choice; 
    scanf("%d", &choice); getchar();
    Player player;

    // Nova igra
    if(choice==1){
        char name[50];
        printf("Ime igraca: "); 
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = 0;
        player = create_player(name);

        // Dodaj u leaderboard ako ga nema
        int found = 0;
        for(int i=0;i<num_players;i++)
            if(strcmp(leaderboard[i].name, player.name)==0) found = 1;
        if(!found){
            update_leaderboard(player.name, player.xp);
        }
    }
    // Nastavi igru
    else if(choice==2){
        if(num_players == 0){
            printf("Nema sacuvanih igraca!\n");
            return 0;
        }
        printf("Izaberi igraca:\n"); 
        for(int i=0;i<num_players;i++)
            printf("%d.%s\n", i+1, leaderboard[i].name);
        int sel; 
        scanf("%d",&sel); getchar();
        if(sel<1||sel>num_players) sel=1;
        player = load_game_for_name(leaderboard[sel-1].name);

        // Provjeri da li je igrac u leaderboardu
        int found = 0;
        for(int i=0;i<num_players;i++)
            if(strcmp(leaderboard[i].name, player.name)==0) found = 1;
        if(!found){
            update_leaderboard(player.name, player.xp);
        }
    }
    else return 0;

    int playing=1;
    while(playing){
        printf("\n--- Meni ---\n1.Borba 2.Statistika 3.Spremi 4.Izlaz\nIzbor: "); 
        scanf("%d",&choice); getchar();
        switch(choice){
            case 1:{
                Enemy e=create_enemy(player.level); 
                print_player_stats(&player);
                print_enemy_stats(&e);
                battle(&player,&e); 
                // Update leaderboard posle borbe
                update_leaderboard(player.name, player.xp);
                break;
            }
            case 2: 
                print_player_stats(&player); 
                break;
            case 3: 
                save_game(&player); 
                break;
            case 4: 
                playing=0; 
                break;
            default: 
                printf("Nepoznata opcija\n");
        }
    }
    return 0;
}
