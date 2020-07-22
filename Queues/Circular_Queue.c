// A program to introduce Circular Queue

#include<stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert(); // Insert Operation
int delete(); // Delete Operation
int peek(); // Peek Operation
void display(); // Display the queue

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
  printf("\nEnter the number to be inserted in the queue : ");
  scanf("%d", &num);
  if(front == 0 && rear == MAX-1)
    printf("OVERFLOW.\n");
  else if(front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = num;
  }
  else if(rear == MAX-1 && rear != 0) {
    rear = 0;
    queue[rear] = num;
  }
  else {
    rear++;
    queue[rear] = num;
  }
}

// delete
int delete() {
  int val;
  if (front == -1 && rear == -1) {
    printf("UNDERFLOW.\n");
    return -1;
  }
  val = queue[front];
  if(front == rear)
    front = rear = -1;
  else {
    if(front == MAX-1)
      front = 0;
    else
      front++;
  }
  return val;
}

// peek
int peek() {
  if(front == -1 && rear == -1) {
    printf("QUEUE IS EMPTY.\n");
    return -1;
  }
  else
    return queue[front];
}

// display
void display()
{
   if(front == -1 && rear == -1)
      printf("Circular Queue is Empty!\n");
   else{
      int i = front;
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\n",queue[i++]);
      }
      else{
	 while(i <= MAX - 1)
	    printf("%d\n", queue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\n",queue[i++]);
      }
   }
}
