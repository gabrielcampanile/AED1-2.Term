#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[50];
    int matricula;
};

int main()
{
    struct Aluno umAluno;

    strcpy(umAluno.nome, "jose");
    umAluno.matricula = 1234;

    printf("%s - %d\n", umAluno.nome, umAluno.matricula);

    struct Aluno *ptr;
    ptr = &umAluno; // ptr aponta para umAluno

    ptr->matricula = 5678; // atualiza matricula de umALuno

    printf("%s - %d\n", umAluno.nome, umAluno.matricula);

    return 0;
}