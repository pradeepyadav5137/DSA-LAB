#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int guess = 10;

struct node
{
    int card_num;
    int hidden;
    struct node *next;
};

struct node *create_node(int number)
{
    struct node *node_Address = (struct node *)malloc(sizeof(struct node));
    (*node_Address).next = NULL;
    (*node_Address).card_num = number;
    (*node_Address).hidden = 0;
    return node_Address;
}

struct node *initial_list(struct node *start, int number)
{
    struct node *new = create_node(number);
    (*new).next = start;
    start = new;
    return start;
}

void display(struct node *start)
{
    struct node *temp = start;
    printf("\n");
    while (temp != NULL)
    {
        if ((*temp).hidden != 0)
        {
            printf(" %d ", (*temp).card_num);
        }
        else
        {
            printf(" * ");
        }
        temp = (*temp).next;
    }
}

void check(struct node *start, int pos1, int pos2)
{
    int i = 0;
    struct node *temp1 = start, *temp2 = start;
   
    if (pos1 <= 6 && pos1 > 0 && pos2 <= 6 && pos2 > 0 && pos1 != pos2)
    {
        for (i = 0; i < pos1 - 1; i++)
        {
            temp1 = (*temp1).next;
        }
        for (i = 0; i < pos2 - 1; i++)
        {
            temp2 = (*temp2).next;
        }
         if ((*temp1).hidden ==1 || (*temp2).hidden==1)
        {
            printf("Card is guessed alredy .....");
            printf("\nGuess left : %d",guess);
            return;
        }
        else if ((*temp1).card_num == (*temp2).card_num)
        {
            printf("\nCard Matched......\nCard is : %d", (*temp1).card_num);
            (*temp1).hidden = 1;
            (*temp2).hidden = 1;
            guess--;
        }
        else
        {
            printf("\nCard not matched.......");
            printf("\nPosition %d Card is : %d",pos1,(*temp1).card_num);
            printf("\nPosition %d Card is : %d",pos2,(*temp2).card_num);
            guess--;
        }
        
        printf("\nGuess left : %d",guess);
    }
    else
    {
        printf("\n Invalid Position !!!!");
    }
}

int main()
{
    struct node *head = NULL;
    int a, b;
    head = initial_list(head, 1);
    head = initial_list(head, 2);
    head = initial_list(head, 1);
    head = initial_list(head, 3);
    head = initial_list(head, 2);
    head = initial_list(head, 3);

    printf("\n 3 2 3 1 2 1\n");
    int i=0;
    sleep(1);
    system("cls");
    do
    {
        printf("\n--------------------------------------------------------------------");
        display(head);
        printf("\nEnter First position : ");
        scanf("%d", &a);
        printf("\nEnter Second position : ");
        scanf("%d", &b);
        check(head, a, b);

    } while (guess != 10);

    printf("\n\t\t.....!!!!! CONGRATULATIONS YOU WON !!!!!.....");

    

    return 0;
}