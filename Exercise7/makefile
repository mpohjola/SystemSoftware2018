CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11

default: Exercise7

Exercise7: Exercise7.o Stars.o
	$(CC) $(CFLAGS) -o Exercise7 Exercise7.o Stars.o

Exercise7.o: Exercise7.c Stars.h
	$(CC) $(CFLAGS) -c Exercise7.c

Stars.o: Stars.c Stars.h
	$(CC) $(CFLAGS) -c Stars.c

clean:
	$(RM) Exercise7 *.o *~
