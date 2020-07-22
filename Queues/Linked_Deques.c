// A program to introduce Linked Deques.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
  int data;
  struct node *next;
};

// Declaration of linked deque
struct queue {
  struct node *front;
  struct node *rear;
};

void input();
void output();
struct queue *create(); // Create linked deque
struct queue *insert_left(struct queue *, int); // Insert at front end
struct queue *insert_right(struct queue *, int); // Insert at rear end
struct queue *delete_left(struct queue *); // Delete from front end
struct queue *delete_right(struct queue *); // Delete from rear end
struct queue *display(struct queue *); // Display linked queue

int main() {
  int option;
  printf("\n*** Main Menu ***\n");
  printf("1. Input restricted deque.\n");
  printf("2. Output restricted deque.\n");
  printf("\nEnter your option : ");
  scanf("%d", &option);
  switch (option) {
    case 1: input();
            break;

    case 2: output();
            break;
  }
  return 0;
}

void input() {
  int option, val;
  struct queue *q = create();
  do {
    printf("\nINPUT RESTRICTED DEQUE\n");
    printf("1. Insert at right\n");
    printf("2. Delete from left\n");
    printf("3. Delete from right\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    printf("\nEnter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1: printf("\nEnter the number to insert in the queue : ");
              scanf("%d", &val);
              q = insert_right(q, val);
              break;

      case 2: q = delete_left(q);
              break;

      case 3: q = delete_right(q);
              break;

      case 4: q = display(q);
              break;
    }
  }while(option!=5);
}

void output() {
  int option, val;
  struct queue *q = create();
  do {
    printf("\nOUTPUT RESTRICTED DEQUE\n");
    printf("1. Insert at right\n");
    printf("2. Insert at left\n");
    printf("3. Delete from left\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    printf("\nEnter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1: printf("\nEnter the number to insert in the queue : ");
              scanf("%d", &val);
              q = insert_right(q, val);
              break;

      case 2: printf("\nEnter the number to insert in the queue : ");
              scanf("%d", &val);
              q = insert_left(q, val);
              break;

      case 3: q = delete_left(q);
              break;

      case 4: q = display(q);
              break;
    }
  }while(option!=5);
}

// create
struct queue *create() {
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
  q->front = q->rear = NULL;
  return q;
}

// insert_left
struct queue *insert_left(struct queue *q, int val) {
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = val;
  if(q->front == NULL) {
    q->front = q->rear = ptr;
    q->front->next = q->rear->next = NULL;
  }
  else {
    ptr->next = q->front;
    q->front = ptr;
  }
  return q;
}

// insert_right
struct queue *insert_right(struct queue *q, int val) {
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

// delete_left
struct queue *delete_left(struct queue *q) {
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

// delete_right
struct queue *delete_right(struct queue *q) {
  struct node *ptr, *p;
  ptr = q->front;
  p = NULL;
  if(q->front == NULL) {
    printf("UNDERFLOW\n");
    return q;
  }
  if(q->front == q->rear) {
      printf("The deleted value is : %d\n", ptr->data);
      free(ptr);
      q->front = NULL;
      q->rear = NULL;
    }
  else {
    while(ptr!=q->rear) {
    p = ptr;
    ptr = ptr->next;
  }
    q->rear = p;
    q->rear->next = NULL;
    printf("The deleted value is : %d\n", ptr->data);
    free(ptr);
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
