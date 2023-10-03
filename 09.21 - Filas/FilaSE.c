// Fila – Lista Sequencial Estática

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

// fim = (fim+1) % max
// inicio = (inicio+1) % max

typedef struct {
    int chave;
    char nome[51];
}TipoItem;

typedef struct {
    TipoItem vet[max];
    int inicio; //índice do primeiro elemento da fila
    int fim; //índice da posição seguinte ao último
    int tam; //tamanho do vetor (MAX)
    int qtd; //quantidade de elementos da fila
}TipoFilaSE;

void inicializaFileSE(TipoFilaSE *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->qtd = 0;
    fila->tam = max;
}

int filaVazia(TipoFilaSE *fila) {
    if(fila->qtd==0) return 1;
    return 0;
    // return(fila->inicio == fila->fim)
}

int filaCheia(TipoFilaSE *fila) {
    if(fila->qtd == fila->tam) return 1;
    return 0;
    // return((fila->fim+1) % fila->tam == fila->inicio)
}

int inserirFilaSE(TipoFilaSE *fila, TipoItem novo) {
    if(filaCheia(fila)) return 0;

    fila->vet[fila->fim] = novo;
    fila->fim = (fila->fim+1) % fila->tam;
    fila->qtd++;

    return 1;
}

TipoItem removerFilaSE(TipoFilaSE *fila) {
    TipoItem itemRemovido;

    if(filaVazia(fila)) {
        itemRemovido.chave = -1;
        return itemRemovido;
    }

    itemRemovido = fila->vet[fila->inicio];
    fila->inicio = (fila->inicio +1) % fila->tam;
    fila->qtd--;

    return itemRemovido;
}

void exibirFilaSE(TipoFilaSE *fila) {
    if(filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }
    
    printf("Elementos na fila:\n");
    for(int i= fila->inicio; i < fila->fim; i++)
        printf("%d - %s\n", fila->vet[i].chave, fila->vet[i].nome);
}

int main() {
    TipoFilaSE fila;
    TipoItem item;
    int i, N, op;

    scanf("%d", &N);
    inicializaFileSE(&fila);

    for(i=0; i<N; i++) {
        scanf("%d", &op);
        if(op==1) {
            scanf("%d %s", &item.chave, item.nome);
            inserirFilaSE(&fila, item);
        }
        else if(op==2) {
            item = removerFilaSE(&fila);
            if(item.chave < 0)
                exit(1);
        }
    }
    exibirFilaSE(&fila);

    return 0;
}
