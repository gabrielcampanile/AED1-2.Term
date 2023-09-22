#include <stdio.h>

struct Aluno{
    char nome[50];
    int matricula;
};

int main(){
    struct Aluno alunos[2], *ptr;
    
    strcpy(alunos[0].nome, "jose");
    alunos[0].matricula = 1234;
    strcpy(alunos[1].nome, "maria");
    alunos[1].matricula = 2222;

    for(int i=0; i<2; i++)
        printf("%s - %d\n", alunos[i].nome, alunos[i].matricula);


    ptr = alunos; //ptr aponta para vetor alunos
    ptr[1].matricula = 3333; //atualiza matricula de maria

    for(int i=0; i<2; i++)
        printf("%s - %d\n", alunos[i].nome, alunos[i].matricula);


    ptr = &alunos[1]; //ptr aponta para alunos[1]
    ptr->matricula = 4444; //atualiza matricula de maria

    for(int i=0; i<2; i++)
        printf("%s - %d\n", alunos[i].nome, alunos[i].matricula);

    return 0;
}