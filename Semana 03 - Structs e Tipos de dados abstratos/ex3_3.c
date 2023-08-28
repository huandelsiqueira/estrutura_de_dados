#include <stdio.h>
#include <conio.h>

typedef struct {
    int nrConta;
    float saldoConta;
} Conta;

void criaConta(int nr_conta, Conta *conta);

void retiraDaConta(Conta *conta, float saque);

void depositaNaConta(Conta *conta, float deposito);

float obtemSaldo(Conta conta);

int main() {
    
    Conta conta_cor, conta_poup;
    int op;
    float deposito;

    do {

        printf("Digite o numero da conta corrente:\n");
        scanf("%d", &conta_cor.nrConta);
        printf("Digite o saldo da conta corrente:\n");
        scanf("%f", &conta_cor.saldoConta);

        depositaNaConta(&conta_cor.nrConta, deposito);

        criaConta(conta_cor.nrConta, &conta_cor);
        
        printf("Digite o numero da conta poupanca:\n");
        scanf("%d", &conta_poup.nrConta);
        printf("Digite o saldo da conta poupanca:\n");
        scanf("%f", &conta_poup.saldoConta);

        criaConta(conta_poup.nrConta, &conta_poup);

        printf("Escolha a opcao desejada:\n(1).Deposito conta corrente.\n(2).Deposito conta poupanca.\n(3).Retirada conta corrente.\n(4).Retirada conta poupanca.\n(5).Fim\n");
        scanf("%d", &op);
        
        if (op == 1) {
            printf("Digite o valor do deposito:\n");
            scanf("%f", &deposito);
            depositaNaConta(&conta_cor.nrConta, deposito);
        }
        
        printf("%.2f", conta_cor.saldoConta);

    } while (op != 5);

}

void criaConta(int nr_conta, Conta *conta) {

    conta->nrConta = nr_conta;
    conta->saldoConta = 0;

}

/*
void criaConta(Conta nr_conta, Conta *conta) {

    *conta->nrConta = nr_conta;
    *conta->saldoConta = 0;

} */
/*
void retiraDaConta(Conta *conta, float saque) {

    *conta = *conta->saldoConta - saque;

} */

void depositaNaConta(Conta *conta, float deposito){

    conta->saldoConta = conta->saldoConta + deposito;

} 
/*
float obtemSaldo(Conta conta) {

    return conta.saldoConta;

} */