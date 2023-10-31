#include <stdio.h>
#include <stdlib.h>
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
     printf("[End Ant]\t\t[cd]\t[End Nodo]\t[peso]\t[End Prox]\n");
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
