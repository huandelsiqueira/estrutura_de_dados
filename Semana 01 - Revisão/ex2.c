/*  Escreva	as	seguintes	funções	em	C:
Nome:	exibeOnzeTracos
Descrição:	Exibe	na	tela	uma	linha	com	11	hifens (“-”).	Utilizar	uma	repetição.
Nome:	retanguloTracos
Descrição:	Exibe	na	tela	um	retângulo	com	4	linhas	(usar	repetição)	de	11	hifens.	
Cada	linha	com	11	hifens deve	ser	impressa	com	a	chamada	da	função	exibeOnzeTracos descrita	anteriormente. Escreva	 um	 programa	 em	 C	 para	 exibir	 na	 tela	 2	 retângulos	 com	 uma linha	 em	 branco	 entre	 eles. Cada	retângulo	deve	ser	mostrado	a	partir	de	uma	chamada	a	função	retanguloTracos */

#include <stdio.h>
#include <conio.h>

void exibeOnzeTracos(void);
void retanguloTracos(void);

int main() {
    int i;
    for (i = 1; i <= 2; i++) {
        retanguloTracos();
        printf("\n");
    }
}

void exibeOnzeTracos() {
    int i;
    for (i = 1; i <= 11; i++) {
        printf("-");
    }
}

void retanguloTracos(void) {
    int i;
    for (i = 1; i <= 4; i++) {
        exibeOnzeTracos();
        printf("\n");
    }
}

