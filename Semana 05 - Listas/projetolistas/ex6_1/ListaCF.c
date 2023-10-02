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
	} else {
		int i, j, flag = 0;
		for (i = 0; i <= lt->n; i++) {
			if (lt->v[i].cod == codref) {
				for (j = lt->n; j >= i; j--) {
					lt->v[j+1] = lt->v[j];
				}
				lt->v[i] = dado;
				lt->n++;
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			return SUCESSO;
		} else {
			return CODIGO_INEXISTENTE;
		}
	}
}

int excluiNodo(ListaCF *lt, int cod, Dado *d) {
	int i, j, flag = 0;
	for (i = 0; i < lt->n; i++) {
		if (lt->v[i].cod == cod) {
			*d = lt->v[i];
			for (j = i+1; j <= lt->n; j++) {
				lt->v[j-1] = lt->v[j];
			}
			flag = 1;
			lt->n--;
			break;
		}
	}
	if (flag == 1) {
		return SUCESSO;
	} else {
		return CODIGO_INEXISTENTE;
	}
}


	




