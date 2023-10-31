#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

void criaLista(ListaSE *lt) {
	lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado dado) {
	Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else {
		pNodo->info = dado;
		pNodo->prox = lt->inicio;
		lt->inicio = pNodo;
		return SUCESSO; 
	}
}

void exibe(ListaSE lt) {
	Nodo *pAux;
	pAux = lt.inicio;
	printf("Lista:\n\n");
	printf("[EndNodo]\t\t[cd]\t[peso]\t\t[EndProx]\n\n");
	while (pAux != NULL) {
		/*printf("|(%d)= %.2f|\n", pAux->info.cod, pAux->info.peso);*/
		printf("%p\t(%d)\t%.2f\t\t%p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
		pAux = pAux->prox;
	}
}

int quantidadeDeNodos(ListaSE lt) {
	int qtNodo = 0;
	Nodo *pNodo;
	pNodo = lt.inicio;
	while (pNodo != NULL) {
		qtNodo++;
		pNodo = pNodo->prox;
	}
	return qtNodo;
}

int estaVazia(ListaSE lt) {
	if (lt.inicio == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int excluiDoInicio(ListaSE *lt, Dado *dado) {
	Nodo *pTemp;
	if (lt->inicio == NULL) {
		return LISTA_VAZIA;
	} else {
		*dado = lt->inicio->info;
		pTemp = lt->inicio;
		lt->inicio = lt->inicio->prox;
		free(pTemp);
		return SUCESSO;
	}
}

int incluiNoFim(ListaSE *lt, Dado dado) {
	Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else if (lt->inicio == NULL) {
		incluiNoInicio(lt, dado);
	} else {
		Nodo *pAux = lt->inicio;
		do {
			if (pAux->prox == NULL) {
				pNodo->info = dado;
				pAux->prox = pNodo;
				pNodo->prox = NULL;
				return SUCESSO;
			}
			pAux = pAux->prox;
		} while (pAux != NULL);
	}
}

int excluiDoFim(ListaSE *lt, Dado *dado) {
	Nodo *pNodo, *pTemp;
	pNodo = lt->inicio;
	if (lt->inicio == NULL) {
		return LISTA_VAZIA;
	} else if (quantidadeDeNodos(*lt) == 1){
		*dado = pNodo->info;
		free(pNodo);
		lt->inicio = NULL;
		return SUCESSO;
	} else {
		do {
			if (pNodo->prox == NULL) {
				*dado = pNodo->info;
				pTemp->prox = NULL;
				free(pNodo);
				return SUCESSO;
			}
			pTemp = pNodo;
			pNodo = pNodo->prox;
		}while(pNodo != NULL);
	}
}

int incluiDepois(ListaSE *lt, Dado dado, int cod) {
	Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));
	Nodo *pAux, *pTemp;
	pAux = lt->inicio;
	if(pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else if (pAux == NULL) {
		return LISTA_VAZIA;
	} else {
		while (pAux != NULL) {
			if (pAux->info.cod == cod) {
				pTemp = pAux;
				pNodo->info = dado;
				pNodo->prox = pTemp->prox;
				pTemp->prox = pNodo;
				return SUCESSO;
			}
			pAux = pAux->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}

int excluiNodo(ListaSE *lt, Dado *dado, int cod) {
	Nodo *pNodo, *pAux = NULL;
	if (lt->inicio == NULL){
		return LISTA_VAZIA;
	} else {
		pNodo = lt->inicio;
		while (pNodo != NULL) {
			if (pNodo->info.cod == cod) {
				if (pAux == NULL) {
					lt->inicio = pNodo->prox;
				} else {
					pAux->prox = pNodo->prox;
				}
				if (dado != NULL) {
					*dado = pNodo->info;
				}
				free(pNodo);
				return SUCESSO;
			}
			pAux = pNodo;
			pNodo = pNodo->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}

int consultaPorCodigo(ListaSE lt, Dado *dado, int cod) {
	while (lt.inicio != NULL) {
		if (lt.inicio->info.cod == cod) {
			*dado = lt.inicio->info;
			return SUCESSO;
		} 
		lt.inicio = lt.inicio->prox;
	}
	return CODIGO_INEXISTENTE;
}
