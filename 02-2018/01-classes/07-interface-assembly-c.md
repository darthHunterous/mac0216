# Aula 07 - Interface entre Assembly e C

### Considerações

* Funções como sub-rotinas (CALL e RET)
* Passagem de parâmetros via pilha
* Pilha armazena variáveis locais da função
* Valor de retorno na pilha ou EAX
* A função não deve mudar o valor inicial dos registradores

### Responsabilidades do Chamador

* Empilhar parâmetros
* Chamar função
* Liberar espaço dos parâmetros

### Responsabilidades da Função Chamada

* Salvar BP do chamador
* Salvar registradores afetados
* Aloca espaço para variáveis locais
* Trabalho usando argumentos e variáveis locais
* Setar valor de retorno (espaço próprio ou EAX)
* Desalocar variáveis locais
* Restaurar registradores
* Restaurar BP
* Retornar

### Função <code>int FUNC (int A, int B, int C)</code>

* Retorna (A<sup>2</sup> + B<sup>2</sup>) / C<sup>2</sup>
* **Pilha de 32 bits**
    <table>
        <tr>
            <td>2 bytes</td>
            <td>temp3</td>
            <td><strong>&larr; ESP</strong></td>
            <td></td>
            <td>A</td>
            <td>+8</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>temp2</td>
            <td></td>
            <td></td>
            <td>B</td>
            <td>+10</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>temp1</td>
            <td></td>
            <td></td>
            <td>C</td>
            <td>+12</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>DX</td>
            <td></td>
            <td></td>
            <td>temp1</td>
            <td>-4</td>
        </tr>
        <tr>
            <td>4 bytes</td>
            <td>EBP (1)</td>
            <td><strong>&larr; EBP (2)</strong></td>
            <td></td>
            <td>temp2</td>
            <td>-6</td>
        </tr>
        <tr>
            <td>4 bytes</td>
            <td>EIP</td>
            <td></td>
            <td></td>
            <td>temp3</td>
            <td>-8</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>10 (A)</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>20 (B)</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>5 (C)</td>
        </tr>
        <tr>
            <td><strong>EBP (1) &rarr;</strong></td>
            <td>...</td>
        </tr>
    </table>
* **Pilha de 64 bits**
    <table>
        <tr>
            <td>128 bytes</td>
            <td><strong>REDZONE</strong></td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>temp3</td>
            <td><strong>&larr; RSP</strong></td>
            <td></td>
            <td>A</td>
            <td>+16</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>temp2</td>
            <td></td>
            <td></td>
            <td>B</td>
            <td>+18</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>temp1</td>
            <td></td>
            <td></td>
            <td>C</td>
            <td>+20</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>DX</td>
            <td></td>
            <td></td>
            <td>temp1</td>
            <td>-4</td>
        </tr>
        <tr>
            <td>8 bytes</td>
            <td>RBP (1)</td>
            <td><strong>&larr; RBP (2)</strong></td>
            <td></td>
            <td>temp2</td>
            <td>-6</td>
        </tr>
        <tr>
            <td>8 bytes</td>
            <td>EIP</td>
            <td></td>
            <td></td>
            <td>temp3</td>
            <td>-8</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>10 (A)</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>20 (B)</td>
        </tr>
        <tr>
            <td>2 bytes</td>
            <td>5 (C)</td>
        </tr>
        <tr>
            <td><strong>EBP (1) &rarr;</strong></td>
            <td>...</td>
        </tr>
    </table>

### Gerando executável para 32 bits em Computador 64 bits

* **Montagem**
    * <code>nasm -f elf32 funcao32.asm</code>
    * <code>as --32 -o funcao32.0 funcao32.s</code>
* **Ligação**
    * <code>ld -m elf_i386 -o funcao32 funcao32.o</code>
* Execução de funcao32 deve funcionar em computador 64 bits também

### Funções em Assembly a partir de programas em C

* **Convenções de funções - 32 bits**
    * Parâmetros passados pela pilha
    * Parâmetros empilhados da direita para esquerda. Último parâmetro é empilhado primeiro.
    * Valor de retorno em AL, AX ou EAX
    * Convenções tradicionais também são válidas
        * Definir stack frame
        * Salvar registradores
        * Alocar ou desalocar espaço na pilha para variáveis locais

* **Exemplo de função soma em C**
    ```c
    #include <stdio.h>
    
    int soma(int, int);

    void main() {
        int x,y;
        x = 2; y = x++;
        printf("%d\n", soma(x, y++));
    }

    int soma(int a, int b) {
        int x;
        x = a + b;
        return x;
    }
    ```
