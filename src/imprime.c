#include <stdio.h>
#include <stdlib.h>
#include "imprime.h"
#include "direcao.h"

void imprimeCristais(struct celula cel[100][100], int size){
	int i, j;
	for(i = 0; i < size; i++){
		printf("\n");
		if(i % 2 == 1) printf(" ");
		for(j = 0; j < size; j++)
			if(cel[i][j].ocupado == 1) printf("X ");
			else printf("%d ", cel[i][j].cristais); 
	}
	printf("\n\n");		
}

void imprimeTerreno(struct celula cel[100][100], int size){
	int i, j;
	for(i = 0; i < size; i++){
		printf("\n");
		if(i % 2 == 1) printf(" ");
		for(j = 0; j < size; j++)
			if(cel[i][j].terreno == BASE) printf("B ");
			else if(cel[i][j].terreno == ESTRADA) printf("E "); 
			else if(cel[i][j].terreno == MONTANHA) printf("M "); 
 			else printf("R "); 

	}
	printf("\n\n");		
}

//simula um "Fog of war"
void imprimeVizinhos(struct celula cel[100][100], struct celula celA, int size){
	int i, j;
	for(i = 0; i < size; i++){
		printf("\n");
		if(i % 2 == 1) printf(" ");
		for(j = 0; j < size; j++)
			if(cel[i][j].ocupado == 1) printf("X ");
			else if(checaVizinho(cel[i][j], celA) == 1) printf("%d ", cel[i][j].cristais);
			else printf("- ");
	}
	printf("\n\n");	
}