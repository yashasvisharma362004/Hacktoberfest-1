/*
 * =====================================================================================
 *
 * Program:  Superhero Battle
 *
 * Problem Statement:
 * A simple, turn-based battle game where the user chooses one hero from
 * the Marvel roster and one from the DC roster. The two heroes then
 * fight until one's health points (HP) drop to zero. Damage is
 * semi-random to make each fight unique.
 *
 * Special Features:
 * Uses a 'struct' to organize hero data (name, HP, attack power).
 * Uses rand() from <stdlib.h> to add variability to attack damage.
 * Uses srand() and time() to ensure different random numbers each time.
 *
 * Complexity: O(1) - The game logic runs in constant time relative to input.
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Welcome to the MARVEL vs DC Battle Arena!
 * Choose your Marvel hero:
 * 1. Iron Man (HP: 100, Attack: 15)
 * 2. Hulk (HP: 150, Attack: 10)
 * Your choice: 1
 *
 * Choose your DC hero:
 * 1. Superman (HP: 120, Attack: 18)
 * 2. Batman (HP: 90, Attack: 12)
 * Your choice: 2
 *
 * Output:
 *
 * --- The Battle Begins! ---
 * Iron Man (100 HP) vs. Batman (90 HP)
 * ---------------------------------
 * > Iron Man attacks Batman for 19 damage! Batman has 71 HP left.
 * > Batman attacks Iron Man for 15 damage! Iron Man has 85 HP left.
 * ...
 * > Iron Man attacks Batman for 21 damage! Batman has -5 HP left.
 *
 * --- BATTLE OVER ---
 * Batman has been defeated! Iron Man is the winner!
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()
#include <string.h> // For strcpy()

// Define a structure to hold all data for a superhero
struct Superhero {
    char name[50];
    int hp;
    int base_attack;
};

int main(void) {
    // Seed the random number generator ONCE at the start of the program
    srand(time(0));

    // --- Hero Rosters ---
    struct Superhero marvel_roster[2];
    strcpy(marvel_roster[0].name, "Iron Man");
    marvel_roster[0].hp = 100;
    marvel_roster[0].base_attack = 15;

    strcpy(marvel_roster[1].name, "Hulk");
    marvel_roster[1].hp = 150;
    marvel_roster[1].base_attack = 10;

    struct Superhero dc_roster[2];
    strcpy(dc_roster[0].name, "Superman");
    dc_roster[0].hp = 120;
    dc_roster[0].base_attack = 18;

    strcpy(dc_roster[1].name, "Batman");
    dc_roster[1].hp = 90;
    dc_roster[1].base_attack = 12;

    struct Superhero marvel_hero, dc_hero;
    int choice;

    // --- Player Selection ---
    printf("Welcome to the MARVEL vs DC Battle Arena!\n");

    printf("\nChoose your Marvel hero:\n");
    printf("  1. %s (HP: %d, Attack: %d)\n", marvel_roster[0].name, marvel_roster[0].hp, marvel_roster[0].base_attack);
    printf("  2. %s (HP: %d, Attack: %d)\n", marvel_roster[1].name, marvel_roster[1].hp, marvel_roster[1].base_attack);
    printf("Your choice: ");
    scanf("%d", &choice);
    marvel_hero = marvel_roster[choice - 1];

    printf("\nChoose your DC hero:\n");
    printf("  1. %s (HP: %d, Attack: %d)\n", dc_roster[0].name, dc_roster[0].hp, dc_roster[0].base_attack);
    printf("  2. %s (HP: %d, Attack: %d)\n", dc_roster[1].name, dc_roster[1].hp, dc_roster[1].base_attack);
    printf("Your choice: ");
    scanf("%d", &choice);
    dc_hero = dc_roster[choice - 1];

    // --- Battle Logic ---
    printf("\n--- The Battle Begins! ---\n");
    printf("%s (%d HP) vs. %s (%d HP)\n", marvel_hero.name, marvel_hero.hp, dc_hero.name, dc_hero.hp);
    printf("---------------------------------\n");

    // The battle continues as long as both heroes have HP above 0
    while (marvel_hero.hp > 0 && dc_hero.hp > 0) {
        // Marvel hero's turn
        int marvel_damage = marvel_hero.base_attack + (rand() % 10); // Base attack + 0-9 bonus damage
        dc_hero.hp -= marvel_damage;
        printf("> %s attacks %s for %d damage! %s has %d HP left.\n", marvel_hero.name, dc_hero.name, marvel_damage, dc_hero.name, dc_hero.hp);

        // Check if DC hero was defeated
        if (dc_hero.hp <= 0) {
            break; // Exit the loop immediately
        }

        // DC hero's turn
        int dc_damage = dc_hero.base_attack + (rand() % 10); // Base attack + 0-9 bonus damage
        marvel_hero.hp -= dc_damage;
        printf("> %s attacks %s for %d damage! %s has %d HP left.\n", dc_hero.name, marvel_hero.name, dc_damage, marvel_hero.name, marvel_hero.hp);
    }

    // --- Declare Winner ---
    printf("\n--- BATTLE OVER ---\n");
    if (marvel_hero.hp > 0) {
        printf("%s has been defeated! %s is the winner!\n", dc_hero.name, marvel_hero.name);
    } else {
        printf("%s has been defeated! %s is the winner!\n", marvel_hero.name, dc_hero.name);
    }

    return 0;
}