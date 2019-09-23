#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

/* Função que inicializa uma tabela de simbolos */
TabSim cria(int tam) {
    TabSim table;
    table.entriesNum = tam;
    table.num = 0;
    table.htable = malloc(tam * sizeof(Lista));
    int i;
    for (i = 0; i < table.entriesNum; i++)
        table.htable[i] = criaL();

    return table;
}

/* Função que desaloca a memória de uma tabela de simbolos */
void destroi(TabSim t) {
    int i;
    
    for (i = 0; i < t.entriesNum; i++)
        destroiL(t.htable[i]);
    
    free(t.htable);
    t.htable = NULL;
}

/* Função que associa um elemento a uma string na tabela de simbolos */ 
int insere(TabSim t, char *n, Elemento *val) {
    int hash = hash_string(t, n);
    strcpy(val->nome, n);

    Elemento *aux = buscaL(t.htable[hash], n);
    if (aux == NULL) {
        t.htable[hash] = insereL(t.htable[hash], val);
        t.num++;
    }
    else {
        aux = retiraL(t.htable[hash], aux);
        t.htable[hash] = insereL(t.htable[hash], val);
    }

    return 0;
}

/* Função que retorna um elemento associado a uma dada chave na tabela de simbolos */
Elemento *busca(TabSim t, char *n) {
    int hash = hash_string(t, n);
    return buscaL(t.htable[hash], n);
}

/* Função que retira um elemento da tabela de simbolos */
int retira(TabSim t, char *n) {
    int hash = hash_string(t, n);
    Elemento *aux = buscaL(t.htable[hash], n);
    if (aux != NULL) {
        aux = retiraL(t.htable[hash], aux);
        return 0;
    }
    return 1;
}

/* Função que retorna um hash para uma dada string */
int hash_string(TabSim t, char *n) {
    int i, hash = 0;
    for (i = 0; n[i] != 0; i++)
        hash = (hash * 251 + n[i]) % t.entriesNum;
    return hash;
}

/* Função que imprime os elementos da tabela de simbolos */
void imprime(TabSim t) {
    int i;
    for (i = 0; i < t.entriesNum; i++)
        imprimeL(t.htable[i]);
}
