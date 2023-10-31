#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaDE.h"

void criaLista(ListaDE *lt){
     lt->inicio = NULL;
     lt->fim = NULL;
     lt->n = 0;
}

int incluiNoInicio(ListaDE *lt, Dado dado) {
    Nodo *pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = dado;
       pNodo->prox = lt->inicio;
       pNodo->ant = NULL;
       
       if (lt->n == 0)
          lt->fim = pNodo;
       else
          lt->inicio->ant =  pNodo;  

       lt->inicio = pNodo;
       lt->n++;
       return(SUCESSO);
    }
}

void exibe(ListaDE lt) {
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nExibindo a Lista\n");
     printf("Inicio: %p \n", lt.inicio);
     printf("[End Ant]\t\t[cd]\t[End Nodo]\t\t[peso]\t[End Prox]\n");
     while (pAux != NULL) {
           printf("%p\t%3d\t%p\t%.2f\t%p\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
     printf("Fim: %p - N= %d\n", lt.fim, lt.n);
}

int excluiDoInicio(ListaDE *lt, Dado *dado) {
	Nodo * pNodo;
	if (lt->n == 0) {
		return LISTA_VAZIA;
	} else {
		*dado = lt->inicio->info;
		pNodo = lt->inicio;
		lt->inicio = lt->inicio->prox;
		if (lt->n == 1) {
			lt->fim = NULL;
		} else {
			lt->inicio->ant = NULL;
		}
		lt->n--;
		free(pNodo);
		return SUCESSO;
	}
}

int estaVazia(ListaDE lt) {
	if (lt.n == 0) {
		return 1;
	} else {
		return 0;
	}
}

int excluiDoFim(ListaDE *lt, Dado *dado) {
	Nodo *pNodo;
	if (lt->n == 0) {
		return LISTA_VAZIA;
	} else if (lt->n == 1){
		pNodo = lt->inicio;
		*dado = pNodo->info;
		lt->inicio = NULL;
		lt->fim = NULL;
	} else {
		pNodo = lt->fim;
		*dado = pNodo->info;
		lt->fim = pNodo->ant;
		lt->fim->prox = NULL;
	}
	free(pNodo);
	lt->n--;
	return SUCESSO;
}

int incluiNoFim(ListaDE *lt, Dado dado) {
	Nodo *pNodo = (Nodo *) malloc (sizeof(Nodo));
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else {
		pNodo->info = dado;
		pNodo->prox = NULL;
		if (lt->inicio == NULL) {
			pNodo->ant = NULL;
			lt->inicio = pNodo;
			lt->fim = pNodo;
		} else {
			pNodo->ant = lt->fim;
			lt->fim->prox = pNodo;
			lt->fim = pNodo;
		}
	}
	lt->n++;
	return SUCESSO;
}

bool verificaExistencia(ListaDE *lt, Dado dado, int cod) {
	Nodo *pNodo = lt->inicio;
	while (pNodo != NULL) {
		if (pNodo->info.cod == cod) {
			return true;
		}
		pNodo = pNodo->prox;
	}
	return false;
}

int consultaPorCodigo(ListaDE lt, Dado *dado, int cod) {
	while (lt.inicio != NULL) {
		if (lt.inicio->info.cod == cod) {
			*dado = lt.inicio->info;
			return SUCESSO;
		}
		lt.inicio = lt.inicio->prox;
	}
	return CODIGO_INEXISTENTE;
}

int incluiDepois(ListaDE *lt, Dado dado, int cod) {
	Nodo *pNodo = (Nodo *) malloc (sizeof(Nodo));
	Nodo *pAux, *pTemp;
	pAux = lt->inicio;
	if (pNodo == NULL) {
		return FALTOU_MEMORIA;
	} else if (pAux == NULL) {
		free(pNodo);
		return LISTA_VAZIA;
	} else {
		while (pAux != NULL) {
			if (pAux->info.cod == cod) {
				pTemp = pAux;
				pNodo->info = dado;
				pNodo->prox = pTemp->prox;
				pNodo->ant = pTemp;
				pTemp->prox = pNodo;
				if (pNodo->prox != NULL) {
					pNodo->prox->ant = pNodo;
				}
				lt->n++;
				return SUCESSO;
			}
			pAux = pAux->prox;
		}
		free(pNodo);
		return CODIGO_INEXISTENTE;
	}
}

int excluiNodo(ListaDE *lt, Dado *dado, int cod) {
	Nodo *pNodo, *pAux = NULL;
	if (lt->inicio == NULL) {
		return LISTA_VAZIA;
	} else {
		pNodo = lt->inicio;
		while (pNodo != NULL) {
			if (pNodo->info.cod == cod) {
				if (pAux == NULL) {
					lt->inicio = pNodo->prox;
					if (pNodo->prox != NULL) {
						pNodo->prox->ant = NULL;
					}	
				} else {
					pAux->prox = pNodo->prox;
					if (pNodo->prox != NULL) {
						pNodo->prox->ant = pAux;
					}
				}
				if (dado != NULL) {
					*dado = pNodo->info;
				}
				free(pNodo);
				lt->n--;
				return SUCESSO;
			}
			pAux = pNodo;
			pNodo = pNodo->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}
