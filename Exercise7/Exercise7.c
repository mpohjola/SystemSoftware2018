/*
File:           Exercise7.c
Author:         Mira Pohjola
Description:    A program for storing information about 0-5 stars. The amount of stars is requested from user as well as
                the information about the stars. After all the information has been input the program prints the given data.
*/

#include <stdio.h>
#include <string.h>
#include "Stars.h"

void requestStars(int numberOfStars);

void fflush_stdin();

int main() {
    int numberOfStars = -1;

    printf("How many stars you want to add (0-5)? ");
    while (scanf("%d", &numberOfStars) != 1 || numberOfStars < 0 || numberOfStars > 5) {
        printf("Number of stars to enter must be a numeric value between 0 and 5.\n");
        printf("\nHow many stars you want to add (0-5)?\n ");
        while(getchar() != '\n');
    }

    requestStars(numberOfStars);
    printStarRecords();
    return 0;
}

void requestStars(int numberOfStars) {
    for (int i = 0; i < numberOfStars; i++) {
        int validName = 0;
        char starName[50] = {0};
        char starYear[6] = {0};
        char starDistance[20] = {0};

        (void) getchar(); //to consume the \n left by previous scanf
        while (validName == 0) {
            printf("\nEnter name of the star: ");
            fgets(starName, sizeof starName, stdin);
            if ((strlen(starName) > 0) && (starName[strlen(starName) - 1] == '\n')) {
                starName[strlen(starName) - 1] = '\0';
            }
            if (isNameValid(starName, sizeof(starName)) == 1) {
                setName(starName, i);
                validName = 1;
            } else {
                printf("\nYou can't leave star name empty! Press Enter to re-input the name. ");
                fflush_stdin();
            }
        }
        printf("Enter distance from Earth: ");
        scanf("%s", starDistance);
        setDistance(starDistance, i);

        printf("Enter Discovery year: ");
        scanf("%s", starYear);
        setDiscoveryYear(starYear, i);
    }
}

//cleans out strangling newline characters from input stream
void fflush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
