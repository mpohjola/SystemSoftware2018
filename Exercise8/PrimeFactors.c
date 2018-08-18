/*
File:           PrimeFactors.c
Author:         Mira Pohjola
Description:    Contains functions for finding largest prime factors for an array of long-type numbers. Prints the
                largest prime factor for each number.
*/

#include <stdio.h>
#include <math.h>
#include "PrimeFactors.h"

void findPrimeFactors(long *numbers, long numbersAmount) {
    for (int i = 0; i < numbersAmount; i++){
        long currentNumber = *(numbers+i);
        getLargestPrimeFactor(currentNumber);
    }
}

void getLargestPrimeFactor(long number) {
    long maxFactor = -1;
    long original = number;
    while (number % 2 == 0){
        maxFactor = 2;
        number >>=1;
    }
    for (int i = 3; i <= sqrt(number); i+=2) {
        while(number % i == 0){
            maxFactor = i;
            number /= i;
        }
    }

    if (number > 2) {
        maxFactor = number;
    }
    printf("\nLargest prime factor of %ld is %ld", original, maxFactor);
}

