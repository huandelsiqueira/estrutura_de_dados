/*Escreva uma funça o em C chamada calcDivisao que receba como entrada dois inteiros e retorne o valor da divisão do primeiro pelo segundo. Retornar também um código de erro indicando se foi ou não possível calcular a divisão.

Entrada: Dois inteiros.
Saída: O resultado da divisão (float)
Retorno: 0 se foi possí vel executar a divisão e 1 caso o segundo parâmetro de entrada for igual a zero.

Escreva um programa em C para ler um valor N. A seguir ler N duplas de valores. Para cada dupla calcular e escrever o resultado da divisão do primeiro valor pelo segundo. Utilizar a função calcDivisao para obter o resultado. Caso a função retorne o código de erro igual a 1 deve ser impressa a mensagem “Divisão por zero”*/

#include <stdio.h>
#include <conio.h>

int calcDivisao(int x, int y, float *r);

int main() {
    
    int a, b, num, i, resdiv;
    float div;

    printf("Quantas divisoes voce quer fazer?\n");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {

        printf("Digite o primeiro numero:\n");
        scanf("%d", &a);
        printf("Digite o segundo numero:\n");
        scanf("%d", &b);

        resdiv = calcDivisao(a, b, &div);

        printf("%.1f\n", div);

        if (resdiv == 1) {
            printf("Divisao por zero.\n");
        }

    } 
}

int calcDivisao(int x, int y, float *r) {

    *r = (float) x / y;

    if (y == 0) {
        return 1;
    } else {
        return 0;
    }

}