CC = gcc
CFLAGS = -I.
XFLAGS = -Wall -std=c99 -pedantic -O2 -Wextra
DEPS = estruturas.h global.h comandos.h
OBJ = lista.o tabsim.o jogo.o animacoes.o comandos.o global.o

%.o: %.c $(DEPS)
	$(CC) $(XFLAGS) -c -o $@ $< $(CFLAGS)

jogo: lista.c tabsim.c jogo.c animacoes.c comandos.c global.c
	gcc -Wall -std=c99 -pedantic -O2 -o jogo lista.c tabsim.c jogo.c animacoes.c comandos.c global.c -I .
