#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "global.h"

typedef void (*APR_DSC)(Elemento*);

void apresenta_descricao(Elemento* atual) {
    /* Funcao que imprime a descricao da sala */
    if (atual == NULL)
        fprintf(stderr, "A sala atual nao e' valida");
    if (atual->conhecido)
        printf("%s\n", atual->curta);
    else
        printf("%s\n", atual->longa);
}

void imprime_conteudo(Elemento* sala) {
    /* Funcao que imprime os objetos visiveis da sala */
    struct elo* aux = sala->conteudo.cabec->next;
    while (aux != NULL) {
        if (aux->val->visivel)
            printf("\t%s %s\n", aux->val->artigos[2], aux->val->nome);
        aux = aux->next;
    }
    printf("\n");
}

void imprime_arquivo(char* nome) {
    /* Funcao que imprime a historia a partir do arquivo txt" */
    FILE* arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo\n");
    }

    char c = fgetc(arquivo);

    while (c != EOF) {
        printf("%c", c);
        c = fgetc(arquivo);
    }
    printf("\n\n");
    fclose(arquivo);
}

void entrou_na_sala(Elemento* sala) {
    /* Funcao que chama as funções necessarias para quando o aventureiro entra na sala */
    apresenta_descricao(sala);
    imprime_conteudo(sala);
}

int acender(Elemento* sala, Elemento* nulo) {
    /* Funcao que acende a luz da sala e torna os objetos visiveis */
    struct elo *aux = sala->conteudo.cabec->next;
    while (aux != NULL) {
        if (aux->val->conhecido)
            aux->val->visivel = 1;
        aux = aux->next;
    }
    return 0;
}

int pegar(Elemento* objeto, Elemento* sala){
    /* Funcao que coloca um objeto da sala na mochila do aventureiro */
    if (buscaL(sala->conteudo, objeto->nome) == NULL){
        printf("%s %s não está na sala...\n", objeto->artigos[0], objeto->nome);
        return 1;
    }
    else {
        aventureiro->mochila = insereL(aventureiro->mochila, objeto);
        retiraL(sala->conteudo, objeto);
        printf("Voce pegou %s %s!\n", objeto->artigos[0], objeto->nome);
        return 0;
    }
}

int examinar(Elemento* objeto, Elemento* nulo) {
    /* Funcao que apresenta a descricao do objeto */
    if (objeto->conhecido)
        printf("%s\n", objeto->curta);
    else{
        printf("%s\n", objeto->longa);
        objeto->conhecido = 1;
    }
    return 0;
}

int largar(Elemento* objeto, Elemento* sala) {
    /* Funcao que move um objeto da mochila do aventureiro para a sala */
    if (buscaL(aventureiro->mochila, objeto->nome) == NULL){
        printf("Este objeto não está na sua mochila...\n");
        return 1;
    }
    else {
        retiraL(aventureiro->mochila, objeto);
        insereL(sala->conteudo, objeto);
        printf ("Voce largou %s %s!\n", objeto->artigos[0], objeto->nome);
        return 0;
    }
}

int andar(Elemento** atual, Elemento* destino) {
    /* Funcao que atualiza a posicao do aventureiro no jogo */
    if (destino == NULL) {
        printf("Não há saída nessa direção...\n");
        return 1;
    }
    if (destino->detalhe->lugar.fechada) {
        printf("A saída está fechada...\n");
        return 1;
    }
    *atual = destino;
    return 0;
}

int relaxar(Elemento* nulo1, Elemento* nulo2) {
    /* Funcao que decrementa o nivel de stress do aventureiro */
    if (aventureiro->nivel_stress > 0){
        aventureiro->nivel_stress--;
        printf("Você toma um suquinho de laranja, e dá uma relaxada dos estudos...\n");
        return 0;
    }
    else {
        printf("Você não está estressado para relaxar!\n");
        return 1;
    }
    
}
