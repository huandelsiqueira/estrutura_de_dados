/*Escreva um programa para ler uma quantidade indeterminada de duplas de valores. Escrever cada dupla em ordem crescente se a soma dos elementos da dupla for par e em ordem decrescente se a soma for ímpar. Os valores em ordem (conforme o caso) devem ser obtidos através da chamada à função duplaClassificada. O programa termina quando os dois valores informados forem iguais (nesta situaça o os valores na o devem ser impressos).

Entrada: Dois valores inteiros.
Saída: Os 2 valores de entrada na ordem desejada
Retorno: Nenhum */

#include <stdio.h>
#include <conio.h>

void duplaClassificada(int a, int b, int *x, int *y);

int main() {

    int a, b, c, d;

    do {

        printf("Digite o primeiro valor:\n");
        scanf("%d", &a);
        printf("Digite o segundo valor:\n");
        scanf("%d", &b);

        duplaClassificada(a, b, &c, &d);

        if (a != b) {
            printf("%d\t%d\n", c, d);
        }

    } while (a != b);
}

void duplaClassificada(int a, int b, int *x, int *y) {

    if (a != b) {
        if ((a + b) % 2 == 0) {

            if (a > b) {
                *x = b;
                *y = a;
            } else {
                *x = a;
                *y = b;
            }

        } else if ((a + b) % 2 == 1) {

            if (a > b) {
                *x = a;
                *y = b;
            } else {
                *x = b;
                *y = a;
            }
            
        }
    }

}