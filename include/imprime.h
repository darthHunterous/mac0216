#ifndef H_IMPRIME
#define H_IMPRIME

#include "generateArena.h"

void imprimeCristais(struct celula cel[100][100], int size);

void imprimeTerreno(struct celula cel[100][100], int size);

void imprimeVizinhos(struct celula cel[100][100], struct celula celA, int size);

#endif
