#include "Cheque.h"

void criaCheque(int nr_cheque, CHEQUE *cheque) {
	
	cheque->nr_cheque = nr_cheque;
	cheque->situacao = 0;
	cheque->valor = 0;
	
}

int obtemSituacao(CHEQUE cheque) {
	
	return cheque.situacao;
	
}

int obtemNumero(CHEQUE cheque) {
	
	return cheque.nr_cheque;
	
}

void exibeCheque(CHEQUE cheque) {
	
	printf("== Numero do cheque: %d | Valor: R$ %.2f | Situacao: %d ==\n ", cheque.nr_cheque, cheque.valor, cheque.situacao);
	return 0;
	
}

float obtemValor(CHEQUE cheque) {
	
	return cheque.valor;
	
}

int compensaCheque(CHEQUE *cheque) {
	
	if (cheque->situacao == 1) {
		cheque->situacao = 2;
		return 0;
	} else {
		return 1;
	}
	
}

int emiteCheque(float valor, CHEQUE *cheque) {
	
	if (cheque->situacao == 0) {
		cheque->valor = valor;
		cheque->situacao = 1;
		return 0;
	} else {
		return 1;
	}
	
}

