#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define MAX_CARDS 52
#define MAX_HAND 12

const char *suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
const char *ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", 
                       "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const int values[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

typedef struct {
    char suit[10];
    char rank[10];
} Card;

typedef struct {
    Card cards[MAX_CARDS];
    int top;
} Deck;

typedef struct {
    Card cards[MAX_HAND];
    int count;
    int value;
    int aces;
} Hand;

typedef struct {
    int total;
    int bet;
} Chips;

void initDeck(Deck *deck) {
    int index = 0;
    for (int s = 0; s < NUM_SUITS; s++) {
        for (int r = 0; r < NUM_RANKS; r++) {
            strcpy(deck->cards[index].suit, suits[s]);
            strcpy(deck->cards[index].rank, ranks[r]);
            index++;
        }
    }
    deck->top = 0;
}

void shuffleDeck(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

Card dealCard(Deck *deck) {
    return deck->cards[deck->top++];
}

void addCardToHand(Hand *hand, Card card) {
    hand->cards[hand->count++] = card;
    for (int i = 0; i < NUM_RANKS; i++) {
        if (strcmp(ranks[i], card.rank) == 0) {
            hand->value += values[i];
            if (i == 12) hand->aces++;
            break;
        }
    }
}

void adjustForAce(Hand *hand) {
    while (hand->value > 21 && hand->aces > 0) {
        hand->value -= 10;
        hand->aces--;
    }
}

void takeBet(Chips *chips) {
    int bet;
    while (1) {
        printf("How many chips would you like to bet? ");
        if (scanf("%d", &bet) != 1) {
            printf("Please enter an integer value.\n");
            while (getchar() != '\n');
            continue;
        }
        if (bet > chips->total) {
            printf("You don't have enough chips. You have %d\n", chips->total);
        } else {
            chips->bet = bet;
            break;
        }
    }
}

void hit(Deck *deck, Hand *hand) {
    Card newCard = dealCard(deck);
    addCardToHand(hand, newCard);
    adjustForAce(hand);
}

void showSome(Hand *player, Hand *dealer) {
    printf("\nDealer's Hand:\n");
    printf(" <card hidden>\n");
    printf(" %s of %s\n", dealer->cards[1].rank, dealer->cards[1].suit);
    printf("\nPlayer's Hand:\n");
    for (int i = 0; i < player->count; i++) {
        printf(" %s of %s\n", player->cards[i].rank, player->cards[i].suit);
    }
    printf("Player's Total: %d\n\n", player->value);
}

void showAll(Hand *player, Hand *dealer) {
    printf("\nDealer's Hand:\n");
    for (int i = 0; i < dealer->count; i++) {
        printf(" %s of %s\n", dealer->cards[i].rank, dealer->cards[i].suit);
    }
    printf("Dealer's Total: %d\n\n", dealer->value);
    printf("Player's Hand:\n");
    for (int i = 0; i < player->count; i++) {
        printf(" %s of %s\n", player->cards[i].rank, player->cards[i].suit);
    }
    printf("Player's Total: %d\n\n", player->value);
}

void playerBusts(Chips *chips) {
    printf("PLAYER BUSTS! Dealer wins.\n");
    chips->total -= chips->bet;
}

void playerWins(Chips *chips) {
    printf("PLAYER WINS!\n");
    chips->total += chips->bet;
}

void dealerBusts(Chips *chips) {
    printf("DEALER BUSTS! Player wins.\n");
    chips->total += chips->bet;
}

void dealerWins(Chips *chips) {
    printf("DEALER WINS!\n");
    chips->total -= chips->bet;
}

void push() {
    printf("It's a push! Player and Dealer tie.\n");
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y') {
        printf("Welcome to Blackjack!\n");
        Deck deck;
        initDeck(&deck);
        shuffleDeck(&deck);

        Hand player = {0};
        Hand dealer = {0};

        hit(&deck, &player);
        hit(&deck, &player);
        hit(&deck, &dealer);
        hit(&deck, &dealer);

        Chips chips = {100, 0};
        takeBet(&chips);

        int playing = 1;
        while (playing && player.value <= 21) {
            showSome(&player, &dealer);
            char choice;
            printf("Hit or Stand? (h/s): ");
            scanf(" %c", &choice);
            if (choice == 'h') {
                hit(&deck, &player);
            } else if (choice == 's') {
                playing = 0;
            } else {
                printf("Invalid input. Please enter 'h' or 's'.\n");
            }
        }

        if (player.value > 21) {
            playerBusts(&chips);
        } else {
            while (dealer.value < 17) {
                hit(&deck, &dealer);
            }
            showAll(&player, &dealer);

            if (dealer.value > 21) {
                dealerBusts(&chips);
            } else if (dealer.value > player.value) {
                dealerWins(&chips);
            } else if (player.value > dealer.value) {
                playerWins(&chips);
            } else {
                push();
            }
        }

        printf("\nPlayer's total chips: %d\n", chips.total);
        printf("Play another hand? (y/n): ");
        scanf(" %c", &playAgain);
    }
    printf("Thanks for playing!\n");
    return 0;
}