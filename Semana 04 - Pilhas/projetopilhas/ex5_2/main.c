#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

int main(){
    int op, cod;
    PilhaCF pl;
   	float peso;
    
    criaPilha(&pl);

    do {
      printf("\n0. Fim                         5. Exibe Pilha\n");    
      printf("1. Empilha                     6. ConsultaTopo\n");    
      printf("2. Desempilha                  7. Pesquisa\n");    
      printf("3. Quantidade de Nodos\n");    
      printf("4. Exibe Situacao da Pilha\n");
      printf("\n\nOperacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
            	printf("Digite o codigo:\n");
            	scanf("%d", &cod);
            	printf("Digite um valor:\n");
            	scanf("%f", &peso);
            	if (empilha(&pl, peso, cod) == SUCESSO) {
 					printf("\nOperacao realizada!\n");
				 } else {
				 	printf("\nPilha cheia!\n");
				 }
                break;
            case 2:
				if (desempilha(&pl, &cod) == SUCESSO) {
					printf("\nOperacao realizada!\n");
				} else {
					printf("\nPilha vazia\n");
				}
                break;
            case 3:
				exibeNodos(pl);
                break;
            case 4:
				if (estaCheia(pl) == PILHA_CHEIA) {
					printf("\nPilha cheia.\n");
				} else if (estaVazia(pl) == PILHA_VAZIA) {
					printf("\nPilha vazia.\n");
				} else {
					printf("\nPilha ainda pode receber dados.\n");
				}
                break;
            case 5:
            	exibePilha(pl);
            	break;
            case 6:
				printf("TOPO[%d]\n", pl.topo);
                break;   
            case 7:
				printf("Digite o codigo do dado a ser pesquisado:\n");
				scanf("%d", &cod);
				if (pesquisa(pl, &cod) == SUCESSO) {
					printf("\nOperacao realizada!\n");
				} else if (pesquisa(pl, &cod) == PILHA_VAZIA) {
					printf("\nPilha vazia!\n");
				} else {
					printf("\nDado nao encontrado!\n");
				}
                break;   
      }
      printf("\n===================================================\n");
      exibePilha(pl);        
	  printf("===================================================\n");    
    } while (op!=0);  
                 
  return 0;
}
