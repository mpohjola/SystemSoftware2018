/*
File:           Exercise9.c
Author:         Mira Pohjola
Description:    Program which finds the largest palindrome number that is a product of two n-digit numbers.
                Digit length is given as a variable in this version but could be for example requested from the user
                The largest found palindrome as well as the factors are printed.
*/

#include <stdio.h>

int checkIfPalindrome(int number);
int getUpperLimit(int numberLength);

int main() {
    int largestPalindrome = 0;

    int digits = 3;

    int maxNumber = getUpperLimit(digits);
    int minNumber = 1 + maxNumber / 10;

    int largestPalindromeFactor1 = 0;
    int largestPalindromeFactor2 = 0;
    for (int number1 = maxNumber; number1 >= minNumber; number1--) {
        for (int number2 = maxNumber; number2 >= minNumber; number2--) {
            int currentProduct = 0;
            currentProduct = number1 * number2;
            if (currentProduct > largestPalindrome && checkIfPalindrome(currentProduct) == 1) {
                largestPalindrome = currentProduct;
                largestPalindromeFactor1 = number1;
                largestPalindromeFactor2 = number2;
            }
        }
    }
    printf("\nLargest palindrome number is %d\n\nNumbers are %d and %d\n\n", largestPalindrome, largestPalindromeFactor1,
           largestPalindromeFactor2);

    return 0;
}

int getUpperLimit(int numberLength){
    int upperLimit = 0;
    for (int i = 1; i <= numberLength; i++) {
        upperLimit *=10;
        upperLimit +=9;
    }
    return upperLimit;
}

int checkIfPalindrome(int number) {
    int original = number;
    int reverse = 0;
    int remainder = 0;
    while (number > 0) {
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;
    }
    if (original == reverse) {
        return 1;
    } else {
        return 0;
    }
}

