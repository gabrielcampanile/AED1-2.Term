// lista linear encadeada dinâmica
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem{
    int chave;
    char nome[50];
    struct TipoItem *prox;
    //outros componentes
}TipoItem;

typedef struct {
    TipoItem *topo;
}TipoPilhaD;

//inicialização
void inicializaPilha(TipoPilhaD *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(TipoPilhaD *pilha) {
    if(pilha->topo == NULL)
        return 1;
    return 0;
}

void push(TipoPilhaD *pilha, TipoItem novo) {
    // 1) novo: alocar memória para 1 item
    TipoItem *aux = malloc(sizeof(TipoItem));
    // 2) copiar informação do item em novo
    aux->chave = novo.chave;
    strcpy(aux->nome, novo.nome);
    // 3) novo->prox recebe o endereço apontado pelo topo
    aux->prox = pilha->topo;
    // 4) atualizar topo: topo da pilha deve apontar para o novo item
    pilha->topo = aux;
}

TipoItem pop(TipoPilhaD *pilha) {
    // 1) guardar endereço do topo (auxiliar)
    TipoItem aux;
    aux.chave = pilha->topo->chave;
    strcpy(aux.nome, pilha->topo->nome);
    TipoItem *apagar;
    apagar = pilha->topo;
    pilha->topo = pilha->topo->prox; // 2) atualização: topo recebe topo->prox
    free(apagar); // 3) liberar memória do item removido (free)
    return aux;
}

void imprimePilha(TipoPilhaD *pilha) {
    TipoItem *p = pilha->topo;
    while(p!=NULL) { //while(p)
        printf("%d %s\n", p->chave, p->nome);
        p = p->prox;
    }
}

int main() {
    TipoPilhaD pilha;
    TipoItem item;
    int i, N;
    scanf("%d", &N);
    inicializaPilha(&pilha);
    //inserindo N itens na pilha
    for(i=0; i<N; i++) {
        scanf("%d %s", &item.chave, item.nome);
        push(&pilha, item);
    }
    imprimePilha(&pilha);
    //desempilhando
    while(!pilhaVazia(&pilha)) {
        item = pop(&pilha);
        printf("Desempilhou: %d %s\n", item.chave, item.nome);
    }
    return 0;
}