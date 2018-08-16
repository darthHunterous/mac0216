
# 03 - Assembly

* **Memory Organization**
    * Organized as rectangles of bits called **words**
        * Data transfer to or from memory are done one (or more) word(s) each time
    * Words in memory are consecutively numerated, starting from zero
        * Those numbers are the words **addresses**
        * Addresses are used by processors to transfer data to/from memory
    * **Memory Capacity**
        * Number of words times word size
        * Intel processors use 8 bits words
    * 1 byte = 8 bits
    * Number of words in computer memory is a exponentiation of 2
<br><br>
* **IEC - Binary Prefixes**
    * International Electrotechnical Commission
        * Ki = 2^10 (kibi)
        * Mi = 2^20 (mebi)
        * Gi = 2^30 (gibi)
        * Ti = 2^40 (tebi)
        * Pi = 2^50 (pebi)
* **SI - Decimal Prefixes**
    * International System of Units
        * k = 10^3 (kilo)
        * M = 10^6 (mega)
        * G = 10^9 (giga)
        * T = 10^12 (tera)
        * P = 10^15 (peta)
* 1 kibibyte (KiB) ≠ 1 kilobyte (kB)
<br><br>
* **Hexadecimal System**
    * 16 digits
        * From 0 to 9 then from A to F
    * Memory addresses are too big, thus hexadecimal system shorts them
* **Conversion from Decimal to Hex**
    * (1000)<sub>10</sub>  = (3E8)<sub>16</sub>
        * 1000 / 16 = 62 with remainder **8**
        * 62 / 16 = 3 with remainder **14**(**E**)
        * 3 / 16 = 0 with remainder **3**
    * Remainders are taken in the reverse order that they were generated
* **Relation between binary and hexadecimal systems**
    * Dividing by 2 four times equals dividing by 16 once
    * We can separate binary digits in groups of 4
        * Decimal number 1000
            * Binary(Hex digit) 0011(3) 1100(E) 1000(8)
    * Makes readability easier
    * With two hex digits we represent 1 byte
<br><br>
* **Negative Numbers in Binary**
    * **Signal Magnitude Representation**
        * Most significant bit represents the signal
            * 0 for positive and 1 for negative
            * (0101)<sub>2</sub> = (5)<sub>10</sub>
            * (1101)<sub>2</sub> = (-5)<sub>10</sub>
        * Summing gets complicated to the computer
            * **First Case**
                * Positive Numbers
                * Just sum
            * **Second Case**
                * Negative numbers
                * Remove signals, sum both of them and then add the negative signal again
            * **Third Case**
                * One positive and one negative
                * Subtracts the smaller number in absolute value from the biggest one
                    * If the biggest number in absolute value has a negative sign, put it in result too
    * Two's Complement**
        * Representation often used
        * Makes summing easy
            * No need to worry whether numbers are negative or positive
            * Just summing them is enough
        * **Example**
            * 4 bits
            * Cycles between (-8)<sub>10</sub> = (1000)<sub>2</sub> and (7)<sub>10</sub> = (0111)<sub>2</sub>
* **Converting to Two's Complement**
    * **Example** (-108)<sub>10</sub>
        * (108)<sub>10</sub> = (01101100)<sub>2</sub>
        * **Step 1:** invert bits
            * (10010011)<sub>2</sub>
        * **Step 2:** summing 1 to the result of inversion
            * (-108)<sub>10</sub> = (10010100)<sub>2</sub>
* **Subtraction in Two's Complement**
    * (109 - 108)<sub>10</sub> = (109 + (-108))<sub>10</sub>
    * Summing with the two's complement of the number to subtract
<br><br>
* **Reminder of x86 Processor Family Architecture**
    * A (accumulator)
    * B (base)
    * C (counter)
    * D (data)
    * **8086 processor (16 bits)**
        * AX (AH, AL), BX (BH, BL), CX (CH, CL), DX (DH, DL), SP, BP, SI, DI
    * **80386 processor (32 bits)**
        * EAX, EBX, ECX, EDX, ESP, EBP, ESI, EDI
    * **x86-64 and AMD64 processors (64 bits)**
        * RAX, RBX, RCX, RDX, RSP, RBP, RSI, RDI, R8-15
