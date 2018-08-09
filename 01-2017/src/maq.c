#include <stdio.h>
#include <stdlib.h>
#include "maq.h"

/* #define DEBUG */

#ifdef DEBUG
#  define D(X) X
char *CODES[] = {
  "PUSH",
  "POP",
  "DUP",
  "ADD",
  "SUB",
  "MUL",
  "DIV",
  "JMP",
  "JIT",
  "JIF",
  "CALL",
  "RET",
  "STS",
  "RCS",
  "EQ",
  "GT",
  "GE",
  "LT",
  "LE",
  "NE",
  "STO",
  "RCL",
  "END",
  "PRN",
  "ALC",
  "FRE",
  "STL",
  "RCE",
  "ATR"
};
#else
#  define D(X)
#endif

static void Erro(char *msg) {
  fprintf(stderr, "%s\n", msg);
}

static void Fatal(char *msg, int cod) {
  Erro(msg);
  exit(cod);
}

Maquina *cria_maquina(INSTR *p) {
  Maquina *m = (Maquina*)malloc(sizeof(Maquina));
  if (!m) Fatal("Memória insuficiente",4);
  m->ip = 0;
  m->prog = p;
  m->rbp = 0;
  m->cristais = 0;
  return m;
}

void destroi_maquina(Maquina *m) {
  free(m);
}

/* Alguns macros para facilitar a leitura do código */
#define ip (m->ip)
#define pil (&m->pil)
#define exec (&m->exec)
#define prg (m->prog)
#define rbp (m->rbp) /* Para facilitar o uso do rbp da maquina */

