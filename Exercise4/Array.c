/*
File:           Array.c
Author:         Mira Pohjola
Description:    Initializes an array to store collatz sequence lengths for numbers between 2-10000 and stores the numbers and
                sequence lengths into the array and provides a method to print the number with the longest sequence.
*/

#include "Array.h"
#include <stdio.h>


int sequencesAmount = 9998;

/*I don't much like the hard-coded array dimensions here since it makes the code less modular
 * but trying to make this more dynamic will have to wait for later date
 * */
int sequencesArray[9998][2];
int lastInsertedNumberIndex = -1;

void storeIntoSequencesArray(int currNumber, int sequenceLength) {
    sequencesArray[lastInsertedNumberIndex + 1][0] = currNumber;
    sequencesArray[lastInsertedNumberIndex + 1][1] = sequenceLength;
    lastInsertedNumberIndex++;
}

void printTheLongestSequence() {
    int longestSequenceNumber = 0;
    int longestSequenceLength = 0;
    for (int i = 0; i < sequencesAmount; i++) {
        if (sequencesArray[i][1] > longestSequenceLength) {
            longestSequenceLength = sequencesArray[i][1];
            longestSequenceNumber = sequencesArray[i][0];
        }
    }
    printf("Number: %d Length: %d \n", longestSequenceNumber, longestSequenceLength);

}