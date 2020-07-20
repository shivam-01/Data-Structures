// A program to introduce Stack and its operations

#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int st[MAX], top = -1;
void push(int st[], int val); // Push operation
int pop(int st[]); // Pop Operation
int peek(int st[]); // Peek Operation
void display(int st[]); // Display the stack

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
               push(st, val);
               break;
      case 2 : val = pop(st);
               if(val!= -1)
               printf("\nThe value deleted from stack is : %d\n", val);
               break;
      case 3 : val = peek(st);
               if(val != -1)
               printf("\nThe value stored at top of stack is : %d\n", val);
               break;
      case 4 : display(st);
               break;
  }
} while (option!=5);
return 0;
}

// push
void push(int st[], int val) {
  if(top == MAX-1)
    printf("\nSTACK OVERFLOW\n");
  else {
    top++;
    st[top] = val;
  }
}

// pop
int pop(int st[]) {
  int val;
  if(top == -1) {
    printf("\nSTACK UNDERFLOW\n");
    return -1;
  }
  else {
    val = st[top];
    top--;
    return val;
  }
}

// Display the stack
void display(int st[]) {
  int i;
  if(top == -1)
    printf("\nSTACK IS EMPTY.\n");
  else {
    for (i = top; i >= 0; i--)
      printf("\n%d", st[i]);
      printf("\n");
  }
}

// peek
int peek(int st[]) {
  if (top == -1) {
    printf("\nSTACK IS EMPTY.\n");
    return -1;
  }
  else
  return (st[top]);
}
