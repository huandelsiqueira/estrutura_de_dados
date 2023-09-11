/*--------------------------------
Arquivo: mainListaCF.c
----------------------------------*/

#include <stdio.h>
#include "ListaCF.h"


int main() {
	ListaCF lista;
	Dado dado;
	int cod;
	
	criaLista(&lista);
	do {
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por codigo\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n\n");	
		printf("Informe a operacao: ");
		scanf("%d",&cod);
		
		switch (cod)
			{
			case 1 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("Informe o peso: ");
					 scanf("%f",&dado.peso);
					 if (incluiNoFim(&lista,dado)==LISTA_CHEIA)
					 	printf("ERRO: Lista Cheia!\n");
					 else
					    printf("Dados Incluidos com SUCESSO!\n");
	//				 exibeErro(erro); 			
					 break;
			case 2 : exibe(lista);
					 break;
			case 3 : break;
			case 4 : break;
			case 5 : break;
			case 6 : break;
			case 7 : break;
			case 8 : break;
			case 9 : break;
			case 10 : break;
			}
		if (cod != 2)
			exibe(lista);

	} while (cod !=0);

	return 0;
}
