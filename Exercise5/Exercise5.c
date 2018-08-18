/*
File:           Ecercise5.c
Author:         Mira Pohjola
Description:    Reads large numbers from Numbers.txt file into a 2D array and then sums the numbers by columns. The
                result is printed on the console.
*/

#include <stdio.h>


int main(){

    int lines = 5;
    int numberLength = 5;
    int numbersArray[lines][numberLength];
    char readBuffer[100] = ""; //reserving enough space for the readbuffer

    FILE *filePointer = NULL;

    filePointer = fopen("Numbers2.txt", "r");

    int currentLineNumber = 0;

    while (fgets(readBuffer, sizeof(readBuffer),filePointer)){
        for (int i = 0; i < numberLength; i++) {
            int currentNumber = readBuffer[i]-'0';
            numbersArray[currentLineNumber][i] = currentNumber;
        }
        currentLineNumber++;
    }
    fclose(filePointer);

    int offset = 0; //initializing the offset value used in summing the columns
    int answerLength = 200; //As we have no real way of knowing the length of the answer we need to reserve enough space
    char sumOfNumbers[answerLength];
    int currentSumIndex = 0;

    for (int i = numberLength-1; i > -1; i--) {
        int currentSumOfColumn = offset;
        for (int j = 0; j < lines; j++){
            currentSumOfColumn = currentSumOfColumn + numbersArray[j][i];
        }
        int columnSum = currentSumOfColumn % 10;

        offset = (currentSumOfColumn - columnSum)/10;

        sumOfNumbers[currentSumIndex] = columnSum;
        currentSumIndex++;
    }
    //next we need to make sure we take in the rest of the offset
    while(offset) {
        int currentNumber = offset%10;
        sumOfNumbers[currentSumIndex] = currentNumber;
        offset /=10;
        currentSumIndex++;
    }

    printf("\nSum:");
    for (int i = currentSumIndex-1; i >= 0; i--) {
        printf("%d", sumOfNumbers[i]);
    }
    printf("\n\n");

    return 0;
}


