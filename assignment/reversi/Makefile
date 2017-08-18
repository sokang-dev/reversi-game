CC = gcc
CFLAGS =  -ansi -Wall -pedantic
DEPS = game.h player.h gameboard.h reversi.h utility.h
OBJ = game.o player.o gameboard.o reversi.o utility.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
reversi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm -f $(OBJ) *~ core 

