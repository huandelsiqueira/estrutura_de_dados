#include <stdio.h>
#include <stdlib.h>
#include "ListaCF.h"

void criaLista(ListaCF *lt) {
	lt->n = 0;
}

void exibe(ListaCF lt) {
	int i;
	printf("==========================================================================================\n");
	printf("Lista:\n\n");
	for (i = 0; i < lt.n; i++) {
		printf("(%d)= %.2f\t", lt.v[i].cod, lt.v[i].peso);
	}
	printf("\n==========================================================================================\n");
}

int incluiNoFim(ListaCF *lt, Dado d) {
	if(lt->n==MAX_NODOS) {
		return LISTA_CHEIA;
	} else {
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}
}

int quantidadeDeNodos(ListaCF lt) {
	return lt.n;
}

int estaVazia(ListaCF lt) {
	if (lt.n == 0) {
		return LISTA_VAZIA;
	} else {
		return SUCESSO;
	}
}

int estaCheia(ListaCF lt) {
	if (lt.n == MAX_NODOS) {
		return LISTA_CHEIA;
	} else {
		return SUCESSO;
	}
}

int excluiDoFim(ListaCF *lt, int *d) {
	if(lt->n < LISTA_VAZIA) {
		return LISTA_VAZIA;
	} else {
		*d = lt->v[lt->n].cod;
		lt->n--;
		return SUCESSO;
	}
}

int incluiNoInicio(ListaCF *lt, Dado d) {
	if (lt->n == MAX_NODOS) {
		return LISTA_CHEIA;
	} else {
		int i;
		for (i = lt->n; i > 0; i--) {
			lt->v[i] = lt->v[i-1];
		}
		lt->v[0] = d;
		lt->n++;
		return SUCESSO;
	}
}

int excluiDoInicio(ListaCF *lt, Dado *d) {
	if (lt->n == 0) {
		return LISTA_VAZIA;
	} else {
		int i;
		*d = lt->v[0];
		for (i = 1; i < lt->n; i++) {
			lt->v[i-1] = lt->v[i];
		}
		lt->n--;
		return SUCESSO;
	}
}

int consultaPorCodigo(ListaCF lt, int cod, Dado *d) {
    if (lt.n == 0) {
        return LISTA_VAZIA;
    } else {
        int i;
        for (i = lt.n; i >= 0; i--) {
            if(lt.v[i].cod == cod) {
                *d = lt.v[i];
                return SUCESSO;
            }
        }
    }
    return CODIGO_INEXISTENTE;
}

int incluiAntes(ListaCF *lt, Dado dado, int codref) {
	if (lt->n == 0) {
		return LISTA_VAZIA;
	} else if (lt->n == MAX_NODOS) {
		return LISTA_CHEIA;
	} else if (lt->n > 0 && lt->n < MAX_NODOS) {
		int i;
		if (codref == lt->v[codref-1].cod) {
			for (i = lt->n; i >= codref; i--) {
				lt->v[i] = lt->v[i-1];
			}
			lt->v[codref-1] = dado;
			lt->n++;
			return SUCESSO;
		}
	}
}

int excluiNodo(ListaCF *lt, int cod, Dado *d) {
	if (lt->n == 0) {
		return LISTA_VAZIA;
	} else {
		int i, j;
		for (j = 1; j <= lt->n; j++) {
			if (lt->v[j].cod == cod) {
				*d = lt->v[cod];
				for (i = cod; i < lt->n; i++) {
					lt->v[i-1] = lt->v[i];
				}
			lt->n--;
			} else if (lt->v[i+1].cod == cod) {
				*d = lt->v[cod];
				for (i = cod; i < lt->n; i++) {
					lt->v[i-1] = lt->v[i];
				}
			} 
		}
	}	
}
