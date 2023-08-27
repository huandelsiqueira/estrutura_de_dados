/*  Escreva	uma	função	chamada	maiorNumero que	receba	como	entrada	dois	inteiros	positivos	e	retorne	o	maior	deles	ou	o	valor	-1	se	eles	forem	iguais.	Considere	que	os	valores	de	entrada	são	sempre	positivos	(não	é	necessário	validar). Escreva	 um	 programa	 em	 C	 para	 ler	 um	 valor	 N.	 A	 seguir	 ler	 N duplas	 de	 inteiros	 (considere	 que	 serão	informado	apenas	valores	positivos).	Para	cada	dupla	informada	exibir	o	maior	elemento	ou	a	frase	“Eles	são	
iguais”.	Para	obter	o	maior	elemento	deve	ser	utilizada	a	função maiorNumero. */

#include <stdio.h>
#include <conio.h>

int maiorNumero(int v1, int v2);

int main() {
    int i, qtd, v1, v2;
    printf("Quantas duplas serao lidas?\n");
    scanf("%d", &qtd);
    for (i = 1; i <= qtd; i++) {
        printf("Digite o primeiro valor:\n");
        scanf("%d", &v1);
        printf("Digite o segundo valor:\n");
        scanf("%d", &v2);
        maiorNumero(v1, v2);
    }
}

int maiorNumero(int v1, int v2) {
    if (v1 > v2) {
        printf("%d\n", v1);
        return v1;
    } else if (v2 > v1) {
        printf("%d\n", v2);
        return v2;
    } else {
        printf("Eles sao iguais\n");
        return -1;
    }
}   