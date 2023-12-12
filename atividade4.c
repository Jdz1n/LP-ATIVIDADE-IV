#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ContaBancaria
{
    int numeroConta;
    char nomeTitular[333];
    float saldo;
    char tipoConta[333];
};
void limpatela()
{
    system("CLS");
    fflush(stdin);
}

void depositar(struct ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Depósito realizado com sucesso!\n");
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    }
    else
    {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
}

void imprimirSaldo(struct ContaBancaria conta)
{
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
}

int main()
{
    struct ContaBancaria minhaConta = {123, "Jadson Dias", 1000.0, "corrente"};

    int opcao;
    float valor;

    do
    {
        printf("| codigo |    Ação            |\n");
        printf("|    1   |    Depositar       |\n");
        printf("|    2   |    Sacar           |\n");
        printf("|    3   |    Consultar Saldo |\n");
        printf("|    4   |    Sair            |\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        limpatela();

        switch (opcao)
        {
        case 1:
            printf("Digite o valor para depósito: ");
            scanf("%f", &valor);
            depositar(&minhaConta, valor);
            break;
        case 2:
            printf("Digite o valor para saque: ");
            scanf("%f", &valor);
            sacar(&minhaConta, valor);
            break;
        case 3:
            imprimirSaldo(minhaConta);
            break;
        case 4:
            printf("Conta fechada! até logo.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente...\n");
        }
    } while (opcao != 4);
}