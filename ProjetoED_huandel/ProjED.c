#include "ProjED.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <deque>


Pergunta listaPerguntas[] = {

	{"Qual o maior planeta do Sistema Solar?", {"Jupiter", "Terra", "Marte", "Venus"}, 1},
    {"Quem escreveu 'Dom Quixote'?", {"Miguel de Cervantes", "Garcia Marquez", "Shakespeare", "Dostoievski"}, 1},
    {"Qual a capital do Brasil?", {"Rio de Janeiro", "Brasilia", "Sao Paulo", "Salvador"}, 2},
    {"Quem pintou a Mona Lisa?", {"Pablo Picasso", "Leonardo da Vinci", "Vincent van Gogh", "Michelangelo"}, 2},
    {"Qual e o animal terrestre mais rapido?", {"Guepardo", "Leao", "Elefante", "Zebra"}, 1},
    {"Quem foi o primeiro presidente dos Estados Unidos?", {"Thomas Jefferson", "Abraham Lincoln", "George Washington", "John F. Kennedy"}, 3},
    {"Qual e o maior oceano do mundo?", {"Oceano Atlantico", "Oceano Indico", "Oceano Artico", "Oceano Pacifico"}, 4},
    {"Quem escreveu a peca 'Romeu e Julieta'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "F. Scott Fitzgerald"}, 1},
    {"Qual e o metal mais abundante na crosta terrestre?", {"Aluminio", "Ferro", "Ouro", "Cobre"}, 2},
    {"Qual pais e conhecido como 'Terra do Sol Nascente'?", {"China", "India", "Japao", "Coreia do Sul"}, 3},
    {"Qual e a montanha mais alta do mundo?", {"Everest", "K2", "Makalu", "Lhotse"}, 1},
    {"Qual e o pais com a maior area territorial do mundo?", {"Russia", "Canada", "Estados Unidos", "China"}, 1},
    {"Quem escreveu \"A Origem das Especies\"?", {"Charles Darwin", "Isaac Newton", "Galileu Galilei", "Albert Einstein"}, 1},
    {"Qual e o maior deserto do mundo?", {"Saara", "Deserto de Atacama", "Deserto do Gobi", "Antartica"}, 1},
    {"Qual e a cor do cavalo branco de Napoleao?", {"Branco", "Preto", "Marrom", "Cinza"}, 1},
    {"Qual e o maior rio do mundo?", {"Nilo", "Yangtze", "Mississipi", "Amazonas"}, 4},
    {"Quem escreveu \"A Divina Comedia\"?", {"Geoffrey Chaucer", "Dante Alighieri", "Virgilio", "Homero"}, 2},
    {"Qual e o pais com a maior populacao do mundo?", {"China", "India", "Estados Unidos", "Indonesia"}, 2},
    {"Quem foi o primeiro ser humano a pisar na Lua?", {"Buzz Aldrin", "Yuri Gagarin", "Neil Armstrong", "Alan Shepard"}, 3},
    {"Qual e o elemento quimico mais abundante na Terra?", {"Hidrogenio", "Oxigenio", "Carbono", "Ferro"}, 2},
    {"Quem pintou \"A Noite Estrelada\"?", {"Pablo Picasso", "Claude Monet", "Salvador Dali", "Vincent van Gogh"}, 4},
    {"Qual e a capital da Franca?", {"Roma", "Berlim", "Londres", "Paris"}, 4},
    {"Qual e o maior mamifero terrestre?", {"Elefante africano", "Baleia azul", "Girafa", "Rinoceronte"}, 2},
    {"Quem escreveu \"O Pequeno Principe\"?", {"Jules Verne", "Victor Hugo", "Antoine de Saint-Exupery", "Gustave Flaubert"}, 3},
    {"Qual e a cordilheira mais extensa do mundo?", {"Himalaias", "Rockies", "Alpes", "Andes"}, 4},
    {"Quem foi o primeiro homem a circunavegar a Terra?", {"Fernao de Magalhaes", "Cristovao Colombo", "Vasco da Gama", "Marco Polo"}, 1},
    {"Quem escreveu \"1984\"?", {"Aldous Huxley", "Ray Bradbury", "George Orwell", "H.G. Wells"}, 3},
    {"Quem pintou \"Guernica\"?", {"Pablo Picasso", "Salvador Dali", "Joan Miro", "Diego Rivera"}, 1},
    {"Qual e a lingua mais falada no mundo?", {"Espanhol", "Mandarim", "Ingles", "Hindi"}, 2},
    {"Qual e o pais com a maior area de floresta tropical do mundo?", {"Brasil", "Congo", "Indonesia", "Peru"}, 1},
    {"Quem foi o primeiro imperador romano?", {"Cesar", "Augusto", "Nero", "Marco Aurelio"}, 2},

};

int numPerguntas = sizeof(listaPerguntas) / sizeof(listaPerguntas[0]);

std::deque<Pergunta> bancoDePerguntas;

void BancoDePerguntas() {
	
	int i, k;
	std::deque<Pergunta>::iterator j;
	
	for (i = 0; i< numPerguntas; i++) {
		
		bancoDePerguntas.push_back((listaPerguntas[i]));
		
	}
	
	j = bancoDePerguntas.begin();
	
	for (j = bancoDePerguntas.begin(); j != bancoDePerguntas.end(); j++) {
		
        printf("Pergunta: %s\n", j->pergunta);
        printf("Opcoes:\n");
        
        for (k = 0; k < 4; k++) {
        	
            printf("(%d) %s\n", k + 1, j->opcoes[k]);
            
        }
        
        printf("Resposta correta: %d\n", j->resposta_correta);
        printf("\n");
        
    }
    
    system("PAUSE");
    
    #ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	
}

void limparBancoDePerguntas() {
	
	if (bancoDePerguntas.empty()) {
		
		printf("O banco de perguntas ja esta vazio!\n");
		
	} else {
		
		bancoDePerguntas.clear();
    	printf("Banco de perguntas esvaziado.\n");
		
	}
    
}

Pergunta obterPerguntaAleatoria() {
	
	int nrPerguntaSorteada;
	
	do {
		nrPerguntaSorteada = rand() % numPerguntas; 
	} while (listaPerguntas[nrPerguntaSorteada].perguntaUsada == true);

    Pergunta perguntaSelecionada;
    memcpy(&perguntaSelecionada, &listaPerguntas[nrPerguntaSorteada], sizeof(Pergunta));
    
    listaPerguntas[nrPerguntaSorteada].perguntaUsada = true;

    return perguntaSelecionada;
    
}

void realizaRodada(dadoJogador *jogador, int respostaJogador) {
	
	int i, j;
	
	Lista lt;
	criaLista(&lt);
	jogador->pontosJogador = 0;
	
	Pergunta perguntaAcertada;
	
	for (i = 0; i < 5; i++) {
							
		printf("+---------------------------------------+\n");
		printf("|Rodada %d - Jogador: %s\t\t|--------------------------------------------------------------\n", i+1, jogador->nomeJogador);
		printf("+---------------------------------------+\n");
		
		srand((unsigned int)time(NULL));
		Pergunta perguntaAtual;
		perguntaAtual = obterPerguntaAleatoria();
		
		printf("%s\n", perguntaAtual.pergunta);
		for (j = 0; j < 4; j++) {

			printf("(%d).%s  ", j+1, perguntaAtual.opcoes[j]);

		}
		
		do {
		
			printf("\n\nDigite sua resposta (1 a 4): ");
			scanf("%d", &respostaJogador);
			printf("\n");
		
		} while (respostaJogador < 1 || respostaJogador > 4);
		
		if (respostaJogador == perguntaAtual.resposta_correta) {
			
			Pergunta perguntaAcertada;
			perguntaAcertada = perguntaAtual;
			
			jogador->pontosJogador += 1;
			
			incluiNoFim(&lt, perguntaAcertada);

			printf("\033[0;32mParabens!!! Voce acertou!\033[0m\n");
			
		} else {
			
			printf("\033[0;31mQue pena, voce errou!\033[0m\n");
			
		}
		
		printf("\nResposta: %d\n\n", perguntaAtual.resposta_correta);
		
		sleep(4);
		
		#ifdef _WIN32
		system("cls");
		#else
			system("clear");
		#endif
		
	}
	
}

void exibePlacar(dadoJogador jogador) {
	
	Lista lt;
	
	printf("+---------------------------------------------------------------+\n");
	printf("| Jogador: %s\t | Placar: %d perguta(s) acertada(s)\t|\n", jogador.nomeJogador, jogador.pontosJogador);
	printf("+---------------------------------------------------------------+\n");
	
	exibe(lt);
		
}

///////////////////

void criaLista(Lista *lt) {
	lt->inicio = NULL;
}

int incluiNoInicio(Lista *lt, Pergunta pergunta) {
	Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else {
		pNodo->perguntaCorreta = pergunta;
		pNodo->prox = lt->inicio;
		lt->inicio = pNodo;
		return SUCESSO; 
	}
}

int incluiNoFim(Lista *lt, Pergunta pergunta) {
	Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else if (lt->inicio == NULL) {
		incluiNoInicio(lt, pergunta);
	} else {
		Nodo *pAux = lt->inicio;
		do {
			if (pAux->prox == NULL) {
				pNodo->perguntaCorreta = pergunta;
				pAux->prox = pNodo;
				pNodo->prox = NULL;
				return SUCESSO;
			}
			pAux = pAux->prox;
		} while (pAux != NULL);
	}
}

void exibe(Lista lt) {

	int i, j;
	
	Nodo *pAux;
	pAux = lt.inicio;
	
	printf("\nLista das perguntas acertadas pelo jogador:\n\n");
	
	while (pAux != NULL) {
		
		printf("- %s\n", pAux->perguntaCorreta.pergunta);
		printf("\n");
		pAux = pAux->prox;
		
	}
}

void limparLista(Lista *lt) {
	
    Nodo *atual = lt->inicio;
    Nodo *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual); 
        atual = proximo;
    }

    lt->inicio = NULL;
}
