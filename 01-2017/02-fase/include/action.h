#ifndef H_ACTION
#define H_ACTION

#include "direcao.h"
#include "inOutExerc.h"

celula mover(celula cel[100][100], celula celA, int direcao, int size);

int recolhe(celula cel[100][100], celula celA, int direcao);

void deposita(celula cel[100][100], celula celA, int direcao);

void ataque(celula cel[100][100], celula celA, int direcao);

#endif
