#include <stdio.h>
#include <string.h>

/*
 * Simple Word Scramble Game in C
 * Beginner-friendly and fully commented
 */

int main() {
    char word[] = "apple";      // Original word
    char scrambled[] = "elppa"; // Scrambled version
    char guess[20];

    printf("Welcome to the Word Scramble Game!\n");
    printf("Unscramble this word: %s\n", scrambled);

    printf("Your guess: ");
    scanf("%s", guess);

    // Check if the guess is correct
    if(strcmp(guess, word) == 0) {
        printf("Correct! Well done!\n");
    } else {
        printf("Wrong! The correct word was: %s\n", word);
    }

    return 0;
}
