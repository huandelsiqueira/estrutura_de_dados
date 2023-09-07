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
         printf("(%d)=%.2f\n", pl.v[f].cod, pl.v[f].peso);     
}

int empilha(PilhaCF *pl, float peso, int cod) {
	
	if(pl->topo == MAX_NODOS-1) {
		return (PILHA_CHEIA);
	} else {
		pl->topo++;
		pl->v[pl->topo].peso = peso;
		pl->v[pl->topo].cod = cod;
		return (SUCESSO);
	}
	
}

int desempilha (PilhaCF *pl, int *d) {
	
	if(pl->topo == -1) {
		return (PILHA_VAZIA);
	} else {
		pl->topo--;
		*d = pl->v[pl->topo].cod;
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

int consulta(PilhaCF pl, Dado *d) {
	
	if (pl.topo == -1) {
		return (PILHA_VAZIA);
	} else {
		*d = pl.v[pl.topo];
		printf("TOPO[%d]\n", pl.topo);
		return (SUCESSO);
	}
	
}

int pesquisa(PilhaCF pl, int *cod) {
	
	if (pl.topo == -1) {
		return(PILHA_VAZIA);
	} else {
		int i;
		for (i = pl.topo; i >= 0; i--) {
			if (pl.v[i].cod == *cod) {
				printf("O valor achado foi:\n");
				printf("(%d)=%.2f = Topo[%d]\n", pl.v[i], pl.v[i].peso, i);
				return (SUCESSO);
			} 
		} 
	return (DADO_INEXISTENTE);	
	}
}

void exibeNodos(PilhaCF pl) {
	int i, c = 0;
	for (i = pl.topo; i >= 0; i--) {
		c = c + 1;
	}
	printf("Quantidade de nodos: %d\n", c);
}

