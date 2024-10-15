#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node {

    char *data;
    int p;
    struct node *next;
};

void printlinklist(struct node *f) {
    struct node *ptr = f;
    while (ptr != NULL) {
      printf(" %s (Priority: %d) ->", ptr->data, ptr->p);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

void enqueue(struct node **f, char val[], int pi) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Queue is full\n");
        return;
    }
    n->data = strdup(val); 
    n->p = pi;
    n->next = NULL;

    // If the queue is empty or the new node has higher priority than the first node
    if (*f == NULL || (*f)->p < pi) {
        n->next = *f;
        *f = n;
    } else {
        // Find the right place to insert based on priority
        struct node *ptr = *f;
        while (ptr->next != NULL && ptr->next->p >= pi) {
            ptr = ptr->next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}


char *dequeue(struct node **f) {
    if (*f == NULL) {
        printf("Queue is empty\n");
        return  NULL;
    } else {
        struct node *temp = *f;
        char  *val= temp->data;
        *f = (*f)->next;
        free(temp);
        return val;
    }
}

char* dequeue_last(struct node **f) {
    if (*f == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }

    struct node *temp = *f;
  if (temp->next == NULL) {
       char *val = temp->data; // Store the data to return
       *f = NULL;               // Update the front to NULL
       free(temp);              // Free the last node
       return val;              // Return the data
    }
    while (temp->next->next!= NULL) {
        temp = temp->next;
        
    }
     char *val = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return val;
}


int main()
{
    int opt, pi;
    char *result;
    char val[20];
    struct node *f = NULL;
    struct node *r= NULL;
   
   

    while (1)
    {
        printf("\nplease chose below option to perform task : \n");
        printf("1- print queue\n");
        printf("2- enqueue\n");
        printf("3- dqueue max\n");      
        printf("4 dqueue min\n");      
        printf("5- exit\n");
        printf("enter option : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printlinklist(f);
            break;
        case 2:
            printf("enter element to enqueue :");
            scanf("%s %d", &val , &pi);
            enqueue(&f, val , pi) ;
            break;                                                                        
        case 3:
            result = dequeue(&f);
            if (result != NULL)
            {
                printf("successfully deleted : %s", result);
            }
            else
                printf("not able to delete");
            break;
         case 4:
            result = dequeue_last(&f);
            if (result != NULL)
            {
                printf("successfully deleted : %s", result);
            }
            else
                printf("not able to delete");
            break;
       
        case 5:
            exit(0);
        }
    }
    return 0;
}



// /...........................OUTPUT..........................

// PS E:\@NITT LAB\dslab\lab_06> ./a.exe

// please chose below option to perform task : 
// 1- print queue
// 2- enqueue
// 3- dqueue
// 4- exit
// enter option : 
// please chose below option to perform task : 
// 1- print queue
// PS E:\@NITT LAB\dslab\lab_06> gcc .\priroityqueue.c
// PS E:\@NITT LAB\dslab\lab_06> ./a.exe

// please chose below option to perform task : 
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2
// enter element to enqueue :Adam 5

// please chose below option to perform task : 
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2
// enter element to enqueue :Barb 4

// please chose below option to perform task : 
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2
// enter element to enqueue :Flo 7

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2   
// enter element to enqueue :Don 1

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 1
//  Flo (Priority: 7) -> Adam (Priority: 5) -> Barb (Priority: 4) -> Don (Priority: 1) -> NULL

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 4
// successfully deleted : Don
// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 1
//  Flo (Priority: 7) -> Adam (Priority: 5) -> Barb (Priority: 4) -> NULL

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2
// enter element to enqueue :Joe 3

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2    
// enter element to enqueue :Linda 6

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 1
//  Flo (Priority: 7) -> Linda (Priority: 6) -> Adam (Priority: 5) -> Barb (Priority: 4) -> Joe (Priority: 3) -> NULL

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 4
// successfully deleted : Joe
// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 4
// successfully deleted : Barb
// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 1
//  Flo (Priority: 7) -> Linda (Priority: 6) -> Adam (Priority: 5) -> NULL

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2
// enter element to enqueue :George 8

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 4
// successfully deleted : Adam
// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 2
// enter element to enqueue :Hannah 2

// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 4
// successfully deleted : Hannah
// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 4
// successfully deleted : Linda
// please chose below option to perform task :
// 1- print queue
// 2- enqueue
// 3- dqueue max
// 4 dqueue min
// 5- exit
// enter option : 1
//  George (Priority: 8) -> Flo (Priority: 7) -> NULL

