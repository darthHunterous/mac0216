#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum {
  ESTRADA,
  MONTANHA,
  RIO,
  BASE
} Terreno;

typedef struct celula{
        Terreno terreno;
		short int cristais; // 0 nao contem cristais, x = numero de cristais;
		int x; // coordenada x do celula
		int y; //coordenada y do celula
		short int ocupado; //0 esta vazio e 1 esta ocupado
} celula;


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

void imprimeOcupados(struct celula cel[100][100], int size){
	int i, j;
	for(i = 0; i < size; i++){
		printf("\n");
		if(i % 2 == 1) printf(" ");
		for(j = 0; j < size; j++)
			if(cel[i][j].ocupado == 1) printf("X ");
			else printf("O ");
	}
	printf("\n\n");
}

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

void insereExercito(struct celula cel[100][100], struct celula celA){
	int x = celA.x; //x = linha
	int y = celA.y; //y = coluna
	cel[x][y].ocupado = 1;
}

void removeExercito(struct celula cel[100][100], struct celula celA){
	int x = celA.x; //x = linha
	int y = celA.y; //y = coluna
	cel[x][y].ocupado = 0;
}



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
