#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct Funcionario
{
    char nome[333];
    char cargo[333];
    float salario;
};
void limpatela()
{
    system("CLS");
}

float calcularMediaSalarial(struct Funcionario *funcionarios, int numFuncionarios, char *cargo)
{
    int a;
    float somaSalarios = 0;
    int cont = 0;

    for (a = 0; a < numFuncionarios; a++)
    {
        if (strcmp(funcionarios[a].cargo, cargo) == 0)
        {
            somaSalarios += funcionarios[a].salario;
            cont++;
        }
    }

    if (cont > 0)
    {
        return somaSalarios / cont;
    }
    else
    {
        return 0.0;
    }
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    int numFuncionarios;
    int a;
    printf("Informe o número de funcionários da empresa: ");
    scanf("%d", &numFuncionarios);

    struct Funcionario *funcionarios = (struct Funcionario *)malloc(numFuncionarios * sizeof(struct Funcionario));

    for (a = 0; a < numFuncionarios; a++)
    {
        printf("Informe o nome do funcionário %d: ", a + 1);
        scanf("%s", funcionarios[a].nome);

        printf("Informe o cargo de %s: ", funcionarios[a].nome);
        scanf("%s", funcionarios[a].cargo);

        printf("Informe o salário de %s: ", funcionarios[a].nome);
        scanf("%f", &funcionarios[a].salario);
    }

    const char *cargoDesejado = "Programador";
    float mediaSalarial = calcularMediaSalarial(funcionarios, numFuncionarios, cargoDesejado);

limpatela();

    printf("\nA média salarial dos programadores é: %.2f\n", mediaSalarial);
}