CC=gcc
CFLAGS=-I./utils
UTILS = utils/
PUZZLE1 = puzzle1/

all: $(PUZZLE1)puzzle.elf 

$(PUZZLE1)puzzle.elf: $(PUZZLE1)puzzle.o $(UTILS)util.o
	$(CC) -o $(PUZZLE1)puzzle.elf $(PUZZLE1)puzzle.o $(UTILS)util.o $(CFLAGS)

$(UTILS)util.o:
	$(CC) -c -o $(UTILS)util.o $(UTILS)util.c