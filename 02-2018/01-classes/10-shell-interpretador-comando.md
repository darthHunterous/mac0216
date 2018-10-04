# Aula 10 - Shells (Interpretadores de Comandos)
### Programas do Sistema
* **Sistema Operacional:** provém funcionalidades através de syscalls
* **Compiladores, montadores, ligadores e interpretadores de comandos:** programas úteis para o funcionamento, mas não contidos no SO

### Interpretador de Comandos
* **Definição:** implementa uma interface de linha de comando. Usuários submetem comandos por meio de linhas sucessivas de texto (comandos)
* **Shell:** interpretador de comandos para SO
    * Interface entre usuário e SO quando não se usa interface gráfica
    * Usuário pode fazer uso intenso das funcionalidades do SO
* Na Computação, shell designa qualquer programa que atue como uma casca (camada externa) entre o usuário e o núcleo do SO
    * Um programa gráfico também pode ser chamado de shell, como o Explorer do Windows
* Em SOs com origem no **Unix**: shell é o interpretador de comandos em modo texto para o SO

### Shells
* **Windows:** <span>command.com</span>, cmd.exe, PowerShell
* **Mac OS:** Terminal.app
* **Unix:** sh (Bourne shell), csh (C shell), bash (Bourne-Again shell), ksh (Korn shell), ash (Almquist shell)

### Árvore Genealógica de Shells do Unix
* 1977 - **sh**
    * 1978 - **csh**
        * 1983 - **tcsh**
        * 1990 - **zsh**
    * 1983 - **ksh**
        * 1989 - **pdksh**
            * 2003 - **mksh**
        * 1992 - **POSIX shell**
    * 1989 - **rc**
        * 1993 - **es**
    * 1989 - **ash**
        * 1996 - **dash**
    * 1989 - **bash**
        * 1994 - **scsh**
        * 1999 - **psh**

### Bash
* Shell padrão do GNU/Linux
* Evolução do sh
* Incorpora características do csh e do ksh
* Implementação com base nas normas POSIX (portabilidade entre SOs)
* Combina **funcionalidades**: interpretador de comandos e linguagem de programação
* **Dois modos**:
    * **Interativo:** executa comandos digitados no prompt
    * **Não-Interativo:** comandos lidos de arquivo de entrada

### Linguagem de Programação no Bash
* O interpretador de comandos permite aos usuários execução de programas utilitários
* A linguagem permite que tais utilitários sejam combinados
* Scripts são arquivos que podem ser criados contendo comandos
    * Permitem personalização do ambiente, automatização de tarefas e otimização do funcionamento do computador

### Funcionamento de um Shell
* Gerencia interação entre um usuário e o SO
* **Passos:**
    * **01:** aguarda a entrada de linhas de comando
    * **02:** interpreta as linhas, traduzindo em chamadas a comandos do shell ou SO
    * **03:** cria processos filhos para execução dos comandos
    * **04:** espera o término da execução dos processos
    * **05:** disponibilizar o resultado da execução (para usuário ou programa)
    * **06:** volta ao passo inicial

### Utilitários para manipular diretórios
* **ls \<opções\> \<diretório\>**
    * Lista entradas em um diretório
* **cd \<diretório\>**
    * Muda o diretório
* **mkdir \<opções\> \<nome\>**
    * Cria novo diretório
* **rmdir \<opções\> \<diretório\>**
    * Apaga um diretório vazio

### Utilitários para Manipular Arquivos
* **cp \<opções\> \<origem\> \<destino\>**
    * Copia arquivos ou diretórios
* **mv \<opções\> \<origem\> \<destino\>**
    * Move arquivos ou diretórios
* **rm \<opções\> \<arquivos\>**
    * Apaga arquivos ou diretórios
* **cat \<arquivos(s)\>**
    * Concatena arquivos e imprime na saída padrão
* **find -name \<arquivo\>**
    * Localiza arquivos ou diretórios
* **sort \<arquivo\>**
    * Ordena alfabeticamente as linhas do arquivo

### Outros utilitários
* **more \<opções\> \<arquivo\>**
    * Exibe conteúdo do arquivo, uma paágina por vez
* **less \<opções\> \<arquivo\>**
    * Exibe o conteúdo do arquivo uma página por vez, permitindo navegação e outras funcionalidades (busca de termos)
* **grep \<opções\> \<padrão\> <arquivo(s)\>**
    * Procura linhas do arquivo que contenham o padrão
* **ps \<opções\>**
    * Exibe informações sobre processos
* **top \<opções\>**
    * Visão dinâmica dos processos em execução
* **kill \<opções\> \<ID do processo\>**
    * Envia um sinal ao processo. Por padrão sinal TERM de término do processo

### Operadores de Redirecionamento em Bash
* **\>**
    * Redireciona a saída para um arquivo, se existir é sobrescrito
* **\>\>**
    * Redireciona a saída para um arquivo, mas acrescenta os dados ao final do arquivo, sem sobrescrever
* **\<**
    * Redireciona a entrada
    * Permite que um arquivo forneça a entrada para um programa
* **2\>**
    * Redireciona saída de erros
    * **Exemplo:** <code>find -name Makefile 2> /dev/null</code>
        * Erros produzidos são redirecionados para o dispositivo de sistema /dev/null (descartados)
* **&>**
    * Redireciona a saída padrão e a de erros
    * **Exemplo:** <code>ls -R /home/user/ &> /dev/null</code>
        * Ambas saídas são descartadas

### Operador Bash - Pipe (|)
* Permite um programa utilizar como entrada a saída de outro
* **Exemplos**
    * <code>ls -a | sort</code>
        * Sort recebe como entrada a saída de ls
    * <code>cat /home/kelly/mac211.txt | wc -l > lista.txt</code>
        * Grava em lista.txt o número de linhas de mac211.txt (contém lista de matriculados em MAC0211 em 2013)
    * <code>cat /home/kelly/mac211.txt | sort >> lista.txt</code>
        * Coloca no final de lista.txt a lista em ordem alfabética dos alunos de MAC0211 em 2013
    * <code>ls -l /etc | sort | less</code>
        * Mostra em ordem alfabética a listagem do diretório /etc, permitindo navegação da listagem

### Materiais Recomendados
* [Manual do Bash](http://www.gnu.org/software/bash/manual/bashref.html)
* [Guia para iniciantes do Bash](http://www.tldp.org/LDP/Bash-Beginners-Guide/html/)
* [HowTo da linha de comando do Bash](http://tldp.org/HOWTO/Bash-Prompt-HOWTO/)
* [Tim Jones - "Evolution of Shell in Linux"](http://www.ibm.com/developerworks/linux/library/l-linux-shells/)
    