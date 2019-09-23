/* Códigos das instruções */
typedef enum {
  PUSH,
  POP,
  DUP,
  ADD,
  SUB,
  MUL,
  DIV,
  JMP,
  JIT,
  JIF,
  CALL,
  RET,
  STS,
  RCS,
  EQ,
  GT,
  GE,
  LT,
  LE,
  NE,
  STO,
  RCL,
  END,
  PRN,
  ALC,
  FRE,
  STL,
  RCE,
  ATR
} OpCode;

/* Tipos dos operandos */
/* no momento, são todos inteiros */
typedef enum {
  NUM,
  ACAO,
  CEL,
  VAR
} Tipo;

/* Operando */
/* typedef struct { */
/*   Tipo t; */
/*   union { */
/* 	int n; */
/* 	int ac; */
/* 	int v; */
/*   }; */
/* } OPERANDO; */
typedef struct OP {
  Tipo t;
  celula cel;
  int val;
} OPERANDO;

/* Instrução */
typedef struct {
  OpCode instr;
  OPERANDO op;
} INSTR;
