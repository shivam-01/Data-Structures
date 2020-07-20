// A program to convert an infix expression into its equivalent prefix notaton

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char st[MAX];
int top = -1;
char infix[100], postfix[100], temp[100];
void push(char st[], char); // Push Operation
char pop(char st[]); // Pop Operation
void InfixtoPostfix(char source[], char target[]); // InfixtoPostfix Operation
int getPriority(char); // getPriority Operation
void reverse(char str[]); // Reverse Operation

int main() {
  printf("\nEnter any infix expression : ");
  gets(infix);
  reverse(infix);
  strcpy(postfix, "");
  InfixtoPostfix(temp, postfix);
  strcpy(temp, "");
  reverse(postfix);
  printf("\nThe corresponding prefix expression is : ");
  puts(temp);
  return 0;
}

// reverse
void reverse(char str[]) {
  int len, i=0, j=0;
  len = strlen(str);
  j = len-1;
  while (j>=0) {
    if (str[j] == '(')
      temp[i] = ')';
    else if (str[j] == ')')
      temp[i] = '(';
    else
      temp[i] = str[j];
      i++;
      j--;
  }
  temp[i] = '\0';
}

// InfixtoPostfix
void InfixtoPostfix(char source[], char target[]) {
  int i=0, j=0;
  char temp;
  strcpy(target, "");
  while (source[i]!='\0') {
    if (source[i] == '(') {
      push(st, source[i]);
      i++;
    }
    else if (source[i] == ')') {
      while ((top!=-1) && (st[top]!='(')) {
        target[j] = pop(st);
        j++;
      }
      if(top == -1) {
        printf("\nINCORRECT EXPRESSION.\n");
        exit(1);
      }
      temp = pop(st);
      i++;
    }
    else if(isdigit(source[i]) || isalpha(source[i])) {
      target[j] = source[i];
      j++;
      i++;
    }
    else if(source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') {
      while ((top!=-1) && (st[top]!='(') && (getPriority(st[top]) >= getPriority(source[i]))) {
        target[j] = pop(st);
        j++;
      }
      push(st, source[i]);
      i++;
    }
    else {
      printf("\nINCORRECT ELEMENT IN EXPRESSION.\n");
      exit(1);
    }
  }
  while ((top!=-1) && (st[top]!='(')) {
    target[j] = pop(st);
    j++;
  }
  target[j] = '\0';
}

// getPriority
int getPriority(char op) {
  if(op == '/' || op == '*' || op == '%')
    return 1;
  else if(op == '+' || op == '-')
    return 0;
}

// push
void push(char st[], char val) {
  if(top == MAX-1)
    printf("\nSTACK OVERFLOW.\n");
  else {
    st[++top] = val;
  }
}

// pop
char pop(char st[]) {
  char val = ' ';
  if(top == -1)
    printf("\nSTACK UNDERFLOW.\n");
  else {
    val = st[top];
    top--;
  }
  return val;
}
