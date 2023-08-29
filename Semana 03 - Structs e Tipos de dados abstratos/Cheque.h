#ifndef Cheque_H
#define Cheque_H

typedef struct {
	int nr_cheque,
		situacao;
	float valor;
} CHEQUE;

void criaCheque(int nr_cheque, CHEQUE *cheque);

int obtemSituacao(CHEQUE cheque);

int obtemNumero(CHEQUE cheque);

void exibeCheque(CHEQUE cheque);

float obtemValor(CHEQUE cheque);

int compensaCheque(CHEQUE *cheque);

int emiteCheque(float valor, CHEQUE *cheque);

#endif
