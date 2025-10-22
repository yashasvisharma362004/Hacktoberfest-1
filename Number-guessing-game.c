#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0, playAgain = 1;
    char name[50];

    printf("=====================================\n");
    printf("🎯 WELCOME TO THE NUMBER GUESSING GAME 🎯\n");
    printf("=====================================\n");
    printf("Enter your name: ");
    scanf("%s", name);

    srand(time(0)); // seed for randomness

    while (playAgain) {
        number = rand() % 100 + 1; // random number 1-100
        attempts = 0;

        printf("\nAlright %s, I have chosen a number between 1 and 100.\n", name);
        printf("Can you guess it? 🤔\n");

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess > number)
                printf("Too high! Try again ⬇️\n");
            else if (guess < number)
                printf("Too low! Try again ⬆️\n");
            else
                printf("🎉 Correct! You got it in %d attempts!\n", attempts);

        } while (guess != number);

        printf("\nWould you like to play again? (1 = Yes, 0 = No): ");
        scanf("%d", &playAgain);

        if (playAgain)
            printf("\n🔄 Starting a new round...\n");
        else
            printf("\n👋 Thanks for playing, %s! See you next time!\n", name);
    }

    printf("\n=====================================\n");
    printf("  Final Thoughts: Luck favors the bold! 😎\n");
    printf("=====================================\n");

    return 0;
}
