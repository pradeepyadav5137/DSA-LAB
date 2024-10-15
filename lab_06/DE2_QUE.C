#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

// output restrict queue

int isempty(struct queue *q) {
    return q->r == q->f;
}

int isfull(struct queue *q) {
    return q->r == q->size - 1;
}

int dequeue(struct queue *q) {
    int a;
    if (isempty(q)) {
	printf("Cannot dequeue, queue is empty.\n");
	return -1;
    } else {
	 a = q->arr[++q->f];
	if (q->f > q->r) {
	    q->f = q->r = -1;
	}
	return a;
    }
}

void enqueueFront(struct queue *q, int val) {
    if (q->f == -1) {
	printf("Cannot insert, queue doesn't have space at first.\n");
    } else {
	q->arr[q->f--] = val;
    }
}


void enqueueRear(struct queue *q, int val) {
    if (isfull(q)) {
	printf("Cannot insert, queue is full.\n");
    } else {
	q->arr[++q->r] = val;
    }
}

void printqueue(struct queue *q) {
    int i;
    if (isempty(q)) {
	printf("Queue is empty.\n");
    } else {
	printf("Queue is: ");
	for (i = q->f + 1; i <= q->r; i++) {
	    printf("%d ", q->arr[i]);
	}
	printf("\n");
    }
}

int main() {
      int flag = 1;
    int opt, val, result;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    while (flag) {
	printf("\nChoose an option:\n");
	printf("1- Print queue\n");
	printf("2- Enqueue at Rear\n");
	printf("3- Enqueue at Front\n");
	printf("4- Dequeue\n");
	printf("5- Check if full\n");
	printf("6- Check if empty\n");
	printf("7- Exit\n");
	printf("Enter option: ");
	scanf("%d", &opt);

	switch (opt) {
	    case 1:
		printqueue(q);
		break;
	    case 2:
		printf("Enter element to enqueue: ");
		scanf("%d", &val);
		enqueueRear(q, val);
		break;
	    case 3:
		printf("Enter element to enqueue: ");
		scanf("%d", &val);
		enqueueFront(q, val);
		break;
	    case 4:
		result = dequeue(q);
		if (result != -1) {
		    printf("Successfully deleted: %d\n", result);
		}
		break;
	    case 5:
		printf(isfull(q) ? "Queue is full.\n" : "Queue is not full.\n");
		break;
	    case 6:
		printf(isempty(q) ? "Queue is empty.\n" : "Queue is not empty.\n");
		break;
	    case 7:
		free(q->arr);
		free(q);
		printf("Exiting program.\n");
		flag = 0;
		break;
	}
    }
    return 0;
}
