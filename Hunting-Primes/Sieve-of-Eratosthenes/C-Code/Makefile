all: run clean

main: *.o
	gcc -o emainEXE *.o

%.o: %.c
	gcc -c $<

run: main
	@echo - - - - - - - - -
	./emainEXE
	@echo - - - - - - - - -

clean:
	rm -f *.o emainEXE

