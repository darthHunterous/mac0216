#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

/* Função que inicializa uma lista ligada com cabeca */
Lista criaL() {
    Lista l;
    struct elo *aux = malloc(sizeof(struct elo));
    l.cabec = aux;
    aux->val = NULL;
    aux->next = NULL;

    return l;
}

/* Função que recebe uma lista e desaloca memória utilizada por ela */
void destroiL(Lista l) {
    struct elo *atual = l.cabec->next;

    if (atual == NULL)
        return;
        
    struct elo *proximo = atual->next;
    
    while (proximo != NULL) {
        free(atual);
        atual = proximo;
        proximo = atual->next;
    }
    atual = NULL;
    proximo = NULL;
    l.cabec->next = NULL;
}

/* Função que insere um elemento novo a lista */
Lista insereL(Lista l, Elemento* val) {
    struct elo *aux = l.cabec->next;
    struct elo *novoElo = malloc(sizeof(struct elo));
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
    struct elo *atual = l.cabec->next;
    while (atual != NULL) {
        if (strcmp(atual->val->nome, n) == 0)
            return atual->val;
        atual = atual->next;
    }
    return NULL;
}

/* Função que remove um elemento da lista */
Elemento *retiraL(Lista l, Elemento *val) {
    struct elo *atual = l.cabec->next;
    struct elo *aux;

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
    struct elo *aux = l.cabec->next;

    while (aux != NULL) {
        printf("%s ", aux->val->nome);
        aux = aux->next;
    }
    printf("NULL\n");
}

/* Retorna 1 para lista vazia e zero se há algum elemento */
int vaziaL(Lista l) {
    if (l.cabec->next == NULL)
        return 1;
    return 0;
}

