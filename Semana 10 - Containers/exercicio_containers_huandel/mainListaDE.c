#include <stdio.h>
#include <stdlib.h>
#include <deque> // Importe da classe "Deque" para usar os comandos do container

typedef struct { //Criação da estrutura do tipo "Dado" para ser utilizada no armazenamento dos dados de entrada
	int cod;
	float peso;
} Dado;

int main() {
	
	FILE *arq; // Criação de uma variável do tipo "FILE", que também é um ponteiro, para ler e gravar os dados nos cases "11" e "12"
    int op,cod,peso, cd;
    std::deque<Dado> lista; // Criação do deque "lista" que irá receber elementos do tipo "Dado" --> "std" vai trazer as funcionalidades da biblioteca do container | "::" é um operador para acessar as informações necessárias dentro de "std" (ou seja, está acessando a classe "deque" que está dentro de "std") 
    std::deque<Dado>::iterator i; // Mesmo princípio da linha de cima. Nesse caso, em particular, a gente cria a variável i (que é um iterador, ou seja, que vai percorrer os elementos dentro do container) --> Por isso é necessário ser do mesmo tipo da variável "lista", mas nesse caso é do tipo "iterator", pois é necessário percorrer os elementos do deque

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
            	Dado dado; // Criação da variável "dado" do tipo Dado para nela armazenar as informações de inserção (cod e peso)
                printf("Digite o codigo:\n");
                scanf ("%d", &dado.cod);
                printf("Digite o peso:\n");
                scanf("%f", &dado.peso);
                lista.push_front(dado); // Esse comando insere o "dado" na início do deque "lista" --> Acesso o meu deque "lista", digo que parâmentro "dado" será passado pela parte inicial do dque (por isso "push_front")
                printf("Operacao Realizada com Sucesso!\n");
                break;
                
            case 2: // Nessa parte o for é usado para percorrer o deque e exibir a lista (deque)
                for (i = lista.begin(); i != lista.end(); i++) { // "i = lista.begin()" significa que a variável "i" é igual ao primeiro elemento do deque "lista" | "i != lista.end()" é a condição em que o for deve ser percorrido até que "i" não seja igual ao elemento final do deque "lista"
                 	printf("%d - %f\n", i->cod, i->peso);
				}
                break;
                 
            case 3:
                printf("Quantidade de nodos: %d\n", lista.size()); // "lista.size()" indica a quantidade que o meu deque "lista" tem de nodos --> Isso ocorre por que o tamanho do deque "lista" é verificado pelo método "size()"
                break;
                 
            case 4:
                if(lista.empty()) { // "lista.empty()" indica se o deque está vazio --> O método "empty()" acessa o deque e verifica se está ou não vazio
                 	printf("Lista vazia!\n");
				} else {
				 	printf("A lista possui 1 ou mais nodos.\n");
				}
                break;
                 
            case 5:
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.erase(lista.begin()); // O método "erase()" irá excluir um elemento do deque. Nesse caso, como a exclusão é do início, é passado como parâmetro "lista.begin()", ou seja, o elemento do deque "lista" que está no início, por isso o método "begin()"
				 	printf("Operacao realizada com sucesso!\n");
				}
                break;
                 
            case 6: // Essa parte é a de inserir um dado no deque na parte final dele
            	printf("Digite o codigo:\n");
				scanf("%d", &dado.cod);
				printf("Digite o peso:\n");
				scanf("%f", &dado.peso);
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.push_back(dado); // O método "push_back()" irá inserir uma variável na parte final do deque "lista"
				 	printf("Operacao realizada com sucesso!\n");
				}
                break;
                 
            case 7:
                if (lista.empty()) {
                 	printf("Lista vazia!\n");
				} else {
				 	lista.erase(lista.end()); // Nessa parte, será excluído um elemento do final do deque. Para isso, vai ser chamado o método "erase()" e, como parâmentro, o elemento final do deque será passado através de "lista.end()" --> "end()" é outro método que irá acessar o deque "lista" e buscar o último elemento
				 	printf("Operacao realizada com sucesso!\n");
				}	
                break;
            
            case 8:
            	printf("Digite o codigo do nodo a ser encontrado:\n");
				scanf("%d", &cd);
                for (i = lista.begin(); i != lista.end(); i++) {
                 	if (i->cod == cd) { //Nessa parte aqui será comparado se "cd" é igual ao "cod" --> "cod" é pertence a "i", pois ele é um campo, e como "i" é um iterator e assume os valores dos elementos que estão do deque "lista", ele é usado para tal comparação
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
							lista.insert(i+1, dado); // "insert()" é um método utilizado para inserir um elemento em uma determinado posição do deque --> Nesse caso, a variável "i" já está com a posição do elemento do deque armazenada. "i+1" é utilizado para indicar que o novo dado será posto na posição após o elemento indicado por "i"
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
							lista.erase(i); // "erase()" irá limpar um elemento --> Como "i" foi passado por parâmetro, será deletado o elemento do deque "lista" que está na posição passada por "i"
						}
					}
				} 
				break;
					
			case 11:// Aqui vai ser feito a gravação dos dados que estão dentro do deque "lista" --> Para isso, a variável "arq" do tipo "FILE" (criada lá na linha 12) será utilizada.
				arq = fopen("Arquivo.txt", "w"); // "fopen()" é uma função que tem como parâmetros o nome do arquivo (Arquivo.txt) que será criado e o modo de abertura do arquivo (como é gravação, usa-se "w", de Write)
				for (i = lista.begin(); i != lista.end(); i++) {
               		fprintf(arq, "%d - %f\n", i->cod, i->peso); //Ao invés de usar printf(), usa-se fprintf(), pois os dados serão escritos/gravados dentro do arquivo | "arq" é a variável do tipo "FILE" que será utilizada como referência ao arquivo onde os dados serão gravados
				}
				fclose(arq); // "fclose()" é utilizado para fechar o arquivo após a gravação
				printf("\nDados gravados!\n");
				break;
				
			case 12:
				arq = fopen("Arquivo.txt", "r"); // Mesmo princípio do case 11, da linha 136". Será passado como parâmetros novamente o nome do arquivo (Arquivo.txt) e o modo de abertura do arquivo (como é leitura de dados, usa-se "r", de Read)
				while (fscanf(arq, "%d - %f\n", &dado.cod, &dado.peso) != EOF) { // Nessa linha, "fscanf()" irá ler os dados do arquivo referenciado pela variável "arq" --> A condição do "while" significa que a leitura será feita até que chegue no final do arquivo ("EOF" - End of File)
					lista.push_back(dado); // "lista.push_back(dado)" siginifica que os dados do arquivos serão lidos e inseridos no fim do deque "lista"
				}
				fclose(arq); // "fclose()" é utilizado para fechar o arquivo após a leitura
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
