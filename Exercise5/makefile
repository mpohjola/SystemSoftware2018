CC = gcc
CFLAGS = -Wall -std=c11

default: Exercise5

exercise5: Exercise5.o
	$(CC) $(CFLAGS) -o Exercise5 Exercise5.o

Exercise5.o: Exercise5.c
	$(CC) $(CFLAGS) -c Exercise5.c

clean:
	$(RM) Exercise5 *.o *~
