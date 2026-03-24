
# c_rpg [![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
<!--![Cover](https://github.com/perla236/c_rpg/blob/main/cover.jpg?raw=true) -->
<p align="center">
<img src="https://raw.githubusercontent.com/perla236/c_rpg/refs/heads/main/cover.jpg" width="500">
</p>
Ovo je jednostavna RPG igra (Role-Playing Game) napisana u C jeziku. Aplikacija simulira osnovne elemente RPG-a, uključujući kreiranje lika, borbu protiv neprijatelja, sustav leveliranja (napredovanja), korištenje predmeta (itema) te spremanje i učitavanje stanja igre i ljestvice najboljih (Leaderboard).

## 🚀 Pokretanje Igre
Za pokretanje igre potrebno je kompajlirati izvorni kod. Pretpostavlja se da imate instaliran C kompajler (poput GCC).
 * Struktura Datoteka: Provjerite jesu li sve datoteke prisutne u istom direktoriju (main.c, player.c, player.h, enemy.c, enemy.h, battle.c, battle.h, item.c, item.h, leaderboard.c, leaderboard.h, file_utils.c, file_utils.h).
 * Kompilacija: Otvorite terminal ili komandnu liniju, navigirajte do direktorija s kodom i kompajlirajte sve datoteke:
    ```bash
    gcc -o c_rpg main.c player.c enemy.c battle.c  item.c leaderboard.c file_utils.c -Wall
    ```  
   Napomena: Možda ćete morati prilagoditi naredbu ovisno o nazivu glavne datoteke (ako nije main.c).
 * Pokretanje: Nakon uspješne kompilacije, pokrenite izvršnu datoteku:
   ```
   ./c_rpg
    ```
## 🎮 Kako se Igra
Igra se vodi kroz tekstualne izbornike u konzoli:
 * Glavni Izbornik: Omogućuje vam odabir imena lika, početak nove igre ili učitavanje postojeće spremljene pozicije.
 * Izbornik Akcija: Tijekom igre birate između ulaska u Borbu (Battle), Spremanja (Save), pregleda Statistika (Stats) ili pregleda Ljestvice najboljih (Leaderboard).
 * Borba: Interaktivni sustav u kojem birate između Napada (Attack) ili korištenja Predmeta (Item).
   * Igrač može birati između 4 tipa napada (Basic, Power, Paralysis, Poison).
   * Neprijatelji (Enemy) imaju dvije vrste napada.
   * Borba se nastavlja dok HP jednog od sudionika ne padne na 0.
 * Leveliranje: Nakon pobjede, igrač dobiva XP (iskustvene bodove). Kada se skupi dovoljno XP-a, lik automatski levelira, povećavajući maksimalni HP i Attack.
 * Spremanje igre: Stanje lika sprema se u datoteku save.dat. Ljestvica najboljih se sprema u leaderboard.dat.
## ⚙️ Kako Funkcionira (Arhitektura)
Aplikacija je modularno organizirana u nekoliko C datoteka (.c) i odgovarajućih zaglavlja (.h), od kojih svaka upravlja specifičnim aspektom igre.
| Modul (Datoteke) | Odgovornost |
|---|---|
| player.h, player.c | Definicija strukture igrača (Player), kreiranje igrača (create_player), napredovanje (level_up) i prikaz statistika. |
| enemy.h, enemy.c | Definicija strukture neprijatelja (Enemy), kreiranje neprijatelja i različiti tipovi neprijateljskih napada. |
| battle.h, battle.c | Upravljanje borbenim sustavom (glavna petlja borbe), AI neprijatelja, te izvršavanje napada igrača. |
| item.h, item.c | Definicija predmeta (Item) (npr. 'Health Potion', 'Attack Potion') i funkcije za njihove efekte. |
| leaderboard.h, leaderboard.c | Upravljanje ljestvicom najboljih (spremanje, učitavanje i ažuriranje rezultata u leaderboard.dat). |
| file_utils.h, file_utils.c | Funkcionalnost za spremanje i učitavanje stanja lika u/iz datoteke save.dat. |

Ključne Korištene Tehnike:
 * Strukture (struct): Koriste se za definiranje objekata igre kao što su Player, Enemy i Item.
 * Pokazivači na Funkcije: Koriste se za implementaciju različitih tipova napada (i igrača i neprijatelja) i efekata predmeta. Ovo omogućuje fleksibilno dodavanje novih akcija.
 * Upravljanje Datotekama: Koristi se binarno I/O (fread, fwrite) za trajno spremanje stanja igre i ljestvice najboljih.
 * Konzolna Grafika: Koriste se ANSI escape sekvence (npr. \033[1;32m za zelenu boju) za prikaz traka zdravlja (HP) i poboljšanje vizualnog iskustva u terminalu.
#### 🇬🇧 (English)
# c_rpg
This is a simple RPG (Role-Playing Game) application written in the C language. The application simulates the core elements of an RPG, including character creation, combat, a leveling system, item usage, and saving/loading game state and a high-score Leaderboard.

## 🚀 How to Run the Game
To run the game, you need to compile the source code. It's assumed you have a C compiler (like GCC) installed.
 * File Structure: Ensure all source files are present in the same directory (main.c, player.c, player.h, enemy.c, enemy.h, battle.c, battle.h, item.c, item.h, leaderboard.c, leaderboard.h, file_utils.c, file_utils.h).
 * Compilation: Open your terminal or command prompt, navigate to the code directory, and compile all files:
   ```bash
    gcc -o c_rpg main.c player.c enemy.c battle.c item.c leaderboard.c file_utils.c -Wall
   ```
   Note: You might need to adjust the command depending on the name of your main file (if it's not main.c).
 * Execution: After successful compilation, run the executable:
   ```bash
   ./c_rpg
    ```
## 🎮 How to Play
The game is navigated through text-based menus in the console:
 * Main Menu: Allows you to select a character name, start a New Game, or Load an existing save file.
 * Action Menu: During gameplay, you choose between entering Battle, Saving the game, viewing Stats, or checking the Leaderboard.
 * Combat (Battle): An interactive system where you choose between Attack or using an Item.
   * The Player can select from 4 attack types (Basic, Power, Paralysis, Poison).
   * Enemies have two types of attacks.
   * Combat continues until one participant's HP drops to 0.
 * Leveling: Upon victory, the player gains XP (Experience Points). When enough XP is accumulated, the character automatically levels up, increasing Max HP and Attack power.
 * Saving: Character state is saved in the save.dat file. The leaderboard is managed in leaderboard.dat.
## ⚙️ How It Works (Architecture)
The application is modularly organized into several C source files (.c) and corresponding header files (.h), with each managing a specific game aspect.
| Module (Files) | Responsibility |
|---|---|
| player.h, player.c | Defines the Player structure, player creation (create_player), leveling up (level_up), and displaying stats. |
| enemy.h, enemy.c | Defines the Enemy structure, enemy creation, and different enemy attack types. |
| battle.h, battle.c | Manages the Combat System (the main battle loop), enemy AI, and executing player attacks. |
| item.h, item.c | Defines Items (e.g., 'Health Potion', 'Attack Potion') and functions for their effects. |
| leaderboard.h, leaderboard.c | Manages the Leaderboard (saving, loading, and updating scores in leaderboard.dat). |
| file_utils.h, file_utils.c | Functionality for saving and loading character state to/from the save.dat file. |

Key Techniques Used:
 * Structures (struct): Used to define game objects like Player, Enemy, and Item.
 * Function Pointers: Employed to implement various attack types (both player and enemy) and item effects. This allows for flexible addition of new actions.
 * File Handling: Binary I/O (fread, fwrite) is used for the persistent storage of game state and the leaderboard.
 * Console Graphics: ANSI escape sequences (e.g., \033[1;32m for green color) are used to display HP bars and enhance the visual experience in the terminal.

