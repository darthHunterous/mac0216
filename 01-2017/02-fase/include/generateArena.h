#ifndef H_GENERATEARENA
#define H_GENERATEARENA

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
		int base; // 0 se não base, x se base pertencente ao exército x
} celula;

void generateArena(int size, struct celula cel[100][100]);

#endif
