//Definir um tipo chamado Aluno para armazenar os seguintes dados de um aluno: número de matrícula e data de nascimento (tipo Data). Escrever um programa em C para ler a data de hoje armazenando-a em uma variável do tipo Data. A seguir ler uma quantidade indeterminada de dados de alunos (Aluno). Para cada aluno lido escrever se ele ja completou 18 anos até a data informada. O programa termina ao ser informado um valor negativo para a matrícula. Nesta situação a data de nascimento não deve ser lida.

#include <stdio.h>
#include <conio.h>

struct Data {
    int dia,
        mes,
        ano;
};

struct Aluno {
    int matricula;
    struct Data dtNasc;
};

int main() {

    struct Aluno aluno;

    struct Data dtHoje;

    printf("Digite a data de hoje:\n");
    scanf("%d %d %d", &dtHoje.dia, &dtHoje.mes, &dtHoje.ano);

    do {
        
        printf("Digite a matricula do aluno:\n");
        scanf("%d", &aluno.matricula);

        if (aluno.matricula >= 0) {
            printf("Digite a data de nascimento do aluno:\n");
            scanf("%d %d %d", &aluno.dtNasc.dia, &aluno.dtNasc.mes, &aluno.dtNasc.ano);

            if (aluno.dtNasc.ano <= (dtHoje.ano - 18)) {
            printf("Aluno maior de 18 anos.\n");
        }

        }

    } while (aluno.matricula >= 0);
}

