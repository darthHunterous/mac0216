# Aula 19 - Regex e AWK

### Expressões Glob
* Expressões envolvendo metacaracteres nos shells antigos para casamento de nomes de arquivos
    * `*`: casa com qualquer sequência
        * `carn*`: casa com carne, carneiro, carnudo
    * `?`: casa com exatamente um caracter
        * `?at`: casa com bat ou cat, mas não com at ou habitat
    * `[...]`: casa com uma classe de caracteres
        * `[CB]at` casa com Cat ou Bat mas não com cat, bat ou at

### Tipos de Expressões Regulares
* **Básicas:** notação aceita por `grep`, `sed` (stream editor) e `ed` (line editor)
* **Estendidas:** aceita pela extensão de `grep`, o `egrep`. Regexes no `Lex` e `Emacs` são parecidas com essas
* **Perl:** notação para regex de Perl e Python, mais poderosas que as anteriores

### Metacaracteres de Regex Básicas
* `.`: um caracter qualquer
* `[abcd]`: um caracter do conjunto dado
* `[a-zA-Z]`: um caracter no intervalo dado
* `[^abcd]`: um caracter que não está no conjunto dado
* `^`: início da cadeia
* `$`: fim da cadeia
* `*`: elemento zero ou mais vezes

### Exemplos de Regex Básicas
* `x.y`: "x" seguido por qualquer caracter seguido por "y"
* `x\.y`: "x" seguido por um ponto seguido por y
* `xz*y`: x seguido por qualquer número de instância de z (zero ou mais), seguido por y
    * "xy" ou "xzy" ou "xzzzy" mas não "xz" nem "xdy"
* `s[xyz]t`: s seguido por qualquer um dentre x, y ou z, seguido por t
    * "sxt" ou "syt" ou "szt"
* `s[^x0-9]t`: s seguido por qualquer caracter que não seja x nem algum outro dígito, seguido por t
* `^x`: x no ínicio da cadeia
    * "xzy" ou "xzzy" mas não "yzy" nem "yxy"
* `x$`: x no fim da cadeia
    * "yzx" ou "yx" mas não "yxz" ou "zxy"

### Metacaracteres de Regex Estendidas
* `?`: elemento uma ou nenhuma vez
* `+`: elemento uma ou mais vezes
* `(n1|n2|n3)`: qualquer uma das opções
* `{m,n}`: elemento pelo menos m e não mais que n vezes

### Exemplos de Regex Estendidas
* `xz?y`: x seguido por no máximo um z seguido por y
    * "xy" ou "xzy"
* `xz+y`: x seguido por uma ou mais instâncias de z, seguido por y
    * "xzy" ou "xzzy" ou "xzzzy"
* `xz{2,5}y`: x seguido por 2, 3, 4 ou 5 instâncias de z seguido por y
    * xzzy ou xzzzy ou xzzzzy ou xzzzzzy

### Classes POSIX
* **Caracteres Alfa-Numéricos:** [:alnum:]
    * ASCII: A-Z a-z 0-9
* **Caracteres do Alfabeto:** [:alpha:]
    * ASCII: A-Z a-z
* **Espaço e Tabulação:** [:blank:]
    * ASCII: " " e \t
* **Caracteres de Controle:** [:cntrl:]
    * ASCII: \x00- \x1F \x7F
* **Dígitos:** [:digit:]
    * ASCII: 0-9
* **Letras Minúsculas:** [:lower:]
    * ASCII: a-z
* **Caracteres Brancos:** [:space:]
    * ASCII: \t \r \n \v \f
* **Letras Maiúsculas:** [:upper:]
    * ASCII: A-Z
* **Dígitos Hexadecimais:** [:xdigit:]
    * ASCII: A-F a-f 0-9

### Exemplos no Bash
* Listar arquivos que comecem com uma letra entre 'a' e 'h'
    * `ls -l [a-h]*`
* Mostrar linhas de um arquivo que começam com a sigla de uma disciplina MAC
    * `grep -E '^MAC[[:digit:]]{3,4}' arquivo.txt`
    * **OBSERVAÇÃO:** opção -E no grep habilita Regex estendidas
* Verificar se a sequência de caracteres é um username válido (começa com letra, mas na sequência pode conter letras ou números, com tamanho mínimo de 2 caracteres e no máximo 7)
    * `grep -E '^[A-z][A-z0-9]{2,7}`

