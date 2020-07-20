// A program to evaluate postfix expression

#include<stdio.h>
#include<ctype.h>
#define MAX 100

float st[MAX];
int top = -1;
void push(float st[], float val); // Push Operation
float pop(float st[]); // Pop Operation
float evaluatePostfixExp(char exp[]); // Evaluate Operation

int main() {
  float val;
  char exp[100];
  printf("\nEnter any postfix expression : ");
  gets(exp);
  val = evaluatePostfixExp(exp);
  printf("\nValue of the postfix expression : %.2f", val);
  return 0;
}

// evaluatePostfixExp
float evaluatePostfixExp(char exp[]) {
  int i = 0 ;
  float op1, op2, value;
  while (exp[i] != '\0') {
    if (isdigit(exp[i]))
      push(st, (float)(exp[i] - '0'));
    else {
      op2 = pop(st);
      op1 = pop(st);
      switch (exp[i]) {
        case '+' : value = op1+op2;
                   break;
        case '-' : value = op1-op2;
                   break;
        case '/' : value = op1/op2;
                   break;
        case '*' : value = op1*op2;
                   break;
        case '%' : value = (int)op1 % (int)op2;
                   break;
      }
      push(st, value);
    }
    i++;
  }
  return(pop(st));
}

// push
void push(float st[], float val) {
  if (top == MAX-1)
    printf("\nSTACK OVERFLOW\n");
  else
    st[++top] = val;
}

// pop
float pop(float st[]) {
  float val = -1;
  if(top == -1)
    printf("\nSTACK UNDERFLOW\n");
  else {
    val = st[top];
    top--;
  }
  return val;
}
