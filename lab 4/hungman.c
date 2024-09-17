#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INCORRECT_GUESSES 10

// Define the structure for each letter node
struct Letter {
    char letter;
    int revealed;
    struct Letter* next;
};

// Create a new letter node
struct Letter* createLetter(char letter) {
    struct Letter* newLetter = (struct Letter*)malloc(sizeof(struct Letter));
    newLetter->letter = letter;
    newLetter->revealed = 0;  // Initially hidden
    newLetter->next = NULL;
    return newLetter;
}

// Append a letter to the linked list
struct Letter* appendLetter(struct Letter* head, char letter) {
    struct Letter* newLetter = createLetter(letter);
    if (head == NULL) {
        return newLetter;
    }
    struct Letter* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newLetter;
    return head;
}

// Display the word with revealed and hidden letters
void displayWord(struct Letter* head) {
    struct Letter* temp = head;
    while (temp != NULL) {
        if (temp->revealed) {
            printf(" %c ", temp->letter);
        } else {
            printf(" * ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Check if a guessed letter is in the word and reveal it
int checkAndReveal(struct Letter* head, char guess) {
    struct Letter* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (tolower(temp->letter) == tolower(guess)) {
            temp->revealed = 1;
            found = 1;
        }
        temp = temp->next;
    }
    return found;
}

// Check if the entire word is revealed
int isWordRevealed(struct Letter* head) {
    struct Letter* temp = head;
    while (temp != NULL) {
        if (!temp->revealed) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main() {
    // The word to guess
    char word[] = "pradeep";
    struct Letter* head = NULL;

    // Initialize linked list with the word
    for (int i = 0; i < strlen(word); i++) {
        head = appendLetter(head, word[i]);
    }

    int incorrectGuesses = 0;
    int maxGuesses = MAX_INCORRECT_GUESSES;
    char guess;

    printf("Welcome to Hangman! Try to guess the word.\n");

    // Game loop
    while (incorrectGuesses < maxGuesses && !isWordRevealed(head)) {
        displayWord(head);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        // Check if the guessed letter is in the word
        if (checkAndReveal(head, guess)) {
            printf("Good guess!\n");
        } else {
            incorrectGuesses++;
            printf("Incorrect! You have %d incorrect guesses left.\n", maxGuesses - incorrectGuesses);
        }

        // Check if the word is fully revealed
        if (isWordRevealed(head)) {
            printf("Congratulations! You guessed the word %s  !\n" , word);
        }
    }

    if (incorrectGuesses == maxGuesses) {
        printf("You've been hanged! The word was '%s'.\n", word);
    }

    return 0;
}
