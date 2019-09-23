CC = gcc
CFLAGS = -I.
XFLAGS = -Wall -std=c99 -pedantic -O2 -Wextra
DEPS = estruturas.h
OBJ = lista.o tabsim.o testes.o

%.o: %.c $(DEPS)
	$(CC) $(XFLAGS) -c -o $@ $< $(CFLAGS)

freq: lista.c tabsim.c testes.c
	gcc -Wall -std=c99 -pedantic -O2 -Wextra -g -o testes lista.c tabsim.c testes.c -I .
