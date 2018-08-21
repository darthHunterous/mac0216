# 05 - Assembly Programs Examples

* **Disassemblers**
    * Receives an executable ou object code and outputs a programa in Assembly
    * **objdump**
        * <code>objdump -D hello.</code>
<br><br>
* **Program Structure**
    * **.text**
        * Executable code, read-only section
    * **.data**
        * Initialized data and variables
    * **.bss**
        * Uninitialized data and variables
    * **_start**
        * Indicates the program start
        * Similar to main() in C
    * **.global _start**
        * Declares the symbol as externally visible
<br><br>
* **Variable Declaration**
    * **Variable**
        * Data that can be updated by the program
        * Has a type and a memory address
        * Pseudo-instructions define the variable type
        * Assembler addresses the memory
        * Variables, constants and label naming
            * Only letters, numbers or '_', '$', '.'
            * Starts with a letter, '_' or '.'
                * '.' denotes a local label
                    * [Section 3.9 - Local Labels](https://www.nasm.us/xdoc/2.10.07/html/nasmdoc3.html)
                    * Local labels are associated with the previous non-local label
                    ```assembly
                    label1  ; some code
                    .loop
                            ; some more code
                            jne  .loop
                            ret
                    label2  ; some code
                    .loop
                            ; some more code
                            jne .loop
                            ret
                    ```
                    * The first .loop defines a symbol called label1.loop and the second defines label2.loop, both can be used to specify a given jump
<br><br>
* **Initialized Variable Declaration**
    * Done in section .data
    * **Pseudo-Instructions**
        * **.byte**
            * Defines byte (1 byte)
        * **.word**
            * Defines word (2 consecutive bytes)
        * **.4byte**
            * Defines doubleword (4 consecutive bytes)
        * **.8byte**
            * Defines quadword (8 consecutive bytes)
<br><br>
* **Accessing Memory Through Variables**
    ```assembly
    .data

    var1:  .word  0x0f17

    .text
           mov  $var1, %eax  # copies to EAX the address associated to var1
           mov  var1, %eax   # copies to EAX the value of var1, 0x0f17
<br><br>
* **Differences Between AT&T and Intel Syntaxes**
    | Function             | AT&T                    | Intel                   |
    |:--------------------:|:-----------------------:|:-----------------------:|
    | *Operand Order*        | MOV origin, destination | MOV destination, origin |
    | *Variable Declaration* | var1: .int value        | var2: DB value          |
    | *Constant Declaration* | const1 = value          | const2: EQU value       |
    | *Register Use*         | MOV %eax, %ebx          | MOV ebx, eax            |
    | *Variable Use*         | MOV $var1, %eax         | MOV eax, var2           |
    | *Constant Use*         | MOV $const1, %eax       | MOV eax, const2         |
    | *Immediate Use*        | MOV $57, %eax           | MOV eax, 57             |
    | *Hex Numbers*          | MOV $0xFF, %eax         | MOV eax, 0FFh           |
    | *Size of Operations*   | MOVB [ebx], %al         | MOV al, byte [ebx]      |
    | *Comment Delimiter*    | # comment in AT&T       | ; comment in Intel      |
<br><br>
* **Exercises**
    * **01**
        * Program that reads a text from StdIn and outputs it in capital letters to StdOut
            * Non-lowercase letters shouldn't be altered
    * **02**
        * Program that reads a text from StdIn and outputs it reversed
    * **03**
        * Program that reads a text from StdIn and outputs its characters and words ammount
            * Space character should be considered the word separator
            * To print the results to StdOut, numbers have to been converted as strings