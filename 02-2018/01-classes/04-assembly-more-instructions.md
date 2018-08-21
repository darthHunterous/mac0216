# 04 - Assembly Instructions and Programs

* **Multiplication - MUL**
    * mul reg|mem
    * Only valid for multiplying unsigned numbers
    * Multiplication might generate a number with double the ammount of bits of the operands
        * **8 bits**
            * mul %bh
            * ax = al * bh
            * Operand is **always** multiplied by the value in **al** and stored in **ax**
        * **16 bits**
            * mul %bx
            * Operand is **always** multiplied by the value in **ax** and the 32 bits result is stored in two 16 bits registers
                * 16 first bits in **ax**
                * 16 last bits in **dx**
        * **32 bits**
            * mul %ebx
            * Operand is always multipled by the value in **eax** and the 64 bits result is stored in two 32 bits registers
                * 32 first bits in **eax**
                * 32 last bits in **edx**
    * MUL can't be used with a constant operand
<br><br>
* **Integer Division - DIV**
    * Inverse of mul
    * Valid only for unsigned integers division
    * div reg|mem
    * div %bh
        * Divides the value in **ax** by the value in **bh**, storing the quotient in **al** and the remainder in **ah**
   * | Divisor | Dividend | Remainder | Quotient |
     |:-------:|:--------:|:---------:|:--------:|
     | 32 bits | edx:eax  |    edx    |   eax    |
     | 16 bits |  dx:ax   |    dx     |    ax    |
     | 8 bits  |    ax    |    ah     |    al    |
    * **Exceptions**
        * Division by zero
        * Overflow
            * When the remainder won't fit the register
                ```assembly
                mov  $1024, %ax
                mov  $2, %bh
                div  %bh
                ```
                * Quotient should be stored in **AL** but 512 occupies at least 10 bits
<br><br>
* **Division and Multiplication of Signed Numbers - IMUL and IDIV**
    * Analogous to DIV and MUL
    * imul reg|mem
    * idiv reg|mem
<br><br>
* **Logical Instructions - AND, OR, NOT**
    * Result is stored in second operand
    * **AND**
        * and reg|mem|const, reg
        * and reg|const, mem
    * **OR**
        * or reg|mem|const, reg
        * or reg|const, mem
    * **XOR**
        * xor reg|mem|const, reg
        * xor reg|const, mem
    * **NOT**
        * not reg|mem
        * Invert bits
* **Tricks with Logical Instructions**
    * **Set a bit**
        * **Example**
            * Setting the third less significant bit of AH
            * or $0b00000100, %ah
    * **Reset a bit**
        * **Example**
            * Reset the third less significant of AH
            * and $0b11111011, %ah
    * **Invert specific bits**
        * **Example**
            * Invert the fourth less significant bit of AX
            * xor $0x1000, %ax
    * **Examine specific bits**
        * **Example**
            * Determine the value of the fourth less significant bit of AX
            * and $0x1000, %ax
            * If the result is zero, the bit is 0, otherwise, is 1
    * **Zero a register**
        * xor %ecx, %ecx
    * **Check if a register is Null**
        * or %ecx, %ecx
        * If the register is null, the zero flag is set
<br><br>
* **Changing Signal - NEG**
    * Generates the two's complement of the operand
    * NEG reg|mem
    * neg %eax
        * Equivalent to
            * not %eax
            * add $1, %eax
<br><br>
* **Unconditional Jump - JMP**
    * Transfer the execution to the address specified by the label
    * jmp label
    ```assembly
    inicio:  mov $5, %eax
             add %eax, %eax
             jmp inicio
    ```
<br><br>
* **Comparison Instruction - CMP**
    * Compares the first operand value with the second, storing in a flag
    * cmp reg|mem|const, reg
    * cmp $5, %ax
    * cpm (%ebx), %cx
<br><br>
* **Conditional Jumps - Instructions**
    * **JE**
        * Jump If Equal
    * **JNE**
        * Jump If Not Equal
    * **JG**
        * Jump If Greater
    * **JGE**
        * Jump If Greater Or Equal
    * **JNG**
        * Jump If Not Greater
    * **JNGE**
        * Jump If Not Greater Or Equal
    * **JL**
        * Jump If Less
    * **JLE**
        * Jump If Less Or Equal
    * **JNL**
        * Jump If Not Less
    * **JNLE**
        * Jump If Less Or Equal
* These jump consider the last comparison made, involving signed numbers
<br><br>
* **If-Else Command Structure**
    * If cont \< 15, then block01, else block02
    ```assembly
            ...
            cmp  15, %cx
            jnl  senao    # if counter >= 15
            ...           # block01
            jmp  fimse
    senao:  ...           # block02
    fimse:  ...           # instructions after if
    ```
* **While Command Structure**
    * While cont \< 15 do block, otherwise end
    ```assembly
             ...
             mov $0, %cx      # reset the counter
    inicio:  cmp $15, %cx
             jge fim          # if counter >= 15
             ...              # command block
             inc %cx          # increases counter
             jmp inicio       # jumps to the beginning
    fim:     mov (%ebx), %ax  # first instruction outside loop
             ...
    ```
