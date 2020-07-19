// A program to introduce Linked List and its operations

#include <stdio.h>
#include <stdlib.h>

// Declaration of linked list
struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;

// Operations on linked list
struct node *create(struct node *); // Create a list
struct node *display(struct node *); // Display the list
struct node *insert_beg(struct node *); // Add a node at the beginning
struct node *insert_end(struct node *); // Add a  node at the end
struct node *insert_before(struct node *); // Add a node before a given node
struct node *insert_after(struct node *); // Add a node after a given node
struct node *delete_beg(struct node *); // Delete a node from the beginning
struct node *delete_end(struct node *); // Delete a node from the end
struct node *delete_node(struct node *); // Delete a given node
struct node *delete_after(struct node *); // Delete a node after a given node
struct node *delete_list(struct node *); // Delete the entire list
struct node *sort_list(struct node *); // Sort the list

int main() {
  int option;
  do{
    printf("*** Main Menu ***\n");
    printf("1. Create a list.\n");
    printf("2. Display the list.\n");
    printf("3. Add a node at the beginning.\n");
    printf("4. Add a node at the end.\n");
    printf("5. Add a node before a given node.\n");
    printf("6. Add a node after a given node.\n");
    printf("7. Delete a node from the beginning.\n");
    printf("8. Delete a node from the end.\n");
    printf("9. Delete a given a node.\n");
    printf("10. Delete a given node after a given node.\n");
    printf("11. Delete the entire list.\n");
    printf("12. Sort the list.\n");
    printf("13. Exit.\n");
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
      case 5 : start = insert_before(start);
      break;
      case 6 : start = insert_after(start);
      break;
      case 7 : start = delete_beg(start);
      break;
      case 8 : start = delete_end(start);
      break;
      case 9 : start = delete_node(start);
      break;
      case 10 : start = delete_after(start);
      break;
      case 11 : start = delete_list(start);
      printf("\n Linked List Deleted.\n");
      break;
      case 12 : start = sort_list(start);
      break;
    }
  } while (option != 13);
  return 0;
}

// Create a node.
struct node *create(struct node *start) {
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to end.");
  printf("\nEnter the data : ");
  scanf("%d", &num);
	while(num!=-1){
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> data = num;
		if(start == NULL) {
			new_node->next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr->next!=NULL)
				ptr = ptr->next;
				ptr->next = new_node;
				new_node->next = NULL;
		}
		printf("\nEnter the data : ");
		scanf("%d",&num);
	}
	return start;
}

// Display the list
struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr!=NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
  return start;
}

// Add a node at the beginning
struct node *insert_beg(struct node *start) {
  struct node *new_node;
  int num;
  printf("\nEnter the data : ");
  scanf("%d", &num);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
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
  new_node->next = NULL;
  ptr = start;
  while (ptr->next!=NULL)
  ptr = ptr->next;
  ptr->next = new_node;
  return start;
}

// Add a node before a given node
struct node *insert_before(struct node *start) {
  struct node *new_node, *ptr, *preptr;
  int num,val;
  printf("\nEnter the data : ");
  scanf("%d", &num);
  printf("\nEnter the value before which the data has to be inserted : ");
  scanf("%d", &val);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  while (ptr->data!=val) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = new_node;
  new_node->next = ptr;
  return start;
}

// Add a node after a given node
struct node *insert_after(struct node *start) {
  struct node *new_node,*ptr,*preptr;
  int num,val;
  printf("\nEnter the data : ");
  scanf("%d", &num);
  printf("\nEnter the value after which the data has to be inserted : ");
  scanf("%d", &val);
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  ptr = start;
  preptr = ptr;
  while(preptr->data!=val){
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = new_node;
  new_node->next = ptr;
  return start;
}

// Delete a node from the beginning
struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;
  start = start->next;
  free(ptr);
  return start;
}

// Delete a node from the end
struct node *delete_end(struct node *start) {
  struct node *ptr,*preptr;
  ptr = start;
  while (ptr->next!=NULL) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = NULL;
  free(ptr);
  return start;
}

// Delete a given node
struct node *delete_node(struct node *start) {
  struct node *ptr,*preptr;
  int val;
  printf("\nEnter the value of the node which has to be decided : ");
  scanf("%d", &val);
  ptr = start;
  if(ptr->data==val){
    start = delete_beg(start);
    return start;
  }
  else{
    while (ptr->data!=val) {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
  }
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
  free(ptr);
  return start;
}

// Delete the entire list
struct node *delete_list(struct node *start){
  struct node *ptr;
  if(start!=NULL){
    ptr = start;
    while (ptr!=NULL) {
      printf("%d is to be deleted next.\n", ptr->data);
      start = delete_beg(ptr);
      ptr = start;
    }
  }
  return start;
}

// Sort the list
struct node *sort_list(struct node *start) {
  struct node *ptr1, *ptr2;
  int temp;
  ptr1 = start;
  while (ptr1->next != NULL) {
    ptr2 = ptr1->next;
    while (ptr2!=NULL) {
      if(ptr1->data > ptr2->data) {
        temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
      }
      ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
  return start;
}
