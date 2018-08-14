# Class 02 - Architectures

* **ENIAC's Architecture**
    * No program storage
    * New calculations had the need of moving plugs and cables
    * Input -> leads to 4 separate components
        * Program
        * Controller (OS)
        * UCP
        * Memory
    * Leads to output
* **Von Neumann's Architecture**
    * Consulting mathematician of ENIAC's project
    * Published the concept of the stored program in 1945
    * Used in modern day computers
    * Input leads to 2 parts
        * Memory
            * Program
            * Data
            * Controller (OS)
        * CPU
    * Then it leads to output
* **Fetch-execute cycle**
    * Program
        * List of instructions
    * Computation through the **fetch-execute cycle**
        * Loop between
            * Processor reads an instruction from the memory
            * Processor executes the instruction
* **Simplified computer model**
    * **CPU**
        * **Registers**
            * Circuit collection to store bits
            * Easier to manage when they are capable of storing the same ammount of bits
            * The ammount of bits storable in a register is responsible for the processor classification (32 or 64 bits processor)
            * Each register has its own function
                * **PC - Program Counter**
                    * Points to the next instruction to be executed
                * **IR - Instruction Register**
                    * Stores the instruction in execution
                * Storage of intermediate results
        * **Arithmetic Logic Unit (ALU)**
            * Performs tasks related to logical and arithmetic operations
        * **Control Unit**
            * Controls the computer actions, coordinating other components from its architecture
    * **Memory**
    * **I/O**
    * Interconnected by the **address bus** and the **data bus**
<br><br>
* **Processors - Instructions Set**
    * Instructions are the operations that the processor is capable of performing
        * Processor portion visible to the programmer
    * Each processor has its own set of instructions
    * Through the **Assembler Language (Assembly)**, we can use this set of instructions directly
    * Processors with different internal architectures might have the same instruction set
        * Intel Pentium and AMD Athlon
    * **Operations**
        * Instruction functions
            * Mathematical and Logical operations
            * Data transfer
                * Memory to register or vice-versa
            * Input and output operations
            * Control Execution Flow
                * Condiional or Unconditional jumps
<br><br>
* **Processors - CISC and RISC**
    * **CISC - Complex Instruction Set Computer**
        * Capable of executing different complex instructions
        * Versatility
    * **RISC - Reduced Instruction Set Computer**
        * Capable of executing a few simples instructions
        * Quicker
        * Cheaper
    * **Example**
        * A = B + C
            * Where all values are stored in memory
        * **CISC Addition**
            ```
            add mem(B), mem(C), mem(A)
            ```
        * **RISC Addition**
            ```
            load  mem(B), reg(1);
            load  mem(C), reg(2);
            add   reg(1), reg(2), reg(3);
            store reg(3), mem(A);
            ```
<br><br>
* **Intel's x86 Processor Family (80x86)**
    * CISC processors
    * Compatible with its older processors verions
        * Program for an old processor can be run in a newer processor
    * Examples
        * 8086
        * 80186
        * 80286
        * 80386
        * 80486
        * Pentium
<br><br>
* **Intel 8080 Processor (8 bits)**
    * Memory of 2^8 segments of 1 byte
    * Address Bus of 8 bits
    * Data Bus of 8 bits
    * **Registers**
        * **A - Acumulator**
            * Data Transfer
            * Arithmetical Operations
            * Input/Output
        * **B - Base**
            * Pointer for memory access
            * Return value of some interruptions
        * **C - Counter**
            * Control the number of executions of a loop
            * Number of shifts to be executed
            * Also used in arithmetical operations
        * **D - Data**
            * Input/Output
            * Multiplication and division of big numbers
        * **H - High and L - Low**
            * Used together as a 16 bits register
            * Might be used for addresses
<br><br>
* **Intel 8086 (16 bits)**
    * Memory composed by 2^16 segments of 1 byte
        * From 0 to 65535 memory address
        * 0 at the top and 65535 at the bottom
            * Counter increases from top to bottom
    * Address Bus of 20 bits
    * Data Bus of 16 bits
    * **Registers**
        * **AX**
            * Composed by two 8 bits registers
                * AH and AL
        * **BX**
            * Composed by two 8 bits registers
                * BH and BL
        * **CX**
            * Composed by two 8 bits registers
                * CH and CL
        * **DX**
            * Composed by two 8 bits registers
                * DH and DL
        * **SP - Stack Pointer Register**
            * Stores the address at the top of the data stack
        * **BP - Stack Base Pointer Register**
            * Stores the address at the bottom of the data stack
        * **SI - Source Index Register**
            * String and array manipulation
        * **DI - Destination Index Register**
            * String and array manipulation
<br><br>
* **Intel 80386 (32 bits)**
    * Memory composed of 2^32 segments of 1 byte size
    * Address bus of 32 bits
    * Data bus of 32 bits
    * **Registers**
        * **EAX**
            * AX (16 bits)
                * Composed of AH and AL (8 bits each)
        * **EBX**
            * BX (16 bits)
                * Composed of BH and BL (8 bits each)
        * **ECX**
            * CX (16 bits)
                * Composed of CH and CL (8 bits each)
        * **EDX**
            * DX (16 bits)
                * Composed of DH and DL (8 bits each)
        * **ESP**
            * SP (16 bits)
        * **EBP**
            * BP (16 bits)
        * **ESI**
            * SI (16 bits)
        * **EDI**
            * DI (16 bits)
