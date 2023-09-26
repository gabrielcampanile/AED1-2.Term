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

int inserirFilaSE(TipoFilaSE *fila, TipoItem novo) {}

TipoItem removerFilaSE(TipoFilaSE *fila) {}

int main() {
    TipoFilaSE fila;
    TipoItem item;
    int i, N, v, op;

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
    return 0;
}
