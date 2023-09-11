#ifndef ListaCF_H
#define ListaCF_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define POSICAO_INVALIDA 3
#define CODIGO_INEXISTENTE 4
#define MAX_NODOS 5

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
	int n;
	Dado v[MAX_NODOS];
} ListaCF;

void criaLista(ListaCF *lt);
void exibe(ListaCF lt);
int estaCheia(ListaCF lt);
int excluiDoFim(ListaCF *lt, int *d);
int excluiDoInicio(ListaCF *lt, Dado *d);
int incluiAntes(ListaCF *lt, Dado dado, int codref);
int incluiNoFim(ListaCF *lt, Dado d);
int quantidadeDeNodos(ListaCF lt);
int estaVazia(ListaCF lt);
int incluiNoInicio(ListaCF *lt, Dado d);
int consultaPorCodigo(ListaCF lt, int cod, Dado *d);
int excluiNodo(ListaCF *lt, int cod, Dado *d);

#endif
