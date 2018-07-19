#include <stdio.h>
#include <stdlib.h>
#include "inOutExerc.h"
#include "generateArena.h"

void insereExercito(celula cel[100][100], celula celA){
	int x = celA.x; //x = linha
	int y = celA.y; //y = coluna
	cel[x][y].ocupado = 1;
}

void removeExercito(celula cel[100][100], celula celA){
	int x = celA.x; //x = linha
	int y = celA.y; //y = coluna
	cel[x][y].ocupado = 0;
}
