#include <stdio.h>
#include <stdlib.h>
#include "filase.h"

int main() {
	
	int op;
	Dado dado;
	FilaSE fl;
	
	criaFila(&fl);
	
	do {
		printf("+----------------**MENU**---------------+\n");
		printf("|(0)-Fim\t\t\t\t|\n");
		printf("|(1)-Insere\t\t\t\t|\n");
		printf("|(2)-Retira\t\t\t\t|\n");
		printf("|(3)-Quantidade de nodos\t\t|\n");
		printf("|(4)-Exibe situacao da fila\t\t|\n");
		printf("|(5)-Consulta frente\t\t\t|\n");
		printf("+---------------------------------------+\n");
		
		printf("Escolha a opcao: ");
		scanf("%d", &op);
		
		switch(op) {
			
			case 1: printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (insere(&fl, dado) == FALTOU_MEMORIA) {
						printf("\nERRO: Fila cheia!\n\n");
					} else {
						printf("\nOperacao realizada com SUCESSO!\n\n");
					}
					break;
			
			case 2: if (retira(&fl, &dado) == SUCESSO) {
						printf("\nOperacao realizada com SUCESSO.\n\n");
					} else {
						printf("\nFila vazia\n\n");
					}
					break;
			
			case 3: 
					printf("\nQuantidade de nodos: %d\n", fl.contador);
					printf("\nOperacao realizada com SUCESSO.\n\n");
					break;
					
			case 4: if (estaVazia(fl) == 1) {
						printf("\nA fila esta vazia!\n\n");
					} else {
						printf("\nA pilha possui 1 ou mais nodos.\n\n");
						printf("\nOperacao realizada com SUCESSO.\n\n");
					}
					break;
			
			case 5: if (consulta(&fl, &dado) == FILA_VAZIA) {
						printf("\nA fila esta vazia!\n");
						printf("\nOperacao realizada com SUCESSO.\n\n");
					} else {
						printf("+===============+\n");
						printf("|(%d) = %.2f\t|\n", dado.cod, dado.peso);
						printf("+===============+\n");
						printf("\nOperacao realizada com SUCESSO.\n\n");
					}
					break;
		}
		
		if (op != 0) {
			printf("\n======================================================================================\n\n");
			exibe(fl); 
			printf("\n\n======================================================================================\n");
			printf("\n\n");
		} 
		
	} while (op != 0);
	
	return 0;
	
}
