/*
File:           Stars.c
Author:         Mira Pohjola
Description:    Contains a struct Star as well as an array of Stars called Stars. Also contains necessary functions for
                setting and getting and validating star information as well as for printing the given information of all stars.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Stars.h"

#define STAR_MAX_AMOUNT 5

struct Star {
    char name[50];
    char discoveryYear[6];
    char distance[20];
};

struct Star Stars[STAR_MAX_AMOUNT];

void setName(char starName[50], int index) {
    strcpy(Stars[index].name, starName);
}

void setDiscoveryYear(char starDiscoveryYear[4], int index) {
    strcpy(Stars[index].discoveryYear, starDiscoveryYear);
}

void setDistance(char starDistance[20], int index) {
    memset(Stars[index].distance, '\0', sizeof(Stars[index].distance));
    strcpy(Stars[index].distance, starDistance);
}

char *getName(int index) {
    return Stars[index].name;
}

char *getDiscoveryYear(int index) {
    return Stars[index].discoveryYear;
}

char *getDistance(int index) {
    return Stars[index].distance;
}

void printStarRecords() {
    if (getName(0)[0] == '\0'){
        printf("\n*** No stars entered ***\n");
    } else {
        printf("\n*** List of the stars you entered ***\n\n");
        for (int i = 0; i < STAR_MAX_AMOUNT; i++) {
            char name[50] = {0};
            strcpy(name, getName(i));
            if (name[0] != '\0') {
                printf("\nName: %s", name);

                char distance[20] = {0};
                strcpy(distance, getDistance(i));
                printf("\nDistance: %s", distance);

                char discoveryYear[6] = {0};
                strcpy(discoveryYear, getDiscoveryYear(i));
                printf("\nDiscovery: %s\n", discoveryYear);
            }
        }
        printf("\n");
    }
}

//Check for star name validity.
int isNameValid(char starName[50], int arrayLength) {
    int isValid = 0;
    if (starName[0] != '\0' && starName[0] != '\n') {
        for (int i = 0; i < arrayLength; i++) {
            //Check that the name contains some valid characters (is not all whitespaces etc.)
            if (!isspace(starName[i]) && starName[i] != 0) {
                isValid = 1;
            }
        }
    }
    return isValid;
}
