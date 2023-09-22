#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matriz, i, j;
    
    matriz = (int**)malloc(5*sizeof(int*));
    for(i=0; i<5; i++)
        matriz[i] = (int*)malloc(5*sizeof(int));

    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            matriz[i][j] = i*j;

    //desalocando matriz
    for(i=0; i<5; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}