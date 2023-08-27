/* Escreva	 uma	 função	 chamada	 exibeDivisores que	 exiba	 na	 tela	 os	 divisores do	 inteiro	 passado	 com	argumento. Escreva	 um	 programa	 em	 C	 para imprimir	 os	 números	 de	 1	 a	 20	 com	 seus	 respectivos	 divisores.	 Cada conjunto	de	divisores	deve	ser	impresso	com	a	função	exibeDivisores.	A	saída	deve	ser impressa	conforme	o formato	abaixo: 
1: 1
2: 1 2
3: 1 3
4: 1 2 4
5: 1 5
6: 1 2 3 6
7: 1 7
8: 1 2 4 8
...
18: 1 2 3 6 9 18
19: 1 19
20: 1 2 4 5 10 20 */

#include <stdio.h>
#include <conio.h>

void exibeDivisores(int);

int main() {
    int i;
    for (i = 1; i <= 20; i++) {
        printf("%d: ", i);
        exibeDivisores(i);
        printf("\n");
    }
}

void exibeDivisores(int n) {
    int i, resto;
    for (i = 1; i <= n+1; i++) {
        resto = n % i;
        if (resto == 0) {
            printf("%d ", i);
        }
    }
}