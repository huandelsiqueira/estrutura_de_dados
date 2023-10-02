#include <stdio.h>
#include <stdlib.h>
#include "pilhase.h"

void criaPilha(PilhaSE *pl) {
	pl->topo = NULL;
	pl->contador = 0;
}

int empilha(PilhaSE *pl, Dado dado) {
	Nodo *proxpl = (Nodo *) malloc(sizeof(Nodo));
	if (proxpl == NULL) {
		return FALTOU_MEMORIA;
	} else {
		proxpl->info = dado;
		proxpl->prox = pl->topo;
		pl->topo = proxpl;
		pl->contador = pl->contador + 1;
		return SUCESSO; 
	}
}

int desempilha(PilhaSE *pl, Dado *dado) {
	if (pl->topo == NULL) {
		return PILHA_VAZIA;
	} else {
		Nodo *proxpl = pl->topo;
		*dado = pl->topo->info;
		proxpl = pl->topo->prox;
		free(pl->topo);
		pl->topo = proxpl;
		pl->contador--;
		return SUCESSO;
	}
}

int estaVazia(PilhaSE pl) {
	if (pl.topo == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void exibe(PilhaSE pl) {
	Nodo *platual = pl.topo;
	if (platual == NULL) {
		printf("\nPilha Vazia.\n");
	} else {
		int i;
		do {
			printf("+===============+\n");
			printf("|(%d) = %.2f\t|\n", platual->info.cod, platual->info.peso);
			printf("+===============+\n");
			platual = platual->prox;
		} while (platual != NULL);
	}
}

int consultaTopo(PilhaSE *pl, Dado *dado) {
	if (pl->topo == NULL) {
		return PILHA_VAZIA;
	} else {
		printf("[TOPO] = %d\n", pl->topo);
		*dado = pl->topo->info;
	}
}
