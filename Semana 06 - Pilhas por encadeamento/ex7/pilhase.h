#ifndef PilhaSE_H
#define PilhaSE_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

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
	Nodo *topo;
	int contador;
} PilhaSE;

void criaPilha(PilhaSE *pl);
int desempilha(PilhaSE *pl, Dado *dado);
int consultaTopo(PilhaSE *pl, Dado *dado);
int empilha(PilhaSE *pl, Dado dado);
int estaVazia(PilhaSE pl);
void exibe(PilhaSE pl);
void exibeNodos(PilhaSE pl);

#endif
