/*
File:           Collatz.c
Author:         Mira Pohjola
Description:    Calculates Collatz sequences for all the numbers within the given number range. Start and end number are included.
                Calls for storing the values into an array.
*/

#include "Array.h"
#include "Collatz.h"


void calculateCollatzSequence(int startNumber, int endNumber){
    for (int i = startNumber; i <= endNumber; i++) {
        int originalNumber = i;
        int currentNumber = i;
        int sequenceLength = 1;
        while (currentNumber != 1) {
            if (currentNumber % 2 == 0){
                currentNumber = currentNumber/2;
            } else {
                currentNumber = currentNumber*3+1;
            };
            sequenceLength++;
        }
        storeIntoSequencesArray(originalNumber, sequenceLength);
    }

}