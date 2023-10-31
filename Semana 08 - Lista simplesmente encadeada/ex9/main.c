#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

int main() {
	
	int op, qtNodo, cod;
	Dado dado;
	ListaSE lt;
	
	criaLista(&lt);
	
	do {
		
		printf("+-------------------------**MENU**----------------------+\n");
		printf("|(0)-Fim\t\t\t(6)-Inclui no fim\t|\n");
		printf("|(1)-Inclui no inicio\t\t(7)-Exclui do fim\t|\n");
		printf("|(2)-Exibe lista\t\t(8)-Consulta por codigo\t|\n");
		printf("|(3)-Quantidade de nodos\t(9)-Inclui depois\t|\n");
		printf("|(4)-Exibe situacao da lista\t(10)-Exclui nodo\t|\n");
		printf("|(5)-Exclui do inicio\t\t\t\t\t|\n");
		printf("+-------------------------------------------------------+\n");
		
		printf("Escolha a opcao: ");
		scanf("%d", &op);
		
		switch(op) {
			
			case 1: 
					printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (incluiNoInicio(&lt, dado) == FALTOU_MEMORIA) {
						printf("\nERRO: Lista cheia!\n");
					} else {
						printf("\nOperacao realizada com SUCESSO!\n");
					}
					break;
					
			case 2: 
					exibe(lt);
					break;
			
			case 3: 
					qtNodo = quantidadeDeNodos(lt);
					printf("\nQuantidade de nodos = %d\n", qtNodo);
					printf("\nOperacao realizada com SUCESSO!\n");
					break;
					
			case 4: 
					if (estaVazia(lt) == 1) {
						printf("\nLista vazia!\n");
					} else {
						printf("\nA lista contem 1 ou mais nodos.\n");
					}
					printf("\nOperacao realizada com SUCESSO!\n");
					break;
					
			case 5:
					if (excluiDoInicio(&lt, &dado) == LISTA_VAZIA) {
						printf("\nLista vazia!\n");
					} else {
						printf("\nO nodo excluido foi = |(%d)= %.2f|\n", dado.cod, dado.peso);
						printf("\nOperacao realizada com SUCESSO!\n");
					}
					break;
					
			case 6:
					printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (incluiNoFim(&lt, dado) == SUCESSO) {
						printf("\nOperacao realizada com SUCESSO!\n");
					} else {
						printf("\nLista cheia!\n");
					}
					break;
					
			case 7:
					if (excluiDoFim(&lt, &dado) == LISTA_VAZIA) {
						printf("\nLista vazia!\n");
					} else {
						printf("\nO nodo excluido foi = |(%d)= %.2f|\n", dado.cod, dado.peso);
						printf("\nOperacao realizada com SUCESSO!\n");
					}
					break;
					
			case 8:
					printf("Digite o codigo a ser verificado:\n");
					scanf("%d", &cod);
					if (consultaPorCodigo(lt, &dado, cod) == SUCESSO) {
						printf("\nO nodo achado foi = |(%d)= %.2f|\n", dado.cod, dado.peso);
						printf("\nOperacao realizada com SUCESSO!\n");
					} else {
						printf("\nCodigo inexistente!\n");
					}
					break;
					
			case 9:
					printf("Digite o codigo de referencia de um nodo da lista:\n");
					scanf("%d", &cod);
					printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (incluiDepois(&lt, dado, cod) == SUCESSO) {
						printf("\nOperacao realizada com SUCESSO!\n");
					} else if (incluiDepois(&lt, dado, cod) == LISTA_VAZIA) {
						printf("\nLista vazia!\n");
					} else {
						printf("\nCodigo inexistente!\n");
					}
					break;
					
			case 10:
					printf("Digite o codigo do nodo da lista a ser excluido:\n");
					scanf("%d", &cod);
					if (excluiNodo(&lt, &dado, cod) == SUCESSO) {
						printf("\nO nodo excluido foi = |(%d)= %.2f|\n", dado.cod, dado.peso);
						printf("\nOperacao realizada com SUCESSO!\n");
					} else if (excluiNodo(&lt, &dado, cod) == CODIGO_INEXISTENTE) {
						printf("\nCodigo inexistente!\n");
					} else {
						printf("\nLista vazia!\n");
					}
					break;
					
			
			
		}
		
		if (op != 0) {
			printf("\n======================================================================================\n\n");
			exibe(lt); 
			printf("\n\n======================================================================================\n");
			printf("\n\n");
		}
		
	} while (op != 0);
	
	return 0;
	
}
