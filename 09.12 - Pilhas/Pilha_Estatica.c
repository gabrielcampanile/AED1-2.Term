#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 10

typedef struct {
    int ra;
    char nome[50];
    //outros campos de item
}TipoItem;

typedef struct {
    TipoItem itens[max];
    int tam;
    int topo;
}TipoPilha;

void inicializarPilha(TipoPilha *pilha) {
    pilha->topo = -1; //pilha vazia
    pilha->tam = max;
}

int pilhaVazia(TipoPilha *pilha) {
    if(pilha->topo == -1)
        return 1;
    return 0;
}

int pilhaCheia(TipoPilha *pilha) {
    if(pilha->topo == pilha->tam-1)
        return 1;
    return 0;
}

int push(TipoPilha *pilha, TipoItem novo) {
    int x, p;
    x = pilhaCheia(pilha);
    if(x==1)
        return 0;
    else {
        pilha->topo++;
        p = pilha->topo;
        pilha->itens[p].ra = novo.ra;
        strcpy(pilha->itens[p].nome, novo.nome);
        return 1;
    }
}

TipoItem pop(TipoPilha *pilha) {
    TipoItem item;
    int x, p;
    x = pilhaVazia(pilha);
    if(x==0){
        p = pilha->topo;
        item.ra = pilha->itens[p].ra;
        strcpy(item.nome, pilha->itens[p].nome);
        pilha->topo--;
        return item;
    }
    else{
        item.ra = -1;
        return item;
    }
}

int main() {
    TipoPilha pilha;
    TipoItem item;
    int i, N;
    inicializarPilha(&pilha);
    scanf("%d", &N);
    //inserindo N itens na pilha
    for(i=0; i<N; i++) {
        scanf("%d %s", &item.ra, item.nome);
        if(!push(&pilha, item)) {
            printf("Pilha cheia.\n");
            break;
        }
    }
    //desempilhando
    while(!pilhaVazia(&pilha)) {
        item = pop(&pilha);
        printf("Desempilha %d %s\n", item.ra, item.nome);
    }
    return 0;
}