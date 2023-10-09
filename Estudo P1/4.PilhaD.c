#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem {
    int chave;
    char nome[50];
    struct TipoItem *prox;
}TipoItem;

typedef struct {
    TipoItem *topo;
}TipoPilhaP;

void inicializaPilha(TipoPilhaP *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(TipoPilhaP *pilha) {
    if(pilha->topo == NULL)
        return 1;
    return 0;
}

void push(TipoPilhaP *pilha, TipoItem novoItem) {
    TipoItem *aux = malloc(sizeof(TipoItem));
    *aux = novoItem;
    aux->prox = pilha->topo;
    pilha->topo = aux;
}

TipoItem pop(TipoPilhaP *pilha) {
    TipoItem aux;
    aux.chave = pilha->topo->chave;
    strcpy(aux.nome, pilha->topo->nome);

    TipoItem *apagar = malloc(sizeof(TipoItem));
    apagar = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(apagar);
    return aux;
}

int main() {
    int i, n;
    TipoItem item;
    TipoPilhaP pilha;

    inicializaPilha(&pilha);

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d %s", &item.chave, item.nome);
        push(&pilha, item);
    }

    while(!pilhaVazia(&pilha)) {
        item = pop(&pilha);
        printf("Desempilhou: %d %s\n", item.chave, item.nome);
    }

    return 0;
}