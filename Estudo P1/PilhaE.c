#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct
{
    int chave;
    char nome[50];
} TipoItem;

typedef struct
{
    TipoItem itens[max];
    int tam, topo;
} TipoPilhaE;

void inicializaPilha(TipoPilhaE *pilha)
{
    pilha->topo = -1;
    pilha->tam = max;
}

int pilhaCheia(TipoPilhaE *pilha)
{
    if (pilha->topo == pilha->tam - 1)
        return 1;
    return 0;
}

int pilhaVazia(TipoPilhaE *pilha)
{
    if (pilha->topo == -1)
        return 1;
    return 0;
}

int push(TipoPilhaE *pilha, TipoItem novoItem)
{
    int x, p;

    x = pilhaCheia(pilha);
    if (x == 1)
    {
        printf("Pilha cheia.\n");
        return 0;
    }
    else
    {
        // pilha->topo++;
        p = ++pilha->topo;
        pilha->itens[p] = novoItem;
        return 1;
    }
}

TipoItem pop(TipoPilhaE *pilha)
{
    int x, p;
    TipoItem item;

    x = pilhaVazia(pilha);
    if (x == 1)
    {
        item.chave = -1;
        return item;
    }
    else
    {
        p = pilha->topo--;
        item = pilha->itens[p];
        return item;
    }
}

int main()
{
    int i, n;
    TipoItem item;
    TipoPilhaE pilha;

    inicializaPilha(&pilha);

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &item.chave, item.nome);
        if (!push(&pilha, item))
            break;
    }

    while(!pilhaVazia(&pilha)) {
        item = pop(&pilha);
        printf("Desempilhou: %d %s\n", item.chave, item.nome);
    }

    return 0;
}