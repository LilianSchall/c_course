CC = gcc
CFLAGS = -Wall -std=c99 -Werror -pedantic -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-strict-prototypes

MAIN = main.c
MAIN_O = main.o
EXE = main

run: clean $(EXE)
	./$(EXE)

all: $(EXE)

$(EXE): $(MAIN_O)
	$(CC) $(CFLAGS) -o $(EXE) $(MAIN_O)

clean:
	rm -f $(EXE) $(MAIN_O)

