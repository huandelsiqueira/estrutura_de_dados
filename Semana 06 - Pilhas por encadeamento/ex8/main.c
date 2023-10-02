#include <stdio.h>
#include <stdlib.h>
#include "pilhase.h"

int main() {
	
	int op;
	Dado dado;
	PilhaSE pl;
	
	criaPilha(&pl);
	
	do {
		
		printf("+----------------**MENU**---------------+\n");
		printf("|(0)-Fim\t\t\t\t|\n");
		printf("|(1)-Empilha\t\t\t\t|\n");
		printf("|(2)-Desempilha\t\t\t\t|\n");
		printf("|(3)-Quantidade de nodos\t\t|\n");
		printf("|(4)-Exibe situacao da lista\t\t|\n");
		printf("|(5)-Consulta topo\t\t\t|\n");
		printf("+---------------------------------------+\n");

		printf("Escolha a opcao: ");
		scanf("%d", &op);
		
		switch(op) {
			
			case 1: printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (empilha(&pl, dado) == FALTOU_MEMORIA) {
						printf("\nERRO: Pilha cheia!\n");
					} else {
						printf("\nOperacao realizada com SUCESSO!\n");
					}
					break;
			
			case 2: if (desempilha(&pl, &dado) == SUCESSO) {
						printf("\nOperacao realizada com SUCESSO.\n");
					} else {
						printf("\nPilha vazia\n");
					}
					break;
			
			case 3: 
					printf("\nQuantidade de nodos: %d\n", pl.contador);
					printf("\nOperacao realizada com SUCESSO.\n");
					break;
					
			case 4: if (estaVazia(pl) == 1) {
						printf("\nA pilha esta vazia!\n");
						printf("\nOperacao realizada com SUCESSO.\n");
					} else {
						printf("\nA pilha possui 1 ou mais nodos.\n");
						printf("\nOperacao realizada com SUCESSO.\n");
					}
					break;
			
			case 5: if (consultaTopo(&pl, &dado) == PILHA_VAZIA) {
						printf("\nA pilha esta vazia!\n");
						printf("\nOperacao realizada com SUCESSO.\n");
					} else {
						printf("+===============+\n");
						printf("|(%d) = %.2f\t|\n", dado.cod, dado.peso);
						printf("+===============+\n");
						printf("\nOperacao realizada com SUCESSO.\n");
					}
					break;
		}
		
		if (op != 0) {
			exibe(pl); 
		}      	       
		
	} while (op != 0);
	
	return 0;
}
