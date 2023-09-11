/*--------------------------------
* Arquivo: ListaCF.h
*/

#ifndef ListaCF_H
#define ListaCF_H

#define MAX_NODOS 5

#define SUCESSO            0
#define LISTA_VAZIA        1
#define LISTA_CHEIA        2
#define POSICAO_INVALIDA   3
#define CODIGO_INEXISTENTE 4

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
    int n;
	Dado v[MAX_NODOS];
} ListaCF;

/*--------------------------------
*  Prot�tipos das fun��es
*/
void criaLista(ListaCF *lt);
int  incluiNoFim(ListaCF *lt, Dado d);
void exibe(ListaCF lt);

#endif
