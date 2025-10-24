#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Interactive Word Scramble Game in C
 * Beginner-friendly with multiple attempts and hints
 */

int main() {
    char word[] = "apple";      // Original word
    char scrambled[] = "elppa"; // Scrambled version
    char guess[20];
    int attempts = 3;           // Number of attempts allowed
    int i;
    char playAgain;

    printf("Welcome to the Word Scramble Game!\n");

    do {
        printf("\nUnscramble this word: %s\n", scrambled);

        for(i = 0; i < attempts; i++) {
            printf("Attempt %d of %d\n", i + 1, attempts);
            printf("Your guess: ");
            scanf("%s", guess);

            // Convert guess to lowercase for case-insensitive comparison
            for(int j = 0; guess[j]; j++){
                guess[j] = tolower(guess[j]);
            }

            if(strcmp(guess, word) == 0) {
                printf("Correct! Well done!\n");
                break;
            } else {
                printf("Wrong! ");
                if(i < attempts - 1) {
                    printf("Try again.\n");
                    // Optional hint: show first letter
                    if(i == 0) {
                        printf("Hint: The first letter is '%c'.\n", word[0]);
                    }
                } else {
                    printf("The correct word was: %s\n", word);
                }
            }
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Goodbye!\n");

    return 0;
}
