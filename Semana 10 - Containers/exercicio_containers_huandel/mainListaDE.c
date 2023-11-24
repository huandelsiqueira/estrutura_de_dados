#include <stdio.h>
#include <stdlib.h>
#include <deque> // Importe da classe "Deque" para usar os comandos do container

typedef struct { //Cria��o da estrutura do tipo "Dado" para ser utilizada no armazenamento dos dados de entrada
	int cod;
	float peso;
} Dado;

int main() {
	
	FILE *arq; // Cria��o de uma vari�vel do tipo "FILE", que tamb�m � um ponteiro, para ler e gravar os dados nos cases "11" e "12"
    int op,cod,peso, cd;
    std::deque<Dado> lista; // Cria��o do deque "lista" que ir� receber elementos do tipo "Dado" --> "std" vai trazer as funcionalidades da biblioteca do container | "::" � um operador para acessar as informa��es necess�rias dentro de "std" (ou seja, est� acessando a classe "deque" que est� dentro de "std") 
    std::deque<Dado>::iterator i; // Mesmo princ�pio da linha de cima. Nesse caso, em particular, a gente cria a vari�vel i (que � um iterador, ou seja, que vai percorrer os elementos dentro do container) --> Por isso � necess�rio ser do mesmo tipo da vari�vel "lista", mas nesse caso � do tipo "iterator", pois � necess�rio percorrer os elementos do deque

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
            	Dado dado; // Cria��o da vari�vel "dado" do tipo Dado para nela armazenar as informa��es de inser��o (cod e peso)
                printf("Digite o codigo:\n");
                scanf ("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
                lista.push_front(dado); // Esse comando insere o "dado" na in�cio do deque "lista" --> Acesso o meu deque "lista", digo que par�mentro "dado" ser� passado pela parte inicial do dque (por isso "push_front")
                printf("Operacao Realizada com Sucesso!\n");
                break;
                
            case 2: // Nessa parte o for � usado para percorrer o deque e exibir a lista (deque)
                for (i = lista.begin(); i != lista.end(); i++) { // "i = lista.begin()" significa que a vari�vel "i" � igual ao primeiro elemento do deque "lista" | "i != lista.end()" � a condi��o em que o for deve ser percorrido at� que "i" n�o seja igual ao elemento final do deque "lista"
                 	printf("%d - %f\n", i->cod, i->peso);
				}
                break;
                 
            case 3:
                printf("Quantidade de nodos: %d\n", lista.size()); // "lista.size()" indica a quantidade que o meu deque "lista" tem de nodos --> Isso ocorre por que o tamanho do deque "lista" � verificado pelo m�todo "size()"
                break;
                 
            case 4:
                if(lista.empty()) { // "lista.empty()" indica se o deque est� vazio --> O m�todo "empty()" acessa o deque e verifica se est� ou n�o vazio
                 	printf("Lista vazia!\n");
				} else {
				 	printf("A lista possui 1 ou mais nodos.\n");
				}
                break;
                 
            case 5:
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.erase(lista.begin()); // O m�todo "erase()" ir� excluir um elemento do deque. Nesse caso, como a exclus�o � do in�cio, � passado como par�metro "lista.begin()", ou seja, o elemento do deque "lista" que est� no in�cio, por isso o m�todo "begin()"
				 	printf("Operacao realizada com sucesso!\n");
				}
                break;
                 
            case 6: // Essa parte � a de inserir um dado no deque na parte final dele
            	printf("Digite o codigo:\n");
				scanf("%d", &dado.cod);
				printf("Digite o peso:\n");
				scanf("%f", &dado.peso);
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.push_back(dado); // O m�todo "push_back()" ir� inserir uma vari�vel na parte final do deque "lista"
				 	printf("Operacao realizada com sucesso!\n");
				}
                break;
                 
            case 7:
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.erase(lista.end()); // Nessa parte, ser� exclu�do um elemento do final do deque. Para isso, vai ser chamado o m�todo "erase()" e, como par�mentro, o elemento final do deque ser� passado atrav�s de "lista.end()" --> "end()" � outro m�todo que ir� acessar o deque "lista" e buscar o �ltimo elemento
				 	printf("Operacao realizada com sucesso!\n");
				}	
                break;
            
            case 8:
            	printf("Digite o codigo do nodo a ser encontrado:\n");
				scanf("%d", &cd);
                for (i = lista.begin(); i != lista.end(); i++) {
                 	if (i->cod == cd) { //Nessa parte aqui ser� comparado se "cd" � igual ao "cod" --> "cod" � pertence a "i", pois ele � um campo, e como "i" � um iterator e assume os valores dos elementos que est�o do deque "lista", ele � usado para tal compara��o
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
							lista.insert(i+1, dado); // "insert()" � um m�todo utilizado para inserir um elemento em uma determinado posi��o do deque --> Nesse caso, a vari�vel "i" j� est� com a posi��o do elemento do deque armazenada. "i+1" � utilizado para indicar que o novo dado ser� posto na posi��o ap�s o elemento indicado por "i"
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
							lista.erase(i); // "erase()" ir� limpar um elemento --> Como "i" foi passado por par�metro, ser� deletado o elemento do deque "lista" que est� na posi��o passada por "i"
						}
					}
				} 
				break;
					
			case 11:// Aqui vai ser feito a grava��o dos dados que est�o dentro do deque "lista" --> Para isso, a vari�vel "arq" do tipo "FILE" (criada l� na linha 12) ser� utilizada.
				arq = fopen("Arquivo.txt", "w"); // "fopen()" � uma fun��o que tem como par�metros o nome do arquivo (Arquivo.txt) que ser� criado e o modo de abertura do arquivo (como � grava��o, usa-se "w", de Write)
				for (i = lista.begin(); i != lista.end(); i++) {
               		fprintf(arq, "%d - %f\n", i->cod, i->peso); //Ao inv�s de usar printf(), usa-se fprintf(), pois os dados ser�o escritos/gravados dentro do arquivo | "arq" � a vari�vel do tipo "FILE" que ser� utilizada como refer�ncia ao arquivo onde os dados ser�o gravados
				}
				fclose(arq); // "fclose()" � utilizado para fechar o arquivo ap�s a grava��o
				printf("\nDados gravados!\n");
				break;
				
			case 12:
				arq = fopen("Arquivo.txt", "r"); // Mesmo princ�pio do case 11, da linha 136". Ser� passado como par�metros novamente o nome do arquivo (Arquivo.txt) e o modo de abertura do arquivo (como � leitura de dados, usa-se "r", de Read)
				while (fscanf(arq, "%d - %f\n", &dado.cod, &dado.peso) != EOF) { // Nessa linha, "fscanf()" ir� ler os dados do arquivo referenciado pela vari�vel "arq" --> A condi��o do "while" significa que a leitura ser� feita at� que chegue no final do arquivo ("EOF" - End of File)
					lista.push_back(dado); // "lista.push_back(dado)" siginifica que os dados do arquivos ser�o lidos e inseridos no fim do deque "lista"
				}
				fclose(arq); // "fclose()" � utilizado para fechar o arquivo ap�s a leitura
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