<br><br>
* **Assembler Language**
    * General Structure of an Instruction
        * **Label**
            * Gives names to program blocks
            * Are used in jumps
            * Must be alphanumeric starting with letters
        * **Mnemonics**
            * Specifies an instruction
            * Examples: MOV, ADD
        * **Operands**
            * Objects to apply instructions over
            * Instructions with more than one operand separates them with commas
            * Not every instruction has operands
        * **Comments**
            * Started with #
            * Documents the code
            * Particularly important in Assembly
<br><br>
* **Program Example**
    ```assembly
             mov $5, %cx     # contador <- 5
    inicio:  mov $0x25, %ax  # ax <- 25h
             add %ax, %ax    # ax += ax
             dec %cx         # contador -= 1   
             jnz inicio
    ```
<br><br>
* **Data Transfer Command - MOV**
    * Copies the value in the second operand to the first one without altering content in the second
    * Leftmost operand is the second one
    * **Formats**
        * mov reg|mem|const, reg
        * mov reg|const, mem
    * **Symbols meaning**
        * *reg*
            * register
        * *mem*
            * Memory position
            * Can be a constant like [1000] or a indicated through a register [EBX]
        * *const*
            * Constant value
    * **Examples**
        * **Correct**
            * mov $-14, %ah
            * mov $36h, %ax
            * mov 'a', %al
            * mov %eax, %ebx
            * mov $1000, %bx
            * mov %ax, (%ebx)
            * mov %ax, 1000
            * mov %ax, 1000(%ebx)
            * mov (1000), %ax
            * movl $0x36, (1000)
        * **Incorrect Uses**
            * *mov $999, %al*
                * 999 can't be stored in 8 bits
            * *mov %ebx, %dx*
                * Aren't registers of the same size
            * *mov (%ebx), 1000*
                * Data can't be trasnferred between memory positions directly
    * **No Size Ambiguity Cases**
        * Occurs between *mem* and *reg*
        * Words manipulated in memory is set by the size of the register
            * Example
                * mov 1000, %ax
                * Copies 2 words from memory (in positions 1000 and 1001) because *ax** has 16 bits size
    * **Size Ambiguity Cases**
        * Between *mem* and *const* operands
        * mov $5, %ebx
        * Ammount of manipulated words:
            * Determined by the architecture (16, 32 or 64 bits)
            * Notation use to determine the bytes ammount
                * movb $5, %ebx  # 8 bits
                * movw $5, %ebx  # 16 bits
                * movd $5, %ebx  # 32 bits
                * movq $5, %ebx  # 64 bits
<br><br>
* **Exchange Data Command - xcgh**
    * Swap the operands values
    * xcgh reg|mem, reg
    * xcgh reg, mem
    * **Examples**
        * xchg %ah, %bl
        * xchg %bl, (%ah)
        * xchg %ah, (%ebx)
<br><br>
* **Sum - ADD**
    * Sums the second operand with the first, storing in the first
    * add reg|mem|const, reg
    * **Examples**
        * add $10, %bl &nbsp;# bl += 10
        * add %al, %bl &nbsp;# bl += al
        * add ($1000), %bl &nbsp;# bl += (1000)
            * bl gets summed with the value in position 1000 in the memory
<br><br>
* **Subtraction - SUB**
    * Subtracts the value in the second operand from the first, storing in the first
    * sub reg|mem|const, reg
<br><br>
* **Increase and Decrease - INC and DEC**
    * Increase or decrease the operand value by 1
    * inc reg|mem
    * dec reg|mem
    * **Examples**
        * inc %cx # cx += 1
        * dec %cx # cx -= 1
<br><br>
* **Useful Links**
    * Chapters 03, 04 and 06 of *Linux Assembly Language Programming*
        * B. Neveln
    * [Book *The Art of Assembly Language Programming*](http://cs.smith.edu/~thiebaut/ArtOfAssembly/artofasm.html)
        * R. Hyde