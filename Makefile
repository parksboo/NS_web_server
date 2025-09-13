CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O2
LDFLAGS=-lpthread
SRC=$(wildcard src/**/*.c src/*.c)
OBJ=$(SRC:.c=.o)

server: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) server