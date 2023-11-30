#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoNo{
int v; //Núm. do vért. destino da aresta
struct TipoNo *prox; //Ponteiro para próx vért. adj.
// ... outros atributos de vértices
}TipoNo;

typedef struct graph{
int V,E; //V=Número de vértices, E=Número de arestas
TipoNo **adj;
}TipoGrafo;

int main() {
    
}