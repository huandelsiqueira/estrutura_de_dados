#ifndef Proj_ED
#define Proj_ED
#include <stdbool.h>
#include <deque>

#define SUCESSO 0
#define FALTOU_MEMORIA 1
#define LISTA_VAZIA 2
#define CODIGO_INEXISTENTE 3
#define PILHA_CHEIA 4
#define QTD_PERGUNTAS 5
#define PILHA_VAZIA 6

typedef struct {
	
	char pergunta[100];
	char opcoes[4][30];
	int resposta_correta;
	bool perguntaUsada;
	
} Pergunta;

typedef struct {
	
	char nomeJogador[20];
	int pontosJogador;
	
} dadoJogador;

///////////////////

typedef struct nodo Nodo;

struct nodo {
	
	Pergunta perguntaCorreta;
	Nodo *prox;
	
};

typedef struct {
	
	Nodo *inicio;
	
} Lista;

///////////////////

Pergunta obterPerguntaAleatoria();
void exibePlacar(dadoJogador jogador);
void realizaRodada(dadoJogador *jogador, int respostaJogador);
void BancoDePerguntas();
void limparBancoDePerguntas();

///////////////////

void criaLista(Lista *lt);
int incluiNoInicio(Lista *lt, Pergunta pergunta);
int incluiNoFim(Lista *lt, Pergunta pergunta);
void exibe(Lista lt);
void limparLista(Lista *lt);

#endif
