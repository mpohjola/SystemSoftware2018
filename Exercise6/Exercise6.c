/*
File:           Ecercise6.c
Author:         Mira Pohjola
Description:    Parses binary numbers from given command-line arguments and handles them. The numbers are treated as 2's
                complement numbers and converted to decimal. Then negative numbers are divided by 2 by using bitwise
                operators and positive numbers are multiplied by two using bitwise operators.
*/

#include <stdio.h>
#include <math.h>

#define SIZE 8

void handleBinaryNumber(int bin[SIZE]);
int convertToDecimal(int bin[]);
int multiplyWithBitwise(int numberToMultiply);
int divideWithBitwise(int numberToDivide);
void writeResult(int bin[SIZE], int decimal, int processedDecimal, int isNegative);

int main(int argc, char *argv[]){

    int bin[SIZE] = {0};
    int currentBinIndex = 0;

    FILE *filePointer = NULL;
    filePointer = fopen("Binary.txt", "w");
    fprintf(filePointer, "Exercise 6 - Learning command line arguments and file write\n");
    fclose(filePointer);

    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (argv[i][j] == '1' || argv[i][j] == '0'){
                bin[currentBinIndex] = argv[i][j]-'0';
                currentBinIndex++;
                if (currentBinIndex == SIZE){
                    handleBinaryNumber(bin); //when we get a binary with the size of SIZE we call a handler for it
                    currentBinIndex = 0;
                }
            }
        }
    }
    return 0;
}

void handleBinaryNumber(int bin[SIZE]){
    int isNegative = 0;
    int decimal = 0;
    int processedDecimal = 0;

    if (bin[0] == 1){
        isNegative = 1;
    }

    //if the number is negative we need to handle it.
    if (isNegative == 1){
        int complement[SIZE] = {0};
        printf("\nTHE BINARY: ");

        //One's complement
        for(int i = 0; i < SIZE; i++){
            printf("%d", bin[i]);
            if (bin[i] == 0) {
                complement[i] = 1;
            } else {
                complement[i] = 0;
            }
        }

        //Two's complement
        int isComplemented = 0;
        int i = SIZE;
        while (isComplemented == 0 && i > 0) {
            i--;
            if(complement[i] == 1){
                complement[i] = 0;
            } else {
                complement[i]=1;
                isComplemented = 1;
            }
        }

        decimal = convertToDecimal(complement) * -1;
        processedDecimal = divideWithBitwise(decimal);
        printf("\nTHE DECIMAL: %d DIVIDED: %d \n", decimal, processedDecimal);
    } else {
        printf("\nTHE BINARY: ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d", bin[i]);
        }
        decimal = convertToDecimal(bin);
        processedDecimal = multiplyWithBitwise(decimal);
        printf("\nTHE DECIMAL: %d MULTIPLIED: %d\n", decimal, processedDecimal);
    }
    writeResult(bin, decimal, processedDecimal, isNegative);
    return;
}

int convertToDecimal(int binary[]){
    int decimalNumber = 0;
    int currentPow = 0;
    for (int i = SIZE-1; i >= 0; i--) {
        decimalNumber += binary[i]*pow(2,currentPow);
        currentPow++;
    }
    return decimalNumber;
}

int multiplyWithBitwise(int numberToMultiply){
    int multiplied = 0;
    multiplied = numberToMultiply << 1;
    return multiplied;
}

int divideWithBitwise(int numberToDivide){
    int divided = 0;
    divided = numberToDivide >> 1;
    return divided;
}

void writeResult(int bin[SIZE], int decimal, int processedDecimal, int isNegative){
    FILE *filePointer = NULL;
    filePointer = fopen("Binary.txt", "a");
    fprintf(filePointer, "\n\nOriginal Binary: ");
    for (int i = 0; i < SIZE; i++) {
        fprintf(filePointer, "%d",bin[i]);
    }
    fprintf(filePointer, "\nDecimal: %d", decimal);
    if (isNegative == 1) {
        fprintf(filePointer, "\nDivided decimal: %d", processedDecimal);
    } else {
        fprintf(filePointer, "\nMultiplied decimal: %d\n", processedDecimal);
    }
    fclose(filePointer);
}

