/*  Escreva	um	programa	em	C	para	ler	a	quantidade	L	de	linhas	(máximo	10)	e	a	quantidade	C	de	colunas	(máximo	10)	de	uma	matriz.	A	seguir	ler	uma	matriz	L	x	C	(considere	que	serão	informados	apenas	valores	positivos).	A	seguir	ler	uma	quantidade	indeterminada	de	valores.	Para	cada	valor	escrever	uma	mensagem	indicando	 se	 ele	 está	 ou	 não	 armazenado	 na	 matriz.	 Para	 cada	 valor	 informado,	 a	 mensagem	 deve	 ser	impressa	apenas	uma	vez.	O	programa	termina	ao	ser	informado	um	valor	negativo. */

#include <stdlib.h>
#include <conio.h>

int main() {
    int L, C, i, j, valor, flag;
    printf("Digite a quantidade de linhas da matriz (maximo 10):\n");
    scanf("%d", &L);
    printf("Digite a quantidade de colunas da matriz (maximo 10):\n");
    scanf("%d", &C);
    int matriz[L][C];
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            do {
                printf("Digite um valor para a matriz[%d][%d]:\n", i, j);
                scanf("%d", &matriz[i][j]);
            } while (matriz[i][j] < 0);
        }
    }
    do {
        flag = 0;
        printf("Digite um valor:\n");
        scanf("%d", &valor);
        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                if (valor == matriz[i][j]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (valor > 0) {
            if (flag == 1) {
                printf("Esta na matriz.\n");
            } else {
                printf("Nao esta na matriz.\n");
            }
        }
    } while (valor > 0);
}