# Aula 11 - Programação Bash
### Tipos de Execução de Comandos
* **Background:** comando executado assincronamente em subshell. Na execução em background, o shell não espera que execução do comando termine
    * Tal execução é indicada pelo caracter **&** ao final do comando
    * <code> sort mac211.txt > saidata.txt &</code>
* **Execução Sequencial:** comandos separados por **;**
    * <code>sort mac211.txt > saida.txt ; cat saida.txt</code>
* **Execução paralela:** através do GNU Parallel
    * <code>cat mac211.txt | parallel -k echo Aluno:</code>
        * Mostra o conteúdo de mac211.txt incluindo o prefixo "Aluno:" em todas as linhas. Opção -k garante que a ordem será mantida
    * <code>cat mac211.txt | parallel -k echo {} ' -Aluno'</code>
        * Mostra o conteúdo de mac211.txt incluindo o sufixo "-Aluno" em todas as linhas

### Listas de Comandos em Bash
* **Lista E:** sequência de um ou mais comandos separados pelo operador de controle **&**
    * comando1 && comando2
    * comando2 só é executado se a execução de comando1 terminou com sucesso (status de saída = 0)
* **Lista OU:** sequência de comandos separados pelo operador de controle **||**
    * comando1 || comando2
    * O comando2 só é executado se o comando1 não terminou com sucesso (saída diferente de zero)

### Comandos Inclusos no Bash
* Comandos contidos no próprio shell, executados sem invocar outros programas
* **history**
    * Lista comandos já executados
* **pwd**
    * Caminho do diretório atual
* **alias \<nome\>=\<comando\>**
    * Cria um apelido para dado comando

### Combinações de Teclas
* **Setas Verticais:** percorre histórico de comandos
* **Setas Horizontais:** posicionamento da linha atual
*  **TAB:** completa comando que está sendo digitado até onde não houver ambiguidade
* **TAB TAB:** lista opções possíveis para o que já foi digitado se houver várias
* **CTRL + C:** cancela execução do programa atual
* **CTRL + D:** gera código de final de arquivo (fecha o terminal)
* **CTRL + Z:** suspende programa em execução
    * **jobs:** lista programas suspensos
    * **fg  %\<numero do programa suspenso\>** ou **%\<numero do programa suspenso\>**
        * Retoma execução do programa suspenso em primeiro plano (modo síncrono)
    * **bg  %\<numero do programa suspenso\>** ou **%\<numero do programa suspenso\>**
        * Retoma execução do programa suspenso em backgroun (modo assíncrono)

### Pilha de Diretórios do Bash
* Mantém pilha com os diretórios visitados recentemente
* **pushd \<dir\>:** empilha diretório atual e faz cd para dir
* **popd \<opções\>:** desempilha diretório e faz cd para ele
* **dirs \<opções\>:** mostra informações sobre o status atual da pilha

### Permissões a Acesso de Arquivos no UNIX
* Todo objeto no sistema de arquivos pertence a um usuário ou grupo
* **Três Conjuntos de Permissões**
    * Ao usuário dono do objeto (owner, u)
    * Aos membros do grupo do objeto (group, g)
    * Todos os usuários do sistema (other, o)
* **Modos de Acesso**
    * **r** - leitura (read)
    * **w** - escrita (write)
    * **x** - execução (execution)
* **Alterar Permissão - Modo Octal**
    * `chmod <modo> <arquivo/arquivos>`
    * Modo vem de um número de 3 dígitos
        * Primeiro dígito: Owner
        * Segundo dígito: Group
        * Terceiro dígito: Public
    * Cada dígito se baseia num octal em que cada categoria de permissão tem valor específico, que são somados
        * Read: valor 4
        * Write: valor 2
        * Execute: valor 1
    * **Exemplo:** `chmod 664 arquivo_teste`
        * Dá permissão de leitura e escrita para dono e grupo e somente leitura para outros usuários
* **Alterar Permissão - Modo Simbólico:**
    * `chmod <referencia> <operador> <modo> <arquivo/arquivos>`
        * Referência: `u`, `g`, `o` (e combinações)
        * Operador: `=`, `+` (acrescentar), `-` (excluir)
        * Modo: `r`, `w`, `x` (e combinações)
    * **Exemplo de Uso**
        * `chmod ug=rw,o=r arquivo_teste`

### Scripts - Bash
* **Transformar script em executável**
    * `chmod u+x script_file`
* **`#!` - Shebang/Hashbang**
    * Indica o caminho do shell a ser carregado para executar o script
* **Comentário**
    * Caracter `#`
* **Exemplo - Hello World**
    ```sh
    #!/bin/bash
    echo Hello World! # imprime Hellow World na saída padrão
    ```
* **Variáveis de Ambiente**
    * Sem tipo, podem conter números, caracteres ou strings
    * Não precisam ser declaradas, basta atribuir valor
* **Recuperar Valor de Variável**
    * Colocar `$` na frente do nome
    ```sh
    STR='Hello World!'
    echo $STR
    ```
