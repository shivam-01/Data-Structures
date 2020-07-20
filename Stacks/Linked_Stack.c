// A program to introduce Linked STACK

#include<stdio.h>
#include<stdlib.h>

// Declaration of linked stack
struct stack {
  int data;
  struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int); // Push Operation
struct stack *display(struct stack *); // Display Operation
struct stack *pop(struct stack *); // Pop Operation
int peek(struct stack *); // Peek Opeartion

int main() {
  int val, option;
  do {
    printf("\n*** Main Menu ***\n");
    printf("1. PUSH.\n");
    printf("2. POP.\n");
    printf("3. PEEK.\n");
    printf("4. DISPLAY.\n");
    printf("5. EXIT.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option) {
      case 1 : printf("\nEnter the value to be pushed on Stack : ");
               scanf("%d", &val);
               top = push(top, val);
               break;
      case 2 : top = pop(top);
               break;
      case 3 : val = peek(top);
               if(val != -1)
               printf("\nThe value stored at top of stack is : %d\n", val);
               else
               printf("\nSTACK IS EMPTY.\n");
               break;
      case 4 : top = display(top);
               break;
  }
} while (option!=5);
return 0;
}

// Push node in the linked stack
struct stack *push(struct stack *top, int val) {
  struct stack *ptr;
  ptr = (struct stack *)malloc(sizeof(struct stack));
  ptr->data = val;
  if (top ==  NULL) {
    ptr->next = NULL;
    top = ptr;
  }
  else {
    ptr->next = top;
    top = ptr;
  }
  return top;
}

// Display the linked stack
struct stack *display(struct stack *top) {
  struct stack *ptr;
  ptr = top;
  if (top == NULL)
    printf("\nSTACK IS EMPTY.\n");
  else {
    while (ptr!=NULL) {
      printf("%d\n", ptr->data);
      ptr = ptr->next;
    }
  }
  return top;
}

// Pop node from the linked stack
struct stack *pop(struct stack *top) {
  struct stack *ptr;
  ptr = top;
  if (top == NULL)
    printf("\nSTACK UNDERFLOW.\n");
  else {
    top = top->next;
    printf("\nThe value being deleted is : %d\n", ptr->data);
    free(ptr);
  }
  return top;
}

// Peek topmost node in the linked stack
int peek(struct stack *top) {
  if (top == NULL)
  return -1;
  else
  return top->data;
}
