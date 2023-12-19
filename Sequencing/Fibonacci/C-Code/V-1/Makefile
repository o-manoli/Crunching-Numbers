CC=gcc
EXE=fibonacciEXE
SRCs=main.c

all: compile run

compile: $(SRCs)
	$(CC) $(SRCs) -o $(EXE)

run:
	@ echo - - - - - - - - - - - - - - -
	./$(EXE)
	@ echo - - - - - - - - - - - - - - -

clean:
	rm -f $(EXE)

