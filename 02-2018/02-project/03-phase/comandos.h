#ifndef __COMANDOS_H__
#define __COMANDOS_H__

#include "estruturas.h"

typedef void (*ANIPTR)(Aventureiro*);

void imprime_arquivo(char* nome);
void apresenta_descricao(Elemento* atual);
void imprime_conteudo(Elemento* sala);
void entrou_na_sala(Elemento* sala);
int acender(Elemento* sala, Elemento* nulo);
int pegar(Elemento* objeto, Elemento* sala);
int examinar(Elemento* objeto, Elemento* nulo);
int largar(Elemento* objeto, Elemento* sala);
int andar(Elemento** atual, Elemento* destino);
int relaxar(Elemento* nulo1, Elemento* nulo2);
void estressar(Aventureiro* aventureiro);
void descarrega_celular(Elemento* celular);

#endif
