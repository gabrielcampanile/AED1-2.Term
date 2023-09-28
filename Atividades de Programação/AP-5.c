#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem
{
    int T, i;
    struct TipoItem *prox;
} TipoItem;

typedef struct
{
    TipoItem *inicio, *fim;
    int T, i;
} TipoFilaD;

void inicializaFila(TipoFilaD *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->T = 0;
}

int filaVazia(TipoFilaD *fila)
{
    if (fila->inicio == NULL)
        return 1;
    return 0;
}

void inserir(TipoFilaD *fila, TipoItem novoItem)
{
    TipoItem *novoNo;

    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;

    if (fila->fim == NULL)
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else
    {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

int remover(TipoFilaD *fila)
{
    TipoItem *auxiliar;
    int retorno;

    if (!filaVazia(fila))
    {
        auxiliar = fila->inicio;
        retorno = auxiliar->T;
        if (fila->inicio == fila->fim)
        { // um unico elemento
            fila->fim = NULL;
            fila->inicio = NULL;
        }
        else
        {
            fila->inicio = fila->inicio->prox;
        }
        free(auxiliar);
        return retorno;
    }
    return 0;
}

int soma(TipoFilaD *fila)
{
    TipoItem *p = fila->inicio;
    int cont = 0;

    while (p != NULL)
    {
        cont += p->T;
        p = p->prox;
    }

    return cont;
}

int faster(TipoFilaD fila[], int a)
{
    int i, f, aux;

    for (i = 1; i < a; i++)
    {
        fila[i].T = soma(&fila[i]);
        // printf("\nfila %d - %d\n", i, fila[i].T);
    }

    f = fila[1].T;
    aux = 1;

    if (a > 2)
        for (i = 2; i < a; i++)
        {
            if (fila[i].T < f)
            {
                f = fila[i].T;
                aux = i;
            }
        }

    return aux;
}

void imprimeLista(TipoFilaD *fila)
{
    TipoItem *p = fila->inicio;
    
    while(p != NULL) {
        printf(" %d", p->i);
        p = p->prox;
    }
}

int main()
{
    int N, a, T, i, j;
    TipoItem novo;

    scanf("%d %d", &N, &a);

    TipoFilaD fila[a + 1];

    // Inicializar filas
    for (i = 0; i < a + 1; i++)
    {
        inicializaFila(&fila[i]);
    }

    // Fila de espera
    for (i = 0; i < N; i++)
    {
        scanf("%d", &T);
        novo.T = T;
        novo.i = i;
        inserir(&fila[0], novo);
    }

    // Filas de atendimento
    for (i = 0; i < N; i++)
    {
        novo.T = remover(&fila[0]);
        // printf("\n%d novo.t\n", novo.T);
        j = faster(fila, a + 1);
        // printf("%d menor fila\n", j);
        novo.i = i+1;
        inserir(&fila[j], novo);
    }

    for(i=1; i<a+1; i++) {
        printf("%i:", i);
        imprimeLista(&fila[i]);
        printf("\n");
        // printf("%i\n", soma(&fila[i]));
    }

    return 0;
}