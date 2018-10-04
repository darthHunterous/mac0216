# Aula 09 - Sistemas Operacionais e Bibliotecas Estáticas e Dinâmicas
### Software
* **Programas de Sistema:** funcionamento do computador
* **Programas aplicativos:** trabalho que o usuário deseja realizado
* **SO** principal programa do sistema de um computador

### **Funções de um SO**
* **Máquina Estendida/Virtual:** interfaces para interação com hardware
    * Serviços acessáveis aos programas por meio de syscalls
* **Gerenciador de Recursos:** gerencia os componentes que compõem o computador. Aloca ordenadamente e controla os recursos para os programas que disputam por isso

### **Motivações para desenvolver SOs**
* *Primeiro momento:* hardware mais caro que a mão de obra
    * Motivação de maximizar a utilização do hardware
* *Segundo momento:* inversão. Hardware mais barato, mão de obra cara
    * Motivação de facilitar o uso

### **Evolução dos Sistemas**
* **01 - Válvulas:** sem SO
* **02 - Transistores:** sistemas em lote (batch)
* **03 - Circuitos Integrados:** sistemas multiprogramados e de tempo compartilhado
* **04 - Computadores Pessoais:** sistemas gráficos, de redes e distribuídos

### Multiprogramação x Multitarefa
* **Multiprogramação/Multitarefa:** diversos programas executando em um mesmo processador
* **Multiprocessamento:** diversos processadores no mesmo sistema, executando programas distintos ou cooperando na execução de um único

### Componentes Centrais de SO
* **Escalonador de Processos:** determina quando e por quanto tempo um processo é executado
* **Gerenciador de Memória:** determina como a memória é alocada a processos e o que fazer com ela cheia
* **Gerenciador de Entrada e Saída:** atende solicitações de I/O para os dispositivos de hardware
* **Gerenciador de Comunicação Interprocessos (IPC):** permite que processos se comuniquem entre si
* **Gerenciador do Sistema de Arquivos:** organiza os dados no armazenamento e fornece uma interface de acesso

### Modo Privilegiado (Supervisor) x Usuário
* Controlados por um bit de um registrador de uso específico
* **Modo Supervisor:** CPU pode executar qualquer instrução do seu conjunto e usar qualquer atributo de hardware
    * SO é executado em modo supervisor, tendo acesso a todo o hardware
* **Modo Usuário:** instruções de I/O e proteção de memória são inacessíveis
    * Programas aplicativos executados em modo usuário

### Arquitetura de SOs
* **Monolítica:** componentes do SO contidos no núcleo, podendo se comunicar diretamente a qualquer outro (chamadas de função)
    * Mais antigo e mais comum
* **Em Camadas:** agrupa componentes com tarefas similares
* **Micronúcleo:** número pequeno de serviços (núcleo pequeno e escalável)
* **Cliente-Servidor:** implementa funcionalidades de SO como processos de usuários (divididos entre processos clientes e processos servidores). O núcleo comunica clientes e servidores

### Biblioteca: Interface e Implementação
* Coleção de implementações de comportamentos com interface bem definida, a qual invoca tais comportamentos
* **Interface:** expressa **o quê** a biblioteca faz
* **Implementação:** expressa **como** a biblioteca faz o que foi definido na interface
#### Características
* Reuso de comportamentos (código)
* Organizadas de maneira que possam ser usadas por programas diferentes e independentes
* Comportamentos implementados nas bibliotecas podem ser integrados (**ligados**) ao programa invocador em algum momento do **ciclo de vida** do programa
    * Geração de executável
    * Invocação de execução
    * Durante a execução

### Bibliotecas Estáticas e Dinâmicas
* **Bibliotecas Estáticas:** código acessado durante a construção (**build**) do executável do programa invocador
* **Bibliotecas Dinâmicas:** integradas (**ligadas**) ao programa depois da invocação da execução
    * **Ligação na inicialização:** quando o programa é carregado para execução, as bibliotecas dinâmicas são carregadas com ele
    * **Carga Preguiçosa:** (mais comum), biblioteca só é carregada quando necessária para continuidade da execução

### Bibliotecas Dinâmicas
* **Vantagens**
    * Compartilhamento entre vários programas utilizadores (em memória e em disco)
    * Menor uso de memória na máquina
    * Novas versões são aproveitadas até pelos programas antigos
* **Desvantagens**
    * Carga mais lenta
    * DLL Hell, complicações do uso de bibliotecas dinâmicas nas versões mais antiga de Windows

