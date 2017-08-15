CC = gcc
CFLAGS = -I -ansi -Wall -pedantic -std=c99
DEPS = game.h player.h gameboard.h reversi.h utility.h
OBJ = game.o player.o gameboard.o reversi.o utility.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
reversi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	


