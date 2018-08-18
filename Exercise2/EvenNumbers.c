/*
File:           EvenNumbers.c
Author:         Mira Pohjola
Description:    Prints out even numbers between 30 and 0
*/

#include <stdio.h>

int main() {
  int number;
  for (number = 30; number >= 0; number = number - 2) {
    printf("%i\n", number);
  }
  return 0;
}
