#include <stdio.h>

struct Aluno
{
    char nome[50];
    char dataNascimento[15];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct Aluno aluno)
{
    return (aluno.nota1 + aluno.nota2) / 2.0;
}

void verificarAprovacao(struct Aluno aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("%s está APROVADO!\n", aluno.nome);
    }
    else
    {
        printf("%s está REPROVADO.\n", aluno.nome);
    }
}

int main()
{
    int i;
    struct Aluno alunos[5];

    for (i = 0; i < 5; i++)
    {
        printf("Informe os dados do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Data de Nascimento: ");
        scanf("%s", alunos[i].dataNascimento);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcularMedia(alunos[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf("\nMédia do aluno %s: %.2f\n", alunos[i].nome, alunos[i].media);
        verificarAprovacao(alunos[i]);
    }

    return 0;
}