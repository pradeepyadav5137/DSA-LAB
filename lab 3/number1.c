#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Phonebook Entry
struct PhonebookEntry {
    int cno;
    char name[50];
    char phone[15];
    int search_count;
    struct PhonebookEntry* next;
};

// Structure for Favorite List Entry
struct FavoriteEntry {
    char name[50];
    struct FavoriteEntry* next;
};

// Function to create a new phonebook entry node
struct PhonebookEntry* createPhonebookEntry(int cno, char* name, char* phone) {
    struct PhonebookEntry* newEntry = (struct PhonebookEntry*)malloc(sizeof(struct PhonebookEntry));
    newEntry->cno = cno;
    strcpy(newEntry->name, name);
    strcpy(newEntry->phone, phone);
    newEntry->search_count = 0;
    newEntry->next = NULL;
    return newEntry;
}

// Function to create a new favorite entry node
struct FavoriteEntry* createFavoriteEntry(char* name) {
    struct FavoriteEntry* newFav = (struct FavoriteEntry*)malloc(sizeof(struct FavoriteEntry));
    strcpy(newFav->name, name);
    newFav->next = NULL;
    return newFav;
}

// Function to add a phonebook entry (returns the new head of the list)
struct PhonebookEntry* addPhonebookEntry(struct PhonebookEntry* head, int cno, char* name, char* phone) {
    struct PhonebookEntry* newEntry = createPhonebookEntry(cno, name, phone);
    
    // If the list is empty, the new entry is the head
    if (head == NULL) {
        return newEntry;
    } else {
        // Traverse to the end of the list and add the new entry
        struct PhonebookEntry* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEntry;
        return head;  // Return the original head as it hasn't changed
    }
}

// Function to display the phonebook
void displayPhonebook(struct PhonebookEntry* head) {
    struct PhonebookEntry* temp = head;
    printf("\nPhonebook:\n");
    while (temp != NULL) {
        printf("Cno: %d, Name: %s, Phone: %s, Searches: %d\n", temp->cno, temp->name, temp->phone, temp->search_count);
        temp = temp->next;
    }
}

// Function to search a customer by cno and increment search count
// Returns the updated favorite list
struct FavoriteEntry* searchCustomer(struct PhonebookEntry* head, struct FavoriteEntry* favHead, int cno) {
    struct PhonebookEntry* temp = head;
    while (temp != NULL) {
        if (temp->cno == cno) {
            printf("\nCustomer found: Name: %s, Phone: %s\n", temp->name, temp->phone);
            temp->search_count++;

            // Add to favorite list if searched more than 2 times
            if (temp->search_count > 2) {
                struct FavoriteEntry* favTemp = favHead;
                int alreadyInFav = 0;

                // Check if already in favorite list
                while (favTemp != NULL) {
                    if (strcmp(favTemp->name, temp->name) == 0) {
                        alreadyInFav = 1;
                        break;
                    }
                    favTemp = favTemp->next;
                }

                if (!alreadyInFav) {
                    struct FavoriteEntry* newFav = createFavoriteEntry(temp->name);
                    newFav->next = favHead;
                    favHead = newFav;
                    printf("Customer %s added to favorite list!\n", temp->name);
                }
            }
            return favHead;  // Return the updated favorite list
        }
        temp = temp->next;
    }
    printf("Customer not found!\n");
    return favHead;
}

// Function to display the favorite list
void displayFavoriteList(struct FavoriteEntry* favHead) {
    struct FavoriteEntry* temp = favHead;
    printf("\nFavorite Customers:\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    struct PhonebookEntry* phonebook = NULL;
    struct FavoriteEntry* favList = NULL;

    // Add some entries to phonebook
    phonebook = addPhonebookEntry(phonebook, 1, "Alice", "1234567890");
    phonebook = addPhonebookEntry(phonebook, 2, "Bob", "0987654321");
    phonebook = addPhonebookEntry(phonebook, 3, "Charlie", "1122334455");

    int choice, cno;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Phonebook\n");
        printf("2. Search Customer by Cno\n");
        printf("3. Display Favorite List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPhonebook(phonebook);
                break;
            case 2:
                printf("Enter Cno to search: ");
                scanf("%d", &cno);
                favList = searchCustomer(phonebook, favList, cno);  // Update favList
                break;
            case 3:
                displayFavoriteList(favList);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
