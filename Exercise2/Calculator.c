/*
File:           Calculator.c
Author:         Mira Pohjola
Description:    Performs basic calculations on two integers and prints the result
*/

#include <stdio.h>
#include <stdlib.h>

void performCalculations(int, int);

int main() {
  int number1 = 2;
  int number2 = 8;
  performCalculations(number1, number2);
  return 0;
}

void performCalculations(int integer1, int integer2) {
  //both given integers
  printf("Integer 1: \t%i\n", integer1);
  printf("Integer 2: \t%i\n", integer2);
  //sum
  printf("Sum: \t\t%i\n", integer1+integer2);
  //difference
  printf("Difference: \t%i\n", integer1-integer2);
  //product
  printf("Product: \t%i\n", integer1*integer2);
  //division
  printf("Division: \t%i\n", integer1/integer2);
}
