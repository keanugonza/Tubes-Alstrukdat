CC = gcc
CFLAGS = -Wall -g -std=c11

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: clean main run

main: $(OBJ_MAIN) $(OBJ_FOO)
	$(CC) $(CFLAGS) -o $@ $^

run:
	./main

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main $(OBJ_MAIN) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)

