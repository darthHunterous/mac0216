#include <stdlib.h>
#include <stdio.h>
#include "comandos.h"
#include "estruturas.h"
#include "global.h"

int main() {
    /* Declaracao do nome do arquivo de apresentacao do jogo */
    char* historia = "historia.txt";

    /* Alocacao de memoria das salas */
    Elemento* segunda = malloc(sizeof(Elemento));
    Elemento* terca = malloc(sizeof(Elemento));
    Elemento* quarta = malloc(sizeof(Elemento));
    Elemento* quinta = malloc(sizeof(Elemento));
    Elemento* sexta = malloc(sizeof(Elemento));
    Elemento* fim = malloc(sizeof(Elemento));

    /* Definicao da primeira sala do jogo */
    Elemento* atual = segunda;

    /* Definicao, alocacao e insercao em lista das salas, elementos do jogo e seus respectivos atributos */
    segunda->nome = "Segunda-Feira";
    segunda->curta = "Bem-vindo ao seu primeiro dia de break! Está tudo um pouco escuro, não?";
    segunda->longa = "É seu primeiro dia de break. Sua missão hoje é estudar para a prova de cálculo que está chegando.";
    segunda->ativo = 1;
    segunda->visivel = 1;
    segunda->conhecido = 1;
    segunda->acoes = NULL;
    segunda->animacao = NULL;
    segunda->conteudo = criaL();

    Elemento* interruptor = malloc(sizeof(Elemento));
    interruptor->nome = "Interruptor";
    interruptor->curta = "O interruptor da lâmpada da sala";
    interruptor->longa = "Ao acender este interruptor você conseguirá ver mais detalhes na sala";
    interruptor->ativo = 1;
    interruptor->visivel = 1;
    interruptor->conhecido = 1;
    interruptor->acoes = NULL;
    interruptor->animacao = NULL;
    interruptor->conteudo = criaL();
    interruptor->artigos[0] = "o";
    interruptor->artigos[1] = "do";
    interruptor->artigos[2] = "um";
    interruptor->artigos[3] = "dum";
    interruptor->detalhe = malloc(sizeof(union detalhe));
    interruptor->detalhe->objeto.quantAdj = 1;
    interruptor->detalhe->objeto.adjetivos = malloc(interruptor->detalhe->objeto.quantAdj * sizeof(char*));
    interruptor->detalhe->objeto.adjetivos[0] = "fluorescente";

    Elemento* guidorizzi = malloc(sizeof(Elemento));
    guidorizzi->nome = "Guidorizzi";
    guidorizzi->curta = "Um livro de cálculo";
    guidorizzi->longa = "Um livro muito prático para você estudar para Cálculo e se preparar para sua prova";
    guidorizzi->ativo = 1;
    guidorizzi->visivel = 0;
    guidorizzi->conhecido = 1;
    guidorizzi->acoes = NULL;
    guidorizzi->animacao = NULL;
    guidorizzi->conteudo = criaL();
    guidorizzi->artigos[0] = "o";
    guidorizzi->artigos[1] = "do";
    guidorizzi->artigos[2] = "um";
    guidorizzi->artigos[3] = "dum";
    guidorizzi->detalhe = malloc(sizeof(union detalhe));
    guidorizzi->detalhe->objeto.quantAdj = 3;
    guidorizzi->detalhe->objeto.adjetivos = malloc(guidorizzi->detalhe->objeto.quantAdj * sizeof(char*));
    guidorizzi->detalhe->objeto.adjetivos[0] = "desgastado";
    guidorizzi->detalhe->objeto.adjetivos[1] = "rasurado";
    guidorizzi->detalhe->objeto.adjetivos[2] = "mofado";

    Elemento* stewart = malloc(sizeof(Elemento));
    stewart->nome = "Stewart";
    stewart->curta = "Um livro mais didático e objetivo de cálculo";
    stewart->longa = "Um livro muito mais intuitivo que pode ser melhor para seus estudos para a prova que está chegando";
    stewart->visivel = 0;
    stewart->conhecido = 1;
    stewart->acoes = NULL;
    stewart->animacao = NULL;
    stewart->conteudo = criaL();
    stewart->artigos[0] = "o";
    stewart->artigos[1] = "do";
    stewart->artigos[2] = "um";
    stewart->artigos[3] = "dum";
    stewart->detalhe = malloc(sizeof(union detalhe));
    stewart->detalhe->objeto.quantAdj = 3;
    stewart->detalhe->objeto.adjetivos = malloc(guidorizzi->detalhe->objeto.quantAdj * sizeof(char*));
    stewart->detalhe->objeto.adjetivos[0] = "novo";
    stewart->detalhe->objeto.adjetivos[1] = "jogado";
    stewart->detalhe->objeto.adjetivos[2] = "encapado";

    segunda->conteudo = insereL(segunda->conteudo, guidorizzi);
    segunda->conteudo = insereL(segunda->conteudo, stewart);
    segunda->artigos[0] = "a";
    segunda->artigos[1] = "da";
    segunda->artigos[2] = "uma";
    segunda->artigos[3] = "duma";
    segunda->detalhe = malloc(sizeof(union detalhe));
    segunda->detalhe->lugar.saidas[0] = terca; 
    segunda->detalhe->lugar.saidas[1] = NULL; 
    segunda->detalhe->lugar.saidas[2] = NULL; 
    segunda->detalhe->lugar.saidas[3] = NULL;
    segunda->detalhe->lugar.fechada = 0;

    terca->nome = "Terça-Feira";
    terca->curta = "Vocễ conseguiu vencer o primeiro dia. Será que consegue continuar?";
    terca->longa = "Você chegou ao segundo dia do break. Agora você precisa terminar seu EP de Algoritmos, \
    para isso, resolva o problema e avance para o próximo dia.";
    terca->ativo = 1;
    terca->visivel = 1;
    terca->conhecido = 1;
    terca->acoes = NULL;
    terca->animacao = NULL;
    terca->conteudo = criaL();

    Elemento* sedgewick = malloc(sizeof(Elemento));
    sedgewick->nome = "Sedgewick";
    sedgewick->curta = "Um ótimo livro de algoritmos e estruturas de dados";
    sedgewick->longa = "Um ótimo livro para você estudar algoritmos de ordenação que serão utilizados no EP";
    sedgewick->ativo = 1;
    sedgewick->visivel = 1;
    sedgewick->conhecido = 1;
    sedgewick->acoes = NULL;
    sedgewick->animacao = NULL;
    sedgewick->conteudo = criaL();
    sedgewick->artigos[0] = "o";
    sedgewick->artigos[1] = "do";
    sedgewick->artigos[2] = "um";
    sedgewick->artigos[3] = "dum";
    sedgewick->detalhe = malloc(sizeof(union detalhe));
    sedgewick->detalhe->objeto.quantAdj = 1;
    sedgewick->detalhe->objeto.adjetivos = malloc(sedgewick->detalhe->objeto.quantAdj * sizeof(char*));
    sedgewick->detalhe->objeto.adjetivos[0] = "rasgado";

    Elemento* videogame = malloc(sizeof(Elemento));
    videogame->nome = "videogame";
    videogame->curta = "Seu videogame";
    videogame->longa = "A possível maior causa da procrastinação. Será que usa-lo é o melhor a se fazer?";
    videogame->visivel = 1;
    videogame->conhecido = 1;
    videogame->acoes = NULL;
    videogame->animacao = NULL;
    videogame->conteudo = criaL();
    videogame->artigos[0] = "o";
    videogame->artigos[1] = "do";
    videogame->artigos[2] = "um";
    videogame->artigos[3] = "dum";
    videogame->detalhe = malloc(sizeof(union detalhe));
    videogame->detalhe->objeto.quantAdj = 1;
    videogame->detalhe->objeto.adjetivos = malloc(videogame->detalhe->objeto.quantAdj * sizeof(char*));
    videogame->detalhe->objeto.adjetivos[0] = "desligado";

    terca->conteudo = insereL(terca->conteudo, sedgewick);
    terca->conteudo = insereL(terca->conteudo, videogame);
    terca->artigos[0] = "a";
    terca->artigos[1] = "da";
    terca->artigos[2] = "uma";
    terca->artigos[3] = "duma";
    terca->detalhe = malloc(sizeof(union detalhe));
    terca->detalhe->lugar.saidas[0] = quarta;
    terca->detalhe->lugar.saidas[1] = NULL;
    terca->detalhe->lugar.saidas[2] = NULL;
    terca->detalhe->lugar.saidas[3] = NULL;
    terca->detalhe->lugar.fechada = 0;

    quarta->nome = "Quarta-feira";
    quarta->curta = "Você chegou na metade do break";
    quarta->longa = "Você conseguiu resistir até o terceiro dia do break, mas lembra que tem uma lista de lógica pra fazer";
    quarta->ativo = 1;
    quarta->visivel = 1;
    quarta->conhecido = 1;
    quarta->acoes = NULL;
    quarta->animacao = NULL;
    quarta->conteudo = criaL();

    Elemento* anotacao = malloc(sizeof(Elemento));
    anotacao->nome = "Anotação de lógica";
    anotacao->curta = "Um papel amassado com algumas anotações de lógica";
    anotacao->longa = "É um papel amassado contendo anotações sobre seu EP passado do Mundo de Wumpus, um problema clássico de Lógica";
    anotacao->ativo = 1;
    anotacao->visivel = 1;
    anotacao->conhecido = 1;
    anotacao->acoes = NULL;
    anotacao->animacao = NULL;
    anotacao->conteudo = criaL();
    anotacao->artigos[0] = "a";
    anotacao->artigos[1] = "da";
    anotacao->artigos[2] = "uma";
    anotacao->artigos[3] = "duma";
    anotacao->detalhe = malloc(sizeof(union detalhe));
    anotacao->detalhe->objeto.quantAdj = 1;
    anotacao->detalhe->objeto.adjetivos = malloc(anotacao->detalhe->objeto.quantAdj * sizeof(char*));
    anotacao->detalhe->objeto.adjetivos[0] = "amassada";

    quarta->conteudo = insereL(quarta->conteudo, anotacao);
    quarta->artigos[0] = "a";
    quarta->artigos[1] = "da";
    quarta->artigos[2] = "uma";
    quarta->artigos[3] = "duma";
    quarta->detalhe = malloc(sizeof(union detalhe));
    quarta->detalhe->lugar.saidas[0] = quinta;
    quarta->detalhe->lugar.saidas[1] = NULL;
    quarta->detalhe->lugar.saidas[2] = NULL;
    quarta->detalhe->lugar.saidas[3] = NULL;
    quarta->detalhe->lugar.fechada = 0;

    quinta->nome = "Quinta-feira";
    quinta->curta = "O fim se aproxima, você chegou longe!";
    quinta->longa = "Está quase no fim, mas não está se esquecendo de nada? Você tem prova de Álgebra Linear na próxima semana.";
    quinta->ativo = 1;
    quinta->visivel = 1;
    quinta->conhecido = 1;
    quinta->acoes = NULL;
    quinta->animacao = NULL;
    quinta->conteudo = criaL();

    Elemento* listaAlgLin = malloc(sizeof(Elemento));
    listaAlgLin->nome = "Lista de Álgebra Linear";
    listaAlgLin->curta = "Os exercícios de AlgLin que você deve entregar semana que vem";
    listaAlgLin->longa = "Até agora, um amontoado de rabiscos que não fazem muito sentido, você precisa estudar para tentar entender";
    listaAlgLin->ativo = 1;
    listaAlgLin->visivel = 1;
    listaAlgLin->conhecido = 1;
    listaAlgLin->acoes = NULL;
    listaAlgLin->animacao = NULL;
    listaAlgLin->conteudo = criaL();
    listaAlgLin->artigos[0] = "a";
    listaAlgLin->artigos[1] = "da";
    listaAlgLin->artigos[2] = "uma";
    listaAlgLin->artigos[3] = "duma";
    listaAlgLin->detalhe = malloc(sizeof(union detalhe));
    listaAlgLin->detalhe->objeto.quantAdj = 1;
    listaAlgLin->detalhe->objeto.adjetivos = malloc(listaAlgLin->detalhe->objeto.quantAdj * sizeof(char*));
    listaAlgLin->detalhe->objeto.adjetivos[0] = "amassada";

    quinta->conteudo = insereL(quinta->conteudo, listaAlgLin);
    quinta->artigos[0] = "a";
    quinta->artigos[1] = "da";
    quinta->artigos[2] = "uma";
    quinta->artigos[3] = "duma";
    quinta->detalhe = malloc(sizeof(union detalhe));
    quinta->detalhe->lugar.saidas[0] = sexta;
    quinta->detalhe->lugar.saidas[1] = NULL;
    quinta->detalhe->lugar.saidas[2] = NULL;
    quinta->detalhe->lugar.saidas[3] = NULL;
    quinta->detalhe->lugar.fechada = 0;

    sexta->nome = "Sexta-feira";
    sexta->curta = "O fim se aproxima, você chegou longe!";
    sexta->longa = "Está quase no fim, mas não está se esquecendo de nada? Você tem prova de Álgebra Linear na próxima semana.";
    sexta->ativo = 1;
    sexta->visivel = 1;
    sexta->conhecido = 1;
    sexta->acoes = NULL;
    sexta->animacao = NULL;
    sexta->conteudo = criaL();

    Elemento* iwoz = malloc(sizeof(Elemento));
    iwoz->nome = "Livro iWoz";
    iwoz->curta = "Biografia de Steve Wozniak";
    iwoz->longa = "Biografia de Steve Wozniak indicada pelo professor Gubi. Talvez não seja muito útil, mas é um bom jeito de passar seu tempo";
    iwoz->ativo = 1;
    iwoz->visivel = 1;
    iwoz->conhecido = 1;
    iwoz->acoes = NULL;
    iwoz->animacao = NULL;
    iwoz->conteudo = criaL();
    iwoz->artigos[0] = "o";
    iwoz->artigos[1] = "do";
    iwoz->artigos[2] = "um";
    iwoz->artigos[3] = "dum";
    iwoz->detalhe = malloc(sizeof(union detalhe));
    iwoz->detalhe->objeto.quantAdj = 2;
    iwoz->detalhe->objeto.adjetivos = malloc(iwoz->detalhe->objeto.quantAdj * sizeof(char*));
    iwoz->detalhe->objeto.adjetivos[0] = "novo";
    iwoz->detalhe->objeto.adjetivos[1] = "conservado";

    Elemento* papel = malloc(sizeof(Elemento));
    papel->nome = "Um papel amassado";
    papel->curta = "Um papel com um enigma escrito";
    papel->longa = "Como montar o frame para subrotinas em Assembly?";
    papel->ativo = 1;
    papel->visivel = 1;
    papel->conhecido = 1;
    papel->acoes = NULL;
    papel->animacao = NULL;
    papel->conteudo = criaL();
    papel->artigos[0] = "o";
    papel->artigos[1] = "do";
    papel->artigos[2] = "um";
    papel->artigos[3] = "dum";
    papel->detalhe = malloc(sizeof(union detalhe));
    papel->detalhe->objeto.quantAdj = 3;
    papel->detalhe->objeto.adjetivos = malloc(papel->detalhe->objeto.quantAdj * sizeof(char*));
    papel->detalhe->objeto.adjetivos[0] = "manchado";
    papel->detalhe->objeto.adjetivos[1] = "escrito";
    papel->detalhe->objeto.adjetivos[1] = "rasurado";

    sexta->conteudo = insereL(sexta->conteudo, iwoz);
    sexta->conteudo = insereL(sexta->conteudo, papel);
    sexta->artigos[0] = "a";
    sexta->artigos[1] = "da";
    sexta->artigos[2] = "uma";
    sexta->artigos[3] = "duma";
    sexta->detalhe = malloc(sizeof(union detalhe));    
    sexta->detalhe->lugar.saidas[0] = fim;
    sexta->detalhe->lugar.saidas[1] = NULL;
    sexta->detalhe->lugar.saidas[2] = NULL;
    sexta->detalhe->lugar.saidas[3] = NULL;
    sexta->detalhe->lugar.fechada = 0;

    aventureiro = malloc(sizeof(Aventureiro));
    aventureiro->aventureiro = malloc(sizeof(Elemento));
    aventureiro->aventureiro->nome = "Claudio Pereiras";
    aventureiro->aventureiro->curta = "Um questionador da sociedade atual";
    aventureiro->aventureiro->longa = "Claudio e' um estudante de Ciencia da Computação e quer estudar durante o Break. No entanto, ele deve vencer as procrastinações da sua vida. Será que ele consegue?";
    aventureiro->aventureiro->ativo = 1;
    aventureiro->aventureiro->visivel = 1;
    aventureiro->aventureiro->conhecido = 1;
    aventureiro->aventureiro->acoes = NULL;
    aventureiro->aventureiro->animacao = NULL;
    aventureiro->aventureiro->conteudo = criaL();
    aventureiro->aventureiro->artigos[0] = "o";
    aventureiro->aventureiro->artigos[1] = "do";
    aventureiro->aventureiro->artigos[2] = "um";
    aventureiro->aventureiro->artigos[3] = "dum";
    aventureiro->aventureiro->detalhe = malloc(sizeof(union detalhe));
    aventureiro->aventureiro->detalhe->objeto.quantAdj = 3;
    aventureiro->aventureiro->detalhe->objeto.adjetivos = malloc(aventureiro->aventureiro->detalhe->objeto.quantAdj * sizeof(char*));
    aventureiro->aventureiro->detalhe->objeto.adjetivos[0] = "Questionador";
    aventureiro->aventureiro->detalhe->objeto.adjetivos[1] = "Procrastinador";
    aventureiro->aventureiro->detalhe->objeto.adjetivos[2] = "Obstinado";
    aventureiro->nivel_stress = 0;
    aventureiro->mochila = criaL();
    
    Elemento* celular = malloc(sizeof(Elemento));
    celular->nome = "Celular";
    celular->curta = "Seu celular";
    celular->longa = "A possível maior causa da procrastinação. Será que pegá-lo é o melhor a se fazer?";
    celular->visivel = 1;
    celular->conhecido = 1;
    celular->acoes = NULL;
    celular->animacao = NULL;
    celular->conteudo = criaL();
    celular->artigos[0] = "o";
    celular->artigos[1] = "do";
    celular->artigos[2] = "um";
    celular->artigos[3] = "dum";
    celular->detalhe = malloc(sizeof(union detalhe));
    celular->detalhe->objeto.quantAdj = 1;
    celular->detalhe->objeto.adjetivos = malloc(celular->detalhe->objeto.quantAdj * sizeof(char*));
    celular->detalhe->objeto.adjetivos[0] = "carregado";

    Elemento* caderno_escolar = malloc(sizeof(Elemento));
    caderno_escolar->nome = "Caderno Escolar";
    caderno_escolar->curta = "Um caderno util para suas atividades academicas!";
    caderno_escolar->longa = "Esse caderno praticamente nao foi usado durante o ano e voce tem a esperança de usa-lo um pouco durante o break e ser produtivo!";
    caderno_escolar->ativo = 1;
    caderno_escolar->visivel = 1;
    caderno_escolar->conhecido = 1;
    caderno_escolar->acoes = NULL;
    caderno_escolar->animacao = NULL;
    caderno_escolar->conteudo = criaL();
    caderno_escolar->artigos[0] = "o";
    caderno_escolar->artigos[1] = "do";
    caderno_escolar->artigos[2] = "um";
    caderno_escolar->artigos[3] = "dum";
    caderno_escolar->detalhe = malloc(sizeof(union detalhe));
    caderno_escolar->detalhe->objeto.quantAdj = 4;
    caderno_escolar->detalhe->objeto.adjetivos = malloc(aventureiro->aventureiro->detalhe->objeto.quantAdj * sizeof(char*));
    caderno_escolar->detalhe->objeto.adjetivos[0] = "novo";
    caderno_escolar->detalhe->objeto.adjetivos[1] = "util";
    caderno_escolar->detalhe->objeto.adjetivos[2] = "fino";
    caderno_escolar->detalhe->objeto.adjetivos[3] = "pequeno";

    /* Sala final do jogo */
    fim->nome = "Fim do Break";
    fim->detalhe = malloc(sizeof(union detalhe));    
    fim->detalhe->lugar.fechada = 0;

    insereL(aventureiro->mochila, caderno_escolar);
    insereL(aventureiro->aventureiro->conteudo, celular);

    Lista animados = criaL();
    animados = insereL(animados, aventureiro->aventureiro);
    animados = insereL(animados, celular);
    
    /* Impressao da apresentacao */
    imprime_arquivo(historia);

    int retorno;

    /* Definicao de um array com objetos para teste */
    Elemento* objetos[5];
    objetos[0] = stewart;
    objetos[1] = videogame;
    objetos[2] = anotacao;
    objetos[3] = listaAlgLin;
    objetos[4] = iwoz;

    int i = 0;
    while (atual != fim) {
        entrou_na_sala(atual);

        printf("Testando a função 'acender'...\n");
        retorno = acender(atual, NULL);
        printf("\ta funçao acender retornou com valor %d\n\n", retorno);

        printf("Listando o conteudo da sala após a execucao de 'acender'...\n");
        imprime_conteudo(atual);

        printf("Testando todos os comandos...\n\n");

        printf("Testando a funçao pegar...\n");
        retorno = pegar(objetos[i], atual);
        printf("\ta função pegar retornou com valor %d\n\n", retorno);
        
        printf("Testando a função largar...\n");
        retorno = largar(objetos[i], atual);
        printf("\ta função largar retornou com valor %d\n\n", retorno);

        printf("Testando a função examinar...\n");
        retorno = examinar(objetos[i], NULL);
        printf("\ta função examinar retornou com valor %d\n\n", retorno);

        printf("Testando a função relaxar...\n");
        retorno = relaxar(NULL,NULL);
        printf("\ta função relaxar retornou com valor %d\n\n", retorno);

        printf("Testando as animacoes...\n\n");
        printf("Testando a animacao estressar...\n");
        printf("Nível de stress do aventureiro antes da execucao: %d\n", aventureiro->nivel_stress);
        estressar(aventureiro);
        printf("Nível de stress do aventureiro apos execucao: %d\n\n", aventureiro->nivel_stress);

        printf("Testando a animacao descarrega celular...\n"); 
        printf("Estado do celular antes da execucao: %s\n", celular->detalhe->objeto.adjetivos[0]);
        descarrega_celular(celular);
        printf("Estado do celular apos execucao: %s\n\n", celular->detalhe->objeto.adjetivos[0]);

        printf("Testando a função andar...\n");
        printf("Local atual: %s\n", atual->nome);
        retorno = andar(&atual, atual->detalhe->lugar.saidas[0]);
        printf("Local atual: %s\n", atual->nome);
        printf("\ta função retornou com valor %d\n", retorno);

        i++;
    }
    return 0;
}
