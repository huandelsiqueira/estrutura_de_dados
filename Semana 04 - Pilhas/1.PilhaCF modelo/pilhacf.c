#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

void criaPilha(PilhaCF *pl){
     pl->topo= -1;
}

void exibePilha(PilhaCF pl){
     int f;
     printf("Exibindo a Pilha\n");
     printf("TOPO[%d]\n", pl.topo);
     for (f=pl.topo;f >= 0;f--)
         printf("%4d\n", pl.v[f]);     
}

int empilha(PilhaCF *pl, int d) {
	
	if(pl->topo == MAX_NODOS-1) {
		return (PILHA_CHEIA);
	} else {
		pl->topo++;
		pl->v[pl->topo] = d;
		return (SUCESSO);
	}
	
}

int desempilha (PilhaCF *pl, int *d) {
	
	if(pl->topo == pl->topo) {
		return (PILHA_VAZIA);
	} else {
		pl->topo--;
		*d = pl->v[pl->topo];
		return (SUCESSO);
	}
	
}

int estaCheia (PilhaCF pl) {
	
	if(pl.topo == MAX_NODOS-1) {
		return (PILHA_CHEIA);
	}
	
}

int estaVazia (PilhaCF pl) {
	
	if(pl.topo == -1) {
		return (PILHA_VAZIA);
	}
	
}

int consulta(PilhaCF pl, int *d) {
	
	if (pl.topo == -1) {
		return (PILHA_VAZIA);
	} else {
		*d = pl.v[pl.topo];
		printf("TOPO[%d]\n", pl.topo);
		return (SUCESSO);
	}
	
}

int pesquisa(PilhaCF pl, int *d) {
	
	if (pl.topo == -1) {
		return (PILHA_VAZIA);
	} else if (*d == pl.topo) {
		*d = pl.v[pl.topo];
		printf("TOPO[%d]\n", pl.topo);
		return (SUCESSO);
	} else {
		return (DADO_INEXISTENTE);
	}
	
}

void exibeNodos(PilhaCF pl) {
	int i, c = 0;
	for (i = pl.topo; i >= 0; i--) {
		c = c + 1;
	}
}

