/*
Program: Rock Paper Scissors
Problem: Play a simple Rock Paper Scissors game against the computer.
Features:
- Player inputs Rock, Paper, or Scissors
- Computer chooses randomly
- Winner is decided based on standard rules
- Score is maintained across rounds
- Replay option included
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *choices[] = {"Rock", "Paper", "Scissors"};
    char playAgain = 'y';
    int playerScore = 0, computerScore = 0;

    srand(time(0)); // Seed for random generator

    while (playAgain == 'y' || playAgain == 'Y') {
        int computer = rand() % 3;
        int player;

        printf("\nEnter your choice (0: Rock, 1: Paper, 2: Scissors): ");
        scanf("%d", &player);

        if (player < 0 || player > 2) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("You chose: %s\n", choices[player]);
        printf("Computer chose: %s\n", choices[computer]);

        if (player == computer) {
            printf("Result: Draw!\n");
        } else if ((player == 0 && computer == 2) ||
                   (player == 1 && computer == 0) ||
                   (player == 2 && computer == 1)) {
            printf("Result: You Win!\n");
            playerScore++;
        } else {
            printf("Result: You Lose!\n");
            computerScore++;
        }

        printf("Score -> You: %d, Computer: %d\n", playerScore, computerScore);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Final Score -> You: %d, Computer: %d\n", playerScore, computerScore);
    printf("Thanks for playing!\n");

    return 0;
}
