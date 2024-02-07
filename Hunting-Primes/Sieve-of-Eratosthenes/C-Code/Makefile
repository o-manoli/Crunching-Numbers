
CC=gcc
CFlags=-c -Wall -g
EXE=PrimesEXE

SRCs=$(wildcard *.c)
OBJs=$(addprefix obj., $(SRCs:%.c=%.o))

all: $(EXE)

obj.%.o: %.c
	$(CC) $(CFlags) $< -o $@

$(EXE): $(OBJs)
	$(CC) -o $(EXE) $(OBJs)

run: $(EXE)
	@ echo - - - - - - - - - - - - - - - - -
	./$(EXE) $(args)
	@ echo - - - - - - - - - - - - - - - - -

clean:
	rm -f $(EXE) $(OBJs)


