/* Escreva	um	programa	em	C	para	ler	um	valor	Q	que	representa	a	quantidade de	alunos	de	uma	turma.	A	seguir	 ler	 Q	 pares	 de	 dados	 contendo,	 cada	 um, a	 altura	 e	 um	 código	 para	 masculino	 (1)	 e	 outro	 para feminino	(2)	de	cada	aluno.	Calcular	e	escrever: 

-A	altura	do	aluno mais	alto	da	turma.
-A	média	de	altura	das	alunas. */

#include <stdio.h>
#include <conio.h>

int main() {
    int i, sexo, qtd, qtdfem= 0;
    float media, altura, soma = 0, maioralt = 0;
    printf("Digite a quantidade de alunos na turma:\n");
    scanf("%d", &qtd);
    for (i = 1; i <= qtd; i++) {
        printf("Digite o sexo do aluno: (1).Masculino ou (2).Feminino\n");
        scanf("%d", &sexo);
        printf("Digite a altura do aluno (em metros):\n");
        scanf("%f", &altura);
        if (sexo == 1 && altura > maioralt) {
            maioralt = altura;
        }
        if (sexo == 2) {
            soma = soma + altura;
            qtdfem = qtdfem + 1;
        }
    }
    media = soma / qtdfem;
    printf("A altura do aluno mais alto eh: %.2f\n", maioralt);
    printf("A media de altura das alunas eh: %.2f\n", media);
}

