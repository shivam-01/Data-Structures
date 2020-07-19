// A program to introduce Circular Doubly Linked list and its operations

#include<stdio.h>
#include<stdlib.h>

// Declaration of Circular Doubly Linked list
struct node {
  struct node *next;
  int data;
  struct node *prev;
};

struct node *start = NULL;

// Operations on Doubly linked list
struct node *create(struct node *); // Create a list
struct node *display(struct node *); // Display the list
struct node *insert_beg(struct node *); // Add a node at the beginning
struct node *insert_end(struct node *); // Add a  node at the end
struct node *delete_beg(struct node *); // Delete a node from the beginning
struct node *delete_end(struct node *); // Delete a node from the end
struct node *delete_node(struct node *); // Delete a given node
struct node *delete_list(struct node *); // Delete the entire list

int main() {
  int option;
  do{
    printf("*** Main Menu ***\n");
    printf("1. Create a list.\n");
    printf("2. Display the list.\n");
    printf("3. Add a node at the beginning.\n");
    printf("4. Add a node at the end.\n");
    printf("5. Delete a node from the beginning.\n");
    printf("6. Delete a node from the end.\n");
    printf("7. Delete a given node.\n");
    printf("8. Delete the entire list.\n");
    printf("9. Exit.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option) {
      case 1 : start = create(start);
      break;
      case 2 : start = display(start);
      break;
      case 3 : start = insert_beg(start);
      break;
      case 4 : start = insert_end(start);
      break;
      case 5 : start = delete_beg(start);
      break;
      case 6 : start = delete_end(start);
      break;
      case 7 : start = delete_node(start);
      break;
      case 8 : start = delete_list(start);
      printf("\nDoubly Linked List Deleted.\n");
      break;
    }
  } while (option != 9);
  return 0;
}

// Create a node
struct node *create(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end.\n");
  printf("\nEnter the data : ");
  scanf("%d", &num);
  while (num!=-1) {
    if(start==NULL){
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = num;
      new_node->next = new_node->prev = new_node;
      start = new_node;
    }
    else {
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = num;
      ptr = start;
      while (ptr->next!=start)
        ptr = ptr->next;
      new_node->next = start;
      start->prev = new_node;
      new_node->prev = ptr;
      ptr->next = new_node;
    }
    printf("\nEnter the data : ");
    scanf("%d", &num);
  }
  return start;
}

// Display the list
struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next!=start) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
  printf("%d\n", ptr->data);
  return start;
}

// Add a node at the beginning
struct node *insert_beg(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\nEnter the data : ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->next!=start)
    ptr = ptr->next;
  new_node->prev = ptr;
  ptr->next = new_node;
  new_node->next = start;
  start->prev = new_node;
  start = new_node;
  return start;
}

// Add a node at the end
struct node *insert_end(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("\nEnter the data : ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->next!=start)
    ptr = ptr->next;
  ptr->next = new_node;
  new_node->prev = ptr;
  new_node->next = start;
  start->prev = new_node;
  return start;
}

// Delete a node from the beginning
struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next!=start)
    ptr = ptr->next;
  ptr->next = start->next;
  start->next->prev = ptr;
  free(start);
  start = ptr->next;
  return start;
}

// Delete a node from the end
struct node *delete_end(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next!=start)
    ptr = ptr->next;
  ptr->prev->next = start;
  start->prev = ptr->prev;
  free(ptr);
  return start;
}

// Delete a given node
struct node *delete_node(struct node *start) {
  struct node *ptr;
  int val;
  printf("\nEnter the value of the node which has to be deleted : ");
  scanf("%d", &val);
  ptr = start;
  if (ptr->data==val) {
    start = delete_beg(start);
    return start;
  }
  else {
    while (ptr->data!=val)
      ptr = ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return start;
  }
}

// Delete the entire list
struct node *delete_list(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next!=start)
    start = delete_end(start);
  free(start);
  return start;
}
