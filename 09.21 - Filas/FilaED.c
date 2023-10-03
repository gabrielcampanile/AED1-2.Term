// Fila - Lista Encadeada Dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem{ 
    int chave;
    char nome[51];
    struct TipoItem *prox;
}TipoItem;

typedef struct {
    TipoItem *inicio, *fim;
}TipoFilaD;

void inicializaLista(TipoFilaD *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(TipoFilaD *fila) {
    if(fila->inicio == NULL) return 1;
    return 0;
}

void inserir(TipoFilaD *fila, TipoItem novoItem) {
    TipoItem *novoNo;
    
    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;
    novoNo->prox = NULL;

    if(fila->fim == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

void remover(TipoFilaD *fila) {
    TipoItem *auxiliar;

    if(!filaVazia(fila)) {
        auxiliar = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(auxiliar);
    }
    else if(fila->inicio == fila->fim) {
        fila->fim = NULL;
    }
}

void exibirFila(TipoFilaD *fila) {
    TipoItem *atual = fila->inicio;
    
    printf("Elementos na fila:\n");
    while (atual != NULL) {
        printf("Chave: %d, Nome: %s\n", atual->chave, atual->nome);
        atual = atual->prox;
    }
}

int main() {
    TipoFilaD fila;
    TipoItem item;
    int opcao;

    inicializaLista(&fila);

    while (1) // loop infinito
    {
        printf("Menu:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Exibir Fila\n");
        printf("4. Sair\n");
        printf("Option: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a chave e o nome: ");
                scanf("%d %s", &item.chave, item.nome);
                inserir(&fila, item);
                break;
            case 2:
                if (!filaVazia(&fila)) {
                    remover(&fila);
                    printf("Elemento removido com sucesso.\n");
                } else {
                    printf("A fila está vazia. Não é possível remover elementos.\n");
                }
                break;
            case 3:
                if (!filaVazia(&fila)) {
                    exibirFila(&fila);
                } else {
                    printf("A fila está vazia. Não há elementos para exibir.\n");
                }
                break;
            case 4:
                exit(0); // Encerra o programa
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
