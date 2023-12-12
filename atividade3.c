#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Produto
{
    char nome[333];
    int quantidade;
    float preco;
};
void limpatela()
{
    fflush(stdin);
    system("CLS");
}

float calcularValorTotal(struct Produto produto)
{
    return produto.preco * produto.quantidade;
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidade)
    {
        produto->quantidade -= quantidadeCompra;
        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Quantidade inválida. Compra não realizada.\n");
    }
}

void consultarEstoque(struct Produto produto)
{
    printf("Nome: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Valor total em estoque: R$ %.2f\n", calcularValorTotal(produto));
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    struct Produto meuProduto = {"Produto Café", 8.99, 50};

    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpatela();
        switch (opcao)
        {
        case 1:
            realizarCompra(&meuProduto);
            break;
        case 2:
            consultarEstoque(meuProduto);
            break;
        case 3:
            printf("Saindo do programa. Volte sempre!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);
}