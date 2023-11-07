#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem {
    int chave;
    char nome[50];
    struct TipoItem *prox;
}TipoItem;

typedef struct {
    TipoItem *inicio, *fim;
}TipoFilaSD;

void inicializaFila(TipoFilaSD *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(TipoFilaSD *fila) {
    if(fila->inicio == NULL ) return 1;
    return 0;
}

void inserir(TipoFilaSD *fila, TipoItem novoItem) {
    TipoItem *novoNo;

    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;
    novoNo->prox = NULL;

    if(filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

int remover(TipoFilaSD *fila) {
    TipoItem *auxiliar;

    if(!filaVazia(fila)) {
        auxiliar = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(auxiliar);
        return 1;
    }
    else if(fila->inicio == fila->fim) {
        fila->fim = NULL;
        return 1;
    }
    else return 0;
}

void exibirFila(TipoFilaSD *fila) {
    TipoItem *p = fila->inicio;

    if(filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("\nElementos da fila:\n");
    while (p != NULL) {
        printf("%d %s\n", p->chave, p->nome);
        p = p->prox;
    }
}

int main() {
    TipoItem item;
    TipoFilaSD fila;
    int option;

    inicializaFila(&fila);

    while(1) {
        printf("Menu:\n");
        printf("1 - Inserir\n");
        printf("2 - Exibir lista\n");
        printf("3 - Remover\n");
        printf("4 - Sair\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                scanf("%d %s", &item.chave, item.nome);
                inserir(&fila, item);
                break;
            case 2:
                exibirFila(&fila);
                break;
            case 3:
                if(remover(&fila)) 
                    printf("Item removido com sucesso.\n");
                else 
                    printf("Fila vazia.\n");
                break;
            case 4:
                exit(0);
            default: 
                printf("Invalid option.\n");
        }

    }
}