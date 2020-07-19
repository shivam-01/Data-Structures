// A program to introduce Circular Linked list and its operations

#include<stdio.h>
#include<stdlib.h>

// Declaration of Linked list
struct node{
  int data;
  struct node *next;
};

struct node *start = NULL;

// Operations on linked list
struct node *create(struct node *); // Create a list
struct node *display(struct node *); // Display the list
struct node *insert_beg(struct node *); // Add a node at the beginning
struct node *insert_end(struct node *); // Add a  node at the end
struct node *delete_beg(struct node *); // Delete a node from the beginning
struct node *delete_end(struct node *); // Delete a node from the end
struct node *delete_after(struct node *); // Delete a node after a given node
struct node *delete_list(struct node *); // Delete the entire list

int main(){
  int option;
  do{
    printf("*** Main Menu ***\n");
    printf("1. Create a list.\n");
    printf("2. Display the list.\n");
    printf("3. Add a node at the beginning.\n");
    printf("4. Add a node at the end.\n");
    printf("5. Delete a node from the beginning.\n");
    printf("6. Delete a node from the end.\n");
    printf("7. Delete a given node after a given node.\n");
    printf("8. Delete the entire list.\n");
    printf("9. Exit.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option){
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
      case 7 : start = delete_after(start);
      break;
      case 8: start = delete_list(start);
      printf("\nCircular Linked List Deleted.\n");
      break;
    }
  } while (option != 9);
  return 0;
}

// Create a list
struct node *create(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end.\n");
  printf("\nEnter the data : ");
  scanf("%d", &num);
  while (num!=-1) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if(start == NULL) {
      new_node->next = new_node;
      start = new_node;
    }
    else {
      ptr = start;
      while (ptr->next!=start)
      ptr = ptr->next;
      ptr->next = new_node;
      new_node->next = start;
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
  ptr->next = new_node;
  new_node->next = start;
  start = new_node;
  return start;
}

// Add a node at the end
struct node *insert_end(struct node *start) {
  struct node *ptr, *new_node;
  int num;
  printf("\nEnter the data : ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->next!=start)
    ptr = ptr->next;
  ptr->next = new_node;
  new_node->next = start;
  return start;
}

// Delete a node from the beginning
struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next!=start)
    ptr = ptr->next;
  ptr->next = start->next;
  free(start);
  start = ptr->next;
  return start;
}

// Delete a node from the end
struct node *delete_end(struct node *start) {
  struct node *ptr, *preptr;
  ptr = start;
  while (ptr->next!=start) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = ptr->next;
  free(ptr);
  return start;
}

// Delete a node after a given node
struct node *delete_after(struct node *start) {
  struct node *ptr, *preptr;
  int val;
  printf("\nEnter the value after which the node has to be deleted : ");
  scanf("%d", &val);
  ptr = start;
  preptr = ptr;
  while (preptr->data!=val) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = ptr->next;
  if(ptr==start)
    start = preptr->next;
  free(ptr);
  return start;
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
