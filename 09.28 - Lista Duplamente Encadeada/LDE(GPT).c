#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem {
    int num;
    struct TipoItem *ant, *prox;
} TipoItem;

typedef struct {
    TipoItem *inicio, *fim;
} TipoListaDE;

void inicializaListaDE(TipoListaDE *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insereNoFinal(TipoListaDE *lista, int valor) {
    TipoItem *novoNo = malloc(sizeof(TipoItem));
    novoNo->num = valor;
    novoNo->ant = NULL;
    novoNo->prox = NULL;

    if (lista->fim == NULL) { // Lista vazia
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else {
        novoNo->ant = lista->fim;
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
    }
}

int removeDoFinal(TipoListaDE *lista) {
    if (lista->fim == NULL) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
        return -1; // Valor inválido para indicar erro
    }

    TipoItem *ultimo = lista->fim;
    int valor = ultimo->num;

    if (lista->inicio == lista->fim) { // Único elemento na lista
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->fim = ultimo->ant;
        lista->fim->prox = NULL;
    }

    free(ultimo);
    return valor;
}

void imprimeListaDE(TipoListaDE *lista) {
    TipoItem *atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->num);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    TipoListaDE lista;
    int opcao, valor;

    inicializaListaDE(&lista);

    while (1) {
        printf("Menu:\n");
        printf("1. Inserir no final\n");
        printf("2. Remover do final\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Option: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &valor);
                insereNoFinal(&lista, valor);
                break;
            case 2:
                valor = removeDoFinal(&lista);
                if (valor != -1) {
                    printf("Elemento removido do final: %d\n", valor);
                }
                break;
            case 3:
                if (lista.inicio != NULL) {
                    printf("Elementos na lista: ");
                    imprimeListaDE(&lista);
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

    return 0;
}
