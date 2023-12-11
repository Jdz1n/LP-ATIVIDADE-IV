#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define TAM cont

struct produto
{
    char nome[333];
    float preco;
    float quantEstoque;
};

void limpaTela()
{
    system("CLS || CLEAR");
    fflush(stdin);
};
void cabecalho()
{
    printf("|           opção         |\n");
    printf("|   1 - Realizar compra   |\n");
    printf("|   2 - Consultar estoque |\n");
    printf("|   3 - Sair do programa  |\n\n\n");
};

float calculo(struct produto tlg[])
{
    return tlg.preco + tlg.preco;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    struct produto tlg[cont];
    int opcao;
    do
    {
        cabecalho();
        printf("Informe a opção desejada: ");
        scanf("%d", &opcao);

        limpaTela();
        switch (opcao)
        {
        case 1:
            printf("Informe o nome do produto: ");
            gets(tlg.nome);

            limpaTela();

            printf("Informe o preço da %s: ", tlg.nome);
            scanf("%f", &tlg.preco);
            cont++;
            tlg.quantEstoque++;
            limpaTela();
            break;
        case 2:

            printf("Valor total do estoque: %.2f\n", calculo);

            break;

        case 3:

            printf("Saindo do programa, até logo.");
            break;
        default:
            printf("Codigo invalido\n\n");
        }
    } while (opcao != 3);
}
