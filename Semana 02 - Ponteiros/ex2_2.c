/*Escreva uma função em C chamada classificaCrescente que classifique 2 valores inteiros passados como argumento em ordem crescente.

Entrada/Saída: Dois números inteiros
Saída: Nenhuma
Retorno: Nenhum

Reescreva o programa principal do exercício 2.1 utilizando a funçao classificaCrescente para obter os valores classificados.
*/

#include <stdio.h>
#include <conio.h>

void classificaCrescente(int *x, int *y);

int main() {
    
    int a, b;

    do {
        
        printf("Digite um numero inteiro:\n");
        scanf("%d", &a);
        printf("Digite outro numero inteiro:\n");
        scanf("%d", &b);

        classificaCrescente(&a, &b);

        if (a != b) {
            printf("%d\t%d\n", a, b);
        }

    } while (a != b);
}

void classificaCrescente(int *x, int *y) {

    int aux;

    if (*x != *y) {
        if (*x > *y) {
            aux = *x;
            *x = *y;
            *y = aux;
        } else {
            *x = *x;
            *y = *y;
        }
    }

}