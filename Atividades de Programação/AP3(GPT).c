#include <stdio.h>
#include <stdlib.h>

typedef struct Monomio
{
    int C, E;
    struct Monomio *prox;
} Monomio;

typedef struct
{
    Monomio *primeiro;
} Polinomio;

void inicializa(Polinomio *lista)
{
    lista->primeiro = NULL;
}

void insere(Polinomio *lista, Monomio novo)
{
    Monomio *atual = lista->primeiro;
    Monomio *anterior = NULL;

    while (atual != NULL && atual->E > novo.E)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->E == novo.E)
    {
        atual->C += novo.C;
    }
    else
    {
        Monomio *novoMonomio = malloc(sizeof(Monomio));
        if (novoMonomio == NULL)
        {
            printf("ERRO! Não foi possível alocar memória.\n");
            exit(1);
        }
        novoMonomio->C = novo.C;
        novoMonomio->E = novo.E;
        novoMonomio->prox = atual;

        if (anterior == NULL)
        {
            lista->primeiro = novoMonomio;
        }
        else
        {
            anterior->prox = novoMonomio;
        }
    }
}

void imprime(Polinomio *lista)
{
    int cont = 0;
    Monomio *atual = lista->primeiro;

    while (atual != NULL)
    {
        if (atual->C != 0)
        {
            printf("%i %i ", atual->C, atual->E);
            cont++;
        }
        atual = atual->prox;
    }

    if (cont != 0)
        printf("\n%i\n", cont);
    else
        printf("nulo\n0\n");

    while (lista->primeiro != NULL)
    {
        Monomio *temp = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;
        free(temp);
    }
}

int main()
{
    int N, i;
    Polinomio lista;
    Monomio elemento;

    inicializa(&lista);
    scanf("%i", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%i %i", &elemento.C, &elemento.E);
        insere(&lista, elemento);
    }

    imprime(&lista);

    return 0;
}
