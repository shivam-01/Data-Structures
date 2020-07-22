// A program to introduce Linear Queue

#include<stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert(); // Insert Operation
int delete(); // Delete Operation
int peek(); // Peek Operation
void display(); // Display the Queue

int main() {
  int option, val;
  do {
    printf("\n*** Main Menu ***\n");
    printf("1. Insert an element.\n");
    printf("2. Delete an element.\n");
    printf("3. Peek.\n");
    printf("4. Display the queue.\n");
    printf("5. EXIT.\n");
    printf("\nEnter your option : ");
    scanf("%d", &option );
    switch(option) {
      case 1 : insert();
               break;
      case 2 : val = delete();
               if(val!= -1)
                printf("The value deleted from queue is : %d\n", val);
               break;
      case 3 : val = peek();
               if(val != -1)
                printf("The fisrt value in the queue is : %d\n", val);
               break;
      case 4 : display();
               break;
  }
} while (option!=5);
return 0;
}

// insert
void insert() {
  int num;
  printf("\nEnter the number to be inserted in queue : ");
  scanf("%d", &num);
  if(rear == MAX-1)
  printf("\nOVERFLOW.");
  else if(front == -1 && rear == -1)
  front = rear = 0;
  else
  rear++;
  queue[rear] = num;
}

// delete
int delete() {
  int val;
  if(front == -1 || front > rear) {
    printf("\nUNDERFLOW.");
    return -1;
  }
  else {
    val = queue[front];
    front++;
    if(front > rear)
      front = rear = -1;
    return val;
  }
}

// peek
int peek() {
  if(front == -1 || front > rear) {
    printf("\nQUEUE IS EMPTY.");
    return -1;
  }
  else {
    return queue[front];
  }
}

// display
void display() {
  int i;
  printf("\n");
  if(front == -1 || front > rear)
    printf("\nQUEUE IS EMPTY.");
  else {
    for(i = front; i <= rear; i++)
      printf("%d\n", queue[i]);
  }
}
