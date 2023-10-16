CC=clang++
CFlags=-c -O3
EXEname=emain

all: main

run: main
	@ echo - - - - - - - - - - -
	@ ./emain
	@ echo - - - - - - - - - - -

main: *.o
	@ $(CC) -o $(EXEname) *.o

%.o:%.cpp
	@ $(CC) $(CFlags) $<

clean:
	rm -f $(EXEname) *.o

test: run clean
