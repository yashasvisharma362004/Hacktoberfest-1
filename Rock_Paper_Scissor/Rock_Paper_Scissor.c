/*
=============================================
🕹️ PROGRAM NAME: Rock Paper Scissors in C
=============================================

🎯 PROBLEM STATEMENT:
Build a console-based Rock Paper Scissors game where a user competes 
against the computer. The computer randomly chooses Rock, Paper, or Scissors,
and the player selects their choice. The program decides the winner 
based on traditional rules and keeps track of scores for multiple rounds.

📥 INPUT / 📤 OUTPUT EXAMPLES:

Example 1:
-----------
Input:
  How many rounds? → 3
  Round 1 → Player: Rock (0)
  Computer: Scissors (2)

Output:
  You Win this round!
  Current Score: You 1 | Computer 0
  ...
  Final Result: You won the match! Well played!

Example 2:
-----------
Input:
  Round 1 → Player: Paper (1)
  Computer: Scissors (2)
Output:
  Computer wins this round!
  Final Score: You 0 | Computer 1

⚙️ FEATURES:
  ✅ Best-of-N round system
  ✅ Randomized computer choices
  ✅ Animated “battle” effect
  ✅ Colored text for readability
  ✅ Random victory/draw/defeat messages
  ✅ Option to replay entire match

⏱️ TIME COMPLEXITY:
  O(1) per round (constant time for decision logic)

📚 AUTHOR:
  Rik Maity (2025)
=============================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int getComputerChoice();
int getWinner(int player, int computer);
void printChoice(int choice);
void printBanner();
void printRoundArt(int player, int computer);
void printSummary(int playerScore, int computerScore);
void clearScreen();
void delay(int milliseconds);
void printRandomMessage(int result);

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int getComputerChoice() {
    return rand() % 3;
}

int getWinner(int player, int computer) {
    if (player == computer)
        return 0;
    else if ((player == 0 && computer == 2) ||
             (player == 1 && computer == 0) ||
             (player == 2 && computer == 1))
        return 1;
    else
        return -1;
}

void printChoice(int choice) {
    switch (choice) {
        case 0:
            printf(RED "Rock" RESET);
            break;
        case 1:
            printf(GREEN "Paper" RESET);
            break;
        case 2:
            printf(CYAN "Scissors" RESET);
            break;
    }
}

void printBanner() {
    printf(YELLOW "=====================================\n" RESET);
    printf(BLUE "         ROCK  PAPER  SCISSORS        \n" RESET);
    printf(YELLOW "=====================================\n" RESET);
}

void printRoundArt(int player, int computer) {
    printf("\nYou chose: ");
    printChoice(player);
    printf("\nComputer chose: ");
    printChoice(computer);
    printf("\n");

    delay(500);
    printf("\nBattle in progress...\n");
    delay(800);
}

void printRandomMessage(int result) {
    const char *winMsgs[] = {
        "Nice move, you crushed it!",
        "You're unstoppable!",
        "Victory is yours!"
    };
    const char *loseMsgs[] = {
        "Ouch! That hurt!",
        "Better luck next round!",
        "Computer outsmarted you this time!"
    };
    const char *drawMsgs[] = {
        "It's a tie. Try again!",
        "Great minds think alike!",
        "Draw! No one wins this time."
    };

    int idx = rand() % 3;
    if (result == 1)
        printf(GREEN "%s\n" RESET, winMsgs[idx]);
    else if (result == -1)
        printf(RED "%s\n" RESET, loseMsgs[idx]);
    else
        printf(YELLOW "%s\n" RESET, drawMsgs[idx]);
}

void printSummary(int playerScore, int computerScore) {
    printf("\n=====================================\n");
    printf(CYAN "             MATCH SUMMARY            \n" RESET);
    printf("=====================================\n");
    printf("Your Score: %d\n", playerScore);
    printf("Computer Score: %d\n", computerScore);
    printf("=====================================\n");

    if (playerScore > computerScore)
        printf(GREEN "You won the match! Well played!\n" RESET);
    else if (playerScore < computerScore)
        printf(RED "Computer wins the match! Try again!\n" RESET);
    else
        printf(YELLOW "It's a draw overall!\n" RESET);
}

int main() {
    int playerChoice, computerChoice, result;
    int playerScore = 0, computerScore = 0;
    int rounds, roundCount = 0;
    char playAgain;

    srand(time(0));
    clearScreen();
    printBanner();

    printf(CYAN "\nWelcome to Rock Paper Scissors!\n" RESET);
    printf("How many rounds would you like to play (Best of N)? ");
    scanf("%d", &rounds);

    while (1) {
        clearScreen();
        printBanner();

        printf("\nRound %d/%d\n", roundCount + 1, rounds);
        printf("\nChoose your move:\n");
        printf("0. Rock\n1. Paper\n2. Scissors\nYour choice: ");
        scanf("%d", &playerChoice);

        if (playerChoice < 0 || playerChoice > 2) {
            printf(RED "Invalid choice! Please try again.\n" RESET);
            delay(1000);
            continue;
        }

        computerChoice = getComputerChoice();
        printRoundArt(playerChoice, computerChoice);
        result = getWinner(playerChoice, computerChoice);

        if (result == 1) playerScore++;
        else if (result == -1) computerScore++;

        printRandomMessage(result);
        printf("\nCurrent Score: You %d | Computer %d\n", playerScore, computerScore);

        roundCount++;
        if (roundCount == rounds) {
            printSummary(playerScore, computerScore);
            break;
        }

        printf("\nPress Enter to play next round...");
        getchar(); getchar();
    }

    printf("\nWould you like to play another match? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        printf(YELLOW "\nThanks for playing! See you next time!\n" RESET);
    }

    return 0;
}
