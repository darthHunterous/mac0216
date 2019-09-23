# Relatorio projeto Aventura parte 3

## Integrantes

* Caio Túlio de Deus Andrade 9797232
* Édio Cerati Neto - 9762678
* Leandro Rodrigues da Silva - 10723944

***



## Compilando

​	Simplesmente digite "make" e depois digite ./avent para jogar a aventura.

***



## Desenvolvimento

​	Nosso desenvolvimento basicamente se resumiu em adaptar nossa implementação funcional das partes 1 e 2 com os exemplos de flex e Bison do professor Gubi. Tivemos muita dificuldade em faze-lo pois as implementações estavam muito diferentes - o professor usava manipulação direta em structs enquanto que fizemos manipulação via ponteiros,  e sua implementação de tabela de símbolos era muito diferente da nossa, por exemplo -  e, posteriormente, nos complicamos com o Bison.

​	Demoramos um tempo para entender o funcionamento do Bison (sua interação com o flex e a entrada, por exemplo), mas conseguimos resolver isso. Assim, conseguimos usar o flex + Bison de maneira plena para a entrada.



## Análise sintática

​	Nosso programa reconhece comandos de inventario, fim, ir para, direção, alguns verbos e o proprio EOL.  A implementação de verbos está muito parecida com a do professor, nela, classificamos um verbo em intransitivo, transitivo direto, ou bitransitivo dependendo do número de parametros na entrada. 



## Problemas de implementação

​	Tivemos problemas com a adaptação do ponteiro de funções, na terceira fase, o  acabou prejudicando um pouco alguns comandos do jogo.



## "Detonado" do jogo

​	Para facilitas os testes, fizemos um mapa linear das salas, sendo assim, para chegar até o fim do jogo, basta ir para o norte até chegar ao fim do jogo.

