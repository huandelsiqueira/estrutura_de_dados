// Definir um tipo chamado Horario para armazenar um horario composto de: hora, minuto, segundo. Escreva um programa em C para ler dois hora rios. Escreva o menor hora rio no formato HH:MM:SS. No caso deigualdade escrever a mensagem "Hora rios iguais". 

#include <stdio.h>
#include <conio.h>

struct Horario {
    int hora,
        minuto,
        segundos;
};

int main() {
    
    struct Horario hr1, hr2;

    printf("Digite o primeiro horario (no formato HH:MM:SS):\n");
    scanf("%d %d %d", &hr1.hora, &hr1.minuto, &hr1.segundos);
    printf("Digite o segundo horario (no formato HH:MM:SS):\n");
    scanf("%d %d %d", &hr2.hora, &hr2.minuto, &hr2.segundos);

    if (hr1.hora > hr2.hora || hr1.minuto > hr2.minuto || hr1.segundos > hr2.segundos) {
        printf("O menor horario eh: %d:%d:%d\n", hr2.hora, hr2.minuto, hr2.segundos);
    } else if (hr1.hora < hr2.hora || hr1.minuto < hr2.minuto || hr1.segundos < hr2.segundos) {
        printf("O menor horario eh: %d:%d:%d\n", hr1.hora, hr1.minuto, hr1.segundos);
    } else {
        printf("Horarios iguais");
    }
    
}
