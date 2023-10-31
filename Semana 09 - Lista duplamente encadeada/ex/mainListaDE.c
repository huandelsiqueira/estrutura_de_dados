#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaDE.h"

int main()
{
    int op,cd,peso;
    ListaDE lt;
    Dado dado;
    
    criaLista(&lt);

    do {
      
      	printf("+-------------------------**MENU**----------------------+\n");
		printf("|(0)-Fim\t\t\t(6)-Inclui no fim\t|\n");
		printf("|(1)-Inclui no inicio\t\t(7)-Exclui do fim\t|\n");
		printf("|(2)-Exibe lista\t\t(8)-Verifica existencia\t|\n");
		printf("|(3)-Quantidade de nodos\t(9)-Consulta por codigo\t|\n");
		printf("|(4)-Exibe situacao da lista\t(10)-Inclui depois\t|\n");
		printf("|(5)-Exclui do inicio\t\t(11)-Exclui nodo\t|\n");
		printf("+-------------------------------------------------------+\n");
		
		printf("Escolha a opcao: ");
		scanf("%d", &op);

      	switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &dado.cod,&dado.peso);
                 if (incluiNoInicio(&lt, dado)==0)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
                 
            case 2:
                 exibe(lt);
                 break;
                 
            case 3:
                 printf("Quantidade de nodos: %d\n", lt.n);
                 break;
                 
            case 4:
                 if(lt.n == 0) {
                 	printf("Lista vazia!\n");
				 } else {
				 	printf("A lista possui 1 ou mais nodos.\n");
				 }
                 break;
                 
            case 5:
                 if (excluiDoInicio(&lt, &dado) == LISTA_VAZIA) {
                 	printf("Lista vazia!\n");
				 } else {
				 	printf("Operacao realizada com sucesso!\n");
				 }
                 break;
                 
            case 6:
            	 printf("Digite o codigo:\n");
				 scanf("%d", &dado.cod);
				 printf("Digite o peso:\n");
				 scanf("%f", &dado.peso);
                 if (incluiNoFim(&lt, dado) == FALTOU_MEMORIA) {
                 	printf("Lista vazia!\n");
				 } else {
				 	printf("Operacao realizada com sucesso!\n");
				 }
                 break;
                 
            case 7:
                 if (excluiDoFim(&lt, &dado) == LISTA_VAZIA) {
                 	printf("Lista vazia!\n");
				 } else {
				 	printf("Operacao realizada com sucesso!\n");
				 }
                 break;
            
            case 8:
            	 printf("Digite o codigo do nodo a ser encontrado:\n");
				 scanf("%d", &cd);
                 if (verificaExistencia(&lt, dado, cd) == true) {
                 	printf("Nodo encontrado na lista.\n");
				 } else {
				 	printf("O nodo nao foi encontrado na lista.\n");
				 }
                 break;
                 
            case 9:
                 printf("Digite o codigo a ser verificado:\n");
				 scanf("%d", &cd);
				 if (consultaPorCodigo(lt, &dado, cd) == SUCESSO) {
			 	 	printf("\nO nodo achado foi = |(%d)= %.2f|\n", dado.cod, dado.peso);
					printf("\nOperacao realizada com SUCESSO!\n");
				 } else {
					printf("\nCodigo inexistente!\n");
				 }
				break;
				
			case 10:
				printf("Digite o codigo de referencia de um nodo da lista:\n");
					scanf("%d", &cd);
					printf("Digite o codigo:\n");
					scanf("%d", &dado.cod);
					printf("Digite o peso:\n");
					scanf("%f", &dado.peso);
					if (incluiDepois(&lt, dado, cd) == SUCESSO) {
						printf("\nOperacao realizada com SUCESSO!\n");
					} else if (incluiDepois(&lt, dado, cd) == LISTA_VAZIA) {
						printf("\nLista vazia!\n");
					} else {
						printf("\nCodigo inexistente!\n");
					}
					break;
					
			case 11:
					printf("Digite o codigo do nodo da lista a ser excluido:\n");
					scanf("%d", &cd);
					if (excluiNodo(&lt, &dado, cd) == SUCESSO) {
						printf("\nO nodo excluido foi = |(%d)= %.2f|\n", dado.cod, dado.peso);
						printf("\nOperacao realizada com SUCESSO!\n");
					} else if (excluiNodo(&lt, &dado, cd) == CODIGO_INEXISTENTE) {
						printf("\nCodigo inexistente!\n");
					} else {
						printf("\nLista vazia!\n");
					}
					break;
           
      	}
      	
      	if (op != 0) {
      		printf("\n========================================================================");
      		exibe(lt);
	  		printf("========================================================================\n");  
		} else {
			printf("\nPrograma encerrado.\n");
		}
      	       
    } while (op!=0);  

  return(0);
}
