#include <stdio.h>

#define MAX 5

typedef struct
{
    int chave;
    char nome[50];
    // outros componentes
} TipoItem;

typedef struct
{
    TipoItem itens[MAX];
    int ultimo; // indica a próxima posição vazia
} ListaLinearSE;

void inicializaLLSE(ListaLinearSE *lista)
{
    lista->ultimo = 0;
}

void imprimeLLSE(ListaLinearSE *lista)
{
    int i = 0;
    for (i = 0; i < lista->ultimo; i++)
        printf("%d %s\n", lista->itens[i].chave, lista->itens[i].nome);
}

int insereNoFinalLLSE(ListaLinearSE *lista, TipoItem novoItem)
{
    int pos = lista->ultimo;
    if (pos < MAX)
    {
        lista->itens[pos] = novoItem;
        lista->ultimo++;
    }
    else
        return -1;
    return 0;
}

int main()
{
    int i, n;
    ListaLinearSE lista;
    TipoItem item;

    inicializaLLSE(&lista);

    printf("Quantos itens voce deseja adicionar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &item.chave, item.nome);
        if (insereNoFinalLLSE(&lista, item) < 0)
        {
            printf("ERRO! Tamanho limite excedido.\n");
            break;
        }
    }
    imprimeLLSE(&lista);

    return 0;
}
