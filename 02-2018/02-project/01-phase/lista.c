#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

/* Função que inicializa uma lista ligada com cabeca */
Lista criaL() {
    Lista l;
    Elo *aux = malloc(sizeof(Elo));
    l.cabec = aux;
    aux->val = NULL;
    aux->next = NULL;

    return l;
}

/* Função que recebe uma lista e desaloca memória utilizada por ela */
void destroiL(Lista l) {
    Elo *atual = l.cabec->next;

    if (atual == NULL)
        return;
        
    Elo *proximo = atual->next;
    
    while (proximo != NULL) {
        free(atual);
        atual = proximo;
        proximo = atual->next;
    }
    atual = NULL;
    proximo = NULL;
    l.cabec->next = NULL;
}

/* Função que inserece um elemtno novo a lista */
Lista insereL(Lista l, Elemento *val) {
    Elo *aux = l.cabec->next;
    Elo *novoElo = malloc(sizeof(Elo));

    /* Seria mais adequado retorna NULL
    Porem, como a especificacao retorna a estrutura Lista e nao um ponteiro, nao e' possivel fazer isso */
    if (novoElo == NULL) {
        fprintf(stderr, "%s", "malloc falhou em alocar memoria");
        exit(1);
    }

    l.cabec->next = novoElo;
    novoElo->next = aux;
    novoElo->val = val;
    
    return l;
}

/* Função que procura um elemento na lista */
Elemento *buscaL(Lista l, char *n) {
    Elo *atual = l.cabec->next;
    while (atual != NULL) {
        if (strcmp(atual->val->N, n) == 0)
            return atual->val;
        atual = atual->next;
    }
    return NULL;
}

/* Função que remove um elemento da lista */
Elemento *retiraL(Lista l, Elemento *val) {
    Elo *atual = l.cabec->next;
    Elo *aux;

    if (atual->val == val) {
        l.cabec->next = atual->next;
        return atual->val;
    }

    while (atual->next != NULL && atual->next->val != val)
        atual = atual->next;
    
    if (atual->next == NULL)
        return NULL;
    else {
        aux = atual->next;
        atual->next = aux->next;
        return aux->val;
    }
}

/* Função que imprime a lista */
void imprimeL(Lista l) {
    Elo *aux = l.cabec->next;

    while (aux != NULL) {
        printf("%s ", aux->val->N);
        aux = aux->next;
    }
    printf("NULL\n");
}
