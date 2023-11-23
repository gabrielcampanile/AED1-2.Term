#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct{
char nome[30]; //informacao do no
int index; //indice do No no grafo
}TipoItem;

typedef struct{
TipoItem l[N]; //lista sequencial de nos
int qtd;
}TipoLista;

typedef struct{
TipoLista lista; //lista linear de nos do grafo
int adj[N][N]; //matriz de adjacencia N x N
}TipoGrafoMatrizAdj;

int inserirNo(TipoLista *lista, char *nome){
if(lista->qtd==N) return -1;
strcpy(lista->l[lista->qtd].nome, nome);
lista->l[lista->qtd].index = lista->qtd;
lista->qtd++;
return 1;
}

int buscaNo(TipoLista *lista, char *nome){
int i;
for(i=0; i<lista->qtd; i++){
if(strcmp(lista->l[i].nome, nome)==0)
return lista->l[i].index;
}
return -1;
}

int criarAresta(TipoGrafoMatrizAdj *grafo, char *no1, char *no2){
int i1 = buscaNo(&grafo->lista,no1);
int i2 = buscaNo(&grafo->lista,no2);
if(i1<0 || i2<0) return -1;

grafo->adj[i1][i2] = 1;
grafo->adj[i2][i1] = 1; //grafo nao direcionado

return 1;
}

void inicializaGrafo(TipoGrafoMatrizAdj *grafo){
int i,j;
grafo->lista.qtd=0;
for(i=0; i<N; i++)
for(j=0; j<N; j++)
grafo->adj[i][j]=0;
}

int main()
{
int i,j;
TipoGrafoMatrizAdj grafo;
inicializaGrafo(&grafo);
inserirNo(&grafo.lista,"Joao");
inserirNo(&grafo.lista,"Maria");
inserirNo(&grafo.lista,"Ana");
inserirNo(&grafo.lista,"Luis");
inserirNo(&grafo.lista,"Paula");
inserirNo(&grafo.lista,"Roberto");
criarAresta(&grafo,"Joao","Maria"); //Joao e Maria sao amigos
criarAresta(&grafo,"Maria","Ana");
criarAresta(&grafo,"Paula","Luis");
//imprime lista de relacoes do grafo
for(i=0; i<grafo.lista.qtd; i++){
printf("%s: ",grafo.lista.l[i].nome);
for(j=0; j<grafo.lista.qtd; j++){
if(grafo.adj[i][j]) printf(" %s",grafo.lista.l[j].nome);
}
printf("¥n");
}
return 0;
}