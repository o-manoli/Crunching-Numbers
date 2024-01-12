CC=g++
CFlags=-c -Wall -O2
EXE=appEXE
OBJs=main

all: run

link: $(OBJs)
	$(CC) -o $(EXE) *.o

%:%.cpp
	$(CC) $(CFlags) $< -o $@.o

run: link
	@ echo - - - - - - - - - - - - - -
	@ ./$(EXE)
	@ echo - - - - - - - - - - - - - -

clean:
	rm -f *.o $(EXE)

