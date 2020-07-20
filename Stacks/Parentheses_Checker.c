// A program to check nesting of parentheses using Stack data structure

#include<stdio.h>
#include<string.h>
#define MAX 10

int top = -1;
int stk[MAX];
void push(char); // Push Operation
char pop(); // Pop Operation

int main() {
  char exp[MAX], temp;
  int i, flag = 1;
  printf("\nEnter an expression : ");
  gets(exp);
  for (i = 0; i < strlen(exp); i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
      push(exp[i]);
    if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
      if (top == -1)
        flag = 0;
      else {
        temp = pop();
        if (exp[i] == ')' && (temp == '{' || temp == '['))
          flag = 0;
        if (exp[i] == '}' && (temp == '(' || temp == '['))
          flag = 0;
        if (exp[i] == ']' && (temp == '(' || temp == '{'))
          flag = 0;
      }
  }
  if (top>=0)
    flag = 0;
  if (flag == 1)
    printf("VALID EXPRESSION.\n");
  else
    printf("INVALID EXPRESSION.\n");
  return 0;
}

// push
void push(char c) {
    stk[++top] = c;
}

// pop
char pop() {
    return(stk[top--]);
}
