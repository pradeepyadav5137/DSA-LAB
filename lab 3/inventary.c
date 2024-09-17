#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Product Node
struct Product {
    int id;
    char name[50];
    float price;
    int count;  // Frequency of purchase
    struct Product* next;
};

// Function to create a new node
struct Product* createNode(int id, char* name, float price) {
    struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->count = 0;  // Initialize purchase count to 0
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
struct Product* insertNode(struct Product* head, int id, char* name, float price) {
    struct Product* newNode = createNode(id, name, price);
    if (head == NULL) {
        return newNode;
    }
    struct Product* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node by product id
struct Product* deleteNode(struct Product* head, int id) {
    struct Product* temp = head;
    struct Product* prev = NULL;

    // If head needs to be deleted
    if (temp != NULL && temp->id == id) {
        head = temp->next;  // Change head
        free(temp);         // Free old head
        return head;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the product was not found
    if (temp == NULL) {
        printf("Product with ID %d not found!\n", id);
        return head;
    }

    // Unlink the node from the list and free it
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to search for a product by ID and increment the purchase count
struct Product* searchNode(struct Product* head, int id) {
    struct Product* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->count++;  // Increment the purchase count
            printf("Product found: %s, Price: %.2f, Purchases: %d\n", temp->name, temp->price, temp->count);
            return temp;
        }
        temp = temp->next;
    }
    printf("Product with ID %d not found!\n", id);
    return NULL;
}

// Function to analyze the linked list and print the most frequently bought products
void analyzeList(struct Product* head) {
    if (head == NULL) {
        printf("No products in the list!\n");
        return;
    }

    struct Product* temp = head;
    int maxCount = 0;

    // Find the maximum purchase count
    while (temp != NULL) {
        if (temp->count > maxCount) {
            maxCount = temp->count;
        }
        temp = temp->next;
    }

    // Print products with the maximum purchase count
    printf("Most frequently bought products:\n");
    temp = head;
    while (temp != NULL) {
        if (temp->count == maxCount && maxCount > 0) {
            printf("Product: %s, Purchases: %d\n", temp->name, temp->count);
        }
        temp = temp->next;
    }
}

// Function to display the entire inventory
void displayInventory(struct Product* head) {
    struct Product* temp = head;
    printf("\nInventory:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Price: %.2f, Purchases: %d\n", temp->id, temp->name, temp->price, temp->count);
        temp = temp->next;
    }
}

int main() {
    struct Product* inventory = NULL;

    // Insert 10 products into the inventory
    inventory = insertNode(inventory, 1, "Product1", 10.0);
    inventory = insertNode(inventory, 2, "Product2", 20.0);
    inventory = insertNode(inventory, 3, "Product3", 30.0);
    inventory = insertNode(inventory, 4, "Product4", 40.0);
    inventory = insertNode(inventory, 5, "Product5", 50.0);
    inventory = insertNode(inventory, 6, "Product6", 60.0);
    inventory = insertNode(inventory, 7, "Product7", 70.0);
    inventory = insertNode(inventory, 8, "Product8", 80.0);
    inventory = insertNode(inventory, 9, "Product9", 90.0);
    inventory = insertNode(inventory, 10, "Product10", 100.0);

    int choice, id;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Inventory\n");
        printf("2. Search Product by ID\n");
        printf("3. Delete Product by ID\n");
        printf("4. Analyze Most Frequently Bought Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory(inventory);
                break;
            case 2:
                printf("Enter Product ID to search: ");
                scanf("%d", &id);
                searchNode(inventory, id);
                break;
            case 3:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);
                inventory = deleteNode(inventory, id);
                break;
            case 4:
                analyzeList(inventory);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
