/* 5 Escreva	um	programa	em	C	para	ler	um	inteiro	Q	(máximo	10).	A	seguir	ler	um	vetor	Z	de	Q	elementos	e um	 valor	 Y.	 Copiar	 todos	 os	 elementos	maiores	 que	 Y	 que	 estão	no	 vetor	 Z	 para	 um	 vetor	W	 (sem	 deixar	elementos	vazios	entre	os	valores	copiados).	Escrever	o	vetor	W após	o	término	cópia. */

#include <stdio.h>
#include <conio.h>

int main() {
    int Q, i, c = 0;
    printf("Digite um valor inteiro (maximo 10):\n");
    scanf("%d", &Q);
    float vetZ[Q], valorY;
    for (i = 0; i < Q; i++) {
        printf("%d. Digite um valor para vetQ[%d]:\n", i+1, i);
        scanf("%f", &vetZ[i]);
    }
    printf("Digite um valor para Y:\n");
    scanf("%f", &valorY);
    for (i = 0; i < Q; i++) {
        if (vetZ[i] > valorY) {
            c = c + 1;
        }
    }
    float vetW[c];
    for (i = 0; i < Q; i++) {
        if (vetZ[i] > valorY) {
            vetW[i] = vetZ[i];
            printf("vetW[%d] = %.2f\n", i, vetW[i]);
        }
    }
}