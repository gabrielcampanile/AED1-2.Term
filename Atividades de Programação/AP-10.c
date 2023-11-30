#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nomes[1024][16]; //lista linear de nos do grafo
    int adj[1024][1024];
    int N; 
}TipoGrafoMatrizAdj;

void inicializaGrafo(TipoGrafoMatrizAdj *grafo){
    int i,j;

    for(i=0; i<grafo->N; i++)
        for(j=0; j<grafo->N; j++)
            grafo->adj[i][j]=0;
}

int buscaNo(TipoGrafoMatrizAdj *grafo, char *nome){
    int i;
    for(i=0; i<grafo->N; i++){
        if(strcmp(grafo->nomes[i], nome)==0)
            return i;
    }
    return -1;
}

int criarAresta(TipoGrafoMatrizAdj *grafo, char *no1, char *no2){
    int i1 = buscaNo(&grafo,no1);
    int i2 = buscaNo(&grafo,no2);
    if(i1<0 || i2<0) return -1;

    grafo->adj[i1][i2] = 1;
    grafo->adj[i2][i1] = 1; //grafo nao direcionado

    return 1;
}