// A program to introduce Multiple Stacks

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;
void pushA(int); // Push operation -> Stack A
int popA(); // Pop Operation -> Stack A
void pushB(int); // Push operation -> Stack B
int popB(); // Pop Operation -> Stack B
void displayA(); // Display the stack A
void displayB(); // Display the stack B

int main() {
  int option, val;
  do {
    printf("\n*** Main Menu ***\n");
    printf("1. PUSH IN STACK A.\n");
    printf("2. PUSH IN STACK B.\n");
    printf("3. POP FROM STACK A.\n");
    printf("4. POP FROM STACK B.\n");
    printf("5. DISPLAY STACK A.\n");
    printf("6. DISPLAY STACK B.\n");
    printf("7. EXIT.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option) {
      case 1 : printf("\nEnter the value to be pushed on Stack A : ");
               scanf("%d", &val);
               pushA(val);
               break;
      case 2 : printf("\nEnter the value to be pushed on Stack B : ");
               scanf("%d", &val);
               pushB(val);
               break;
      case 3 : val = popA();
               if(val != -999)
                printf("\nThe value popped from Stack A is : %d\n", val);
               break;
      case 4 : val = popB();
               if(val != -999)
                printf("\nThe value popped from Stack B is : %d\n", val);
               break;
      case 5 : displayA();
               break;
      case 6 : displayB();
               break;
  }
} while(option!=7);
return 0;
}

// Push into stack A
void pushA(int val) {
  if (topA == topB-1)
    printf("\nSTACK A OVERFLOW.");
  else {
    topA += 1;
    stack[topA] = val;
  }
}

// Pop from stack A
int popA() {
  int val;
  if (topA == -1) {
    printf("\nSTACK A UNDERFLOW.\n");
    val = -999;
  }
  else {
    val = stack[topA];
    topA--;
  }
return val;
}

// Display stack A
void displayA() {
  int i;
  if(topA == -1)
    printf("\nSTACK A IS EMPTY.\n");
  else {
    printf("\nThe contents of Stack A are : \n");
    for(i=topA; i>=0; i--)
      printf("%d\n", stack[i]);
  }
}

// Push into stack B
void pushB(int val) {
  if (topB-1 == topA)
    printf("\nSTACK B OVERFLOW.\n");
  else {
    topB -= 1;
    stack[topB] = val;
  }
}

// Pop from stack B
int popB() {
  int val;
  if (topB == MAX) {
    printf("\nSTACK B UNDERFLOW.\n");
    val = -999;
  }
  else {
    val = stack[topB];
    topB++;
  }
return val;
}

// Display stack B
void displayB() {
  int i;
  if(topB == MAX)
    printf("\nSTACK B IS EMPTY.\n");
  else {
    printf("\nThe contents of Stack B are : \n");
    for(i=topB; i<MAX; i++)
      printf("%d\n", stack[i]);
  }
}
