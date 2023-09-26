// Fila - Lista Circular Encadeada Dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem {
    int chave;
    struct TipoItem *prox;
    // outros componentes
}TipoItem;

typedef struct {
    TipoItem *ultimo;
    int tamanho;
}TipoListaCircular;

void inicializaLista(TipoListaCircular *lista) {
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void imprimeLista(TipoListaCircular *lista) {
    TipoItem *p = lista->ultimo;
    if(p != NULL) { //se lista não for vazia
        do {
            p=p->prox;
            printf("%d\n", p->chave);
        } while(p!=lista->ultimo);
    }
}

void insereNoFinal(TipoListaCircular *lista, TipoItem novoItem) {
    TipoItem *novoNo;

    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;

    if(lista->ultimo == NULL) { //lista vazia
        novoNo->prox = novoNo; //novo nó será único
        lista->ultimo = novoNo;
    }
    else {
        novoNo->prox = lista->ultimo->prox; //aponta para o início
        lista->ultimo->prox = novoNo;
        lista->ultimo = novoNo;
    }
    lista->tamanho++;
}

int removerListaCircular(TipoListaCircular *lista, int chave) {}