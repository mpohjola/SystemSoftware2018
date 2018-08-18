/*
File:           Ecercise4.c
Author:         Mira Pohjola
Description:    'Main' class of the program which calculates collatz sequence lengths for given range and then prints
                the number with the longest sequence as well as the sequence length.
*/

#include "Array.h"
#include "Collatz.h"

int main() {
    int startNumber = 2;
    int endNumber = 10000;

    calculateCollatzSequence(startNumber, endNumber);

    printTheLongestSequence();

    return 0;
}


