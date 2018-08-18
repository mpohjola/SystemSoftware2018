CC = gcc
CFLAGS = -Wall -Wextra -std=c11

default: Exercise6

Exercise6: Exercise6.o
	$(CC) $(CFLAGS) -o Exercise6 Exercise6.o -lm

Exercise6.o: Exercise6.c
	$(CC) $(CFLAGS) -c Exercise6.c

clean:
	$(RM) Exercise6 *.o *~ Binary.txt
