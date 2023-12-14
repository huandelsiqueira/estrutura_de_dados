#include "ProjED.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <deque>

int main() {
	
	int escolhaMenu, respostaJogador;
	dadoJogador jogador;
	
	Lista lt;
	criaLista(&lt);
	
	std::deque<Pergunta> bancoDePerguntas;
	std::deque<Pergunta>::iterator i;
	
	do {
		
		printf("+---------------------------------------------------------------+\n");
		printf("|\t\t\t\t\t\t\t\t|\n");
		printf("|\tBEM VINDO AO JOGO DE 'PERGUNTAS' E 'RESPOSTAS'\t\t|\n");
		printf("|\t\t\t\t\t\t\t\t|\n");
		printf("+---------------------------------------------------------------+\n");
		printf("+---------------------------------------------------------------+\n");
		printf("| (1).Iniciar jogo\t\t\t\t\t\t|\n");
		printf("| (2).Mostrar regras do jogo\t\t\t\t\t|\n");
		printf("| (3).Mostrar banco de perguntas\t\t\t\t|\n");
		printf("| (4).Sair do jogo\t\t\t\t\t\t|\n");
		printf("+---------------------------------------------------------------+\n");
		
		printf("Digite a opcao desejada: ");
		scanf("%d", &escolhaMenu);
		printf("\n");
		
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		
		switch(escolhaMenu) {
			
			case 1:
					
					printf("Digite o nome do jogador: ");
					scanf("%s", &jogador.nomeJogador);
					printf("\n");
					
					#ifdef _WIN32
        				system("cls");
					#else
        				system("clear");
					#endif
					
					limparLista(&lt);
					
					realizaRodada(&jogador, respostaJogador);
				
					exibePlacar(jogador);
					
					system("PAUSE");
					
					#ifdef _WIN32
        				system("cls");
					#else
        				system("clear");
					#endif
						
					break;
					
			case 2:
					printf("+---------------------------------------------------------------+\n");
					printf("|\t\t\tREGRAS DO JOGO\t\t\t\t|\n");
					printf("+---------------------------------------------------------------+\n");
					printf("+---------------------------------------------------------------+\n");
					printf("| (1).O jogo e constituito por 5 rodadas.\t\t\t|\n|\t\t\t\t\t\t\t\t|\n");
					printf("| (2).Cada rodada possui uma unica pergunta e resposta correta. |\n|\t\t\t\t\t\t\t\t|\n");
					printf("| (3).Cada pergunta e unica do jogador e nao se repete.\t\t|\n|\t\t\t\t\t\t\t\t|\n");
					printf("| (3).A resposta do jogador para determinada pergunta sera dada |\n");
					printf("| em um opcao entre os numeros 1, 2, 3 e 4.\t\t\t|\n|\t\t\t\t\t\t\t\t|\n");
					printf("| (4).Ao final do jogo, sera exibido o placar de acertos.\t|\n|\t\t\t\t\t\t\t\t|\n");
					printf("| (5).A cada pergunta correta, esta sera armazenada e exibida\t|\n");
					printf("| no final do jogo.\t\t\t\t\t\t|\n");
					printf("+---------------------------------------------------------------+\n");
					
					system("PAUSE");
					
					#ifdef _WIN32
        				system("cls");
					#else
        				system("clear");
					#endif
					break;
			
			case 3:
					BancoDePerguntas();
					break;
					
			case 4:
					limparBancoDePerguntas();
					printf("+---------------------------------------------------------------+\n");
					printf("|\t\t\tFIM DO JOGO!\t\t\t\t|\n");
					printf("+---------------------------------------------------------------+\n");
					break;
			
		}
		
	} while (escolhaMenu != 4);
	
}
