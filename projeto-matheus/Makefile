CC=gcc
CFLAGS=-Isrc -Wall -Wextra -g

all: git_simulation

git_simulation: src/main.o src/git_commands.o src/data_structures.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f src/*.o git_simulation

.PHONY: all clean