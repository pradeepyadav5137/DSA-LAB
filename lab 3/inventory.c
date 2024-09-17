
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct product
{
    int id;
    int price;
    char name[10];
    int boughtCount;
    struct product *next;
};


struct product *createNode(int id, int price, char *name)
{
    struct product *newNode = (struct product *)malloc(sizeof(struct product));
    newNode->id = id;
    strcpy(newNode->name, name);
    // newNode->name[10] = name;
    newNode->price = price;
    newNode->boughtCount = 0;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct product **head, int id, char *name, int price)
{
    struct product *newNode = createNode(id, price, name);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct product *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteNode(struct product **head, int id)
{
    struct product *temp = *head;
    struct product *prev = NULL;

    
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    
    if (temp != NULL && temp->id == id)
    {
        *head = temp->next; 
        free(temp);         
        printf("Product with ID %d deleted.\n", id);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->id != id)
    {
        prev = temp; 
        temp = temp->next;
    }

    
    if (temp == NULL)
    {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    
    free(temp);
    printf("Product with ID %d deleted.\n", id);
}


void searchNode(struct product **head, int id){
      struct product *ptr = *head;
      
      while(ptr != NULL)
      {
        if(ptr->id == id){
            printf("item %d is in the Inventory. " ,ptr->id);
            break;
        }
        ptr= ptr->next;
      }

   
}

void printInventory(struct product **head)
{
    struct product *temp = *head;
    printf("\nProduct Inventory:\n");
    while (temp != NULL)
    {
        printf("ID: %d, Name: %s, Price: %d, Bought Count: %d\n", temp->id, temp->name, temp->price, temp->boughtCount);
        temp = temp->next;
    }
}

int main()
{
    struct product *inventory = NULL;

    int id, price;
    char name[10];
    int num;

    printf("Enter the details of 3 products (ID, Name, Price):\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Product %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Name: ");
        scanf("%s", name);
        printf("Price: ");
        scanf("%d", &price);

        // Insert the product into the inventory list
        insertNode(&inventory, id, name, price);
    }
    do
    {
        printf("Enter the bellow option to perform tasks : \n");
        printf("1 - print Inventory\n 2-insert another node \n 3- delete node \n 4 - search item by id\n 5- exit program \n");
        
        scanf("\n%d", &num);
        if (num == 1)
        {
            printInventory(&inventory);
        }
        else if (num == 2)
        {
            printf("Product %d:\n");
            printf("ID: ");
            scanf("%d", &id);
            printf("Name: ");
            scanf("%s", name);
            printf("Price: ");
            scanf("%d", &price);

            // Insert the product into the inventory list
            insertNode(&inventory, id, name, price);
        }
        else if (num == 3)
        {
            printf("enter id");
            scanf("%d", &id);
            deleteNode(&inventory, id);
        }
        else if(num == 4)
        {
            printf("enter id");
            scanf("%d", &id);
            searchNode(&inventory,id);

        }
    } while (num != 5);

    return 0;
}
