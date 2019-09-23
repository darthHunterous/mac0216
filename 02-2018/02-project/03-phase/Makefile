LOADLIBES= -ll -lreadline

%.c: %.y
	bison $<
	mv $*.tab.c $*.c

avent: avent.o aventl.o coisas.o tabsim.o lista.o comandos.o

avent.c : avent.y

aventl.o: aventl.l avent.c

dist:
	tar czf avent.tgz aventl.l avent.y coisas.c coisas.h tabsim.c lista.c comandos.c comandos.h estruturas.h Makefile
