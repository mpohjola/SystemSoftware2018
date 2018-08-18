/*
File:           OddEven.c
Author:         Mira Pohjola
Description:    Checks if integer is odd or even and prints the result
*/

#include <stdio.h>

void checkAndPrintOddOrEven(int);

int main() {
  checkAndPrintOddOrEven(9);
  checkAndPrintOddOrEven(200);
  checkAndPrintOddOrEven(-12);
  checkAndPrintOddOrEven(0);

  return 0;
}

void checkAndPrintOddOrEven(int number) {
  if (number == 0) {
    printf("Number %i is neither odd nor even\n", number);
  } else if (number % 2 == 0) {
    printf("Number %i is even\n", number);
  } else {
    printf("Number %i is odd\n", number);
  }
}
