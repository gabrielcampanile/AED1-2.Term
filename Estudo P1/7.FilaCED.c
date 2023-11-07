#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int chave;
    struct TipoItem *prox;
}TipoItem;

typedef struct {
    TipoItem *ultimo;
    int tamanho;
}TipoFilaC;

void inicializaFilaC(TipoFilaC *fila) {
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

void imprimeFilaC(TipoFilaC *fila) {
    TipoItem *p = fila->ultimo;

    if(p!=NULL) {
        do {
            p = p->prox;
            printf("%d\n", p->chave);
        } while(p!=fila->ultimo);
    }
}

void insererNoFinal(TipoFilaC *fila, TipoItem novoItem) {
    TipoItem *novoNo;

    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;

    if(fila->ultimo == NULL) {
        fila->ultimo = novoNo;
        fila->ultimo->prox = novoNo;
    }
    else {
        novoNo->prox = fila->ultimo->prox;
        fila->ultimo->prox = novoNo;
        fila->ultimo = novoNo;
    }
    
    fila->tamanho++;
}

int removerFilaC(TipoFilaC *fila, int chave) {
    if(fila->ultimo == NULL) {
        printf("Fila vazia.\n");
        return 0;
    }

    TipoItem *anterior = fila->ultimo;
    TipoItem *atual = fila->ultimo->prox;

    while(atual!=fila->ultimo) {
        if(atual->chave == chave) {
            anterior->prox = atual->prox;
            free(atual);
            fila->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if(atual->chave == chave) {
        if(fila->ultimo == fila->ultimo->prox)
            fila->ultimo = NULL;
        else {
            anterior->prox = atual->prox;
            fila->ultimo = anterior;
        }
        fila->tamanho--;
        return 1;
    }

    printf("Elemento com chave %d não encontrado na lista.\n", chave);
    return -1; // Remoção falhou
}

int main() {
    int opcao, chave;
    TipoItem item;
    TipoFilaC fila;

    inicializaFilaC(&fila);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir no final\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Option: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a chave: ");
                scanf("%d", &item.chave);
                insereNoFinal(&fila,item);
                break;
            case 2:
                if (fila.tamanho > 0) {
                    printf("Informe a chave a ser removida: ");
                    scanf("%d", &chave);
                    removerFilaC(&fila, chave);
                } else {
                    printf("A lista está vazia. Não é possível remover elementos.\n");
                }
                break;
            case 3:
                if (fila.tamanho > 0) {
                    printf("Elementos na lista:\n");
                    imprimeFilaC(&fila);
                } else {
                    printf("A lista está vazia.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }
}