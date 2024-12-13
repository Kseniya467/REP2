CC = gcc
CFLAGS = -Wall -g
OBJ = main.o Holod.o

all: Holod

Holod: $(OBJ)
	$(CC) -o Holod $(OBJ)

main.o: main.c Holod.h
	$(CC) $(CFLAGS) -c main.c

Holod.o: Holod.c Holod.h
	$(CC) $(CFLAGS) -c Holod.c

clean:
	rm -f *.o Holod
	 
