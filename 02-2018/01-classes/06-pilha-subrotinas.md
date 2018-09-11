# Aula 06 - Pilha e Sub-Rotinas

* **Pilha:** porção da memória compartilhada com o SO
    * Comunica programas e subprogramas
    * Armazenamento temporário
    * Syscalls
* **Registrador EBP:** endereço da base da pilha
    * Base Pointer
* **Registrador ESP:** endereço do topo da pilha
    * Stack Pointer
* Os valores dos endereços de memória da pilha crescem em direção à base
<br><br>
### Operações de Manipulação de Pilha
* **PUSH:** armazena o operando no topo da pilha
    * <code>PUSH reg|mem|const</code>
    * Número de bits armazenados é definido pelo tamanho do operando
    * PUSH não pode ser aplicada a operandos de 8 bits
    ```asm
    push %eax

    # equivale a 
    sub $4, %esp
    mov %eax, (%esp)
    ```
* **POP:** remove o valor do topo da pilha, armazenando no operando
    * <code>POP reg|mem</code>
    * Número de bits retirados da pilha é definido pelo tamanho do operando
    * Não pode ser aplicado a operandos de 8 bits
    ```asm
    pop %bx

    # equivale a
    mov (%esp), %ebx
    add $2, %esp
    ```
* **PUSHA (Push All):** empilha o valor de todos os registradores de uso geral
    * Ordem de empilhamento: eax, ecx, edx, ebx, esp, ebp, esi, edi
* **POPA (Pop All):** desempilha o valor de todos os registradores de uso geral
    * Ordem de desempilhamento inversa à de PUSHA
* **PUSHF (Push Flags):** empilha o valor de todas as flags
* **POPF (Pop Flags):** desempilha o valor de todas as flags
<br><br>
### Sub-Rotinas
* Implementação de tarefas complexas em componentes mais simples
* Melhoram a legibilidade e facilitam manutenção
* Podem ser chamadas como se fossem instrução presente na linguagem
* Em linguagem de montagem, usa-se as instruções **CALL** e **RET**
* **CALL:** salva na pilha o endereço da instrução seguinte e transfere a execução para o endereço especifico pelo rótulo
    * <code>CALL rot</code>
    * Equivalente a
        ```asm
        push %epi
        jmp rot
        ```
* **RET**: recupera da pilha o endereço da próxima instrução, transferindo a execução para tal endereço
    * Equivalente a
        ```asm
        pop %ebx
        jmp %ebx
        ```
* **Exemplo de Programa implementando Sub-Rotinas:**
    ```asm
    _start:     
                ...
                call abre_arq
                ...             ; operacoes de manipulacao do arquivo
                ...             ; outras operacoes
                call fecha_arq
                ...

    abre_arq:
                ...
                mov $5, %eax    ; syscall (open)
                int 0x80
                ret

    fechar_arq:
                ...
                mov $6, %eax    ; syscall (close)
                int 0x80
                ret
    ```
<br><br>
### Implementando Funções
* Implementadas como sub-rotinas (call e ret)
* Passagem de parâmetros via pilha
* Pilha armazena variáveis locais da função
* Valor de retorno através da pilha ou EAX
* **Responsabilidades do programador na Chamada:**
    * Empilhar parâmetros
    * Chamar função
    * Liberar espaço dos parâmetros
* **Responsabilidades da Função Chamada:**
    * Salvar BP do chamador
    * Salvar todos os registradores a serem afetados
    * Alocar espaço de variáveis locais
    * Setar valor de retorno (espaço próprio ou EAX)
    * Desalocar as variáveis locais
    * Restaurar registradores
    * Restaurar BP
    * Retornar
<br><br>
### Exercícios
* **01:** Função que receba um inteiro *i* e uma string *s* (endereço do vetor de caracteres), transformando *i* em string e armazenando em *s*
* **02:** Função que recebe inteiro *i* e string *s*, armazenando em *s* a representação hexadecimal do número
    * *Dica:* operações lógicas e rotações (SHR e SHL) para obter bits específicos
    * SHR $4, %eax
        * Rotaciona EAX 4 bits à direita (equivale a dividir por 2<sup>4</sup>)
<br><br>
### Useful Links
* [Funções em Assembly](http://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/15AssemblyFunctions.pdf)
* Capítulo 07 de *Linux Assembly Language Programming*