<br><br>
* **Conditional Jumps - JZ and JNZ**
    * **JZ**
        * Jump If Zero
    * **JNZ**
        * Jump If Not Zero
    * These jumps consider the *last arithmetic or logic operation* 
<br><br>
* **Conditional Jumps - Unsigned Version**
    * Consider the last comparison made
    * **JA**
        * Jump If Above
    * **JAE**
        * Jump If Above Or Equal
    * **JNA**
        * Jump If Not Above
    * **JNAE**
        * Jump If Not Above Or Equal
    * **JB**
        * Jump If Below
    * **JBE**
        * Jump If Below Or Equal
    * **JNB**
        * Jump If Not Below
    * **JNBE**
        * Jump If Not Below Or Equal
<br><br>
* **System Calls**
    * How programs ask services to the OS Kernel
        * Read and write files, creation and execution of new processes
    * How to perform syscalls in Assembly
        * Put the syscall number in EAX
        * First 3 arguments in EBX, ECX and EDX (even ESI and EDI if necessary)
        * Generate the syscall interruption
            * INT 0x80
        * Return values are put in EAX
<br><br>
* **Assemblers**
    * **GCC Inline Assembly**
        * Support to x86 architecture
        * Machine language code can be inserted in C programs
        * Uses GAS
    * **GAS - GNU Assembler**
        * AT&T Syntax
            * Newer versions accepts Intel Syntax, used by most assemblers
        * Platforms
            * Unix
            * Windows
            * DOS
        * Part of <code>binutils</code> Linux package
        * Executable
            * <code>gas</code> or <code>as</code>
    * **NASM - Netwide Assembler**
        * Linux <code>nasm</code> package
        * <code>sudo apt-get install nasm</code>
<br><br>
* **NASM - Hello, world (32 bits) - hello.asm**
    ```assembly
    global _start  ; exports to the linker the entry point

    section .text
    _start:

        ; sys_write(stdout, message, size)

        mov eax, 4         ; sys_write system call
        mov ebx, 1         ; stdout
        mov ecx, mensagem  ; message address
        mov edx, tamanho   ; size of message string
        int 80h            ; kernel call

        ; sys_exit(return_code)

        mov eax, 1    ; syscall sys_exit
        mov ebx, 0    ; returns zero (success)
        int 80h       ; kernell call

    section  .data
    message: db 'Hello, world!', 0x0A  ; message and line break
    size:    equ $ - message           ; message size
    ```
* **NASM - Hello, World (64 bits) - hello.asm**
    ```assembly
    global _start    ; exports the entry point to linker

    section .text
    _start:

        ; sys_write(stdout, message, size)

        mov rax, 1          ; sys_write syscall
        mov rdi, 1          ; stdout
        mov rsi, message    ; message address
        mov rdx, size       ; message string size
        syscall             ; kernel call

        ; sys_exit(return_code)

        mov rax, 60    ; sys_exit syscall
        mov rdi, 0     ; returns zero for success
        syscall        ; kernel call
    
    section .data
    message: db 'Hello, world!', 0x0A  ; message and linebreak
    size:    equ $ 0 message           ; message size
    ```
* **GAS - Hello, World (32 bits) - hello.S**
    ```assembly
    .text

        .global  _start  # exports the entry point to the linker

    _start:
        # sys_write(stdout, message, size)
        movl  $4, %eax        # syscal for sys_write
        movl  $1, %ebx        # stdout
        movl  $message, %ecx  # message addres
        movl  $tamanho, %edx  # message string size
        int   $0x80

        # sys_exit(return_code)
        movl  $1, %eax  # syscall sys_exit
        movl  $0, %ebx  # returns zero (success)
        int   $0x80     # kernel call

    .data
    message:
        .ascii  "Hello, world!\n"  # message and linebreak
        tamanho =  . - message     # message size
    ```
<br><br>
* **Generating the Executable**
    * **Step 01 - Generating the Object Code**
        * 32 bits, NASM
            * <code>nasm -f elf32 hello.asm</code>
        * 64 bits, NASM
            * <code>nasm -f elf64 hello.asm</code>
        * GAS
            * <code>as -o hello.o hello.S</code>
        * These commands generate a hello.o file
    * **Step 02 - Linking (Generating Machine Code)**
        * <code>ld -s -o hello hello.o</code>
        * Generates the hello executable
<br><br>
* **Structure of a Assembly Program**
    * **Sections**
        * **.text**
            * Source-code, read-only section
        * **.data**
            * Where data and variables are stored
        * **.bss**
            * Uninitialized data and variables
<br><br>
* **Useful Links**
    * [NASM - The Netwide Assembler](http://www.nasm.us/)
    * [GAS - GNU Assembler](http://sourceware.org/binutils/docs-2.23/as/index.html)
    * [Comparison between GAS and NASM](http://www.ibm.com/developerworks/linux/library/l-gas-nasm/index.html)
    * [Syscalls Table](http://www.ime.usp.br/~kon/MAC211/syscalls.html)


