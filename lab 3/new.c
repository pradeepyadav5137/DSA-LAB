#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each product node
struct Product {
    int id;
    char name[50];
    float price;
    int boughtCount;  // To track how many times a product has been bought
    struct Product* next;
};

// Function to create a new node (product)
struct Product* createNode(int id, char* name, float price) {
    struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->boughtCount = 0;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new product node at the end of the linked list
void insertNode(struct Product** head, int id, char* name, float price) {
    struct Product* newNode = createNode(id, name, price);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Product* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node (product) by ID
void deleteNode(struct Product** head, int id) {
    struct Product* temp = *head, *prev = NULL;
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node (product) by ID
struct Product* searchNode(struct Product* head, int id) {
    struct Product* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to increment the bought count for a product
void buyProduct(struct Product* head, int id) {
    struct Product* product = searchNode(head, id);
    if (product != NULL) {
        product->boughtCount++;
        printf("Product %s bought successfully!\n", product->name);
    } else {
        printf("Product not found!\n");
    }
}

// Function to print the most frequently bought product
void printMostFrequent(struct Product* head) {
    struct Product* temp = head;
    struct Product* mostFrequent = NULL;
    int maxCount = 0;
    
    while (temp != NULL) {
        if (temp->boughtCount > maxCount) {
            maxCount = temp->boughtCount;
            mostFrequent = temp;
        }
        temp = temp->next;
    }
    
    if (mostFrequent != NULL) {
        printf("Most frequently bought product: %s, Bought %d times\n", mostFrequent->name, mostFrequent->boughtCount);
    } else {
        printf("No products have been bought yet.\n");
    }
}

// Function to print the entire inventory
void printInventory(struct Product* head) {
    struct Product* temp = head;
    printf("Product Inventory:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Price: %.2f, Bought Count: %d\n", temp->id, temp->name, temp->price, temp->boughtCount);
        temp = temp->next;
    }
}

int main() {
    struct Product* inventory = NULL;

    // Inserting 10 products into the inventory
    insertNode(&inventory, 101, "Product1", 10.50);
    insertNode(&inventory, 102, "Product2", 15.30);
    insertNode(&inventory, 103, "Product3", 12.75);
    insertNode(&inventory, 104, "Product4", 22.40);
    insertNode(&inventory, 105, "Product5", 18.90);
    insertNode(&inventory, 106, "Product6", 9.80);
    insertNode(&inventory, 107, "Product7", 35.00);
    insertNode(&inventory, 108, "Product8", 40.60);
    insertNode(&inventory, 109, "Product9", 25.10);
    insertNode(&inventory, 110, "Product10", 30.70);

    // Simulating some purchases
    buyProduct(inventory, 101);
    buyProduct(inventory, 103);
    buyProduct(inventory, 103);
    buyProduct(inventory, 105);
    buyProduct(inventory, 105);
    buyProduct(inventory, 105);

    // Print the most frequently bought product
    printMostFrequent(inventory);

    // Print the inventory
    printInventory(inventory);

    // Delete a product from the inventory
    deleteNode(&inventory, 107);
    printf("\nAfter deleting Product7:\n");
    printInventory(inventory);

    return 0;
}
