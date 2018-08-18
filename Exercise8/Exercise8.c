/*
File:           Exercise8.c
Author:         Mira Pohjola
Description:    Program for finding prime factors for an array of numbers. The array length is taken as command line
                argument and the array is populated with random numbers. Attempting to give command line arguments other
                than a single integer result in error message.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "PrimeFactors.h"

#define MAX_RANDOM_NUMBER 999999

void printErrorMessage();

void generateRandomNumbersToArray(long *numbersArray, int arrayLength);

int getRandomNumber();

int main(int argc, char *argv[]) {
    long *numbersArray = NULL;
    int arrayLength = 0;

    int hasErrors = 0;

    srand(time(0)); //using time to seed the randomizer

    if (argc < 3 && argc > 1) {
        int j = 0;
        while (hasErrors == 0 && argv[1][j] != '\0') {
            if (isalpha(argv[1][j])) {
                hasErrors = 1;
            }
            j++;
        }
        if (hasErrors == 0) {
            arrayLength = atoi(argv[1]);
            if (arrayLength < 1 ) {
                hasErrors = 1;
            }
        }
    } else {
        hasErrors = 1;
    }
    if (hasErrors == 1) {
        printErrorMessage();
    } else {
        numbersArray = (long *) malloc(arrayLength * sizeof(long));
        if (numbersArray == NULL) {
            printf("\nAllocating memory for the numbersArray was not successful!");
        } else {
            //Generate random numbers to the array and start prime factorizing them
            generateRandomNumbersToArray(numbersArray, arrayLength);
            findPrimeFactors(numbersArray,arrayLength);
            printf("\n");

        }
    }
    free(numbersArray);
    return 0;
}

void printErrorMessage() {
    printf("\nYou should input one (1) positive integer number.\nOther characters / multiple numbers are not allowed!\n");
}

void generateRandomNumbersToArray(long *numbersArray, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        *(numbersArray + i) = getRandomNumber();
    }
}

int getRandomNumber() {
    int number = (rand() % (MAX_RANDOM_NUMBER - 1 + 1)) + 1;
    return number;
}