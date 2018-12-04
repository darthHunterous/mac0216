# Flex

### Regex em Flex
* **Exemplo - Placar Jogo de Futebol**
    * `BRA 987 X 1 ARG`
        * `^[A-Z]{3}[ \t]+[0-9]+[ \t]*[xX][ \t]*[0-9]+[ \t]+[A-Z]{3}$`
    * `^`: início
    * `[A-Z]{3}`: três letras maiúsculas
    * `[ \t]+`: ao menos um espaço ou tab
    * `[0-9]+`: ao menos um dígito
    * `[ \t]*`: espaços ou tabs não obrigatórios
    * `[xX]`: letras xis minúscula ou maiúscula
    * `[ \t]*`: espaços ou tabs não obrigatórios
    * `[0-9]+`: ao menos um dígito
    * `[ \t]+`: ao menos um espaço ou tab
    * `[A-Z]{3}`: três letras maiúsculas
    * `$`: fim

### Geral
* Flex gera um arquivo `lex.yy.c`, que define a função `yylex()`
* Compila-se e linka com a biblioteca `-lfl` para gerar o executável
* Analisa a entrada para ocorrência de uma dada expressão regular, executando o código em C correspondente

### Exemplos
* Scanner que ao encontrar "username", a troca pelo login do usuário
    ```c
    %%
    username    printf("%s", getlogin());
    ```
    * "username" é o **padrão**
    * printf é a **ação**
* Texto que não seja encontrado no padrão é copiado para a saída
* `%%` marca o começo da regra

### Exemplo - Contador de Caracteres e Linhas
```c
    int num_lines = 0, num chars = 0;
%%
\n  ++num_lines; ++num_chars;
.   ++num_chars;

%%
main() {
    yylex();
    printf("Number of lines = %d, Number of chars = %d\n", num_lines, num_chars);
}
```

### Exemplo - Scanner de Pascal
```c
%{
#include <math.h> /* Necessário para atof() */
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%

{DIGIT}+    {
            printf("Um inteiro: %s (%d) \n", yytext, atoi(yytext));
}

{DIGIT}+"."{DIGIT}*    {
            printf("Um float: %s (%g)\n", yytext, atof(yytext));
}

if|then|begin|end|procedure|function    {
            print("Uma palavra chave: %s\n", yytext);
}

{ID}        printf("Um identificador: %s\n", yytext);

"+"|"-"|"*"|"/"    printf("Um operador: %s\n", yytext);

"{"[^}\n]*"}"   /* remove comentários de uma linha */

[ \t\n]+        /* remove espaços em branco */

.           printf("Caracter não reconhecido: %s\n", yytext);

%%

main(argc, argv)
int argc;
char** argv;
    {
    ++argv, --argc;    /* pula o nome do programa */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;
    yylex();
    }
```

### Formato do Arquivo de Entrada
* Um arquivo `flex` contém três seções, separadas por linhas de `%%`
    ```c
    definições
    %%
    regras
    %%
    código_do_usuário
    ```
* **Definições:**
    * Declarações de definições simples de `nomes` para simplificar a especificação do scanner
        * `nome definição`
            * **nome**: palavra que começa com letra ou underscore , seguida por zero ou mais letras, dígitos, undescore ou traço
            * **definição:** começa no primeiro caracter não-whitespace após o nome, seguindo até o final da linha
        * `DIGIT   [0-9]`
            * Define DIGIT como uma regex que identifica um único dígito
        * A definição pode ser referenciada como `{name}`, que é expandida para `(definição)`
            * `{DIGIT}+"."{DIGIT}+` equivale a `([0-9]+"."([0-9])*`
    * Declarações das `condições iniciais`
* **Regras:**
    * Da forma `padrão ação`
        * `padrão` sem identação e `ação` começa na mesma linha
    * Qualquer texto identado ou representado por `%{}` antes da primeira regra pode ser usado para declarar variáveis locais à rotina de scan e código a ser executado quando a rotina começa
* **Código do Usuário:** copiado para `lex.yy.c` letra por letra (verbatim)
    * Presença dessa seção é opcional

### Padrões
* `'x'`: reconhece o caracter 'x'
* `'.'`: qualquer caracter except newline
* `[xyz]`: classe de caracteres que reconhece qualquer um dos três caracteres
* `[abj-oZ]`: classe de caracteres com um faixa aceita, reconhece de 'j' a 'o', além dos outros
* `[^A-Z]`: negação da classe, reconhece qualquer caracter fora dela
* `r*`: zero ou mais expressões regulares `r`
* `r+`: um ou mais `r`
* `r?`: r opcional, um ou zero
* `r{2,5}`: de dois a cinco r's (intervalo incluso)
* `r{2,}`: dois ou mais r's
* `r{4}`: exatamente quatro r's
* `{nome}`: expansão da `definição` de `nome`
* `"[xyz]\"foo`: pega a string `"[xyz]"foo`
* `\*`: escapa o caracter "*", pode ser usado com qualquer outro
* `\0`: caracter ASCII nulo (código zero)
* `\123`: caracter de valor octal 123
* `\x2a`: caracter de valor hexadecimal 2a