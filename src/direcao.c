#include <stdio.h>
#include <stdlib.h>
#include "direcao.h"
#include "generateArena.h"

// adotando sistema Offset de coordenadas, ou seja, os vizinhos de
// 2,2 sao : 1,1; 1,2; 1,3; 2,1; 3,2; 2,3;
int checaVizinho(struct celula celA, struct celula celB){

	int xA = celA.x;
	int yA = celA.y;

	int xB = celB.x;
	int yB = celB.y;

	if(xA % 2 == 1){
		if(xA == xB){
			if(yA + 1 == yB || yA - 1 == yB) return 1;
		}

		else if(xA - 1 == xB || xA + 1 == xB){
			if(yA == yB || yA + 1 == yB)     return 1;
		}
	}

	if(xA % 2 == 0){
		if(xA == xB){
			if(yA + 1 == yB || yA - 1 == yB) return 1;
		}

		else if(xA - 1 == xB || xA + 1 == xB){
			if(yA == yB || yA - 1 == yB)     return 1;
		}
	}

	return 0; //nao sao vizinhos;
}


celula calculaDirecao(struct celula celA, int direcao){
	//seguindo um relogio, temos 1 = movimento para frente e para cima(1 hora)
	//2 movimento para frente (3 horas)
	//ate 6 movimento para cima e para tras (11 horas)

	int x = celA.x; //x = linha
	int y = celA.y; //y = coluna

	if(x % 2 == 0){
		switch (direcao){
			case 1: //1 hora
				x--;
			break;

			case 2: //3 horas
				y++;
			break;

			case 3: // 5 horas
				x++;
			break;

			case 4: // 7 horas
				x++;
				y--;
			break;

			case 5: // 9 horas
				y--;
			break;

			case 6: // 11 horas
				x--;
				y--;
			break;

			case 0:
			break;

			default:
				printf("\n!!!Movimento invalido!!!\n");
				break;
		}

	}

	else{

		switch (direcao){
			case 1: // 1 hora
				x--;
				y++;
			break;

			case 2: //3 horas
				y++;
			break;

			case 3:// 5 horas
				x++;
				y++;
			break;

			case 4:// 7 horas
				x++;
			break;

			case 5:// 9 horas
				y--;
			break;

			case 6:// 11 horas
				x--;
			break;

			case 0://parado
			break;

			default:
				printf("Movimento invalido");
				break;
		}
	}

	celA.x = x;
	celA.y = y;

	return celA;

}
