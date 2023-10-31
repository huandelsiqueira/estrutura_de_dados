#ifndef ListaSE_H
#define ListaSE_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *inicio;
} ListaSE;

void criaLista(ListaSE *lt);
int incluiNoInicio(ListaSE *lt, Dado dado);
void exibe(ListaSE lt);
int quantidadeDeNodos(ListaSE lt);
int estaVazia(ListaSE lt);
int excluiDoInicio(ListaSE *lt, Dado *dado);
int incluiNoFim(ListaSE *lt, Dado dado);
int excluiDoFim(ListaSE *lt, Dado *dado);
int incluiDepois(ListaSE *lt, Dado dado, int cod);
int excluiNodo(ListaSE *lt, Dado *dado, int cod);
int consultaPorCodigo(ListaSE lt, Dado *dado, int cod);

#endif
