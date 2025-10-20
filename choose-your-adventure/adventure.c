/*
 * =====================================================================================
 *
 * Program:  Adventure Game
 *
 * Problem Statement:
 * A simple, text-based 'Choose Your Own Adventure' game where the
 * player makes a series of choices to reach a "win" or "lose" ending.
 * The game demonstrates nested if/else logic and state tracking with
 * a variable (hasKey).
 *
 * Special Features:
 * Uses sleep() from <unistd.h> (on Linux/macOS) to add a
 * dramatic pause. For Windows, you would need <windows.h> and Sleep().
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Enter your choice (1, 2, or 3): 1
 * Enter your choice (1 or 2): 1
 * Enter your choice (1 or 2): 1
 *
 * Output:
 * --- You walk left towards the river. ---
 * ...
 * --- You cautiously step onto the rope bridge. ---
 * ...
 * --- You grab the object... it's a small, ornate key! ---
 * ...
 * You use the key you found! The chest opens...
 * It's filled with gold and jewels! This is a fine treasure!
 * YOU WIN!
 *
 * =====================================================================================
 */

#include <stdio.h>  // For printf and scanf
#include <unistd.h> // For the sleep() function (to add a pause)

int main(void) {
    int choice1, choice2, choice3; // Variables to store the user's choices
    int hasKey = 0; // A "state" variable. 0 = no key, 1 = has key

    // --- The Story Starts ---
    printf("=========================================\n");
    printf("   The Quest for the C-Dragon's Lair   \n");
    printf("=========================================\n\n");
    
    printf("You are an adventurer standing at the edge of the Whispering Woods.\n");
    printf("Your quest: find the legendary Lair of the C-Dragon.\n");
    printf("Before you are three paths:\n");
    printf("  1. The winding path to the LEFT, towards the river.\n");
    printf("  2. The dark path to the RIGHT, into a spooky cave.\n");
    printf("  3. The overgrown path STRAIGHT ahead, into the deep woods.\n");
    printf("\nEnter your choice (1, 2, or 3): ");
    
    scanf("%d", &choice1);

    // --- Branch 1: The Left Path (River) ---
    if (choice1 == 1) {
        printf("\n--- You walk left towards the river. ---\n");
        printf("The river is wide and fast. You spot two ways to cross:\n");
        printf("  1. A rickety-looking rope bridge.\n");
        printf("  2. A narrow, shallow-looking ford.\n");
        printf("Enter your choice (1 or 2): ");
        
        scanf("%d", &choice2);

        if (choice2 == 1) {
            printf("\n--- You cautiously step onto the rope bridge. ---\n");
            printf("It sways violently! Halfway across, you see something shiny stuck in the ropes.\n");
            printf("  1. Quickly grab the shiny object.\n");
            printf("  2. Ignore it and focus on crossing.\n");
            printf("Enter your choice (1 or 2): ");

            scanf("%d", &choice3);

            if (choice3 == 1) {
                printf("\n--- You grab the object... it's a small, ornate key! ---\n");
                hasKey = 1; // You got the key!
                printf("You shove it in your pocket and scramble to the other side.\n");
            } else {
                printf("\n--- You ignore it and make it safely to the other side. ---\n");
            }

            printf("On the other side, you find a large, ancient stone chest.\n");
            
            if (hasKey == 1) {
                printf("You use the key you found! The chest opens...\n");
                printf("It's filled with gold and jewels! This is a fine treasure!\n");
                printf("YOU WIN!\n");
            } else {
                printf("The chest is locked. You have no key and can't open it.\n");
                printf("A grumpy troll wanders by and claims the chest for himself.\n");
                printf("GAME OVER.\n");
            }

        } else if (choice2 == 2) {
            printf("\n--- You try to walk the ford. ---\n");
            printf("The 'shallow' water was a lie! A strong current pulls you under.\n");
            printf("GAME OVER.\n");
        } else {
            printf("\nInvalid choice. While you hesitated, a giant eagle swooped down.\n");
            printf("GAME OVER.\n");
        }
    }
    // --- Branch 2: The Right Path (Cave) ---
    else if (choice1 == 2) {
        printf("\n--- You walk right and enter the dark cave. ---\n");
        printf("It's damp and smells of sulfur. You hear a low growl.\n");
        printf("You light a torch. You see two tunnels:\n");
        printf("  1. A narrow passage with a faint light at the end.\n");
        printf("  2. A wide, dark tunnel that slopes steeply down.\n");
        printf("Enter your choice (1 or 2): ");
        
        scanf("%d", &choice2);

        if (choice2 == 1) {
            printf("\n--- You squeeze into the narrow passage. ---\n");
            printf("You crawl towards the light. You emerge in a small chamber.\n");
            printf("The light is... the eye of the C-Dragon! It was sleeping.\n");
            printf("It wakes up. You are its dinner.\n");
            printf("GAME OVER.\n");
        } else if (choice2 == 2) {
            printf("\n--- You walk past the cave. ---\n");
            printf("You safely continue on your path and find a small village.\n");
            printf("You live a long, happy life. YOU WIN!\n");
        } else {
            printf("\nInvalid choice. You stumbled in the dark and alerted the dragon.\n");
            printf("GAME OVER.\n");
        }
    }
    // --- Branch 3: The Straight Path (Woods) ---
    else if (choice1 == 3) {
        printf("\n--- You push through the overgrown path. ---\n");
        printf("Vines and thorns snag at your clothes. It's eerily quiet.\n");
        printf("You push aside a large bush and...\n");
        
        sleep(2); // Pauses the program for 2 seconds for dramatic effect

        printf("...walk right into a giant spider's web!\n");
        printf("The spider descends. You are its dinner.\n");
        printf("GAME OVER.\n");
    }
    // --- Branch 4: Invalid First Choice ---
    else {
        printf("\nThat's not a valid path! You wander aimlessly in the woods.\n");
        printf("You are lost forever.\n");
        printf("GAME OVER.\n");
    }

    printf("\nThanks for playing!\n");
    return 0; // End the program
}