### AWK
* Ferramenta para tratamento de texto com base em Regex
* Exemplos de uso
    * Processamento de arquivos de texto e criação de relatóros
    * Tradução de arquivos entre diferentes formatos
    * Criação de pequenos banco de dados
    * Realização de operações matemáticas em arquivos de dados numéricos
* Pode realizar de tarefas simples de processamento de texto via linha de comando ou como linguagem de programação para scripts mais complexos
* O nome AWK vem de seus criadores: Aho, Weinberger e Kernighan

### Estrutura AWK
* Formato Simples
    * `awk '<padrão de busca> <ações do programa> arquivo_entrada`
* Formato Geral
    * `awk [-F<sc>] 'prog' | -f <arq_prog> [<vars>] [-|<arq_entrada>]`
    * `sc`: caracter separador de campo
    * `prog`: programa awk de linha de comando
    * `arq_prog`: arquivo contendo programa awk
    * `vars`: inicialização de variáveis
    * `-`: lê da entrada padrão
    * `arq_entrada`: arquivo texto de entrada
* Estrutura do script `arq_prog`
    ```awk
    BEGIN              {<inicializações>}
    <padrão de busca>  {<ações do programa>}
    <padrão de busca>  {<ações do programa>}
    ...
    END                {<ações finais>}
    ```

### Entradas em AWK
* AWK lê um script e o aplica na sua entrada
    * Pode ser passado como primeiro parâmetro do programa, entre aspas, ou através da opção `-f nome-do-script`
* Entrada quebrada em registros (normalmente linhas)
* Registros quebrados em campos (normalmente espaços em branco)
    * Referenciados por variáveis posicionais como $1, $2, .., $n
* $0 se refere ao registro inteiro
* NR: variável embutida, contém número de registros já processados
* NF: variável com número de campos do registro atual
* length: variável com número de caracteres da linha atual
* Para definir outro separador de campos, pode-se usdar a opção -F no awk

### Regexes de AWK
* Todas as já conhecidas com algumas adicionais
* `\`: caracter de *escape*, usado para remover o significado especial de um metacaracter
* `BEGIN`: casa com o início do arquivo
* `END`: casa com o final do arquivo

### Exemplos AWK
* Mover todos arquivos que iniciem com "junk" para o diretório "lixo", renomeando-os com extensão ".lix"
    * `ls junk* | awk '{print "mv "$0"  ../lixo/"$0".lix"}' | bash`
* Calcular soma e média de números armazenados em um arquivo (um número por linha)
    ```awk
    BEGIN  { s = 0 }
           { s += $1 }
    END    { print "Soma: ", s, "Media: ", s/NR}
    ```
* Calcular tamanho médio das linhas de um arquivo
    ```awk
         { s += length }
    END  { print "Tamanho medio das linhas: ", s/NR }
    ```

### Outras Características AWK
* Variáveis não são declaradas, passando a existir na primeira vez que são usadas
* Não existe tipo de variável
* Não é preciso inicializar variáveis, seu valor inicial é sempre string vazia (convertida para zero em operações aritméticas)
* Possível utilizar vetores, cujos índices podem ser números ou strings

### AWK - Exemplos com Vetores
* Contador de ocorrências de palavras
    ```awk
         {
              for (i = 1; i <= NF; i++)
                  freq[$i]++
         }
    END  {
              for (palavra in freq)
                  printf "%s\t%d\n", palavra, freq[palavra]
         }
    ```
* Ordenar arquivos considerando como chave valores numéricos armazenados em seu primeiro campo
    ```awk
         {
              if ($1 > max)
                  max = $1
              vet[$1] = $0
         }
    END  {
              for (x = 1; x <= max; x++)
                  if (x in vet)
                      print vet[x]
         }
    ```

### Bibliografia e Materiais Recomendados
* ["The Art of Unix Programming" - Eric S. Raymond, Capítulo 08, Seção "Case Study: Regular Expressions](http://www.catb.org/esr/writings/taoup/html/ch08s02.html#regexps)
* ["Mastering Regular Expressions" - Jeffrey Friedl, a Bíblia das Expressões Regulares](http://regex.info/)
* [GAWK - Guia do Usuário](http://www.gnu.org/software/gawk/manual/gawk.html)
* [An Awk Primer - Tutorial de AWK](http://www.vectorsite.net/tsawk.html)
* [Notas de Aulas MAC0211 de 2010, por Fábio Kon](http://www.ime.usp.br/~kon/MAC211)