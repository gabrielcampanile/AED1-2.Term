#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

typedef struct {
    int chave;
    char nome[50];
}TipoItem;

typedef struct {
    TipoItem vet[max];
    int inicio; //indice do primeiro elemento da fila
    int fim; //indice apos o ultimo elemento da fila
    int tamanho; // tamanho da fila
    int quantidade; // numero de elementos da fila
}TipoFilaSE;

void inicializaFila(TipoFilaSE *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
    fila->tamanho = max;
}

int filaVazia(TipoFilaSE *fila) {
    if(fila->quantidade == 0) return 1;
    return 0;
}

int filaCheia(TipoFilaSE *fila) {
    if(fila->quantidade == fila->tamanho) return 1;
    return 0;
}

int inserir(TipoFilaSE *fila, TipoItem novo) {
    if(filaCheia(fila)) return 0;

    fila->vet[fila->fim] = novo;
    fila->fim = fila->fim+1 % fila->tamanho;
    fila->quantidade++;

    return 1;
}

TipoItem remover(TipoFilaSE *fila) {
    TipoItem itemRemovido;

    if(filaVazia(fila)) {
        itemRemovido.chave = -1;
        return itemRemovido;
    }

    itemRemovido = fila->vet[fila->inicio];
    fila->inicio = fila->inicio+1 % fila->tamanho;
    fila->quantidade--;

    return itemRemovido; 
}

void exibir(TipoFilaSE *fila) {
    if(filaVazia(fila))
        printf("Fila vazia.\n");

    printf("\nElementos da fila:\n");
    for(int i=fila->inicio; i<fila->fim; i++) {
        printf("%d %s\n", fila->vet[i].chave, fila->vet[i].nome);
    }
}

int main() {
    int i, n, op;
    TipoItem item;
    TipoFilaSE fila;

    inicializaFila(&fila);

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &op);
        if(op==1) {
            scanf("%d %s", &item.chave, item.nome);
            inserir(&fila, item);
        }
        else if(op==2) {
            remover(&fila);
        }
    }
    exibir(&fila);

    return 0;
}