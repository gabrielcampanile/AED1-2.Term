// Fila - Lista Encadeada Dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem{
    int chave;
    char nome[51];
    struct TipoItem *prox;
}TipoItem;

typedef struct {
    TipoItem *inicio, *fim;
}TipoFilaD;

void inicializaLista(TipoFilaD *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(TipoFilaD *fila) {
    if(fila->inicio == NULL) return 1;
    return 0;
}

void inserir(TipoFilaD *fila, TipoItem novoItem) {
    TipoItem *novoNo;
    
    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;

    if(fila->fim == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

void remover(TipoFilaD *fila) {
    TipoItem *auxiliar;

    if(!filaVazia) {
        auxiliar = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(auxiliar);
    }
    else if(fila->inicio == fila->fim) {
        fila->fim = NULL;
    }
}

void destroy(TipoItem *fila) {
    if(fila->prox != NULL) {
        destroy(fila->prox);
    }
    free(fila);
}

int main() {

}