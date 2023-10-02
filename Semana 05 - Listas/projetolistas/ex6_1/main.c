#include <stdio.h>
#include <stdlib.h>
#include "ListaCF.h"

int main() {
	ListaCF lt;
	Dado dado, d;
	int qtNodos, op, codref;

	criaLista(&lt);

	do {
		printf("+----------------------**MENU**-------------------------+\n");
		printf("|(0)-Fim\t\t\t(5)-Exclui do fim\t|\n");
		printf("|(1)-Inclui no fim\t\t(6)-Inclui no inicio\t|\n");
		printf("|(2)-Exibe lista\t\t(7)-Exclui do inicio\t|\n");
		printf("|(3)-Quantidade de nodos\t(8)-Consulta por codigo\t|\n");
		printf("|(4)-Exibe situacao da lista\t(9)-Inclui antes\t|\n");
		printf("|(5)-Exclui do fim\t\t(10)-Exclui nodo\t|\n");
		printf("+-------------------------------------------------------+\n");

		printf("Escolha a opcao: ");
		scanf("%d", &op);

		switch(op) {
			case 1: 
					printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (incluiNoFim(&lt, dado) == LISTA_CHEIA) {
						printf("\nERRO: Lista cheia!\n");
					} else {
						printf("\nOperacao realizada com SUCESSO!\n");
					}
					break;

			case 2: 
					exibe(lt);
					break;
					
			case 3: 
					qtNodos = quantidadeDeNodos(lt);
					printf("\nQuantidade de nodos: %d\n", qtNodos);
					break;

			case 4: 
					if (estaCheia(lt) == LISTA_CHEIA) {
						printf("\nSituacao: Lista cheia!\n");
					} else if (estaVazia(lt) == LISTA_VAZIA) {
						printf("\nSituacao: Lista vazia!\n");
					} else {
						printf("\nSituacao: Lista ainda pode receber dados!\n");
					}
					break;

			case 5: 
					if(excluiDoFim(&lt, &dado.cod) == LISTA_VAZIA) {
						printf("\nERRO: Lista vazia!\n");
					} else {
						exibe(lt);
					}
					break;

			case 6: 
					printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (incluiNoInicio(&lt, dado) == LISTA_CHEIA) {
						printf("\nERRO: Lista cheia!\n");
					} else {
						printf("\nOperacao realizada com SUCESSO!\n");
					}
					break;

			case 7: 
					if(excluiDoInicio(&lt, &dado) == LISTA_VAZIA) {
						printf("\nERRO: Lista vazia!\n");
					} else {
						exibe(lt);
					}
					break;

			case 8: 
					printf("Digite o codigo do valor a ser pesquisado:\n ");
					scanf("%d", &dado.cod);
                    if((consultaPorCodigo(lt, dado.cod, &dado))== SUCESSO) {
                    	printf("\nCodigo achado!\n");
                    	printf("(%d)= %.2f\n", dado.cod, dado.peso);
                        printf("\nOperacao realizada!");
                    } else if (consultaPorCodigo(lt, dado.cod, &dado) == LISTA_VAZIA) {
                        printf("\nLista vazia!\n");
                    } else {
                        printf("\nDado nao encontrado!\n");
                    }
					break;

			case 9:	
					printf("Qual dados serao inseridos?\n");
					printf("Codigo:\n");
					scanf("%d", &dado.cod);
					printf("Peso:\n");
					scanf("%f", &dado.peso);
					printf("Para incluir antes de um codigo, digite o codigo de referencia:\n");
					scanf("%d", &codref);
					if (incluiAntes(&lt, dado, codref) == SUCESSO) {
						printf("\nOperacao realizada com SUCESSO!\n");
					} else if (incluiAntes(&lt, dado, codref) == CODIGO_INEXISTENTE) {
						printf("\nCodigo de referencia inexistente.\n");
					} else if (incluiAntes(&lt, dado, codref) == LISTA_CHEIA) {
						printf("\nLista cheia!\n");
					} else {
						printf("\nLista vazia! - Sem codigo de referencia.\n");
					}
					break;

			case 10:
					printf("Digite o codigo do nodo a ser exluido:\n");
					scanf("%d", &codref);
					if (excluiNodo(&lt, codref, &dado) == SUCESSO) {
					 	printf("O nodo exluido: (%d)= %.2f\n", dado.cod, dado.peso);
					} else if (excluiNodo(&lt, codref, &dado) == CODIGO_INEXISTENTE){
					 	printf("\nCodigo de referencia nao encontrado.\n");
					} 
					break;
		}
	} while (op != 0);
}
