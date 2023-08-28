#include <stdio.h>
#include <conio.h>

typedef struct {
    int nrConta;
    float saldoConta;
} CONTA;

void criaConta(int nr_conta, CONTA *pconta);

void retiraDaConta(float saque, CONTA *pconta);

void depositaNaConta(float deposito, CONTA *pconta);

float obtemSaldo(CONTA conta);

int main() {

    CONTA conta_corr, conta_poup;
    int op;
    float deposito, saque, emprestimo, saquepoupemprestimo;

    printf("Bem vindo, sr. Silva!\n\n");

    printf("Crie sua CONTA CORRENTE adicionando um numero para ela:\n");
    scanf("%d", &conta_corr.nrConta);

    criaConta(conta_corr.nrConta, &conta_corr);

    printf("Adicione o saldo inicial para sua CONTA CORRENTE:\n");
    scanf("%f", &conta_corr.saldoConta);

    printf("Crie sua CONTA POUPANCA adicionando um numero para ela:\n");
    scanf("%d", &conta_poup.nrConta);

    criaConta(conta_poup.nrConta, &conta_poup);

    printf("Adicione o saldo inicial para sua CONTA POUPANCA:\n");
    scanf("%f", &conta_poup.saldoConta);
    
    do {

        printf("\nEscolha a opcao desejada:\n(1).Deposito conta corrente.\n(2).Deposito conta poupanca.\n(3).Retirada conta corrente.\n(4).Retirada conta poupanca.\n(5).Fim\n");
        scanf("%d", &op);

        if (op != 5) {

            if (op == 1) {
                printf("Deposito na CONTA CORRENTE:\n");
                printf("Digite a quantidade do deposito:\n");
                scanf("%f", &deposito);
                depositaNaConta(deposito, &conta_corr);
            }

            if (op == 2) {
                printf("Deposito na CONTA POUPANCA:\n");
                printf("Digite a quantidade do deposito:\n");
                scanf("%f", &deposito);
                depositaNaConta(deposito, &conta_poup);
            }

            if (op == 3) {
                printf("Retirada na CONTA CORRENTE:\n");
                printf("Digite a quantidade do saque:\n");
                scanf("%f", &saque);
                
                if (conta_corr.saldoConta < saque) {
                    if (conta_poup.saldoConta >= (conta_corr.saldoConta - saque)) {
                        saquepoupemprestimo = saque - conta_corr.saldoConta;
                        retiraDaConta(saquepoupemprestimo, &conta_poup);
                        conta_corr.saldoConta = 0;
                        //conta_corr.saldoConta = conta_corr.saldoConta + saquepoupemprestimo;
                    } else {
                        printf("\n==SALDO INSUFICIENTE!!!==\n");
                    }
                } else {
                    retiraDaConta(saque, &conta_corr);
                }
            }

            if (op == 4) {
                printf("Retirada na CONTA POUPANCA:\n");
                printf("Digite a quantidade do saque:\n");
                scanf("%f", &saque);
                retiraDaConta(saque, &conta_poup);
            }

            printf("\n==========================================\n");
            printf("SALDO ATUALIZADO:\n\n");
            printf("Saldo da conta corrente = R$ %.2f\n", conta_corr.saldoConta);
            printf("Saldo da conta poupanca = R$ %.2f\n", conta_poup.saldoConta);
            printf("==========================================\n\n");
        }   

    } while (op != 5);

    printf("\n===Programa encerrado!===\n");

}

void criaConta(int nr_conta, CONTA *pconta) {

    pconta->nrConta = nr_conta;
    pconta->saldoConta = 0;

} 

float obtemSaldo(CONTA conta) {

    return conta.saldoConta;

}

void depositaNaConta(float deposito, CONTA *pconta){

    pconta->saldoConta = pconta->saldoConta + deposito;

} 

void retiraDaConta(float saque, CONTA *pconta) {
    
    if (pconta->saldoConta >= saque) {
        pconta->saldoConta = pconta->saldoConta - saque;
    } else {
        printf("\n==SALDO INSUFICIENTE!!!==\n");
    }
} 