CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11

default: Exercise10

Exercise10: Exercise10.o
	$(CC) $(CFLAGS) -o Exercise10 Exercise10.o

Exercise10.o: Exercise10.c
	$(CC) $(CFLAGS) -c Exercise10.c

clean:
	$(RM) Exercise10 *.o *~