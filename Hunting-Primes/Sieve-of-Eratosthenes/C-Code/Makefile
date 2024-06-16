
CC = gcc

CFLAGS = -Wall

SRCs = main.c primes.c
OBJs = $(SRCs:%.c=%.o)
DEPs = primes.h

defallt: primes.run

%.o: %.c $(DEPs)
	$(CC) $(CFLAGS) -c $< -o $@

%.exe: $(OBJs)
	$(CC) $^ -o $@

%.run: %.exe
	@ echo - - - - - - - - - - - - - - - -
	./$< $(args)
	@ echo - - - - - - - - - - - - - - - -