* Não pode haver espaços antes e depois do `=` na definição da variável
* **Exemplo - Script de Backup da Home**
    ```sh
    #!/bin/bash
    ARQ_SAIDA=/var/meu-backup-$(date +%d%m%Y).tgz
    tar -czf $ARQ_SAIDA /home/usuario/
    ```
    * `$(comando)` executa `comando` e captura seu resultado
    * `$(date +%d%m%Y)` executa comando `date` e gera uma string no formato 26112018 (26 de Novembro de 2018)
* **Exportando Variável de Ambiente**
    * `export PATH=/usr/bin`
    * Ao exportar, a variáve fica visível em scripts e programs executados depois
    * **Exemplo**
        ```sh
        # Script abaixo
        #!/bin/bash
        echo Oi, $USUARIO

        # Durante a Execução
        $ export USUARIO=Edio
        $ ./digaoi
        Oi, Edio
        ```
* **Variáveis de Ambiente Padrões**
    * `PATH` - caminho para busca de programas
    * `PWD` - diretório atual
    * `SHELL` - shell padrão
    * `CDPATH` - diretórios base para o comando `cd`
    * `JAVA_HOME` - diretório de instalação do Java

### Comandos Compostos - Programação Shell
* Construtores em Shell
* Iniciam por palavra reservada ou operador de controle, terminando com a palavra reservada ou operador de controle correspondente
* Laços, condicionais e mecanismos de agrupamento
* **Laços - While**
    * Executa `comandos conseguintes` enquanto `comandos de teste` tenham status de saída zero
    ```sh
    while {comandos de teste}; do
        {comandos conseguintes}
    done
    ```
    * O `while` devolve o status de saída do último comando executado em `comandos conseguintes` ou zero se nenhum foi executado
    * Status zero significa sucesso na execução
    * **Exemplo - Contador**
        ```sh
        #!/bin/bash
        CONTADOR=0
        while [$CONTADOR -lt 10]; do
            echo O contador vale $CONTADOR
            let CONTADOR=CONTADOR+1
        done
        ```

### Comandos para Expressões Lógicas - Retornando Verdadeiro
* `-a ARQ`: arquivo ARQ existe
* `-d DIR`: diretório DIR existe
* `-z STRING`: STRING tem comprimento zero
* `-n STRING`: comprimento de STRING não é zero
* `STRING1 = STRING2`: strings iguais
* `STRING1 != STRING2`: se strings diferentes
* `STRING1 < STRING2`: se STRING1 é lexicograficamente menor que STRING2
* `NUM1 -eq NUM2`: inteiro NUM1 igual a NUM2
* `NUM1 -ne NUM2`: inteiro NUM1 não igual a NUM2
* `NUM1 -lt NUM2`: inteiro NUM1 menor que NUM2
* `NUM1 -le NUM2`: inteiro NUM1 menor ou igual a NUM2
* `NUM1 -gt NUM2`: inteiro NUM1 maior que NUM2
* `NUM1 -ge NUM2`: inteiro NUM1 maior ou igual a NUM2
* `!EXPR`: se EXPR é falso
* `EXPR1 -a EXPR2`: se ambas expressões são verdadeiras
* `EXPR1 -o EXPR2`: se ao menos uma expressão é verdadeira

### Laços - Comando Until
* Executa `comandos conseguintes` enquanto `comandos de teste` devolvem status de saída **diferente de zero** (ou seja, enquanto não for sucesso ainda)
    ```sh
    until {comandos de teste}; do
        {comandos conseguintes}
    done
    ```
* Devolve o status de saída do último comando executado em `comandos conseguintes` ou zero caso nenhum tenha sido
* **Exemplo - Contador**
    ```sh
    #!/bin/bash
    CONTADOR=20
    until [ $CONTADOR -lt 10 ]; do
        echo O contador vale $CONTADOR
        let CONTADOR=CONTADOR-1
    done
    ```

### Laços - Comando For
* Expande `palavras` e executa `comandos conseguintes` uma vez para cada membro resultante da expansão. `nome` contém o membro atual.
    ```sh
    for {nome} in {palavras ...}; do
        {comandos conseguintes}
    done
    ```
* Devolve o status de saída do último comando executado em `comandos conseguintes` ou zero caso nenhum tenha sido
* **Exemplo - Percorrer Diretório Atual**
    ```sh
    #!/bin/bash
    for i in $(ls); do
        echo item : $i
    done
    ```
* **Exemplo - Listar Número de 1 a 10**
    ```sh
    #!/bin/bash
    for i in `seq 1 10`; do
        echo $i
    done
    ```

### Materiais Recomendados
* [Manual Bash](http://www.gnu.org/software/bash/manual/bashref.html)
* [Guia Iniciantes - Bash](http://www.tldp.org/LDP/Bash-Beginners-Guide/html/)
* [HowTo - Programação Bash](http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO.html)
* [Bash By Example - Parte 1](http://www.ibm.com/developerworks/linux/library/l-bash/index.html)
* [Bash By Example - Parte 2](http://www.ibm.com/developerworks/linux/library/l-bash2/index.html)