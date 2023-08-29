#include "Cheque.h"
#include <stdio.h>
#include <conio.h>

int main() {
	
	CHEQUE cheque1, cheque2;
	int sit, nr_cheque;
	
	printf("==Sistema de Cheques - Adicione o Nr, valor e situacao (0-Em branco, 1-Emitido, 2-Compensado) de um cheque.==\n\n");
	
	printf("Digite um numero para o primeiro cheque:\n");
	scanf("%d", &cheque1.nr_cheque);
	
	criaCheque(cheque1.nr_cheque, &cheque1);
	
	printf("Digite um numero para o segundo cheque:\n");
	scanf("%d", &cheque2.nr_cheque);
	
	criaCheque(cheque2.nr_cheque, &cheque2);
	
	printf("Digite o valor do primeiro cheque (Nr: %d):\n", cheque1.nr_cheque);
	scanf("%f", &cheque1.valor);
	
	emiteCheque(cheque1.valor, &cheque1);
	
	printf("Digite o valor do segundo cheque (Nr: %d):\n", cheque2.nr_cheque);
	scanf("%f", &cheque2.valor);
	
	emiteCheque(cheque2.valor, &cheque2);
	
	printf("\n========================================================\n");
	exibeCheque(cheque1);
	exibeCheque(cheque2);
	printf("========================================================\n");
	
	if (obtemValor(cheque1) > obtemValor(cheque2)) {
		printf("\nO cheque de Nr: %d foi compensado.\n", cheque1.nr_cheque);
		compensaCheque(&cheque1);
	} else {
		printf("\nO cheque de Nr: %d foi compensado.\n", cheque2.nr_cheque);
		compensaCheque(&cheque2);
	}
	
	printf("\nSituacao do cheque (Nr: %d):", cheque1.nr_cheque);
	sit = obtemSituacao(cheque1);
	printf(" %d\n", sit);
	printf("Situacao do cheque (Nr: %d):", cheque2.nr_cheque);
	sit = obtemSituacao(cheque2);
	printf(" %d\n", sit);
	
	nr_cheque = obtemNumero(cheque1);
	printf("\nNumero do cheque:");
	printf(" %d\n", nr_cheque);
	nr_cheque = obtemNumero(cheque2);
	printf("Numero do cheque:");
	printf(" %d\n", nr_cheque);
	
}
