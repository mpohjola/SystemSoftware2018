/*
File:           Stars.h
Author:         Mira Pohjola
Description:    Header file for Stars.c
*/
#ifndef SYSTEMSOFTWARE_EX7_STARS_H
#define SYSTEMSOFTWARE_EX7_STARS_H

void setName(char starName[50], int index);
void setDiscoveryYear(char starDiscoveryYear[6], int index);
void setDistance(char starDistance[20], int index);

char * getName(int index);
char * getDiscoveryYear(int index);
char * getDistance(int index);

int isNameValid(char starName[50], int arrayLength);

void printStarRecords();

#endif //SYSTEMSOFTWARE_EX7_STARS_H