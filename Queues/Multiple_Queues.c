// A program to introduce Multiple Queues

#include<stdio.h>
#define MAX 10
int QUEUE[MAX], rearA = -1, frontA = -1, rearB = MAX, frontB = MAX;
void insertA(int); // Insert in Queue A
void insertB(int); // Insert in Queue B
int deleteA(); // Delete from Queue A
int deleteB(); // Delete from Queue B
void displayA(); // Display Queue A
void displayB(); // Display Queue B

int main() {
  int option, val;
  do {
    printf("\n*** Main Menu ***\n");
    printf("1. INSERT IN QUEUE A.\n");
    printf("2. INSERT IN QUEUE B.\n");
    printf("3. DELETE FROM QUEUE A.\n");
    printf("4. DELETE FROM QUEUE B.\n");
    printf("5. DISPLAY QUEUE A.\n");
    printf("6. DISPLAY QUEUE B.\n");
    printf("7. EXIT.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option) {
      case 1 : printf("\nEnter the value to be inserted in Queue A : ");
               scanf("%d", &val);
               insertA(val);
               break;
      case 2 : printf("\nEnter the value to be inserted in Queue B : ");
               scanf("%d", &val);
               insertB(val);
               break;
      case 3 : val = deleteA();
               if(val != -1)
                printf("The value deleted from Queue A is : %d\n", val);
               break;
      case 4 : val = deleteB();
               if(val != -1)
                printf("The value deleted from Queue B is : %d\n", val);
               break;
      case 5 : printf("The contents of Queue A are : \n");
               displayA();
               break;
      case 6 : printf("The contents of Queue B are : \n");
               displayB();
               break;
  }
} while(option!=7);
return 0;
}

// insertA
void insertA(int val) {
  if(rearA == rearB-1)
    printf("\nOVERFLOW.\n");
  else {
    if(rearA == -1 && frontA == -1) {
      rearA = frontA = 0;
      QUEUE[rearA] = val;
    }
    else
      QUEUE[++rearA] = val;
  }
}

// deleteA
int deleteA() {
  int val;
  if(frontA == -1) {
    printf("\nUNDERFLOW.\n");
    return -1;
  }
  else {
    val = QUEUE[frontA];
    frontA++;
    if(frontA > rearA)
      frontA = rearA = -1;
    return val;
  }
}

// displayA
void displayA() {
  int i;
  if(frontA == -1)
    printf("\nQUEUE A IS EMPTY.\n");
  else {
    for(i=frontA; i<=rearA; i++)
      printf("%d\n", QUEUE[i]);
  }
}

// insertB
void insertB(int val) {
  if(rearA == rearB-1)
    printf("\nOVERFLOW.\n");
  else {
    if(rearB == MAX && frontB == MAX) {
      rearB = frontB = MAX-1;
      QUEUE[rearB] = val;
    }
    else
      QUEUE[--rearB] = val;
  }
}

// deleteB
int deleteB() {
  int val;
  if(frontB == MAX) {
    printf("\nUNDERFLOW.\n");
    return -1;
  }
  else {
    val = QUEUE[frontB];
    frontB--;
    if(frontB < rearB)
      frontB = rearB = MAX;
    return val;
  }
}

// displayB
void displayB() {
  int i;
  if(frontB == MAX)
    printf("\nQUEUE B IS EMPTY.\n");
  else {
    for(i=frontB; i>=rearB; i--)
      printf("%d\n", QUEUE[i]);
  }
}
