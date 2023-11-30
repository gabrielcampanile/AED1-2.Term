#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nomes[100][16]; //lista linear de nos do grafo
    int adj[100][100];
    int N, qtd; 
}TipoGrafoMatrizAdj;

void inicializaGrafo(TipoGrafoMatrizAdj *grafo){
    int i,j;

    for(i=0; i<grafo->N; i++) {
        for(j=0; j<grafo->N; j++) {
            grafo->adj[i][j]=0;
            grafo->adj[i][i]=1;
        }
    }
}

int buscaNo(TipoGrafoMatrizAdj *grafo, char *nome){
    int i;
    for(i=0; i<grafo->N; i++){
        if(strcmp(grafo->nomes[i], nome)==0)
            return i;
    }
    return -1;
}

int novoNome(TipoGrafoMatrizAdj *grafo, char *no) {
    int x = grafo->qtd;
    
    strcpy(grafo->nomes[x], no);
    grafo->qtd++;
    
    return grafo->qtd - 1;
}

int criarAresta(TipoGrafoMatrizAdj *grafo, char *no1, char *no2){
    int i1 = buscaNo(grafo,no1);
    if(i1<0)
        i1 = novoNome(grafo, no1);
    int i2 = buscaNo(grafo,no2);
    if(i2<0)
        i2 = novoNome(grafo, no2);

    grafo->adj[i1][i2] = 1;
    grafo->adj[i2][i1] = 1; //grafo nao direcionado

    return 1;
}

void amigos2grau(TipoGrafoMatrizAdj *grafo, char *nome) {
    int i, j, k, x = buscaNo(grafo, nome), y;
    int amigos2 = 0;
    int amigoRep[100];

    for (i = 0; i < grafo->N; i++) {
        if (grafo->adj[x][i] == 1) { // Se "nome" é amigo de primeiro grau de "grafo->nomes[i]"
            // printf("1º %s\n", grafo->nomes[i]);
            for (j = 0; j < grafo->N; j++) {
                if (grafo->adj[i][j] == 1 && grafo->adj[x][j] != 1) { // Se "grafo->nomes[i]" é amigo de primeiro grau de "grafo->nomes[j]" e "nome" não é amigo de primeiro grau de "grafo->nomes[j]"
                    y = buscaNo(grafo, grafo->nomes[j]);
                    for(k=0; k< amigos2; k++) {
                        if(amigoRep[k] == y)
                            break;
                    }
                    if(k == amigos2) {
                        amigoRep[amigos2] = y;
                        amigos2++;
                    }
                }
            }
        }
    }

    printf("%d\n", amigos2);
}


int main() {
    TipoGrafoMatrizAdj matriz;
    
    char nome0[16], nome1[16], nome2[16];
    scanf("%s", nome0);

    int N, M, i, j;
    while(N<1 || N>1024) {
        scanf("%d", &N);
    }    
    while(M<1 || M>1024) {
        scanf("%d", &M);
    }

    matriz.N = N;

    inicializaGrafo(&matriz);

    for(i=0; i<M; i++) {
        scanf("%s %s", nome1, nome2);
        criarAresta(&matriz, nome1, nome2);
    }
    /*
    printf("X ");
    
    for(i=0; i<N; i++)
        printf("%s ", matriz.nomes[i]);
        
    printf("\n");
    
    for(i=0; i<N; i++) {
        printf("%s ", matriz.nomes[i]);
        for(j=0; j<N; j++) {
            printf("%d   ", matriz.adj[i][j]);
        }
        printf("\n");
    }
    */ 
    amigos2grau(&matriz, nome0);

    return 0;
}