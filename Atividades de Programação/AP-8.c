#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TipoNo
{
    int freq;
    char letra;
    struct TipoNo *esq, *dir;
} TipoNo;

typedef struct
{
    TipoNo *raiz;
} TipoArv;

void inicializaArv(TipoArv *arv)
{
    arv->raiz = NULL;
}

TipoNo *novoNo(int n, char l)
{
    TipoNo *novo = (TipoNo *)malloc(sizeof(TipoNo));
    novo->freq = n;
    novo->letra = l;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TipoNo *insert(TipoArv *arv, TipoNo *no, int n, char letra)
{
    if (arv->raiz == NULL)
        arv->raiz = novoNo(n, letra);

    if (no == NULL)
        no = novoNo(n, letra);
    else if (n >= no->freq)
        no->dir = insert(arv, no->dir, n, letra);
    else
        no->esq = insert(arv, no->esq, n, letra);
    return no;
}

void emOrdem(TipoNo *no)
{
    if (no == NULL)
        return;
    emOrdem(no->esq);
    printf("%c", no->letra);
    emOrdem(no->dir);
}

TipoNo *substituimenoradireita(TipoNo *p, TipoNo *suc)
{
    // Encontra o sucessor de p, ou seja, o descendente mais a esquerda da subárvore da direita de p.
    // É um nó terminal - seu conteúdo é copiado em q e é removido
    TipoNo *q;

    if (suc->esq == NULL)
    {
        p->freq = suc->freq;
        p->letra = suc->letra;
        // remover sucessor
        q = suc;
        suc = suc->dir; // altera p->dir
        free(q);
    }
    else
        suc->esq = substituimenoradireita(p, suc->esq);

    printf("\nteste substitui");

    return suc;
}

TipoNo *removerNo(TipoNo *p)
{ // p é o ponteiro para o nó a ser removido; retorna em p o ponteiro para o nó que o substituiu
    TipoNo *q;

    if (p == NULL)
    {
        return NULL;
    }

    if (p->esq == NULL)
    { // substitui por filho à direita
        q = p->dir;
        free(p);
        return q;
    }

    else if (p->dir == NULL)
    { // substitui por filho à esquerda
        q = p->esq;
        free(p);
        return q;
    }

    else
    {
        q = p;
        TipoNo *r = p->esq;
        while (r->dir != NULL)
        {
            q = r;
            r = r->dir;
        }
        if (q != p)
        {
            q->dir = r->esq;
            r->esq = p->esq;
        }
        r->dir = p->dir;
        free(p);
        return r;
    }
}

TipoNo *busca_remove(TipoNo *raiz, int n, char l)
{
    TipoNo *aux;

    if (raiz == NULL)
        return NULL;

    raiz->esq = busca_remove(raiz->esq, n, l);

    raiz->dir = busca_remove(raiz->dir, n, l);

    if (raiz->letra == l)
    {
        aux = removerNo(raiz);
        return aux;
    }

    return raiz;
}

int main()
{
    TipoArv arv;
    inicializaArv(&arv);

    char a, b;
    int freqA, freqB;
    scanf("%c %c", &a, &b);

    char string[1025];
    int cont[27] = {0};
    scanf("%s", string);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] <= 'z' && string[i] >= 'a')
            string[i] -= 32;

        if (string[i] <= 'Z' && string[i] >= 'A')
            cont[string[i] - 65]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cont[i] > 0)
            insert(&arv, arv.raiz, cont[i], (char)i + 65);
        if ((char)i + 65 == a)
            freqA = cont[i];
        if ((char)i + 65 == b)
            freqB = cont[i];
    }

    printf("\n");
    emOrdem(arv.raiz);

    arv.raiz = busca_remove(arv.raiz, freqA, a);
    arv.raiz = busca_remove(arv.raiz, freqB, b);

    printf("\n");
    emOrdem(arv.raiz);

    return 0;
}