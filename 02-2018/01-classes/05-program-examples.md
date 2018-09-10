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
<table>
    <tr>
        <th>Function</th>
        <th>AT&T</th>
        <th>Intel</th>
    </tr>
    <tr>
        <td><em>Operand Order</em></td>
        <td>MOV origin, destination</td>
        <td>MOV destination, origin</td>
    </tr>
    <tr>
        <td><em>Variable Declaration</em></td>
        <td>var1: .int value</td>
        <td>var2: DB value</td>
    </tr>
    <tr>
        <td><em>Constant Declaration</em></td>
        <td>const1 = value</td>
        <td>const2: EQU value</td>
    </tr>
    <tr>
        <td><em>Register Use</em></td>
        <td>MOV %eax, %ebx</td>
        <td>MOV ebx, eax</td>
    </tr>
    <tr>
        <td><em>Variable Use</em></td>
        <td>MOV $var1, %eax</td>
        <td>MOV eax, var2</td>
    </tr>
    <tr>
        <td><em>Constant Use</em></td>
        <td>MOV $const1, %eax</td>
        <td>MOV eax, const2</td>
    </tr>
    <tr>
        <td><em>Immediate Use</em></td>
        <td>MOV $57, %eax</td>
        <td>MOV eax, 57</td>
    </tr>
    <tr>
        <td><em>Hex Numbers</em></td>
        <td>MOV $0xFF, %eax</td>
        <td>MOV eax, 0FFh</td>
    </tr>
    <tr>
        <td><em>Size of Operations</em></td>
        <td>MOVB [ebx], %al</td>
        <td>MOV al, byte [ebx]</td>
    </tr>
    <tr>
        <td><em>Comment Delimiter</em></td>
        <td># comment in AT&T</td>
        <td>; comment in Intel</td>
    </tr>
</table>

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