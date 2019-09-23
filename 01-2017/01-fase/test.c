#include <stdio.h>
#include "instr.h"

INSTR programa[] = {
  {PUSH, 3},
  {PUSH, 6},
  {CALL, 5},
  {PRN,  0},
  {END,  0},
  {ADD,  0},
  {RET,  0}
};

int main () {

    printf("%d", programa[2].op.t);
    return 0;
}
