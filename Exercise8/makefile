CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11

default: Exercise8

Exercise8: Exercise8.o PrimeFactors.o
	$(CC) $(CFLAGS) -o Exercise8 Exercise8.o PrimeFactors.o -lm

Exercise8.o: Exercise8.c PrimeFactors.h
	$(CC) $(CFLAGS) -c Exercise8.c

PrimeFactors.o: PrimeFactors.c PrimeFactors.h
	$(CC) $(CFLAGS) -c PrimeFactors.c

clean:
	$(RM) Exercise8 *.o *~