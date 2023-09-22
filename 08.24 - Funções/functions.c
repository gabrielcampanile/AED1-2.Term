#include <stdio.h>
#include <stdlib.h>

int main(){
    char *nome;
    nome = malloc(100); //aloca 100 bytes => string de 100 caracteres
    //ou nome = calloc(100, sizeof(char));

    free(nome);

    int *vetor, i;
    vetor = malloc(20*sizeof(int)); //aloca espaço para vetor de 20 inteiros

    vetor[0] = 0;
    for(i=1; i<20; i++)
    vetor[i] = vetor[i-1];

    free(vetor);

    return 0;
}