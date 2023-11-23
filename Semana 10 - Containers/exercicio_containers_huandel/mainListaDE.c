#include <stdio.h>
#include <stdlib.h>
#include <deque>

typedef struct {
	int cod;
	float peso;
} Dado;

int main() {
	
	FILE *arq;
    int op,cod,peso, cd;
    std::deque<Dado> lista;
    std::deque<Dado>::iterator i;

    do {
      
      	printf("+-------------------------**MENU**----------------------+\n");
		printf("|(0)-Fim\t\t\t(6)-Inclui no fim\t|\n");
		printf("|(1)-Inclui no inicio\t\t(7)-Exclui do fim\t|\n");
		printf("|(2)-Exibe lista\t\t(8)-Consulta por codigo\t|\n");
		printf("|(3)-Quantidade de nodos\t(9)-Inclui depois\t|\n");
		printf("|(4)-Exibe situacao da lista\t(10)-Exclui nodo\t|\n");
		printf("|(5)-Exclui do inicio\t\t(11)-Gravar Arquivo\t|\n");
		printf("|\t\t\t\t(12)-Ler Arquivo\t|\n");
		printf("+-------------------------------------------------------+\n");
		
		printf("Escolha a opcao: ");
		scanf("%d", &op);

      	switch(op){
            case 1:
            	Dado dado;
                printf("Digite o codigo:\n");
                scanf ("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
                lista.push_front(dado);
                printf("Operacao Realizada com Sucesso!\n");
                break;
                
            case 2:
                for (i = lista.begin(); i != lista.end(); i++) {
                 	printf("%d - %f\n", i->cod, i->peso);
				}
                break;
                 
            case 3:
                printf("Quantidade de nodos: %d\n", lista.size());
                break;
                 
            case 4:
                if(lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	printf("A lista possui 1 ou mais nodos.\n");
				}
                break;
                 
            case 5:
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.erase(lista.begin());
				 	printf("Operacao realizada com sucesso!\n");
				}
                break;
                 
            case 6:
            	printf("Digite o codigo:\n");
				scanf("%d", &dado.cod);
				printf("Digite o peso:\n");
				scanf("%f", &dado.peso);
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.push_back(dado);
				 	printf("Operacao realizada com sucesso!\n");
				}
                break;
                 
            case 7:
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.erase(lista.end());
				 	printf("Operacao realizada com sucesso!\n");
				}	
                break;
            
            case 8:
            	printf("Digite o codigo do nodo a ser encontrado:\n");
				scanf("%d", &cd);
                for (i = lista.begin(); i != lista.end(); i++) {
                 	if (i->cod == cd) {
                 		printf("\n%d - %f\n", i->cod, i->peso);
                 		printf("O dado foi encontrado!");
					}
				}
                break;
                 
            case 9:
                printf("Digite o codigo de referencia:\n");
				scanf("%d", &cd);
				printf("Digite o codigo:\n");
                scanf ("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
				if (lista.empty()) {
			 	 	printf("\nLista vazia!\n");
				} else {
					for (i = lista.begin(); i != lista.end(); i++) {
               			if (i->cod == cd) {
							lista.insert(i+1, dado);
						}
					}
				}
				break;	
				
			case 10:
				printf("Digite o codigo do nodo da lista a ser excluido:\n");
				scanf("%d", &cd);
				if (lista.empty()) {
					printf("\nLista vazia!\n");
				} else {
					for (i = lista.begin(); i != lista.end(); i++) {
               			if (i->cod == cd) {
							lista.erase(i);
						}
					}
				} 
				break;
					
			case 11:
				arq = fopen("Arquivo.txt", "w");
				for (i = lista.begin(); i != lista.end(); i++) {
               		fprintf(arq, "%d - %f\n", i->cod, i->peso);
				}
				fclose(arq);
				printf("\nDados gravados!\n");
				break;
				
			case 12:
				arq = fopen("Arquivo.txt", "r");
				while (fscanf(arq, "%d - %f\n", &dado.cod, &dado.peso) != EOF) {
					lista.push_back(dado);
				}
				fclose(arq);
				printf("\nDados lidos!\n");
				break;
           
      	}
      	
      	if (op != 0) {
      		printf("\n====================\n");
      		for (i = lista.begin(); i != lista.end(); i++) {
                printf("%d - %f\n", i->cod, i->peso);
			}
	  		printf("====================\n");  
		} else {
			printf("\nPrograma encerrado.\n");
		}
      	       
    } while (op!=0);  

  return(0);
}
