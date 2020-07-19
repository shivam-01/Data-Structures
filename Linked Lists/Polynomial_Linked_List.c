// A program to store two polynomials and perform basic arithmetic operations on them

#include<stdio.h>
#include<stdlib.h>

// Declaration of Linked list
struct node{
  int coeff;
  int pow;
  struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *add_result = NULL;
struct node *sub_result = NULL;

// Operations on linked list
struct node *create(struct node *); // Create a list
struct node *display(struct node *); // Display the list
struct node *add(struct node *, struct node *, struct node *); // Addition
struct node *sub(struct node *, struct node *, struct node *); // Subtraction
struct node *add_node(struct node *, int, int); // Add a node

int main() {
  int option;
  do{
    printf("\n*** Main Menu ***\n");
    printf("1. Enter the first polynomial.\n");
    printf("2. Display the first polynomial.\n");
    printf("3. Enter the second polynomial.\n");
    printf("4. Display the second polynomial.\n");
    printf("5. Add the polynomials.\n");
    printf("6. Display the Addition result.\n");
    printf("7. Subtract the polynomials.\n");
    printf("8. Display the Subtraction result.\n");
    printf("9. Exit.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option){
      case 1 : start1 = create(start1);
      break;
      case 2 : start1 = display(start1);
      break;
      case 3 : start2 = create(start2);
      break;
      case 4 : start2 = display(start2);
      break;
      case 5 : add_result = add(start1, start2, add_result);
      break;
      case 6: add_result = display(add_result);
      break;
      case 7 : sub_result = sub(start1, start2, sub_result);
      break;
      case 8: sub_result = display(sub_result);
      break;
    }
  } while (option != 9);
  return 0;
}

// Create a linked list
struct node *create(struct node *start) {
  struct node *new_node, *ptr;
  int c, p;
  printf("Enter -1 to end.");
  printf("\nEnter the coefficient : ");
  scanf("%d", &c);
  printf("\nEnter its power : ");
  scanf("%d", &p);
  while (c!=-1) {
    if(start==NULL){
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->coeff = c;
      new_node->pow = p;
      new_node->next = NULL;
      start = new_node;
    }
    else {
      ptr = start;
      while (ptr->next!=NULL)
        ptr = ptr->next;
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->coeff = c;
      new_node->pow = p;
      new_node->next = NULL;
      ptr->next = new_node;
    }
    printf("\nEnter the coefficient : ");
    scanf("%d", &c);
    if(c==-1)
      break;
    printf("\nEnter its power : ");
    scanf("%d", &p);
  }
  return start;
}

// Display the linked list
struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  printf("\nThe polynomial expression is:\n");
  while (ptr!=NULL) {
    printf("(%dx^%d)", ptr->coeff,  ptr->pow);
    ptr = ptr->next;
    if(ptr != NULL)
            printf(" + ");
  }
  return start;
}

// Add the polynomials
struct node *add(struct node *start1, struct node *start2, struct node *result) {
  struct node *ptr1, *ptr2;
  int sum_num, p;
  ptr1 = start1;
  ptr2 = start2;
  while (ptr1 && ptr2) {
    if (ptr1->pow > ptr2->pow) {
      result = add_node(result,ptr1->coeff,ptr1->pow);
      ptr1 = ptr1->next;
    }

    else if (ptr1->pow < ptr2->pow) {
      result = add_node(result,ptr2->coeff,ptr2->pow);
      ptr2 = ptr2->next;
    }

    else {
      sum_num = ptr1->coeff + ptr2->coeff;
      result = add_node(result,sum_num,ptr1->pow);
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }

  while (ptr1 || ptr2) {
    if (ptr1) {
      result = add_node(result,ptr1->coeff,ptr1->pow);
      ptr1 = ptr1->next;
    }

    if (ptr2) {
      result = add_node(result,ptr2->coeff,ptr2->pow);
      ptr2 = ptr2->next;
    }
  }
printf("\nAddition Completed...\n");
return result;
}

// Subtract the polynomials
struct node *sub(struct node *start1, struct node *start2, struct node *result) {
  struct node *ptr1, *ptr2;
  int sub_num, p;
  ptr1 = start1;
  ptr2 = start2;
  while (ptr1 && ptr2) {
    if (ptr1->pow > ptr2->pow) {
      result = add_node(result,ptr1->coeff,ptr1->pow);
      ptr1 = ptr1->next;
    }

    else if (ptr1->pow < ptr2->pow) {
      result = add_node(result,ptr2->coeff,ptr2->pow);
      ptr2 = ptr2->next;
    }

    else {
      sub_num = ptr2->coeff - ptr1->coeff;
      result = add_node(result,sub_num,ptr1->pow);
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }

  while (ptr1 || ptr2) {
    if (ptr1) {
      result = add_node(result,ptr1->coeff,ptr1->pow);
      ptr1 = ptr1->next;
    }

    if (ptr2) {
      result = add_node(result,ptr1->coeff,ptr1->pow);
      ptr1 = ptr1->next;
    }
  }
printf("\nSubtraction Completed...\n");
return result;
}

// Add a node
struct node *add_node(struct node *start, int c, int p) {
  struct node *ptr, *new_node;
  if (start == NULL) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coeff = c;
    new_node->pow = p;
    new_node->next = NULL;
    start = new_node;
  }

  else {
    ptr = start;
    while (ptr->next != NULL)
      ptr = ptr->next;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coeff = c;
    new_node->pow = p;
    new_node->next = NULL;
    ptr->next = new_node;
  }
return start;
}
