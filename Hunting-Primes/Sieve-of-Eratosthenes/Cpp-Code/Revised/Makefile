CC=g++
CFlags=-c -Wall -O2
EXE=appEXE
SRCs=main.cpp
OBJs=$(SRCs:.cpp=.o)

all: run

link: $(OBJs)
	$(CC) -o $(EXE) *.o

%.o:%.cpp
	$(CC) $(CFlags) $< -o $@

run: link
	@ echo - - - - - - - - - - - - - -
	@ ./$(EXE)
	@ echo - - - - - - - - - - - - - -

clean:
	rm -f *.o $(EXE)

