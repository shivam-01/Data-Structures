// A program to introduce Header Linked list and its operations

#include<stdio.h>
#include<stdlib.h>

// Declaration of Linked List
struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;

// Operations on linked list
struct node *create(struct node *); // Create a list
struct node *display(struct node *); // Display the list

int main() {
  int option;
  do{
    printf("*** Main Menu ***\n");
    printf("1. Create a list.\n");
    printf("2. Display the list.\n");
    printf("3. Exit.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option){
      case 1 : start = create(start);
      break;
      case 2 : start = display(start);
      break;
    }
  } while (option != 3);
  return 0;
}

struct node *create(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end.\n");
  printf("\nEnter the data : ");
  scanf("%d", &num);
  while (num!=-1) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (start==NULL) {
      start = (struct node *)malloc(sizeof(struct node));
      start->next = new_node;
    }
    else {
      ptr = start;
      while (ptr->next!=NULL)
        ptr = ptr->next;
      ptr->next = new_node;
    }
    printf("\nEnter the data : ");
    scanf("%d", &num);
  }
  return start;
}

struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr!=NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
  return start;
}
