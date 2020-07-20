// A program to introduce Tower of Hanoi puzzle

#include<stdio.h>

int count = 0;
int move(int, char, char, char);

int main() {
  int n;
  printf("\nEnter the number of rings : ");
  scanf("%d", &n);
  move(n,'A','C','B');
  printf("\nTotal number of moves : %d", count);
  return 0;
}

int move(int n,char source,char dest,char spare) {
  if(n == 1) {
    printf("\nMove from %c to %c", source, dest);
    count++;
  }
  else {
    move(n-1,source,spare,dest);
    move(1,source,dest,spare);
    move(n-1,spare,dest,source);
  }
  return count;
}
