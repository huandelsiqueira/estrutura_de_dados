/*Escreva uma função em C chamada duplaCrescente que classifique 2 valores inteiros passados como argumento em ordem crescente.

Entrada: Dois números inteiros
Saída: Os dois inteiros em ordem crescente.
Retorno: Nenhum.

Escreva um programa em C para ler uma quantidade indeterminada de duplas de inteiros. Escrever cada dupla em ordem crescente. Os valores em ordem crescente devem ser obtidos através da chamada à função duplaCrescente. O programa termina quando os dois valores informados forem iguais (nesta situaça o os valores não devem ser impressos).*/

#include <stdio.h>
#include <conio.h>

void duplaCrescente(int x, int y, int *c, int *d);

int main() {
    
    int a, b, c, d;

    do {

        printf("Digite um numero inteiro:\n");
        scanf("%d", &a);
        printf("Digite outro numero inteiro:\n");
        scanf("%d", &b);

        duplaCrescente(a, b, &c, &d);

        if (a != b) {
            printf("%d\t%d\n", c, d);
        }

    } while (a != b);
}

void duplaCrescente(int x, int y, int *c, int *d) {

    if (x != y) {
        if (x > y) {
            *c = y;
            *d = x;
        } else {
            *c = x;
            *d = y;
        }
    }
    
}