* **Exemplo função soma em Assembly - 32 bits**
    ```asm
    .global soma

    var_x   = -4
    param_a = 8
    param_b = 12

    soma:  push  %ebp                   # cria stack frame
           mov   %esp, %ebp
           sub   $4, %esp               # reserva espaco de x
           mov   param_a(%ebp), %eax    # obtem a
           add   param_b(%ebp), %eax    # soma a e b e armazena em eax
           mov   %eax, var_x(%ebp)      # armazena a soma em x
           mov   %eax, var_x(%ebp)      # valor de retorno em x
           add   $4, %esp               # libera espaco de x
           pop   %ebp                   # restaura o apontador da base
           ret
    ```
* **Convenções de Funções em 64 bits**
    * Parâmetros passados pelos registradores RDI, RSI, RDX, RCX, R8, R9 (em ordem). Demais parâmetros são passados pela pilha
    * Parâmetros passados da esquerda para direita (primeiro em RDI, segundo em RSI, etc)
    * Registradores acima e RAX, R10 e R11 são alterados na chamada, portanto podem ser usados na função sem terem seus valores salvos
    * Valores inteiros são retornados em RAX (RDX também se o valor tiver mais de 64 bits)
    * Exemplo, em void foo(long a, int b), a é passado em RDI (long ocupa 64bits) e b em ESI (int ocupa 32)
* **Exemplo Função Soma em Assembly - 64 bits**
    ```asm
    .global soma

    soma:
            push  %rbp              # cria stack frame
            mov   %rsp, %rbp
            sub   $4, %rsp          # reserva espaco para x
            mov   %edi, (%rbp-$4)   # armazena primeiro parametro em x
            add   %esi, (%rbp-$4)   # soma os dois parametros de entrada
            mov   (%rbp-$4), %eax   # armazena x em eax (retorno da funcao)
            add   $4, %rsp          # libera espaco de x
            pop   %rbp              # restaura a base da pilha
            ret
    ```
<br><br>
### Executáveis de programas mistos
* <code>gcc -m32 -o prog prog.c soma.s</code>
    * -m32 gera executável de arquitetura 32 bits (-m64 análogo)
    * -o prog gera um executável de nome prog
    * No gcc a extensão do arquivo em assembly deve ser .s
    * Na sintaxe Intel, o .s deve incluir ".intel_syntax noprefix"
    * Comentários na sintaxe da Intel iniciam-se por \#
    * Pode ser necessária instalação de gcc-multilib
* **Gerando código objeto e fazendo ligação**
    * Montagem
        * <code>as --32 -o soma.o soma.s</code>
        * <code>gcc -c -m32 -o prog.o prog.c</code>
    * Ligação
        * <code>gcc -o prog -m32 prog.o soma.o</code>
* **Chamada a funções em C a partir de Assembly 32 bits**
    ```asm
    global main    ; no gcc, rotulo de entrada por padrao e' main
    extern printf

    section .text

    main:
         push  dword[num]  ; segundo param int
         push  dword msg   ; primeiro param *char
         call  printf      ; chama funcao printf
         add   esp, 8      ; libera espaco dos params
         ret
    
    section .data

    msg: DB 'Esse numero -> %d <- deveria ser 1234.', 10,0
    num: DD 1234
    ```
* **Chamada a funções em C em Assembly 64 bits**
    ```asm
    .global main
    .extern printf

    .text
    main:
         mov  $msg, %rdi  # primeiro param: *char
         mov  num, %rsi   # segundo param : int
         mov  $0, %rax    # rax deve conter qtd params nao int de printf
         call printf      # chama printf
         ret

    .data
    msg: .string "Esse numero -> %d <- deveria ser 1234.\n"
    num: .word 1234
    ```
<br><br>
* **Gerar código em Assembly a partir de C**
    * <code>gcc -S -m32 -masm=intel -fverbose-asm programa.c</code>
    * -S (gera código em Assembly)
    * -m32: arquitetura 32 bits (-m64 para 64 bits)
    * -masm=intel (código sintaxe Intel. Por padrão utiliza-se AT&T)
    * -fverbose-asm (inclui comentários no código para facilitar a compreensão)
<br><br>
* **Links Úteis**
    * [Funções em Linguagem de Montagem](http://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/15AssemblyFunctions.pdf)
    * [Convenções Chamada x86](https://en.wikipedia.org/wiki/X86_calling_conventions)
    