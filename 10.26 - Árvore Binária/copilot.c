
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int dado) {
    if (raiz == NULL) {
        raiz = criarNo(dado);
    } else if (dado <= raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado) {
        return raiz;
    } else if (dado < raiz->dado) {
        return buscar(raiz->esquerda, dado);
    } else {
        return buscar(raiz->direita, dado);
    }
}

void emOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->dado);
    emOrdem(raiz->direita);
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 17);
    printf("Percurso em ordem: ");
    emOrdem(raiz);
    printf("\n");
    No* no = buscar(raiz, 7);
    if (no == NULL) {
        printf("Elemento não encontrado\n");
    } else {
        printf("Elemento encontrado: %d\n", no->dado);
    }
    return 0;
}
