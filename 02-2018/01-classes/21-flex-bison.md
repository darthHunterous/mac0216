# Aula 21- Flex e Bison

### Flex - Código do Usuário (Seção do Fim)
* Função main() do seu programa e de outras funções necessárias
* Todo código nessa seção junto com o que é colocando entre `%{ %}` é copiado para o arquivo de saída gerado pelo Flex
* Seção opcional, na ausência dela não é necessário colocar o separado `%%` correspondente

### Flex - Regras (Seção do Meio)
* Definem os tipos léxicos entendidos pelo analisador
* Flex usa tais regras para gerar código do analisador
* Uma **regra** é um par `[padrão - ação]`
* **Padrão:** definido por Regex
* **Ação:** trecho de código em C
    * Executada sempre que o analisador léxico encontrar no texto de entrada uma cadeia que casa com o padrão associado
* **Formato:** `[padrão] [ação]`
    * Novo padrão sempre em uma nova linha, sem indentação
    * Definição da ação tem que começar na mesma linha

### Flex - Exemplo
* Código que gera um programa que conta linhas e caracteres de um texto da entrada padrão
```flex
%{
int contLinhas = 0, contCaracteres = 0;
%}

%%
\n      ++contLinhas; ++contCaracteres;
.       ++contCaracteres;
<<EOF>> yyterminate();

%%
main() {
    yylex();
    printf("Linhas: %d, Chars: %d\n", contLinhas, contCaracteres);
}
```

### Flex - Como Usar
* Executar Flex com um arquivo de entrada contendo as regras
    * `flex contlc.lex`
* Flex gera como saída um arquivo `lex.yy.c`, contendo o código fonte do analisador léxico
* Função `yylex()` faz a análise léxica, portanto sendo sempre chamada na main
* Compilar arquivo `lex.yy.c` e o ligar à biblioteca do Flex (`libfl`) para gerar programa analisador
    * `gcc lex.yy.c -o contlc -lfl`

### Flex - Variáves Internas
* `char *yytext`: apontador para cadeia de caracteres com último item reconhecido
* `int yyleng`: comprimento do último item reconhecido
* `FILE *yyin`: descritor do arquivo de entrada processado

### Flex - Exemplo
* Contador de linhas, palavras e caracteres de um arquivo passado via linha de comando
```c
%{
int contChar = 0, contPalavra = 0, contLinha = 0;
%}

EOL        \n
PALAVRA    [^ \n\t]+

%%
{PALAVRA}    {contPalavra++; contChar += yyleng;}
{EOL}        {contChar++; contLinha++;}
.            {contChar++;}

%%
int main(int argc, char** argv) {
    yyin = fopen(argv[1], "r");    /* abre arquivo entrada */
    yylex();                       /* executa scanner */
    printf("Linhas: %d, Palavras: %d, Chars: %d\n", contLinha, contPalavra, contChar);
    fclose(yyin);    /* fecha arquivo de entrada */
}
```

### Flex - Regex
* Similar às regexes estendidas do Unix e AWK, com algumas novidades
* `{nome}`: expande a definição do nome
* `"[xyz]\"foo"`: string literal '[xyz]"foo'
* `\123`: caracter com código octal 123
* `\x2a`: caracter com código hex 2A
* `r/s`: um r só se for sucedido por s. s é verificado pela regra mas não consumido da entrada
* `<<EOF>>`: fim do arquivo
* `<c>r`: um r somente na condição de início c
* `<c1,c2,c3>r`: um r em qualquer uma das condições c1, c2 ou c3
* `<*>r`: um r em qualquer condição de início (até nas exclusivas)
* Considerar **r** e **s** regexes

### Flex - Condições de Início
* Flex tem mecanismos para habilitação condicional de regras
* Regras condicionais são habilitadas por uma **condição de início**
* **Condições de início para regras adicionais:** habilitam conjunto de regras executadas adicionalmente às regras não condicionais
* **Condições de início para regras exclusivas:** habilitam conjunto de regras executados de forma exclusiva (demais regras fora do conjunto não são executadas)

### Flex - Exemplo de Condições de Início
* Declaração de uma condição de início para regras exclusivas
    ```c
    %x STRING

    %%
    \""  {
          printf(" string ");
          /* habilita todas regras que começam com <STRING> */
          BEGIN(STRING);
    }
    <STRING>[^""]  ; /* nenhuma ação para um caracter aspas */
    <STRING>\""     {
                      /* desabilita a condição de início STRING */
                      BEGIN(INITIAL);
                    }
    ```