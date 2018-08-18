CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11

default: Exercise9

Exercise9: Exercise9.o
	$(CC) $(CFLAGS) -o Exercise9 Exercise9.o

Exercise9.o: Exercise9.c
	$(CC) $(CFLAGS) -c Exercise9.c

clean:
	$(RM) Exercise9 *.o *~

