HEADERS = SharedMemoryVariables.h
CC = gcc

default: SharedMemoryVariables.o

SharedVariables.o: SharedMemoryVariables.c $(HEADERS)
	$(CC) -c SharedMemoryVariables.c -o SharedMemoryVariables.o -g Wall -lm -lpthred 

clean:
	-rm -f SharedMemoryVariables.o
