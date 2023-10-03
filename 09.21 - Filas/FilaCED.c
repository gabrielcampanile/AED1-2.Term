// Fila - Lista Circular Encadeada Dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem {
    int chave;
    struct TipoItem *prox;
    // outros componentes
}TipoItem;

typedef struct {
    TipoItem *ultimo;
    int tamanho;
}TipoListaCircular;

void inicializaLista(TipoListaCircular *lista) {
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void imprimeLista(TipoListaCircular *lista) {
    TipoItem *p = lista->ultimo;
    if(p != NULL) { //se lista não for vazia
        do {
            p=p->prox;
            printf("%d\n", p->chave);
        } while(p!=lista->ultimo);
    }
}

void insereNoFinal(TipoListaCircular *lista, TipoItem novoItem) {
    TipoItem *novoNo;

    novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;

    if(lista->ultimo == NULL) { //lista vazia
        novoNo->prox = novoNo; //novo nó será único
        lista->ultimo = novoNo;
    }
    else {
        novoNo->prox = lista->ultimo->prox; //aponta para o início
        lista->ultimo->prox = novoNo;
        lista->ultimo = novoNo;
    }
    lista->tamanho++;
}

int removerListaCircular(TipoListaCircular *lista, int chave) {
    if (lista->ultimo == NULL) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
        return 0;
    }

    TipoItem *anterior = lista->ultimo;
    TipoItem *atual = lista->ultimo->prox;

    while (atual != lista->ultimo) {
        if (atual->chave == chave) {
            anterior->prox = atual->prox;
            free(atual);
            lista->tamanho--;
            return 1; // Remoção bem-sucedida
        }

        anterior = atual;
        atual = atual->prox;
    }

    if (atual->chave == chave) {
        if (lista->ultimo == lista->ultimo->prox) { // Único elemento na lista
            lista->ultimo = NULL;
        } else {
            anterior->prox = atual->prox;
            lista->ultimo = anterior;
        }
        free(atual);
        lista->tamanho--;
        return 1; // Remoção bem-sucedida
    }

    printf("Elemento com chave %d não encontrado na lista.\n", chave);
    return -1; // Remoção falhou
}

int main() {
    TipoListaCircular lista;
    TipoItem item;
    int opcao, chave;

    inicializaLista(&lista);

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
                insereNoFinal(&lista, item);
                break;
            case 2:
                if (lista.tamanho > 0) {
                    printf("Informe a chave a ser removida: ");
                    scanf("%d", &chave);
                    removerListaCircular(&lista, chave);
                } else {
                    printf("A lista está vazia. Não é possível remover elementos.\n");
                }
                break;
            case 3:
                if (lista.tamanho > 0) {
                    printf("Elementos na lista:\n");
                    imprimeLista(&lista);
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