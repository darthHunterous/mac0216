# 01 - Introduction

* **Topics**
    * Computery History and basics of computer architecture
    * Assembly
    * Program linking
    * Tools for compilation
        * Make
        * Ant
    * Code modularization
    * Development of a medium port program in a procedural language
        * C
    * Depuration techniques and testing
    * Version Control
    * Regex
    * Lexical analysers
        * Flex
    * Syntatic analysers
        * Bison
    * Standard input and output
        * Concatenation through pipelines
    * Textual processing languages
<br><br>
* **Computer History**
    * **Early Age - Calculators**
        * Abacus
            * Mesopotamia - 5500 B.C.
            * Sums and subtractions
        * Slide Rule
            * William Oughtred - England, 1638
            * Based on logarithms studies from John Napier
            * Multiplying big numbers
        * Pascal Machine
            * France, 1642
            * First mechanical calculator
            * Sums and subtractions
            * Leibniz created in 1694 an enhanced version, capable of multiplications and divisions
        * Arithmomètre
            * Charles Xavier Thomas, France, 1820
            * First mechanical calculator comercialized
        * **Those devices weren't programmable, thus the calculator wording**
    * **Early Age - Jacquard Loom**
        * 1790
        * Capable of drawing complex patterns
        * Drawings were coded in punched cards
        * Artisans feared for their jobs
    * **Early Age - Remarkable People**
        * Babbage
            * 1791 - 1871
            * Analytical machine (1833)
            * It was a programmable machine but was unable to build it
        * Ada Lovelace (1815 - 1852)
            * Wrote programs for the Babagge machine
            * Invented the term "algorithm"
                * Homage to the arab mathematician Al-Khawarizmi, 720 A.D.
        * Hollerith (1860 - 1929)
            * Punched cards for the american census in 1890
            * Lead to IBM's foundation
        * Turing (1912 - 1954)
            * Many contributions to Computer Science
                * Computability
                * Criptology
                * Programming
                * Neural Networks
                * AI
        * Von Neumann (1903 - 1957)
            * Mathematician that engineered the modern computer architecture
<br><br>
* **History of Computer Architecture**
    * **First Generation - Valve**
        * 1941 - 1957
        * Used for calculations
        * Each machine had its own code
            * New functions required reprogramming the computer
        * Overheating
        * Each on or off valve represented a machine instruction
        * ENIAC - 1945
            * Electronic Numerical Integrator and Computer
            * First digital eletronic computer
            * 30 tons
            * 18 thousand valves
            * 4500 calculations per second
            * Inspired Von Neumann to develop the concept of **program stored in memory**
    * **Second Generation - Transistor**
        * 1958 - 1964
        * Transistor
            * Eletronic component created in 1947 in the Bell Laboratories
            * From silicon
        * Advantages over valves
            * Smaller, less heat and don't break with physical shocks
        * Computers 100 times smaller than those from the First Generation
        * More energy efficient and less expensive
        * Programmable in assemble language instead of machine language
        * IBM 7094 (1962)
            * Storage in magnetic tape
            * Punched cards also
            * More than 10 thousand units sold (sales success)
        * The transistor was one of the biggest inventions in modern history
            * Provided the computer revolution
                * Can be easily mass produced, thus low cost
<br><br>
* **Third Generation - Integrated Circuit**
    * 1965 - 1970
    * Silicon integrated circuits made possible the miniaturization of eletronic components
    * Significant improvement in speed and efficiency
    * Keyboard and monitor for input and output
    * First non-graphical OS's
    * Machines capable of upgrades
    * IBM 360 (1965)
        * Sold more than 30 thousand units
        * Intel 4004 microprocessor
<br><br>
* **4th Generation - Microprocessors**
    * 1971 until today
    * 1971 - Intel 4004
        * First microprocessor
        * First integrated circuit accordingly to Von Neumann's architecture
            * UCP
            * Memory
            * Input/Output
    * Emergence of microcomputers with less than 20kg
    * 1975 - Altair 8800
        * Sold as a kit for specialized magazines
        * Its buses became a pattern in industry
    * 1975 - BASIC Interpreter creation
        * Bill Gates
        * Paul Allen
        * Foundation of Microsoft
    * 1976 - Apple Creation
        * Steve Jobs
        * Steve Wozniac
        * 1976 - Apple I
        * 1977 - Apple II
    * 1981 - IBM PC
    * 1981 - MS-DOS
    * 1984 - Macintosh first graph OS
        * Xerox already had a window based interface in 1973
    * 1985 - Windows 1.0
    * 1991 - Web Creation
    * 1991 - Linux
<br><br>
* **Present Day**
    * Parallel computing
    * Portable computers (notebooks, smartphones)
    * Ubiquitous computing
        * IoT
    * Green computing
        * Energy efficiency
        * Less hazardous material
<br><br>
* **Moore's Law**
    * 1965 - Gordon Moores, Intel's cofounder noticed that component ammount in integrated circuits had doubled every year since 1958 (integrated circuit invention)
        * He had foreseen that this tendency would continue for the following 10 years
    * Semiconductors industry uses Moore's Law as their goal in research and development
    * This law impacts in processing speed, memory capacity
<br><br>
* **Programming Language Evolution**
    * **High level Languages - Early Age**
        * 1957 - FORTRAN
            * FORmula TRANslating
            * Useful for number manipulation
        * 1958 - ALGOL 58
            * ALGOrithm Language
            * First structured language
        * 1958 - LISP
            * LISt Processing
            * Used in AI
        * 1959 - COBOL
            * COmmom Business Oriented Language
            * Useful for input/output manipulation
        * 1964 - BASIC
            * Beginners All-purpose Symbolic Instruction Code
        * 1967 - Simula 67
            * Fundamental concepts of OOP
    * **High Level Languages - "Modern"" Ones**
        * 1970 - PASCAL
            * Teaching language
            * Has the best of FORTRAN, COBOL, ALGOL
        * 1970 - PROLOG
            * PROgrammation en LOGique
            * Language for programming logics
        * 1972 - C
            * One of the most used languages
        * 1980 - Smalltalk
            * OOP
            * Best of LISP, Simula 67 and Logo
        * 1983 - C++ and Objective-C
            * C extension for OOP
        * 1987 - PERL
            * Practcal Extracting and Report Language
            * Based in scripts
        * 1995 - Java
            * Released as the "Internet language"
        * 2000 - C#
            * Mix of C++ and Java
            * Created by Microsoft
<br><br>
* **Useful Links**
    * [Chapter 2 - "Computer History"](http://ccsl.ime.usp.br/files/books/intro-java-cc.pdf)
    * Chapter 2 - "Computer Evolution and Performance"
        * William Stalling - "Computer Organization and Architecture"
    * [Microchip - Small Invention, Great Revolution](http://www.lsi.usp.br/~chip/como_funcionam.html)
    * [MAC0211 Notes](http://www.ime.usp.br/~kon/MAC211)