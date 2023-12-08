#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dado;
    struct Node *prox;
} Node;

typedef struct ListaAdj
{
    Node *cabeca;
} ListaAdj;

typedef struct Grafo
{
    int vertices;
    struct ListaAdj *lista;
} Grafo;

Grafo *criarGrafo(int N)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->vertices = N;
    grafo->lista = (ListaAdj *)malloc(N * sizeof(ListaAdj));
    
    for (int i = 0; i < N; i++)
    {
        grafo->lista[i].cabeca = NULL;
    }
    
    return grafo;
}

void novoNoListaAdj(Grafo *grafo, int origem, int destino)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->dado = destino;
    novoNo->prox = NULL;

    // If the list is empty or the new node should be inserted before the head
    if (grafo->lista[origem].cabeca == NULL || grafo->lista[origem].cabeca->dado > destino)
    {
        novoNo->prox = grafo->lista[origem].cabeca;
        grafo->lista[origem].cabeca = novoNo;
    }
    else
    {
        // Find the node before the point of insertion
        Node *current = grafo->lista[origem].cabeca;
        while (current->prox != NULL && current->prox->dado < destino)
        {
            current = current->prox;
        }

        // Insert the new node
        novoNo->prox = current->prox;
        current->prox = novoNo;
    }
}

void adicionarAresta(Grafo *grafo, int origem, int destino)
{
    novoNoListaAdj(grafo, origem, destino);
}

void imprimirGrafo(Grafo *grafo, int V)
{
    Node *temp = grafo->lista[V].cabeca;
    while (temp != NULL)
    {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
}

int main()
{
    int V;
    scanf("%d", &V);

    int N, M, origem, destino;
    scanf("%d %d", &N, &M);

    Grafo *grafo = criarGrafo(N);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &origem, &destino);
        adicionarAresta(grafo, origem, destino);
    }

    imprimirGrafo(grafo, V);
    return 0;
}