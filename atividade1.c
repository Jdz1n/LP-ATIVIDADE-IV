#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 3

struct agenda
{
    char nome[333];
    char numero[333];
    char gmail[333];
};

char encontrarContato(struct agenda tlg[], char *opcao)
{
    int a;

    for (a = 0; a < TAM; a++)
    {
        if (strcmp(tlg[a].nome, opcao) == 0)
        {
            return printf("\nTelefone de %s:  %s ", tlg[a].nome, tlg[a].numero);
            break;
        }
    }

    return printf("Contato não encontrado...");
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    struct agenda tlg[TAM];
    int a;
    char opcao[333];

    for (a = 0; a < TAM; a++)
    {
        printf("Informe  o nome do %d° contato: ", a + 1);
        gets(tlg[a].nome);

        printf("Informe o numero de %s: ", tlg[a].nome);
        gets(tlg[a].numero);
        fflush(stdin);
        printf("Informe o gmail de %s: ", tlg[a].nome);
        gets(tlg[a].gmail);
    }
    fflush(stdin);
    system("CLS");

    printf("Digite o nome do cntt que deseja procurar: ");
    gets(opcao);
    system("CLS");

    encontrarContato(tlg, opcao);
}
