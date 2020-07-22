// A program to introduce Priority Queue

#include<stdio.h>
#include<malloc.h>

// Declaration of Priority Queue
struct node {
  int data;
  int priority;
  struct node *next;
};

struct node *start = NULL;
struct node *insert(struct node *); // Insert Operation
struct node *delete(struct node *); // Delete Operation
void display(struct node *); // Display the Queue

int main() {
  int option;
    do {
      printf("\n*** Main Menu ***\n");
      printf("1. INSERT\n");
      printf("2. DELETE\n");
      printf("3. DISPLAY\n");
      printf("4. EXIT.\n");
      printf("\nEnter your option : ");
      scanf("%d", &option );
      switch(option) {
        case 1 : start = insert(start);
                 break;
        case 2 : start = delete(start);
                 break;
        case 3 : display(start);
                 break;
    }
  } while (option!=4);
  return 0;
}

// insert
struct node *insert(struct node *start) {
  int val, pri;
  struct node *ptr, *p;
  ptr = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the value and its priority : ");
  scanf("%d %d", &val, &pri);
  ptr->data = val;
  ptr->priority = pri;
  if(start == NULL || pri < start->priority) {
    ptr->next = start;
    start = ptr;
  }
  else {
    p = start;
    while (p->next!=NULL && p->next->priority<=pri)
      p = p->next;
    ptr->next = p->next;
    p->next = ptr;
  }
  return start;
}

// delete
struct node *delete(struct node *start) {
  struct node *ptr;
  if(start == NULL) {
    printf("UNDERFLOW\n");
    return start;
  }
  else {
    ptr = start;
    printf("Deleted value is : %d\n", ptr->data);
    start = start->next;
    free(ptr);
  }
  return start;
}

// display
void display(struct node *start) {
  struct node *ptr;
  ptr = start;
  if(start == NULL)
    printf("QUEUE IS EMPTY\n");
  else {
    printf("Priority Queue is : \n");
  while (ptr!=NULL) {
    printf("%d[priority = %d]\n", ptr->data, ptr->priority);
    ptr = ptr->next;
    }
  }
}
