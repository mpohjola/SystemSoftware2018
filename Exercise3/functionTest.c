#include <stdio.h>

void divideByTwo1(int number) {
  number = number >> 1;
  printf("Line 12, number is: %d\n", number);
}

void divideByTwo2(int *number) {
  *number = *number >> 1;
  printf("Line 18, number is: %d\n", *number);
}

int main() {
  int testNumber = 2048;

  divideByTwo1(testNumber);
  printf("Line 26, number is: %d\n", testNumber);
  divideByTwo2(&testNumber);
  printf("Line 29, number is: %d\n", testNumber);
  return 0;
}