void exec_maquina(Maquina *m, int n) {
  int i;

  for (i = 0; i < n; i++) {
	OpCode   opc = prg[ip].instr;
	OPERANDO arg = prg[ip].op;

	D(printf("%3d: %-4.4s %d\n     ", ip, CODES[opc], arg));

	switch (opc) {
	  OPERANDO tmp;
	  OPERANDO op1;
	  OPERANDO op2;
	  OPERANDO res;

	case PUSH:
	  res.t = NUM;
	  res.val = arg;
	  empilha(pil, res);
	  break;
	case POP:
	  desempilha(pil);
	  break;
	case DUP:
	  tmp = desempilha(pil);
	  empilha(pil, tmp);
	  empilha(pil, tmp);
	  break;
	case ADD:
		op1 = desempilha(pil);
		op2 = desempilha(pil);

		if (op1.t == NUM && op2.t == NUM) {
			res.t = NUM;
			res.val = op1.val + op2.val;
			empilha (pil, res);
		}
		else {
			printf ("Operação invalida!\n");
			empilha(pil, op2);
			empilha(pil, op1);
		}
	  break;
	case SUB:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  if (op1.t == NUM && op2.t == NUM) {
	  	res.t = NUM;
	  	res.val = pil, op2.val - op1.val;
	  	empilha(pil, res);
	  }
	  else {
	  	printf ("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case MUL:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);

	  if (op1.t == NUM && op2.t == NUM) {
	  	res.t = NUM;
	  	res.val = op1.val * op2.val;
	  	empilha(pil, res);
	  }
	  else {
	  	printf ("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case DIV:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);

	  if (op1.t == NUM && op2.t == NUM) {
	  	res.t = NUM;
	  	res.val = op2.val / op1.val;
	  	empilha(pil, res);
	  }
	  else {
	  	printf("Operação invalida!\n");
	  	empilha(op2);
	  	empilha(op1);
	  }
	  break;
	case JMP:
	  ip = arg;
	  continue;
	case JIT:
	  op1 = desempilha(pil);
	  if (op1.t == NUM) {
	  	if (op1.val != 0) {
			ip = arg;
			continue;
	  	}
	  }
	  break;
	case JIF:
	op1 = desempilha(pil);
	  if (op1.t = NUM) {
	  	if (op1.val == 0) {
			ip = arg;
			continue;
	  	}
	  }
	  else {
	  	printf ("Operação invalida!\n")/
	  	empilha(pil, op1);
	  }
	  break;
	case CALL:
	  res.t = NUM;
	  res.val = ip;
	  empilha(exec, res); /*Empilha o endereço de retorno */
	  res.val = rbp;
	  empilha(exec, res); /*Empilhar o antigo valor de rbp logo após o endereço de retorno*/
	  rbp = exec->topo-1; /*Define a posição do antigo valor do rbp como a nova base*/
	  ip = arg;
	  continue;
	case RET:
	  op1 = desempilha(exec);
	  op2 = desempilha(exec);
	  if (op1.t == NUM && op2 == NUM) {
	  	rbp = op1.val; /*Acerta o valor de rbp para antigo, que estava empilhado*/
	  	ip = op2.val;
	  }
	  else {
	  	printf("Operação invalida!\n");
	  	empilha(exec, op2);
	  	empilha(exec, op1);
	  }
	  break;
	case EQ:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  res.t = NUM;
	  if (op1 == NUM && op2 == NUM) {
	  	if (op1.val == op2.val) {
	  		res.val = 1;
	  	}
	  	else {
	  		res.val = 0;
	  	}
	  	empilha(pil, res);
	}
	else {
		printf("Operação invalida!\n");
		empilha(pil, op2);
		empilha(pil, op1);
	}
	  break;
	case GT:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  res.t = NUM;
	  if (op1.t == NUM && op2.t == NUM) {
	  	if (op1.val < op2.val) {
	  		res.val = 1;
	  	}
	  	else {
			res.val = 0;
	  	}
	  	empilha(pil, res);
	  }
	  else {
	  	printf("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case GE:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  res.t = NUM;
	  if (op1.t == NUM && op2.t == NUM) {
	  	if (desempilha(pil) <= desempilha(pil)) {
			res.val == 1;
	  	}
	  	else {
			res.val == 0;
	  	}
	  	empilha(pil, res);
	  }
	  else {
	  	printf("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case LT:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  res.t = NUM;
	  if (op1.t == NUM && op2.t == NUM) {
	  	if (op1.val > op2.val){
			res.val = 1;
	  	}
	  	else {
			res.val = 0;
	  	}
	  	empilha(pil, res);
	  }
	  else {
	  	printf("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case LE:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  res.t = NUM;
	  if (op1.t == NUM && op2.t == NUM) {
	  	if (op1.val >= op2.val) {
			res.val = 1;
	  	}
	  	else {
			res.val = 0;
	  	}
	  	empilha(pil, res);
	  }
	  else {
	  	printf ("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case NE:
	  op1 = desempilha(pil);
	  op2 = desempilha(pil);
	  res.t = NUM;
	  if (op1.t == NUM && op2.t == NUM) {
	  	if (op1.val != op2.val){
			res.val = 1;
	  	}
	  	else
			res.val = 0;
	  }
	  else {
	  	printf ("Operação invalida!\n");
	  	empilha(pil, op2);
	  	empilha(pil, op1);
	  }
	  break;
	case STO:
	  m->Mem[arg] = desempilha(pil);
	  break;
	case RCL:
	  empilha(pil, m->Mem[arg]);
	  break;
	case END:
	  return;
	case PRN:
	  op1 = desempilha(pil);
	  if (op1.t == NUM) {
	  	printf("%d\n", desempilha(pil));
	  }
	  break;
	case ALC: /* Comando para alocar espaço na pilha de execução para as variáveis locais (arg = numero de variáveis)*/
	  exec->topo = exec->topo + arg;
	  break;
	case FRE: /* Comando para liberar o espaço que foi alocado na pilha de execução para as variáveis locais (arg = numero de variveis)*/
	  exec->topo = exec->topo - arg;
	  break;
	case STL: /* Comando que desempilha um elemento da pilha de dados o armazena em uma posição rbp+arg na pilha de execução*/
	  exec->val[rbp+arg] = desempilha(pil);
	  break;
	case RCE: /* Comando que empilha na pilha de dados um elemento da pilha de execução dado por rbp+arg */
	  empilha(pil, exec->val[rbp+arg]);
	  break;
	case ATR:
	  op1 = desempilha(pil);

	  if (op1.t = CEL) {
	  	res.t = NUM;
	  	if (arg == 1) {
	  		res.val = op1.cel.terreno;
	  	}
	  	else if (arg == 2) {
	  		res.val = op.cel.cristais;
	  	}
	  	else if (arg == 3) {
	  		res.val = op.cel.ocupado;
	  	}
	  	else if (arg == 4) {
	  		res.val = op.cel.base;
	  	}
	  	empilha(pil, res);
	  }
	  else {
	  	printf("Operação invalida!\n");
	  	empilha(pil, op1);
	  }
	  break;
	}
	D(imprime(pil,5));
	D(puts("\n"));

	ip++;
  }
}
