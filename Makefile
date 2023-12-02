CC=gcc
CFLAGS=-I./utils
UTILS = utils/
PUZZLE1 = puzzle1/
PUZZLE2 = puzzle2/

all: $(PUZZLE1)puzzle.elf $(PUZZLE2)puzzle.elf

$(PUZZLE1)puzzle.elf: $(PUZZLE1)puzzle.o $(UTILS)util.o
	$(CC) -o $(PUZZLE1)puzzle.elf $(PUZZLE1)puzzle.o $(UTILS)util.o $(CFLAGS)

$(PUZZLE2)puzzle.elf: $(PUZZLE2)puzzle.o $(UTILS)util.o
	$(CC) -o $(PUZZLE2)puzzle.elf $(PUZZLE2)puzzle.o $(UTILS)util.o $(CFLAGS)

$(UTILS)util.o:
	$(CC) -c -o $(UTILS)util.o $(UTILS)util.c