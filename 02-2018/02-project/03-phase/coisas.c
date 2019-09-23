#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "coisas.h"
#include "avent.tab.h"
#include "comandos.h"

/* Variáveis globais */
TabSim* global  = NULL; /* Tabela de símbolos global */
TabSim* inventario = NULL; /* material com o aventureiro */
Aventureiro* aventureiro = NULL;

/* Inicializacao das salas */
Elemento segunda = {"Segunda-Feira", "Bem-vindo ao seu primeiro dia de break! Está tudo um pouco escuro, não?", "É seu primeiro dia de break. Sua missão hoje é estudar para prova de cálculo que está chegando.", 1, 1, 0, LUGAR, NULL, NULL, NULL, {"a", "da", "uma", "duma"}, NULL};
Elemento terca = {"Terça-Feira", "Você conseguiu vencer o primeiro dia. Será que consegue continuar?", "Você chegou ao segundo dia do break. Agora você precisa terminar seu EP de Algoritmos, para isso, resolva o problema e avance paro próximo dia.", 1, 1, 0, LUGAR,NULL, NULL, NULL, {"a", "da", "uma", "duma"}, NULL};
Elemento quarta = {"Quarta-feira", "Você chegou na metade do break",  "Você conseguiu resistir até o terceiro dia do break, mas lembra que tem uma lista de lógica pra fazer", 1, 1, 0, LUGAR, NULL, NULL, NULL, {"a", "da", "uma", "duma"}, NULL};
Elemento quinta = {"Quinta-Feira", "O fim se aproxima, você chegou longe!", "Está quase no fim, mas não está se esquecendo de nada? Você tem prova de Álgebra Linear na próxima semana.", 1, 1, 0,LUGAR, NULL, NULL, NULL, {"a", "da", "uma", "duma"}, NULL};
Elemento sexta = {"Sexta-Feira", "Vamos lá, você chegou longe!", "Você resistiu até agora. Será que ainda tem forças para a prova de TecProg?", 1, 1, 0, LUGAR, NULL, NULL, NULL, {"a", "da", "uma", "duma"}, NULL};
Elemento fim = {"Fim", "Parabéns, você chegou ao fim do break após muita dedicação!", "Parabéns, você chegou ao fim do break após muita dedicação!\nCréditos:\n \tLeandro Rodrigues\n \tÉdio Cerati Neto\n\tCaio Andrade\n\nDigite \"fim\" para encerrar", 1, 1 , 0, LUGAR, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento* atual = &segunda;

/* Objetos  */
Elemento interruptor = {"Interruptor", "O interruptor da lâmpada da sala", "Ao acender este interruptor você conseguirá ver mais detalhes na sala", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento guidorizzi = {"Guidorizzi", "Um livro de cálculo", "Um livro muito prático para você estudar para Cálculo e se preparar para sua prova", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento stewart = {"Stewart", "Num livro mais didático objetivo de cálculo", "Um livro muito mais intuitivo que pode ser melhor para seus estudos para a prova que está chegando", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento sedgewick = {"Sedgewick", "Um ótimo livro de algoritmos e estruturas de dados", "Um ótimo livro para você estudar algoritmos de ordenação que serão utilizados no EP", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento videogame = {"Videogame", "Seu videogame", "A possível maior causa da procrastinação. Será que usa-lo é melhor a se fazer?", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento anotacao = {"Anotação de lógica", "Um papel amassado com algumas anotações de lógica", "É um papel amassado contendo anotações sobre seu EP passado do Mundo de Wumpus, um problema clássico de Lógica", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento listaAlgLin = {"Lista de Álgebra Linear", "Os exercícios de AlgLin que você deve entregar semana que vem", "Até agora, um amontoado de rabiscos que não fazem muito sentido, você precisa estudar para tentar entender", 1, 1, 1, OBJ, NULL, NULL, NULL, {"a", "da", "uma", "duma"}, NULL};
Elemento iWoz = {"Livro iWoz", "Biografia de Steve Wozniak", "Biografia de Steve Wozniak indicada pelo professor Gubi. Talvez não seja muito útil, mas é um bom jeito de passar seu tempo", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento papel = {"Um papel amassado", "Um papel com um enigma: Faz sentido usar flex sem bison?", "Faz sentido usar flex sem bison?", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento celular = {"Celular", "Seu celular", "A possível maior causa da procrastinação. Será que pegá-lo é o melhor a se fazer?", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};
Elemento caderno_escolar = {"Caderno Escolar", "Um caderno util para suas atividades academicas!", "Esse caderno praticamente nao foi usado durante o ano e voce tem a esperança de usa-lo um pouco durante o break e ser produtivo!", 1, 1, 1, OBJ, NULL, NULL, NULL, {"o", "do", "um", "dum"}, NULL};

int yyparse();
TabSim* tab_global;

int main() {
    /* Declaracao do nome do arquivo de apresentacao do jogo */
    char* historia = "historia.txt";

    /* Inicializa Tabela de Símbolos */
    tab_global = cria(10);

    /* Alocacao de memoria das salas */
    segunda.conteudo = criaL();
    segunda.detalhe = malloc(sizeof(union detalhe));
    segunda.detalhe->lugar.saidas[0] = &terca; 
    segunda.detalhe->lugar.saidas[1] = NULL; 
    segunda.detalhe->lugar.saidas[2] = NULL; 
    segunda.detalhe->lugar.saidas[3] = NULL;
    segunda.detalhe->lugar.fechada = 0;

    terca.conteudo = criaL();
    terca.detalhe = malloc(sizeof(union detalhe));
    terca.detalhe->lugar.saidas[0] = &quarta; 
    terca.detalhe->lugar.saidas[1] = NULL; 
    terca.detalhe->lugar.saidas[2] = NULL; 
    terca.detalhe->lugar.saidas[3] = NULL;
    terca.detalhe->lugar.fechada = 0;

    quarta.conteudo = criaL();
    quarta.detalhe = malloc(sizeof(union detalhe));
    quarta.detalhe->lugar.saidas[0] = &quinta; 
    quarta.detalhe->lugar.saidas[1] = NULL; 
    quarta.detalhe->lugar.saidas[2] = NULL; 
    quarta.detalhe->lugar.saidas[3] = NULL;
    quarta.detalhe->lugar.fechada = 0;

    quinta.conteudo = criaL();
    quinta.detalhe = malloc(sizeof(union detalhe));
    quinta.detalhe->lugar.saidas[0] = &sexta; 
    quinta.detalhe->lugar.saidas[1] = NULL; 
    quinta.detalhe->lugar.saidas[2] = NULL; 
    quinta.detalhe->lugar.saidas[3] = NULL;
    quinta.detalhe->lugar.fechada = 0;

    sexta.conteudo = criaL();
    sexta.detalhe = malloc(sizeof(union detalhe));
    sexta.detalhe->lugar.saidas[0] = &fim; 
    sexta.detalhe->lugar.saidas[1] = NULL; 
    sexta.detalhe->lugar.saidas[2] = NULL; 
    sexta.detalhe->lugar.saidas[3] = NULL;
    sexta.detalhe->lugar.fechada = 0;

    fim.conteudo = criaL();
    fim.detalhe = malloc(sizeof(union detalhe));
    fim.detalhe->lugar.saidas[0] = NULL; 
    fim.detalhe->lugar.saidas[1] = NULL; 
    fim.detalhe->lugar.saidas[2] = NULL; 
    fim.detalhe->lugar.saidas[3] = NULL;
    fim.detalhe->lugar.fechada = 0;

    /* Alocação de Memória dos Objetos */
    interruptor.conteudo = criaL();
    interruptor.detalhe = malloc(sizeof(union detalhe));
    interruptor.detalhe->objeto.quantAdj = 1;
    interruptor.detalhe->objeto.adjetivos = malloc(interruptor.detalhe->objeto.quantAdj* sizeof(char*));
    interruptor.detalhe->objeto.adjetivos[0] = "fluorescente";

    guidorizzi.conteudo = criaL();
    guidorizzi.detalhe = malloc(sizeof(union detalhe));
    guidorizzi.detalhe->objeto.quantAdj = 3;
    guidorizzi.detalhe->objeto.adjetivos = malloc(guidorizzi.detalhe->objeto.quantAdj* sizeof(char*));
    guidorizzi.detalhe->objeto.adjetivos[0] = "desgastado";
    guidorizzi.detalhe->objeto.adjetivos[1] = "rasurado";
    guidorizzi.detalhe->objeto.adjetivos[2] = "mofado";

    stewart.conteudo = criaL();
    stewart.detalhe = malloc(sizeof(union detalhe));
    stewart.detalhe->objeto.quantAdj = 3;
    stewart.detalhe->objeto.adjetivos = malloc(stewart.detalhe->objeto.quantAdj* sizeof(char*));
    stewart.detalhe->objeto.adjetivos[0] = "novo";
    stewart.detalhe->objeto.adjetivos[1] = "jogado";
    stewart.detalhe->objeto.adjetivos[2] = "encapado";

    sedgewick.conteudo = criaL();
    sedgewick.detalhe = malloc(sizeof(union detalhe));
    sedgewick.detalhe->objeto.quantAdj = 1;
    sedgewick.detalhe->objeto.adjetivos = malloc(sedgewick.detalhe->objeto.quantAdj* sizeof(char*));
    sedgewick.detalhe->objeto.adjetivos[0] = "rasgado";

    videogame.conteudo = criaL();
    videogame.detalhe = malloc(sizeof(union detalhe));
    videogame.detalhe->objeto.quantAdj = 1;
    videogame.detalhe->objeto.adjetivos = malloc(sedgewick.detalhe->objeto.quantAdj* sizeof(char*));
    videogame.detalhe->objeto.adjetivos[0] = "desligado";

    anotacao.conteudo = criaL();
    anotacao.detalhe = malloc(sizeof(union detalhe));
    anotacao.detalhe->objeto.quantAdj = 1;
    anotacao.detalhe->objeto.adjetivos = malloc(anotacao.detalhe->objeto.quantAdj* sizeof(char*));
    anotacao.detalhe->objeto.adjetivos[0] = "amassada";

    listaAlgLin.conteudo = criaL();
    listaAlgLin.detalhe = malloc(sizeof(union detalhe));
    listaAlgLin.detalhe->objeto.quantAdj = 1;
    listaAlgLin.detalhe->objeto.adjetivos = malloc(listaAlgLin.detalhe->objeto.quantAdj* sizeof(char*));
    listaAlgLin.detalhe->objeto.adjetivos[0] = "amassada";

    iWoz.conteudo = criaL();
    iWoz.detalhe = malloc(sizeof(union detalhe));
    iWoz.detalhe->objeto.quantAdj = 2;
    iWoz.detalhe->objeto.adjetivos = malloc(iWoz.detalhe->objeto.quantAdj* sizeof(char*));
    iWoz.detalhe->objeto.adjetivos[0] = "novo";
    iWoz.detalhe->objeto.adjetivos[1] = "conservado";

    papel.conteudo = criaL();
    papel.detalhe = malloc(sizeof(union detalhe));
    papel.detalhe->objeto.quantAdj = 3;
    papel.detalhe->objeto.adjetivos = malloc(papel.detalhe->objeto.quantAdj* sizeof(char*));
    papel.detalhe->objeto.adjetivos[0] = "manchado";
    papel.detalhe->objeto.adjetivos[1] = "escrito";
    papel.detalhe->objeto.adjetivos[2] = "rasurado";

    celular.conteudo = criaL();
    celular.detalhe = malloc(sizeof(union detalhe));
    celular.detalhe->objeto.quantAdj = 1;
    celular.detalhe->objeto.adjetivos = malloc(papel.detalhe->objeto.quantAdj* sizeof(char*));
    celular.detalhe->objeto.adjetivos[0] = "carregado";
    
    caderno_escolar.conteudo = criaL();
    caderno_escolar.detalhe = malloc(sizeof(union detalhe));
    caderno_escolar.detalhe->objeto.quantAdj = 4;
    caderno_escolar.detalhe->objeto.adjetivos = malloc(caderno_escolar.detalhe->objeto.quantAdj* sizeof(char*));
    caderno_escolar.detalhe->objeto.adjetivos[0] = "novo";
    caderno_escolar.detalhe->objeto.adjetivos[1] = "util";
    caderno_escolar.detalhe->objeto.adjetivos[2] = "fino";
    caderno_escolar.detalhe->objeto.adjetivos[3] = "pequeno";

    /* Alocação de Memória do Aventureiro */
    aventureiro = malloc(sizeof(Aventureiro));
    aventureiro->aventureiro = malloc(sizeof(Elemento));
    aventureiro->mochila = criaL();
    aventureiro->nivel_stress = 0;

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


    /* Inserção dos objetos em outros elementos */
    segunda.conteudo = insereL(segunda.conteudo, &interruptor);
    segunda.conteudo = insereL(segunda.conteudo, &guidorizzi);
    segunda.conteudo = insereL(segunda.conteudo, &  stewart);

    terca.conteudo = insereL(terca.conteudo, &sedgewick);
    terca.conteudo = insereL(terca.conteudo, &videogame);

    quarta.conteudo = insereL(quarta.conteudo, &anotacao);

    quinta.conteudo = insereL(quinta.conteudo, &listaAlgLin);

    sexta.conteudo = insereL(sexta.conteudo, &iWoz);
    sexta.conteudo = insereL(sexta.conteudo, &papel);

    aventureiro->mochila = insereL(aventureiro->mochila, &caderno_escolar);
    aventureiro->mochila = insereL(aventureiro->mochila, &celular);

    /* Descrição inicial */
    imprime_arquivo(historia);

    /* Que comece o jogo */
    entrou_na_sala(&segunda);  
    while (yyparse());

    return 0; 
}