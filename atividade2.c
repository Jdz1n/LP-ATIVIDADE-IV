#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

struct dadosAluno
{
    char nome[333];
    char dataNascimento[10];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct dadosAluno aluno)
{
    return (aluno.nota1 + aluno.nota2) / 2.0;
};

void situacaoAluno(struct dadosAluno aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("situação aprovado!\n");
    }
    else
    {
        printf("situação reporovado.\n");
    }
}

void limpatela()
{
    fflush(stdin);
    system ("CLS");
}

void main()
{
    int a;
    struct dadosAluno alunos[TAM];

    for (a = 0;a  < TAM; a++)
    {
        printf("Informe o nome do %d° aluno:\n", a + 1);
        scanf("%s", alunos[a].nome);
        printf("Data de Nascimento de %s: ", alunos[a].nome);
        scanf("%s", alunos[a].dataNascimento);
        printf("Nota 1 de %s: ", alunos[a].nome);
        scanf("%f", &alunos[a].nota1);
        printf("Nota 2 de %s: ",alunos[a].nome);
        scanf("%f", &alunos[a].nota2);

        alunos[a].media = calcularMedia(alunos[a]);
    }
limpatela();
    for (a = 0; a < 5; a++)
    {
        printf("\nMédia do aluno %s: %.2f\n\n", alunos[a].nome, alunos[a].media);
        situacaoAluno(alunos[a]);
    }
}