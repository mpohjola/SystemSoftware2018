/*
File:           Exercise10.c
Author:         Mira Pohjola
Description:    Rock Paper Scissors Lizard Spock with C. In this version, best of three games wins and user plays against computer.
                The computer selects it's choice randomly and points are calculated for each rounds. If rounds is a tie, the round
                will be renewed. After three rounds have been completed, the game ends.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int doRound(int roundNumber);

void fflush_stdin();

int getRoundResult(int userInput, int computerInput);

void printError();

void printHelp();

void printMenu();

void printRoundResult(char userInput[], char computerInput[]);


int main() {
    srand(time(0)); //using time to seed the randomizer
    printf("\n\n Welcome to Rock Paper Scissors Lizard Spock\n\n");
    int userScore = 0;
    int computerScore = 0;
    int rounds = 1;
    int userInput;
    int computerChoice = 0;
    while (rounds <= 3) {
        userInput = doRound(rounds);
        computerChoice = (rand() % 5) + 1;
        int roundResult = getRoundResult(userInput, computerChoice);
        if (roundResult == 1) {
            userScore++;
            printf("\nUser wins the round!\n");
            rounds++;
        } else if (roundResult == -1) {
            computerScore++;
            printf("\nComputer wins the round!\n");
            rounds++;
        }
    }
    printf("\n********************************\n");
    printf("Game ends with:\nUser score: %d \nComputer score: %d\n", userScore, computerScore);
    printf("\n********************************\n");
    return 0;

}

int doRound(int roundNumber) {
    int validInput = 0;
    int userInput;
    int numberOfItems;
    while (validInput != 1) {
        printf("\nRound %d: \n Please choose your action!\n", roundNumber);
        printMenu();
        numberOfItems = scanf("%d", &userInput);
        if (numberOfItems == EOF) {
            fflush_stdin();
            printError();
        } else if (numberOfItems == 0) {
            fflush_stdin();
            printError();
        } else if (userInput == 0) {
            printHelp();
        } else if (userInput > 5) {
            printError();
        } else {
            validInput = 1;
        }
    }
    fflush_stdin();
    return userInput;
}

//cleans out strangling newline characters from input stream
void fflush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getRoundResult(int userInput, int computerInput) {
    int point = 0; //point will be -1 if computer wins the rounds, 1 if user wins the round and 0 if tie.
    if (userInput == 1) { //rock
        if (computerInput == 1) { //rock
            printf("\nIt is a tie!\n");
            printRoundResult("Rock", "Rock");
        } else if (computerInput == 2) { //paper
            printf("Paper covers rock!\n");
            printRoundResult("Rock", "Paper");
            point--; //computer wins
        } else if (computerInput == 3) { //scissors
            printf("Rock crushes Scissors!\n");
            printRoundResult("Rock", "Scissors");
            point++; //user wins
        } else if (computerInput == 4) { //lizard
            printf("Rock crushes Lizard!\n");
            printRoundResult("Rock", "Lizard");
            point++; //user wins
        } else if (computerInput == 5) { //spock
            printf("Spock vaparizes Rock!\n");
            printRoundResult("Rock", "Spock");
            point--; //computer wins
        }
    } else if (userInput == 2) { //paper
        if (computerInput == 1) { //rock
            printf("Paper covers rock!\n");
            printRoundResult("Paper", "Rock");
            point++; //user wins
        } else if (computerInput == 2) { //paper
            printf("\nIt is a tie!\n");
            printRoundResult("Paper", "Paper");
        } else if (computerInput == 3) { //scissors
            printf("Scissors cuts Paper!\n");
            printRoundResult("Paper", "Scissors");
            point--; //computer wins
        } else if (computerInput == 4) { //lizard
            printf("Lizard eats Paper!\n");
            printRoundResult("Paper", "Lizard");
            point--; //computer wins
        } else if (computerInput == 5) { //spock
            printf("Paper disqualifies Spock!\n");
            printRoundResult("Paper", "Spock");
            point++; //user wins
        }

    } else if (userInput == 3) { //scissors
        if (computerInput == 1) { //rock
            printf("Rock crushes Scissors!\n");
            printRoundResult("Scissors", "Rock");
            point--; //computer wins

        } else if (computerInput == 2) { //paper
            printf("Scissors cuts Paper!\n");
            printRoundResult("Scissors", "Paper");
            point++; //user wins

        } else if (computerInput == 3) { //scissors
            printf("\nIt is a tie!\n");
            printRoundResult("Scissors", "Scissors");

        } else if (computerInput == 4) { //lizard
            printf("Scissors decapitates Lizard!\n");
            printRoundResult("Scissors", "Lizard");
            point++;

        } else if (computerInput == 5) { //spock
            printf("Spock smashes Scissors!\n");
            printRoundResult("Scissors", "Spock");
            point--;

        }

    } else if (userInput == 4) { //lizard
        if (computerInput == 1) { //rock
            printf("Rock crushes Lizard!\n");
            printRoundResult("Lizard", "Rock");
            point--;

        } else if (computerInput == 2) { //paper
            printf("Lizard eats Paper!\n");
            printRoundResult("Lizard", "Paper");
            point++;

        } else if (computerInput == 3) { //scissors
            printf("Scissors decapitates Lizard!\n");
            printRoundResult("Lizard", "Scissors");
            point--;

        } else if (computerInput == 4) { //lizard
            printf("\nIt is a tie!\n");
            printRoundResult("Lizard", "Lizard");

        } else if (computerInput == 5) { //spock
            printf("Lizard poisons Spock!\n");
            printRoundResult("Lizard", "Spock");
            point++;

        }

    } else if (userInput == 5) { //spock
        if (computerInput == 1) { //rock
            printf("Spock vaporizes Rock!\n");
            printRoundResult("Spock", "Rock");
            point++;

        } else if (computerInput == 2) { //paper
            printf("Paper disqualifies Spock!\n");
            printRoundResult("Spock", "Paper");
            point--;

        } else if (computerInput == 3) { //scissors
            printf("Spock smashes Scissors!\n");
            printRoundResult("Spock", "Scissors");
            point++;

        } else if (computerInput == 4) { //lizard
            printf("Lizard poisons Spock!\n");
            printRoundResult("Spock", "Lizard");
            point--;

        } else if (computerInput == 5) { //spock
            printf("\nIt is a tie!\n");
            printRoundResult("Spock", "Spock");
        }

    }
    return point;
}

void printError() {
    printf("\nInvalid input detected. Please choose one of the input options in the menu!\n");
}

void printHelp() {
    printf("This game is originally created by Sam Kass and Karen Bryla\n\n");
    printf("In the game you choose one of the five given options and computer chooses one as well. You get points based on"
           "the following rule set:\n\n");
    printf("Scissors cuts Paper\n");
    printf("Paper covers Rock\n");
    printf("Rock crushes Lizard\n");
    printf("Lizard poisons Spock\n");
    printf("Spock smashes Scissors\n");
    printf("Scissors decapitates Lizard\n");
    printf("Lizard eats Paper\n");
    printf("Paper disproves Spock\n");
    printf("Spock vaporizes Rock\n");
    printf("Rock crushes Scissors\n");
    printf("\nBest out of three games wins. Good luck!\n");
}

void printMenu() {
    printf("\n********************************\n");
    printf("0 = Help\n\n");
    printf("1 = Rock\n");
    printf("2 = Paper\n");
    printf("3 = Scissors\n");
    printf("4 = Lizard\n");
    printf("5 = Spock\n");
    printf("\n********************************\n");
}

void printRoundResult(char userInput[], char computerInput[]) {
    printf("\nYour choice: %s\n", userInput);
    printf("Computer's choice: %s\n", computerInput);
}