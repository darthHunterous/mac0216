#include <stdio.h>
#include <stdlib.h>

#include "generateArena.h"
#include "imprime.h"
#include "direcao.h"
#include "inOutExerc.h"
#include "action.h"


int main(){

	celula cel[100][100];
	int size = 10;
	int x, y, cristais, i = 0;
	int direcao = 0;
	celula posicao;	

	generateArena(size, cel);

	printf("\nDigite a cel onde o robo sera adicionado: ");
	scanf("%d%d", &x, &y);
	posicao.x = x;
	posicao.y = y;
	insereExercito(cel, posicao);

	imprimeTerreno(cel, size);

	while(i < 6){
		imprimeVizinhos(cel, posicao, size);
		printf("\n\n Em que direcao voce quer movimentar o robo?");
		scanf("%d", &direcao);
		posicao = mover(cel, posicao, direcao, size);
		imprimeVizinhos(cel, posicao, size);
		printf("\n\n Em que direcao voce quer recolher cristais?");
		scanf("%d", &direcao);
		cristais += recolhe(cel, posicao, direcao);
		printf("%d Cristais recolhidos\n", cristais);
		i++;

	}

}
