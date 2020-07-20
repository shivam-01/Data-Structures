// A program to Reverse a list using Stack

#include<stdio.h>

int stk[10];
int top = -1;
void push(int); // Push Operation
int pop(); // Pop Operation

int main() {
  int val, n, i;
  int arr[10];
  printf("\nEnter the number of elements in the array : ");
  scanf("%d", &n);
  printf("\nEnter the elements of the array : ");
  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);
  for (i=0; i<n; i++)
    push(arr[i]);
  for(i=0; i<n; i++) {
    val = pop();
    arr[i] = val;
  }
  printf("\nThe reversed array is : ");
  for (i=0; i<n; i++)
    printf("%d\n", arr[i]);
  return 0;
}

// push
void push(int val) {
  stk[++top] = val;
}

// pop
int pop() {
  return(stk[top--]);
}
