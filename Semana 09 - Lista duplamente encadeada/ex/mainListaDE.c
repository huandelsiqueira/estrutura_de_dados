#include <stdio.h>
#include <stdlib.h>
#include "ListaDE.h"

int main()
{
    int op,cd,peso;
    ListaDE lt;
    Dado d;
    
    criaLista(&lt);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Inclui Depois\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            11. Exclui Nodo\n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Verifica Existencia      \n");    
      printf("4. Exibe Situacao da Lista     9. Consulta por Codigo      \n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoInicio(&lt, d)==0)
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
           
      }
      printf("\n========================================================================");
      exibe(lt);
	  printf("========================================================================\n");         
    } while (op!=0);  

  return(0);
}
