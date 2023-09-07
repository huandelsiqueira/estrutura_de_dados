#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

int main(){
    int op;
    PilhaCF pl;
    int d;
    
    criaPilha(&pl);

    do {
      printf("\n0. Fim                         5. Exibe Pilha\n");    
      printf("1. Empilha                     6. ConsultaTopo\n");    
      printf("2. Desempilha                  7. Pesquisa\n");    
      printf("3. Quantidade de Nodos\n");    
      printf("4. Exibe Situacao da Pilha\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
 				empilha(&pl, d);
                break;
            case 2:
				desempilha(&pl, &d);
                break;
            case 3:
				exibeNodos(pl);
                break;
            case 4:
				if (estaCheia(pl) == PILHA_CHEIA ) {
					printf("Pilha Cheia.\n");
				} else if (estaVazia(pl) == PILHA_VAZIA) {
					printf("Pilha Vazia.\n");
				} else {
					printf("Pilha ainda recebe dados.\n");
				}
                break;
            case 5:
            	exibePilha(pl);
            	break;
            case 6:
				printf("TOPO[%d]\n", pl.topo);
                break;   
            case 7:
				printf("Digite o valor do dado a ser pesquisado:\n");
				scanf("%d", &d);
				pesquisa(pl, &d);
                break;   
      }
      exibePilha(pl);            
    } while (op!=0);  
                 
  return 0;
}
