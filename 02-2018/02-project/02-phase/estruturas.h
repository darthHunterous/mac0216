#ifndef __ESTRUTURAS_H__
#define __ESTRUTURAS_H__

struct elo Elo;
union detalhe Detalhe;

typedef struct {
    struct elo* cabec;
} Lista;

typedef struct elemento{    
    char* nome;
    char* curta;
    char* longa;
    char ativo;
    char visivel;
    char conhecido;
    void* acoes;
    void* animacao;
    Lista conteudo;
    char* artigos[4];
    union detalhe* detalhe;
} Elemento;

typedef struct {
    char** adjetivos;
    int quantAdj;
} Objeto;

typedef struct lugar {
    Elemento* saidas[4];
    int fechada;
} Lugar;

union detalhe {
    Objeto objeto;
    Lugar lugar;
};

struct elo {
    struct elo *next;
    Elemento* val;
};

typedef struct {
    Elemento* aventureiro;
    Lista mochila;
    int nivel_stress;
} Aventureiro;

typedef struct {
    int entriesNum;
    int num;
    Lista *htable;
} TabSim;

typedef int (*FPTR) (Elemento*, Elemento*);

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
int vaziaL(Lista l);

#endif