<br><br>
* **Intel x86-64 or AMD64 (64 bits)**
    * Memory composed by 2^64 segments of 1 byte size
    * Address bus of 64 bits
    * Data bus of 64 bits
    * **Registers**
        * **RAX**
            * EAX (32 bits)
        * **RBX**
            * EBX (32 bits)
        * **RCX**
            * ECX (32 bits)
        * **RDX**
            * EDX (32 bits)
        * **RSP**
            * ESP (32 bits)
        * **RBP**
            * EBP (32 bits)
        * **RSI**
            * ESI (32 bits)
        * **RDI**
            * EDI (32 bits)
        * **R8 to R15 Registers**
            * Eight extra registers
<br><br>
* **Fetch-Execute Cycle**
    * CPU Instruction execution steps
        * Reads next instruction in memory and stores in the **Instruction Register**
        * Changes **Program Counter** register to point to the next instruction
        * Determines the kind of instruction read
        * If the instruction uses a memory data, determines where it its
        * Loads data, if necessary, in a register
        * Executes instruction
        * Returns to the first step to execute following instruction
<br><br>
* **From High-Level Source Code to Executable Code**
    * GCC compilation steps
        * **Source code**
            * program.c
        * **Translation Unit**
            * program.c -> program.i
            * Through **Pre-Processing**
            * program.i
                * <code>gcc -E</code>
        * **Machine Language Code**
            * program.i -> program.s
            * Through **Compilation**
            * program.s
                * <code>gcc -S</code>
        * **Object Code**
            * program.s -> program.o
            * Through **Assembling**
            * prog.o
                * <code>gcc -c</code>
        * **Executable File**
            * program.o -> a.out
            * Through **Linking**
            * a.out
                * <code>gcc</code>
<br><br>
* **Assembler Language (Assembly)**
    * **Advantages**
        * To learn how a CPU works
        * Total control over the code
        * Better performance over critical parts of the program
        * To write a new OS or porting to a new machine
        * Access unusual processor programming modes
            * Example: 16-bit mode
        * Manually optimize code generated through a not efficient compiler
        * Generate optimized code for a given hardware configuration
    * **Disadvantages**
        * Long code
        * Highly prone to errors
        * Difficult to track errors
        * Hard to maintain
        * The code is not portable to other architectures
<br><br>
* **Numeral System**
    * **Decimal System (base 10)**
        * ENIAC
        * Positional system
            * Value of a digit depends on its position
            * Total number value is the sum of each digit relative value
                * 735 = 7\*10^2 + 3\*10^1 + 5\*10^0
    * **Binary System**
        * Only two digits (0 and 1)
    * **From Binary to Decimal**
        * (111001,1)<sub>2</sub> = (1\*2^5 + 1\*2^4 + 1\*2^3 + 0\*2^2 + 0\*2^1 + 1\*2^0 + 1\*2^-1)<sub>10</sub>
            * Equals to (57,5)<sub>10</sub>
    * **From Decimal to Binary**
        * (57,3125)<sub>10</sub> = (111001,0101)<sub>2</sub>
        * **Integer Part - Successive Divisions Method**
            * 57 // 02 = 28 with remainder **1** (**Least** Significant Bit)
            * 28 // 02 = 14 with remainder **0**
            * 14 // 02 = 07 with remainder **0**
            * 07 // 02 = 03 with remainder **1**
            * 03 // 02 = 01 with remainder **1**
            * 01 // 02 = 00 with remainder **1** (**Most** Significant Bit)
        * **Fractional Part - Successive Multiplications Method**
            * 0,3125 \* 2 = **0**,625 (**Most** Significant Bit)
            * 0,6250 \* 2 = **1**,250
            * 0,2500 \* 2 = **0**,500
            * 0,5000 \* 2 = **1**,000 (**Least** Significant Bit)
        * For Integer Part, remainders are taken in inverse of their generated order
        * For Fractional Part, remainders are takine in their generated order
<br><br>
* **Binary Arithmetic**
    * **Addition**
        * 0 + 0 = 0
        * 0 + 1 = 1
        * 1 + 0 = 1
        * 1 + 1 = 10
    * **Subtraction**
        * 0 - 0 = 0
        * 1 - 0 = 1
        * 1 - 1 = 0
        * 10 - 1 = 1
<br><br>
* **Useful Links**
    * [GCC Compilation Steps](http://www.redhat.com/magazine/002dec04/features/gcc/)
    * [Chapter 02 - Linux Assembly HOWTO](http://www.tldp.org/HOWTO/pdf/Assembly-HOWTO.pdf)
        * Boldyshev and Rideau
    * Chapter 01, 02 and 03 of "Linux Assembly Language Programming"
        * Neveln
    * "Structured Computer Organization"
        * Tanenbaum
