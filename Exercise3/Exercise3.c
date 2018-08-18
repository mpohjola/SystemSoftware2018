/*
File:           Ecercise3.c
Author:         Mira Pohjola
Description:    Generating a random number and then testing if the random number is
                a Hexanacci number or a prime number
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber();
void checkIfHexanacciNumber(int);
void checkIfPrimeNumber(int);

int main() {
  srand(time(0)); //Using current time to seed the random generator
  int randomNumber = generateRandomNumber();
  printf("Random number: %d\n", randomNumber);
  checkIfHexanacciNumber(randomNumber);
  checkIfPrimeNumber(randomNumber);
  return 0;
}

int generateRandomNumber()  {
  int randomNumber = rand() % (150000 - 0 + 1);
  return randomNumber;
}

void checkIfHexanacciNumber(int number) {
  int currentHexanumber = 0;
  int hexanumbers[7] = {0,0,0,0,0,1,0};
  int isHexanumber = 0;

  while (currentHexanumber <= number && isHexanumber == 0) {
    //we want to have the if check here to make sure we correctly flag 0 as hexanacci number
    if (number == currentHexanumber) {
      isHexanumber = 1;
    };
    currentHexanumber = hexanumbers[0]+ hexanumbers[1]+hexanumbers[2]+hexanumbers[3]+hexanumbers[4]+hexanumbers[5];
    hexanumbers[6] = currentHexanumber;
    //shifting the array to left in order to fit the newest hexanacci number in it
    for (int i = 0; i <= 6; i++) {
      hexanumbers[i] = hexanumbers[i+1];
    };
  };

  if (isHexanumber == 1) {
    printf("Number %d is a Hexanacci number\n", number);
  } else {
    printf("Number %d is not a Hexanacci number\n", number);
  }
}

void checkIfPrimeNumber(int number) {
  int isPrime = 1;
  if (number <= 1) {
    isPrime = 0;
  } else if (number % 2 == 0 && number > 2) {
    isPrime = 0;
  } else {
    for (int i = 3; i < number / 2; i+= 2){
      if (number % i == 0 ){
        isPrime = 0;
      }
    }
  }
  if (isPrime == 1) {
    printf("Number %d is prime\n", number);
  } else {
    printf("Number %d is not prime\n", number);
  }
}
