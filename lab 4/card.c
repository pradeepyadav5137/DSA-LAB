#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Card {
    int value;
    int revealed;
    struct Card* next;
};

// Create a new card
struct Card* createCard(int value) {
    struct Card* newCard = (struct Card*)malloc(sizeof(struct Card));
    newCard->value = value;
    newCard->revealed = 0;
    newCard->next = NULL;
    return newCard;
}

// Append a card to the linked list
struct Card* appendCard(struct Card* head, int value) {
    struct Card* newCard = createCard(value);
    if (head == NULL) {
        return newCard;
    }
    struct Card* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newCard;
    return head;
}

// Shuffle the linked list
void shuffleCards(struct Card** head, int size) {
    struct Card* temp = *head;
    struct Card** cardArray = (struct Card**)malloc(size * sizeof(struct Card*));
    int i = 0;

    while (temp != NULL) {
        cardArray[i++] = temp;
        temp = temp->next;
    }

    srand(time(NULL));
    for (i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Card* swap = cardArray[i];
        cardArray[i] = cardArray[j];
        cardArray[j] = swap;
    }

    for (i = 0; i < size - 1; i++) {
        cardArray[i]->next = cardArray[i + 1];
    }
    cardArray[size - 1]->next = NULL;
    *head = cardArray[0];
    free(cardArray);
}

// Display the cards
void displayCards(struct Card* head) {
    struct Card* temp = head;
    int pos = 1;
    printf("Board:\n");
    while (temp != NULL) {
        if (temp->revealed) {
            printf("[%d: %d] ", pos, temp->value);
        } else {
            printf("[%d: X] ", pos);
        }
        temp = temp->next;
        pos++;
    }
    printf("\n");
}

// Get a card by position
struct Card* getCardByPosition(struct Card* head, int position) {
    struct Card* temp = head;
    int pos = 1;
    while (temp != NULL && pos < position) {
        temp = temp->next;
        pos++;
    }
    return temp;
}

// Check if all cards are revealed
int allCardsRevealed(struct Card* head) {
    struct Card* temp = head;
    while (temp != NULL) {
        if (!temp->revealed) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main() {
    int numPairs = 4;
    int totalCards = numPairs * 2;
    int guessCount = 0;
    struct Card* head = NULL;

    // Initialize card pairs
    for (int i = 1; i <= numPairs; i++) {
        head = appendCard(head, i); // Add each pair of cards
        head = appendCard(head, i);
    }

    // Shuffle the cards
    shuffleCards(&head, totalCards);

    int pos1, pos2;
    struct Card *card1, *card2;

    // Game loop
    while (!allCardsRevealed(head)) {
        displayCards(head);

        // Input: Player selects two cards
        printf("First card (1-%d): ", totalCards);
        scanf("%d", &pos1);
        printf("Second card (1-%d): ", totalCards);
        scanf("%d", &pos2);

        // Increment guess count
        guessCount++;

        // Get selected cards
        card1 = getCardByPosition(head, pos1);
        card2 = getCardByPosition(head, pos2);

        // Check if they match
        if (card1 != NULL && card2 != NULL && card1->value == card2->value && card1 != card2) {
            printf("Match! Cards %d and %d.\n", pos1, pos2);
            card1->revealed = 1;
            card2->revealed = 1;
        } else {
            printf("No match. Try again.\n");
        }

        // Display guess count so far
        printf("Guesses: %d\n\n", guessCount);
    }

    // Victory message
    printf("You matched all pairs in %d guesses! Congratulations!\n", guessCount);
    return 0;
}
