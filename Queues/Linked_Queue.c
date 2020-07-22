// A program to introduce Linked Queue

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
  int data;
  struct node *next;
};

// Declaration of linked queue
struct queue {
  struct node *front;
  struct node *rear;
};

struct queue *create(); // Create linked queue
struct queue *insert(struct queue *, int); // Insert Operation
struct queue *delete(struct queue *); // Delete Operation
struct queue *display(struct queue *); // Display the linked queue
int peek(struct queue *); // Peek Operation

int main() {
  int val, option;
  struct queue *q = create();
  do {
    printf("\n*** Main Menu ***\n");
    printf("1. Insert an element.\n");
    printf("2. Delete an element.\n");
    printf("3. Peek.\n");
    printf("4. Display the queue.\n");
    printf("5. EXIT.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option) {
      case 1 : printf("\nEnter the number to insert in the queue : ");
               scanf("%d", &val);
               q = insert(q,val);
               break;
      case 2 : q = delete(q);
               break;
      case 3 : val = peek(q);
               if(val != -1)
                printf("The first value in the queue is : %d\n", val);
               break;
      case 4 : q = display(q);
               break;
  }
} while (option!=5);
return 0;
}

// create linked queue
struct queue *create() {
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
  q->front = q->rear = NULL;
  return q;
}

// insert
struct queue *insert(struct queue *q, int val) {
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = val;
  if(q->front == NULL) {
    q->front = q->rear = ptr;
    q->front->next = q->rear->next = NULL;
  }
  else {
    q->rear->next = ptr;
    q->rear = ptr;
    q->rear->next = NULL;
  }
  return q;
}

// display
struct queue *display(struct queue *q) {
  struct node *ptr;
  ptr = q->front;
  if(ptr == NULL)
    printf("QUEUE IS EMPTY.\n");
  else {
    printf("\nThe contents of queue are : \n");
    while (ptr!=q->rear) {
      printf("%d\n", ptr->data);
      ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
  }
  return q;
}

// delete
struct queue *delete(struct queue *q) {
  struct node *ptr;
  ptr = q->front;
  if(q->front == NULL)
    printf("UNDERFLOW.\n");
  else {
    q->front = q->front->next;
    printf("The value deleted is : %d\n", ptr->data);
    free(ptr);
  }
  return q;
}

// peek
int peek(struct queue *q) {
  if(q->front == NULL) {
    printf("QUEUE IS EMPTY.\n");
    return -1;
  }
  else
    return q->front->data;
}
