# Relatório - Projeto "Aventura!" Parte 2

## Integrantes

 * Caio Túlio de Deus Andrade - 9797232
 * Édio Cerati Neto - 9762678
 * Leandro Rodrigues da Silva - 10723944 

***

### Como rodar o programa

​	Basta digitar "Make" no diretorio, e depois digitar ./jogo

### Problemas encontrados

​	Tivemos problemas em encaixar as ações nos objetos, pois, de acordo com o enunciado, toda ação deveria ter prototipo **ação(Elemento *, Elemento *)** , no entando, muitas ações recebiam argumentos de tipo diferente de "Elemento" - algumas recebiam "Sala *", por exemplo - dessa forma, se tornou imprático criar um array com ações, pois não teria como padronizarmos o array com malloc. Dessa forma, nossos testes de ação foram manuais. 

​	Também tivemos problemas em inserir a animação corresponde nos elementos, por não conseguirmos lidar com a incompatibilidade de tipos, alguns elementos possuiam animações que dependiam de aventureiro*, outros de elemento *, assim, não haveria um arquivo header padronizado. Como não ficou muito claro como lidar com ponteiro void (que aparentemente seria uma solução), decidimos deixar este problema para a próxima fase.

​	Tivemos problemas na hora de definir a "hierarquia" no estruturas.h, isto é, a ordem de declaração das estruturas. Como foi criada uma dependência circular (Elemento depende de Lugar, Lugar depende de Elemento e Elemento depende de Lista, lista depende de elo, e elo depende de Elemetno) , resolvemos esse problema com Forward declaration.

### Sobre a estrutura

​	Fizemos uma separação cliente-interface-implementação, com a implementação estando dividida entre "animacoes.c", "comandos.c", "lista.c", "tabsim.c", e a interface foi dividida em "comandos.h", "estruturas.h", "global.h". O cliente é o arquivo jogo.c .

#### 	***Interface***

​	Em "estruturas.h" definimos as estruturas basicas do jogo e as funções da tabela de simbolos, e de listas. 

​	Em "comandos.h" declaramos os prototipos das animações e ações do jogo. Tambem declaramos o typedef contendo a definição de ponteiro de função e ponteiro de animação.

​	Em "global.h", apenas delcaramos a variavel aventureiro como global, fizemos isso usando o operador "extern"

### Implementação

​	Em comandos.c definimos a implementação basica dos comandos (ou seja, ações). Além disso, definimos as funções relacionadas a impressão da introdução ao jogo (apresenta_descrição, imprime_conteudo,imprime_arquivo e entrou_na_sala).

​	Em animações.c foram definidas as animações. 
​	Em lista.c e tabsim,c, foram definidas as implementações de listas ligadas e tabela de símbolos.

### Cliente

​	O arquivo jogo.c é o cliente do nosso projeto. Nele, fizemos a inicialização dos elementos, salas e aventureiro (que não foi definida numa função especifica porque isso poderia acarretar em perda de informação com alocação de memória dentro de um blocod e função), conectamos as salas e implementamos o laço de execução do jogo.