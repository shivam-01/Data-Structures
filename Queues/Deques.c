// A program to introduce DEQUE

#include<stdio.h>
#define MAX 10
int deque[MAX];
int left = -1, right = -1;
void input(); // Input Restricted Deque
void output(); // Output Restricted Deque
void insert_left(); // Insert Left Operation
void insert_right(); // Insert Right Operation
void delete_left(); // Delete Left Operation
void delete_right(); // Delete Right Operation
void display(); // Display the Queue

int main() {
  int option;
  printf("\n*** Main Menu ***\n");
  printf("1. Input restricted deque.\n");
  printf("2. Output restricted deque.\n");
  printf("\nEnter your option : ");
  scanf("%d", &option);
  switch (option) {
    case 1: input();
            break;

    case 2: output();
            break;
  }
  return 0;
}

// Input Restricted Deque
void input() {
  int option;
  do {
    printf("\nINPUT RESTRICTED DEQUE\n");
    printf("1. Insert at right\n");
    printf("2. Delete from left\n");
    printf("3. Delete from right\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    printf("\nEnter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1: insert_right();
              break;

      case 2: delete_left();
              break;

      case 3: delete_right();
              break;

      case 4: display();
              break;
    }
  }while(option!=5);
}

// Output Restricted Deque
void output() {
  int option;
  do {
    printf("\nOUTPUT RESTRICTED DEQUE\n");
    printf("1. Insert at right\n");
    printf("2. Insert at left\n");
    printf("3. Delete from left\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    printf("\nEnter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1: insert_right();
              break;

      case 2: insert_left();
              break;

      case 3: delete_left();
              break;

      case 4: display();
              break;
    }
  }while(option!=5);
}

// insert_right
void insert_right() {
  int val;
  printf("\nEnter the value to be added : ");
  scanf("%d", &val);
  if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
    printf("OVERFLOW.\n");
    return;
  }
  if (left == -1) {
    left = 0;
    right = 0;
  }
  else {
    if (right == MAX-1)
      right = 0;
    else
      right = right + 1;
  }
  deque[right] = val;
}

// insert_left
void insert_left() {
  int val;
  printf("\nEnter the value to be added : ");
  scanf("%d", &val);
  if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
    printf("OVERFLOW.\n");
    return;
  }
  if (left == -1) {
    left = 0;
    right = 0;
  }
  else {
    if (left == 0)
      left = MAX-1;
    else
      left = left + 1;
  }
  deque[left] = val;
}

// delete_left
void delete_left() {
  if (left == -1) {
    printf("UNDERFLOW.\n");
    return;
  }
  printf("The deleted element is : %d\n", deque[left]);
  if (left == right) {
    left = -1;
    right = -1;
  }
  else {
    if(left == MAX-1)
      left = 0;
    else
      left = left + 1;
  }
}

// delete_right
void delete_right() {
  if (left == -1) {
    printf("UNDERFLOW.\n");
    return;
  }
  printf("The deleted element is : %d\n", deque[right]);
  if (left == right) {
    left = -1;
    right = -1;
  }
  else {
    if(right == 0)
      right = MAX-1;
    else
      right = right - 1;
  }
}

// display
void  display() {
  int front = left, rear = right;
  if(front == -1) {
    printf("QUEUE IS EMPTY.\n");
    return;
  }
  printf("The elements of the queue are : \n");
  if(front <= rear) {
    while (front <= rear) {
      printf("%d\n", deque[front]);
      front++;
    }
  }
  else {
    while (front <= MAX - 1) {
      printf("%d\n", deque[front]);
      front++;
    }
    front = 0;
    while (front <= rear) {
      printf("%d\n", deque[front]);
      front++;
    }
  }
  printf("\n");
}
