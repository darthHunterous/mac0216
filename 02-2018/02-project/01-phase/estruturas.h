#ifndef __ESTRUTURAS_H__
#define __ESTRUTURAS_H__

typedef struct {
    char N[80];
} Elemento;

typedef struct elo {
    struct elo *next;
    Elemento *val;
} Elo;

typedef struct {
    Elo *cabec;
} Lista;

typedef struct lugar {
    Elemento *lugar;
    struct lugar *saida;
    int fechada;
} Lugar;

typedef struct {
    Elemento *objeto;
    Lista adjetivos;
    int invisivel;
} Objeto;

typedef struct {
    Objeto aventureiro;
    Objeto *mochila;
} Aventureiro;

typedef struct {
    int entriesNum;
    int num;
    Lista *htable;
} TabSim;

TabSim cria(int tam);
void destroi(TabSim t);
int insere(TabSim t, char *n, Elemento *val);
Elemento *busca(TabSim t, char *n);
int retira(TabSim t, char *n);
int hash_string(TabSim t, char *n);
void imprime(TabSim t);

Lista criaL();
void destroiL(Lista l);
Lista insereL(Lista l, Elemento *val);
Elemento *buscaL(Lista l, char *n);
Elemento *retiraL(Lista l, Elemento *val);
void imprimeL(Lista l);

#endif
