#include <stdio.h>
#include <stdlib.h>
#include "filase.h"

void criaFila(FilaSE *fl) {
	fl->frente = NULL;
	fl->re = NULL;
	fl->contador = 0;
}

int insere(FilaSE *fl, Dado dado) {
	Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else {
		pNodo->info = dado;
		pNodo->prox = NULL;
		if (fl->frente == NULL) {
			fl->frente= pNodo;
		} else {
			fl->re->prox = pNodo;
		}
		fl->re = pNodo;
		fl->contador = fl->contador + 1;
		return SUCESSO;
	}
}

int retira(FilaSE *fl, Dado *dado) {
	Nodo *pNodo = fl->frente;
	if (fl->frente == NULL) {
		fl->re = NULL;
		return FILA_VAZIA;
	} else {
		*dado = fl->frente->info;
		fl->frente = pNodo->prox;
		free(pNodo);
		fl->contador--;
		return SUCESSO;
	}
}

int estaVazia(FilaSE fl) {
	if (fl.frente == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int consulta(FilaSE *fl, Dado *dado) {
	if (fl->frente == NULL) {
		return FILA_VAZIA;
	} else {
		printf("[TOPO] = %d\n", fl->frente);
		*dado = fl->frente->info;
	}
}

void exibe(FilaSE fl) {
	Nodo *pNodo = fl.frente;
	if (pNodo == NULL) {
		printf("\nFila Vazia.\n");
	} else {
		do {
			printf("|(%d) = %.2f|\t", pNodo->info.cod, pNodo->info.peso);
			pNodo = pNodo->prox;
		} while (pNodo != NULL);
	}
}
