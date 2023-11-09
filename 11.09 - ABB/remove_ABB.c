#include <stdio.h>
#include <stdlib.h>



boolean busca_remove(tree raiz, tipo_elem x) { // return true se removeu e false se x não estava na árvore
    if(raiz == NULL)
        return FALSE;
    
    if(raiz->info == x) {
        removerNo(raiz);
        return TRUE;
    }

    if(raiz->info < x) // buscar e remover na sub-árvore direita
        return busca_remove(raiz->dir, x);
    else               // buscar e remover na sub-árvore esquerda   
        return busca_remove(raiz->esq, x);
}

void removerNo(pno p) { //p é o ponteiro para o nó a ser removido; retorna em p o ponteiro para o nó que o substituiu
    pno q;

    if(p->esq == NULL) { // substitui por filho à direita
        q = p;
        p = p->dir;
        free(q);
    }
    
    else if(p->dir == NULL) { // substitui por filho à esquerda
        q = p;
        p = p->esq;
        free(q);
    }

    else
        substituimenoradireita(p, p->dir);
        // alternativamente: substituimenoraesquerda(p, p->esq);
}

void substituimenoradireita(pno p, npo suc) {
    // Encontra o sucessor de p, ou seja, o descendente mais a esquerda da subárvore pa diretia de p.
    // É um nó terminal - seu conteúdo é copiado em q e é removido
    pno q;

    if(suc->esq == NULL) {
        p->info = suc->info;
        // remover sucessor
        q = suc;
        suc = suc->dir; //altera p->dir
        free(q);
    }
    else
        substituimenoradireita(p, suc->esq);
}
