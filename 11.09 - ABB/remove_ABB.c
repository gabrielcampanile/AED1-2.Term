#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pno
{
    int info;
    struct pno *esq, *dir;
} pno;

typedef struct
{ 
    pno *raiz;
} tree;

void substituimenoradireita(struct pno *p, struct pno *suc)
{
    // Encontra o sucessor de p, ou seja, o descendente mais a esquerda da subárvore pa diretia de p.
    // É um nó terminal - seu conteúdo é copiado em q e é removido
    struct pno *q;

    if (suc->esq == NULL)
    {
        p->info = suc->info;
        // remover sucessor
        q = suc;
        suc = suc->dir; // altera p->dir
        free(q);
    }
    else
        substituimenoradireita(p, suc->esq);
}

void removerNo(struct pno *p)
{ // p é o ponteiro para o nó a ser removido; retorna em p o ponteiro para o nó que o substituiu
    struct pno *q;

    if (p->esq == NULL)
    { // substitui por filho à direita
        q = p;
        p = p->dir;
        free(q);
    }

    else if (p->dir == NULL)
    { // substitui por filho à esquerda
        q = p;
        p = p->esq;
        free(q);
    }

    else
        substituimenoradireita(p, p->dir);
    // alternativamente: substituimenoraesquerda(p, p->esq);
}

bool busca_remove(struct pno *raiz, int x)
{ // return true se removeu e false se x não estava na árvore
    if (raiz == NULL)
        return false;

    if (raiz->info == x)
    {
        removerNo(raiz);
        return true;
    }

    if (raiz->info < x) // buscar e remover na sub-árvore direita
        return busca_remove(raiz->dir, x);
    else // buscar e remover na sub-árvore esquerda
        return busca_remove(raiz->esq, x);
}

int main()
{
    return 0;
}