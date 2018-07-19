#include <stdio.h>
#include <stdlib.h>
#include "action.h"


celula mover(struct celula cel[100][100], struct celula celA, int direcao, int size){
 	celula celB;

	removeExercito(cel, celA);

	celB = calculaDirecao(celA, direcao);
	
	if(celB.x < 0 || celB.y < 0 || celB.x >= size || celB.y >= size){
		printf("Movimento Invalido!\n");
		return celA;
	}	

	insereExercito(cel, celB);
	return celB;
}

int recolhe(struct celula cel[100][100], struct celula celA, int direcao){
	int x, y;
	int cristais = 0;
	celula celB = calculaDirecao(celA, direcao);
	x = celB.x;
	y = celB.y;

	cristais = cel[x][y].cristais;
	cel[x][y].cristais = 0;

	return cristais;
}

void deposita(struct celula cel[100][100], struct celula celA, int direcao){
	int x, y;
	celula celB = calculaDirecao(celA, direcao);
	x = celB.x;
	y = celB.y;

	cel[x][y].cristais++;
}

void ataque(struct celula cel[100][100], struct celula celA, int direcao){
	int x, y;
	celula celB = calculaDirecao(celA, direcao);
	x = celB.x;
	y = celB.y;

	//dano++??? vida--??
}
