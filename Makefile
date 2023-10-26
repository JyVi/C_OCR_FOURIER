CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=-lm $(shell pkg-config --libs SDL2_image gtk+-3.0)
LDLIBS=-fsanitize=address -g
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
Test=tests/test.c
TestOBJ=$(Test:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o program $(LDFLAGS)

test: $(OBJ) $(TestOBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TestOBJ) -o test $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ) 
	$(RM) $(TestOBJ) 
	$(RM) program test