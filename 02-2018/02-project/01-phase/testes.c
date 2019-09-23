#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

int main() {
    /* Testes para funcao cria Lista */
    printf("Testando a funcao cria Lista\n");
    Lista testeL = criaL();

    if (testeL.cabec->next == NULL)
        printf("\ta Lista foi inicializada corretamente\n");

    printf("\n");

    /* Testes para funcao insereL */
    printf("Testando insercao na lista\n");
    Elemento *elem1 = malloc(sizeof(Elemento));
    Elemento *elem2 = malloc(sizeof(Elemento));
    Elemento *elem3 = malloc(sizeof(Elemento));

    strcpy(elem1->N, "projeto");
    strcpy(elem2->N, "tecprog");
    strcpy(elem3->N, "adventure");

    printf("\telementos na lista vazia:\t");
    imprimeL(testeL);

    testeL = insereL(testeL, elem1);
    printf("\telementos na lista:\t");
    imprimeL(testeL);

    testeL = insereL(testeL, elem2);
    printf("\telementos na lista:\t");
    imprimeL(testeL);
    
    testeL = insereL(testeL, elem3);
    printf("\telementos na lista:\t");
    imprimeL(testeL);

    printf("\n");

    /* Testes para funcao busca */
    printf("Testando busca na lista\n");
    Elemento *aux = buscaL(testeL, "inexistente");
    printf("\tBuscando uma entrada inexistente na lista\n");
    if (aux == NULL)
        printf("\t\tA chave \"inexistente\" nao esta presente na lista\n");
    printf("\tBuscando a chave \"tecprog\" na lista: ");
    imprimeL(testeL);
    aux = buscaL(testeL, elem2->N);
    printf("\t\tElemento encontrado: %s\n", elem2->N);
    printf("\tChecando que a lista nao foi alterada: ");
    imprimeL(testeL);

    printf("\n");

    /* Testes para funcao retiraL */
    printf("Testando remocao da lista\n");
    printf("\telementos na lista:\t");
    imprimeL(testeL);

    printf("\n");
    aux = retiraL(testeL, elem3);
    printf("\telementos removido:\t%s\n", aux->N);
    printf("\telementos na lista:\t");
    imprimeL(testeL);
    

    printf("\n");
    aux = retiraL(testeL, elem1);
    printf("\telementos removido:\t%s\n", aux->N);
    printf("\telementos na lista:\t");
    imprimeL(testeL);

    printf("\n");
    aux = retiraL(testeL, elem2);
    printf("\telementos removido:\t%s\n", aux->N);
    printf("\telementos na lista:\t");
    imprimeL(testeL);

    printf("\n");

    /* Testes para funcao destroi Lista */
    printf("Testando a funcao destroi Lista\n");

    testeL = insereL(testeL, elem1);
    testeL = insereL(testeL, elem2);
    testeL = insereL(testeL, elem3);

    printf("\tLista antes da destruicao: ");
    imprimeL(testeL);

    printf("\tDesalocando lista...\n");
    destroiL(testeL);
    if (testeL.cabec->next == NULL)
        printf("\t\tA lista foi desalocada corretamente\n\n");


    /* Testes para funcao cria TabSim */
    printf("Testando a funcao cria TabSim\n");

    TabSim teste = cria(10);

    printf("\tnumero de listas ligadas == %d\n", teste.entriesNum);
    printf("\tnumero de elementos na tabela == %d\n", teste.num);

    int i;
    for (i = 0; i < teste.entriesNum; i++)
        if (teste.htable[i].cabec == NULL)
            printf("\tlista %d esta NULL nessa inicializacao\n", i);

    printf("\n");

    /* Testes para funcao hash_string */
    printf("Testando a funcao hash_string\n");
    printf("\thash da string \"projeto\" == %d\n", hash_string(teste, "projeto"));
    printf("\thash da string \"tecprog\" == %d\n", hash_string(teste, "tecprog"));
    printf("\thash da string \"adventure\" == %d\n", hash_string(teste, "adventure"));

    printf("\n");

    /* Testes para inserir elementos na TabSim */
    printf("Testando a funcao de insercao na Tabela\n");
    printf("\tEstagio atual da tabela:\n");
    imprime(teste);

    printf("\tInserindo \"projeto\" de hash valor 01:\n");
    Elemento *test1 = malloc(sizeof(Elemento));
    int retorno = insere(teste, elem1->N, test1);
    if (!retorno)
        imprime(teste);
    
    printf("\tInserindo \"tecprog\" de hash valor 06:\n");
    Elemento *test2 = malloc(sizeof(Elemento));
    retorno = insere(teste, elem2->N, test2);
    if (!retorno)
        imprime(teste);

    printf("\tInserindo \"adventure\" de hash valor 04:\n");
    Elemento *test3 = malloc(sizeof(Elemento));
    retorno = insere(teste, elem3->N, test3);
    if (!retorno)
        imprime(teste);
    
    printf("\tA tentativa de reinsercao de um elemento nao provoca erros:\n");
    printf("\tReinsercao de \"projeto\":\n");
    retorno = insere(teste, elem1->N, test1);
    if (!retorno)
        imprime(teste);
    
    /* Teste da funcao Busca na TabSim */
    printf("\nTestando funcao busca na tabela de simbolos\n");
    printf("\tA busca por \"projeto\" deve retornar ao qual foi associado\n");
    printf("\tPortanto, o elemento associado tem valor: %s\n\n", busca(teste, elem1->N)->N);

    /* Teste da funcao retira da TabSim */
    printf("Testando funcao retira da Tabela de Simbolos\n");
    printf("\tRetirando \"projeto\":\n");
    retorno = retira(teste, elem1->N);
    if (!retorno)
        imprime(teste);
    
    printf("\n");

    /* Teste de desalocacao da TabSim */
    printf("Desalocando a tabela de simbolos\n");
    destroi(teste);

    /* Todos os modulos do programa foram testados acima 
    Desalocando, portanto memoria alocada para os testes abaixo */
    free(elem1);
    free(elem2);
    free(elem3);

    free(test1);
    free(test2);
    free(test3);

    elem1 = NULL;
    elem2 = NULL;
    elem3 = NULL;

    test1 = NULL;
    test2 = NULL;
    test3 = NULL;
}
