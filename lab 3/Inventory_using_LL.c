#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    int P_id;
    char P_name[20];
    int price;
    struct node * next ;
};

struct node * create_node()
{
    struct node * node_address=(struct node *)malloc(sizeof(struct node));

    (*node_address).next=NULL;

    printf("Enter product id : ");
    scanf("%d",&(*node_address).P_id);

    printf("Enter product name : ");
    scanf("%s",&(*node_address).P_name);

    printf("Enter product price : ");
    scanf("%d",&(*node_address).price);

    return node_address;
}

struct node * insert_item(struct node *start)
{
    struct node *new=create_node(),*current=start;
    if(start==NULL)
    {
        start=new;
    }
    else
    {
        while((*current).next!=NULL)
        {
            current=(*current).next;
        }

        (*current).next=new;
    }
    return start;
}

void display(struct node * start)
{
    struct node * current=start;
    if(start!=NULL)
    {
        printf("\n\tProduct ID\tProduct name\tProduct price");
        while(current!=NULL)
        {
            printf("\n\t%d\t\t%s\t\t%d",(*current).P_id,(*current).P_name,(*current).price);
            current=(*current).next;
        }
    }
    else
    {
        printf("\nList is empty.");
    }
}

struct node * search(struct node *start)
{
    int datum;
    struct node * current =start;
    printf("\nEnter the Product ID you want to search : ");
    scanf("%d",&datum);
    while(current!=NULL)
    {
        if((*current).P_id==datum)
        {
            printf("\nItem %d is in the Inventory.",(*current).P_id);
            break;
            return current;
        }
        current=(*current).next;
    }
    if(current==NULL)
    {printf("\nProduct is not in Inventory.");return current;}
    
}

struct node * delete_node(struct node * start)
{
    int id;
    printf("\nEnter the Product ID you want to search : ");
    scanf("%d",&id);
    struct node * current =start,* temp;
    if(start==NULL)
    {
        printf("\nInventory is empty.");
        return start;
    }
    else if((*start).next==NULL||(*start).P_id==id)
    {
        if((*start).P_id==id&&(*start).next==NULL)
        {
            printf("\nItem deleted.");
            free(start);
            start=NULL;
            return start;
        }
        else if((*start).P_id==id)
        {
            start=(*start).next;
            free(current);
            return start;
        }
        else{printf("\nNo such data to delete.");return start;}
    }
    else
    {
        while((*current).next!=NULL&&(*current).next->P_id!=id)
        {
            current=(*current).next;
        }
        if((*current).next==NULL)
        {
            printf("\nNo such data to delete.");
            return start;
        }
        else
        {
            temp=(*current).next;
            (*current).next=(*current).next->next;
            free(temp);
            return start;
        }

    }
}

int main()
{
    struct node * head=NULL,*end=NULL;
    int choice;
    for(int i=0 ;i<3;i++)
    {
        head=insert_item(head);
    }
    do
    {
        printf("\n----------------------------------------------------------------------");
        printf("\nWhat you want :\n1.Insert an item\n2.Delete an item.\n3.Display the items\n4.Search an item.\n5.Exit\n\t\tYour option : ");
        scanf("%d",&choice);
        if(choice<0||choice>5)
        {printf("\n\t\tInvalid input !!!!!!");}
        else
        {
            if(choice==1)
            {
                head=insert_item(head);
            }
            else if(choice==2)
            {
                head = delete_node(head);
            }
            else if(choice==3)
            {
                display(head);
            }
            else if(choice==4)
            {
                search(head);
            }
        } 

    }while(choice!=5);
    return 0;
}






