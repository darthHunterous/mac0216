#include <stdio.h>
#include "maq.h"

INSTR prog[] = {


  {PUSH, 8},
  {CALL, 4},
  {PRN, 0},
  {END, 0},


  {ALC, 1},
  {DUP, 0},
  {STL, 1},
  {PUSH, 1},
  {EQ, 0},
  {JIF, 13},
  {PUSH, 1},
  {FRE, 1},
  {RET, 0},
  {RCE, 1},
  {PUSH, 1},
  {SUB, 0},
  {CALL, 4},
  {RCE, 1},
  {MUL, 0},
  {FRE, 1},
  {RET, 0},

};

int main(int ac, char **av) {
    Maquina *maq = cria_maquina(prog);
    exec_maquina(maq, 10000);
    destroi_maquina(maq);
    return 0;
}