### Bibliotecas Estáticas
* **Vantagens**
    * Código das funções adicionados ao executável final, não há risco de não se localizar a biblioteca em tempo de execução
    * Versão fixa, não havendo problemas de incompatibilidade
    * Mudanças em bibliotecas novas não afetam programas antigos
    * Carga dos programas é mais rápida
* **Desvantagens**
    * Tamanho maior de executável
    * Código adicionado mesmo que em execução não seja usado

### Bibliotecas estáticas e dinâmicas no Linux
* **Nomeação**
    * **Estáticas:** extensão .a
    * **Dinâmicas:** extensão .so
* **Convenção**
    * Prefixo lib
    * Exemplos
        * libtest.a
        * <span>libtest.so</span>
* GCC: referência às bibliotecas por meio do parâmetro <code>-l</code>
    * <code>gcc prog.c -lm -lpthread</code>
        * Biblioteca matemática: /usr/lib/libm.so
        * Biblioteca para uso de threads: /usr/lib/libpthread.so

### Criando Biblioteca Estática
* **Primeiro passo:** gerar código objeto a partir dos fontes da biblioteca
* **Segundo passo:** compactar os objetos em um arquivo .a com o comando <code>ar</code>
* **Exemplo**
    * <code>gcc -c calc_media.c -o calc_media.o</code>
    * <code>gcc -c calc_dp.c -o calc_dp.o</code>
    * <code>ar -rcv libestat.a calc_media.o calc_dp.o</code>
* **Listar objetos dentro de uma biblioteca**
    * <code>ar -t libestat.a</code>

### Ligando biblioteca estática
* **Biblioteca criada por usuário**
    * <code>gcc -o meuprog meuprog.c libestat.a</code>
    * Usando -L para indicar a localização
        * <code>gcc -o meuprog meuprog.c -L[caminho] libestat.a</code>
* **Biblioteca padrão em C**
    * Forçar a ligação com versão estática: <code>-static</code>
    * <code>gcc -o meuprog meuprog.c -static -lm -lc</code>

### Criação de biblioteca dinâmica
* Gerar código objeto com -fPIC (para gerar código que funcione independetemente da posição de memória em que fi colcoado)
* Opção -shared do gcc para gerar o .so
* **Exemplo**
    * <code>gcc -c -fPIC calc_media.c -o calc_media.o</code>
    * <code>gcc -c -fPIC calc_dp.c -o calc_dp.o</code>
    * <code>gcc -o <span>libestat.so</span> -shared calc_media.o calc_dp.o</code>
    * <code>mv <span>libestat.so</span>  /home/user/libs/</code>

### Ligação de biblioteca dinâmica
* <code>gcc -o meuprog meuprog.c -L/home/user/libs -lestat</code>
* -lestat faz gcc buscar a biblioteca <span>libestat.so</span>
* -static -lestat buscaria libestat.a
* A biblioteca não é incluída no executável, ligada dinamicamente na execução
* **ldd**
    * Mostra as bibliotecas dinâmicas carregadas em um executável
    * <code>ldd meuprog</code>

### Executar Programa com biblioteca dinâmica
* Indicação ao ligador onde as bibliotecas se encontram
    * Editando variável de ambiente LD_LIBRARY_PATH
        * <code>export LD_LIBRARY_PATH=/home/user/libs:$LD_LIBRARY_PATH</code>
    * Criação de arquivo /etc/ld.so.conf.d/mylibs.conf
        * <code>echo "/home/user/libs" | sudo tee -a /etx/ld.so.conf.d/mylibs.conf</code>
        * <code>sudo ldconfig</code>

### Variáveis de Ambiente
* **LD_LIBRARY_PATH:** onde o ligador deve buscar bibliotecas dinâmicas
* **LD_PRELOAD:** bibliotecas a serem carregadas antes das outras
* **LD_BIND_NOW:** on ou off. Habilitada, faz as bibliotecas dinâmicas carregas no início da execução, do contrário a carga é sob demanda

### Conteúdo Extra
* Tanenbaum e Woodhull - Operating Systems: Design and Implementation (Capítulo 01)
* [Introdução a Sistemas Operacionais](http://people.csail.mit.edu/rinard/osnotes/h1.html)
* [Tutorial - Criação e Uso de Bibliotecas Estáticas e Dinâmicas no Linux](http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html)
* [Introdução ao GCC](http://www.network-theory.co.uk/gcc)
* [DLL Hell](http://en.wikipedia.org/wiki/DLL_Hell)