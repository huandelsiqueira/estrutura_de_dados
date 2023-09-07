#ifndef Pilhacf_H
#define Pilhacf_H

#define SUCESSO 0
#define PILHA_VAZIA 1
#define PILHA_CHEIA 2
#define DADO_INEXISTENTE 3
#define MAX_NODOS 5

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
	Dado v[MAX_NODOS];
	int topo;
} PilhaCF;

void criaPilha(PilhaCF *pl);
int empilha(PilhaCF *pl, float peso, int cod);
int desempilha(PilhaCF *pl,int *d);
int estaCheia(PilhaCF pl);
int estaVazia(PilhaCF pl);
int consulta(PilhaCF pl,Dado *d);
void exibePilha(PilhaCF pl);
int pesquisa(PilhaCF pl, int *cod);
void exibeNodos(PilhaCF pl);

#endif
