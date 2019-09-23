#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generateArena.h"

void generateArena(int size, struct celula cel[100][100]){

	int i, j, r;
	srand(time(NULL));

	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			if(i == 0 && j == 0)
				cel[i][j].terreno = BASE; //base do time 1 em uma extremidade do mapa
			
			else if(i == (size - 1) && j == (size-1))
				cel[i][j].terreno = BASE; //base do time 2 na outra extremidade do mapa

			else {
				r = rand() % 3;
				if(r == 0)
					cel[i][j].terreno = ESTRADA;
				else if(r == 1)
					cel[i][j].terreno = MONTANHA;
				else 
					cel[i][j].terreno = RIO;
			}	
			r = rand() % 5;
			cel[i][j].cristais = r; //o terreno terreno algum valor entre 0 e 4 cristais;
			
			cel[i][j].x = i;
			cel[i][j].y = j; 
		}
	}

	return;
}