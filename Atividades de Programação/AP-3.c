#include <stdio.h>
#include <stdlib.h>

#define ALOCA_TAM 10

typedef struct
{
    int C, E;
} Monomio;

typedef struct
{
    Monomio *elementos;
    int ultimo;
    int tamanho;
} Polinomio;

int inicializa(Polinomio *lista)
{
    lista->ultimo = 0;
    lista->tamanho = ALOCA_TAM;
    lista->elementos = malloc(ALOCA_TAM * sizeof(Monomio));
    if (lista->elementos == NULL)
        return -1;
    return 0;
}

int compara(Polinomio *lista, Monomio novo)
{
    for (int i = 0; i < lista->ultimo; i++)
        if (novo.E == lista->elementos[i].E)
            return 1;
    return 0;
}

int insere(Polinomio *lista, Monomio novo)
{
    int pos = lista->ultimo, i;

    if (pos == lista->tamanho)
    {
        // Monomio *novaLista = realloc(lista->elementos, (lista->tamanho + ALOCA_TAM) * sizeof(Monomio));
        lista->elementos = (Monomio *)realloc(lista->elementos, (lista->tamanho + ALOCA_TAM) * sizeof(Monomio));

        if (lista->elementos == NULL)
        {
            printf("ERRO! Não foi possível alocar memória.\n");
            return -1;
        }
        lista->tamanho += ALOCA_TAM;
    }

    if (compara(lista, novo) == 0)
    {
        lista->elementos[pos] = novo;
        lista->ultimo++;
    }
    else
    {
        for (i = 0; i < lista->ultimo; i++)
            if (novo.E == lista->elementos[i].E)
                lista->elementos[i].C += novo.C;
    }

    return 0;
}

void organiza(Polinomio *lista)
{
    int i, j, n = lista->ultimo;
    Monomio aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (lista->elementos[j].E < lista->elementos[j + 1].E)
            {
                // Troca os elementos se estiverem fora de ordem
                aux = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j + 1];
                lista->elementos[j + 1] = aux;
            }
        }
    }
}

void imprime(Polinomio *lista)
{
    int i = 0, cont = 0;
    for (i = 0; i < lista->ultimo; i++)
    {
        if (lista->elementos[i].C != 0)
        {
            printf("%i %i ", lista->elementos[i].C, lista->elementos[i].E);
            cont++;
        }
    }
    if (cont != 0)
        printf("\n%i\n", cont);
    else
        printf("nulo\n0\n");
    free(lista->elementos);
}

int main()
{
    int N, i;
    Polinomio lista;
    Monomio elemento;

    if (inicializa(&lista) < 0)
    {
        printf("Erro! Não foi possível alocar memória.\n");
        exit(1);
    }
    scanf("%i", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%i %i", &elemento.C, &elemento.E);
        insere(&lista, elemento);
    }

    organiza(&lista);
    imprime(&lista);

    return 0;
}