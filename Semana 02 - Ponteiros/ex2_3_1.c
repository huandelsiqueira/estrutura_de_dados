/*Escreva uma função chamada duplaClassificada que classifique 2 valores inteiros conforme o código passado como argumento (0-ordem crescente 1-ordem decrescente).

Entrada: Um código que identifica a ordem de classificação (0-ordem crescente 1-ordem decrescente).
Entrada: Os dois numeros inteiros.
Saída: Os 2 valores de entrada na ordem desejada
Retorno: Nenhum */

#include <stdio.h>
#include <conio.h>

void duplaCrescente(int x, int y, int cod, int *w, int *z);

int main() {

    int a, b, cod, *c, *d;

    do {

        printf("Digite o primeiro numero:\n");
        scanf("%d", &a);
        printf("Digite o segundo numero:\n");
        scanf("%d", &b);
        
        if (a != b) {
            printf("Digite a operacao desejada (0).Crescente ou (1).Decrescente:\n");
            scanf("%d", &cod);
        }

        duplaCrescente(a, b, cod, &c, &d);

        if (a != b) {
           printf("%d\t%d\n", c, d);
        }

    } while (a != b);


}

void duplaCrescente(int x, int y, int cod, int *w, int *z) {

    if (cod == 0) {
        if (x > y) {
            *w = y;
            *z = x;
        } else {
            *w = x;
            *z = y;
        }
    } else if (cod == 1) {
        if (x > y) {
            *w = x;
            *z = y;
        } else {
            *w = y;
            *z = x;
        }
    }

}