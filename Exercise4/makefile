
CC = gcc
CFLAGS = -g -Wall -std=c11

default: exercise4

exercise4: Exercise4.o Array.o Collatz.o
	$(CC) $(CFLAGS) -o exercise4 Exercise4.o Array.o Collatz.o

Exercise4.o: Exercise4.c Array.h Collatz.h
	$(CC) $(CFLAGS) -c Exercise4.c

Collatz.o: Collatz.c Collatz.h Array.h
	$(CC) $(CFLAGS) -c Collatz.c

Array.o: Array.c Array.h
	$(CC) $(CFLAGS) -c Array.c

clean:
	$(RM) exercise4 *.o *~
