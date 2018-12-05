# Aula 22 - Flex e Bison

### Geradores de Analisadores Sintáticos
* UNIX originalmente com YACC - Yet Another Compiler Compiler
    * Gera **analisador sintático** (parser) a partir da especificação de uma gramáticas
* **GNU Bison**, implementação da FSF (Free Software Foundation) para o YACC, compatível com ele, mas com mais funcionalidades
    * Possibilidade de criação de programas simples interativos, como calculadoras, a analisadores de linguagens de programação

## GNU Bison
* Recebe com entrada especificação de gramática no formato BNF (Backus Naur Form)
* Na definição de uma gramática formal, cada unidade sintática é associada a um símbolo
* **Símbolos Não-Terminais:** definidos a partir do agrupamento de símbolos menores
* **Símbolos Terminais:** símbolos que não podem ser subdivididos
* **Exemplos em C**
    * Símbolos não terminais: expressão, sentença, declaração e definição de função
    * Símbolos terminais: identificador, número, string, if, while, do, for, continue, break, return, cont, static, int, char, float, double, +, -, *, /, %, &, &&, =, ==, {, }, [, ], ", ', etc

### Gramática da Calculadora Infixa da Aula 16
* `<programa> ::= <programa><expr> ; | <expr> ;`
* `<expr> ::= <expr> + <termo> | <expr> - <termo> | <termo>`
* `<termo> ::= <termo> * <fator> | <termo> / <fator> | <fator>`
* `<fator> ::= NUMERO | -<fator> | (<expr>) | K[<expr>] | K[<expr>] := <expr>`

### Bison - Estrutura da Entrada
* Análogo a Flex
    ```bison
    %{
        Prólogo
    }
    Declarações do Bison
    %%
    Regras Gramaticais
    %%
    Epílogo
    ```
* **Prólogo:** definições iniciais em C, jogadas diretamente para o arquivo de saída do Bison, antes da função `yyparse()` (analisador sintático em si)
* **Declarações do Bison:** definidos símbols terminais e não-terminais e relações de precedência. Pode ser deixado vazio em gramáticas mais simples
* **Regras Gramaticais:** coração do arquivo, faz-se obrigatório ter ao menos uma regra gramatical
* **Epílogo:** copiado letra por letra para o arquivo de saída

### Descrição da Gramática no Bison - Símbolos
* Símbolo não terminal é representado por um identificador
    * Por convenção, apenas letras minúsculas, como `expressao`, `comando`, `declaracao`
* Símbolo terminal (token) representado por:
    * Identificador. Para diferenciar dos símbolos não-terminais, usa se letras maiúsculas como `INTEIRO`, `IDENTIFICADOR`, `RETURN`
    * Caracter Literal. (quando token se refere a um único caracter como abre ou fecha parênteses)
    * String literal como "<=" ou ":="

### Descrição da Gramática no Bison - Regras
* **Formato geral**:
    * `resultado: componentes...;`
        * Resultado é um não-terminal
        * `exp: exp '+' exp;`
* Múltiplas regras podem ser escritas separadamente ou unidas por "|"
    * `resultado: componentes-regra1 | componentes-regra2 | ... ;`
    * `exp: exp '+' exp | NUMERO;`

### Valor Semântico
* Para ser útil, o programa tem que gerar alguma saída, além de analisar a sintaxe da entrada
* Para gerar saída, é necessário definir a semântica (significado) do que se está processando
* Para um compilador, a saída se dá em uma outra linguagem, como linguagem de montagem por exemplo
* No caso de uma calculadora, a saída é o resultado

### Símbolos - Tipo e Valor Semântico
* Cada token reconhecido em um parser além de ter um tipo (símbolo não-terminal) tem valor semântico associado a ele
    * Expressão "1+2" possui 2 tokens de mesmo tipo (INTEIRO ou NUMERO) mas com valores semânticos diferentes
    * Podemos atribuir como valor semântico para a expressão "1+2" o valor 3

### Bison - Atribuição de Valor Semântico
* Cada regra pode ser seguida de ação que define o que fazer quando ela é detectada
    * `expr: expr '+' expr  { $$ = $1 + $3; }`
    * Define que o valor de expr é a soma das duas sub-expressões
* Tipos dos valores semânticos são definidos na seção *Declarações do Bison*, primeira parte do arquivo de entrada
    * Também devem ser definidos símbolos para a definição da gramática

### Bison - Regras e Ações
* **Ação:** código em C delimitado por `{ }`
* A ação pode ser colocada em qualquer posição da regra. A maior parte das regras possuem única ação, no final
* Ações definidas no meio de uma regra são usada somente em contextos especiais por serem complicadas
* Quando uma ação não é definida, o Bison fornece ação padrão: `$$ = $1`, o valor do primeiro símbolo na regra é o valor da regra inteira

### Criando Analisador Sintático
* Especificar a gramático em um .y, descrevendo a ação para cada regra gramatical
* Escrever analisador léxico para fornecer itens léxicos (tokens) para o Bison, manualmente ou via Flex
* Escrever uma função para chamar a `yyparse()` gerada pelo Bison
* Escrever opcionalmente funções relatando erros

### Gerar código, compilar e executar analisador sintático
* Arquivos do Bison (`.y`) são processados e geram arquivos `.tab.c`
* `.tab.c` são compilados pelo gcc para gerar executável
* O executável processa arquivo de entrada, gera árvore sintática do programa e executa os comandos associados à gramática

### Exemplos com Calculadoras
* Calculadora Polonesa Simples
* Calculadora Infixa
* Calculadora com variáveis e Funções
* Explicações no [manual](http://www.gnu.org/software/bison/manual/html_node/Examples.html#Examples) do Bison
* Exemplos acima em ordem crescente de dificuldade

### Bibliografia e Materiais Recomendados
* [Manual do Bison](http://www.gnu.org/software/bison/manual/index.html)
    * [Principais Conceitos](http://www.gnu.org/software/bison/manual/html_node/Concepts.html#Concepts)
    * [Exemplos](http://www.gnu.org/software/bison/manual/html_node/Examples.html#Examples)
* [Ponte entre Flex e Bison](http://flex.sourceforge.net/manual/Bison-Bridge.html)