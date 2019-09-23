/* Calculadora infixa */

%{
#include <stdio.h>
#include "estruturas.h"
#include "coisas.h"
#include "comandos.h"

int yylex();
int yyerror(char *);

/* Macro para simplificar a escrita das chamadas de função */
#define F(x) (*(Fptr)(x->acoes))
#define YYDEBUG 1

/* Identifica qual a versão correta do verbo chamado */
Elemento* AcertaF(Elemento *f, Elemento *o1) {
  Elemento *s;

  /* Verifica se existe uma versão especial no local atual */
  if ((s = buscaL(atual->conteudo, f->nome)))
		return s;

  /* Verifica se o primeiro objeto tem uma versão especial */
  if (o1) {
		if ((s = buscaL(o1->conteudo, f->nome)))
	  	return s;
  }
  return f;	
}
%}

/* Declaracoes */
%union {
  Elemento *tptr;
  char *str;
  int  direc;
}

%token <tptr> VERBO OBJ LUGAR

/* DESC representa uma palavra desconhecida */
%token <str> DESC
%token  NORTE SUL LESTE OESTE VAPARA EOL FIM INVENT PEGAR EXAMINAR LARGAR ACENDER RELAXAR

%type <direc> dir
%type <tptr> obj

%defines

%%
/* Gramatica */


input: EOL		{ printf("Zzzz...\n"); }
    | cmd
	| VAPARA  {
	  		   /* movimentação */
	  		   printf("Seguindo para ");
	  		  }
			  dir {
					if ($3 >= 0 && atual->detalhe->lugar.saidas[$3]) {
					  atual = atual->detalhe->lugar.saidas[$3];
					  entrou_na_sala(atual);
					}
					else puts("Não há passagem....");
			      } eol
	 | dir {
			 /* movimentação  */
             if ($1 >= 0 && atual->detalhe->lugar.saidas[$1]) {
			   atual = atual->detalhe->lugar.saidas[$1];
			   printf("\nVocê foi para %s %s\n", atual->artigos[0], atual->nome);
			   entrou_na_sala(atual);
			}
			 else puts("Não há passagem....");
			} eol

	| INVENT {
			 /* listagem do inventário */
			 if (!vaziaL(aventureiro->mochila)) {
			   puts("Você tem:");
			   imprimeL(aventureiro->mochila);
			 }
			 else puts("Você está sem nada no momento...");
												
		 } eol
	| FIM  { return 0;}
	| DESC { puts("Não tem registro, Will Robinson.");}
	| error eol;
;

cmd: VERBO {
			 /* Intransitivo */
  	 	     F(AcertaF($1,NULL))(NULL,NULL);
		   } eol
   | VERBO obj {
			   /* Transitivo direto */
			   F(AcertaF($1,$2))($2->acoes,NULL);
			 } eol 
   | VERBO obj obj {
                 /* Bitransitivo */
			     F(AcertaF($1,$2))($2->acoes,$3->acoes);
			   } eol
   | VERBO DESC {
			     printf("%s??\n", $2);
			 } eol 
   | VERBO obj DESC {
			   printf("não sei o que é isso: %s\n",  $3);
			   } eol 
   | VERBO DESC DESC {
			     printf("Pare de jogar e vá descansar um pouco\n"
						"Fazer isso com %s e %s, que coisa\n", $2,$3
						);
			   } eol 
;

obj: OBJ    { $$ = $1;}
   | LUGAR  { $$ = $1;};

dir: NORTE	  { $$=0; }
	 | SUL	  { $$=1; }
	 | LESTE  { $$=2; }
	 | OESTE  { $$=3; }
	 | DESC   { puts("... (onde é isso?)"); $$=-1;}
;

eol: EOL {return 1;}
%%

int yyerror(char *s) {
  puts("Não entendi...");
  return 0;
}
