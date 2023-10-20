CC=clang
CFlags=-c -Wall -O2
EXE=emainEXE
SHELL:=/usr/bin/bash
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: run clean

main: $(OBJS)
	@ $(CC) -o $(EXE) *.o

%.o: %.c
	@ $(CC) $(CFlags) $< -o $@

run: main
	@ echo - - - - - - - - - - -
	@ time ./$(EXE)
	@ echo - - - - - - - - - - -

clean:
	@ rm -f *.o $(EXE)

