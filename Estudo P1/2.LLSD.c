#include <stdio.h>
#include <stdlib.h>

#define ALOCA_TAM 10

typedef struct
{
    int chave;
    char nome[50];
} TipoItem;

typedef struct
{
    TipoItem *itens;
    int ultimo;
    int tamanho;
} TipoListaSD;

int inicializaLista(TipoListaSD *lista)
{
    lista->ultimo = 0;
    lista->tamanho = ALOCA_TAM;
    lista->itens = malloc(ALOCA_TAM * sizeof(TipoItem));
    if (lista->itens == NULL)
        return 0;
    return 1;
}

void imprimeLista(TipoListaSD *lista)
{
    for (int i = 0; i < lista->ultimo; i++)
    {
        printf("%d %s\n", lista->itens[i].chave, lista->itens[i].nome);
    }
}

int insereNoFinal(TipoListaSD *lista, TipoItem novoItem)
{
    int pos = lista->ultimo;

    if (pos == lista->tamanho)
    {
        lista->itens = (TipoItem *)realloc(lista->itens, (lista->tamanho + ALOCA_TAM) * sizeof(TipoItem));
        if (lista->itens == NULL)
        {
            printf("Não foi possivel alocar memoria.\n");
            return 0;
        }
        lista->tamanho += ALOCA_TAM;
    }
    lista->itens[pos] = novoItem;
    lista->ultimo++;

    return 1;
}

int main()
{
    int i, n;
    TipoItem item;
    TipoListaSD lista;

    inicializaLista(&lista);

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %s\n", &item.chave, item.nome);
        insereNoFinal(&lista, item);
    }

    imprimeLista(&lista);

    return 0;
}