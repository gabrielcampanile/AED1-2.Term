#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem {
    int num;
    char letra;
    struct TipoItem *ant, *prox;
} TipoItem;

typedef struct {
    TipoItem *inicio, *fim;
} TipoListaDE;

void inicializaLista(TipoListaDE *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

int somaLista(TipoListaDE *lista) {
    int cont = 0;
    TipoItem *p = lista->inicio;
    while(p != NULL) {
        if(p->num < 10) {
            cont+=2;
        }
        else if(p->num >= 10 && p->num<100) {
            cont+=3;
        }
        else if(p->num >= 100 && p->num<1000) {
            cont+=4;
        }
        p = p->prox;
    }

    return cont;
}

void imprimeLista(TipoListaDE *lista) {
    TipoItem *p = lista->inicio;
    
    printf("%d\n", somaLista(lista));
    
    while(p != NULL) {
        printf("%d%c", p->num, p->letra);
        p = p->prox;
    }
    printf("\n");
}
void ruido(TipoListaDE *lista) {
    TipoItem *ruido = lista->inicio;

    while (ruido != NULL) {
        TipoItem *proxRuido = ruido->prox; // Salvar o próximo item antes de liberar ruido

        if (ruido->num == 1) {
            if (ruido->ant == NULL && proxRuido != NULL && proxRuido->num > 1) {
                proxRuido->num++;
                proxRuido->ant = NULL;
                lista->inicio = proxRuido;
                free(ruido);
            } else if (ruido->ant != NULL && proxRuido != NULL && ruido->ant->num > 1 && proxRuido->num > 1) {
                if (ruido->ant->num >= proxRuido->num) {
                    ruido->ant->num++;
                    ruido->ant->prox = proxRuido;
                    proxRuido->ant = ruido->ant;
                } else {
                    proxRuido->num++;
                    ruido->ant->prox = proxRuido;
                    proxRuido->ant = ruido->ant;
                }
                free(ruido);
            } else if (proxRuido == NULL && ruido->ant != NULL && ruido->ant->num > 1) {
                ruido->ant->num++;
                ruido->ant->prox = NULL;
                free(ruido);
            }
        }

        ruido = proxRuido; // Atualizar ruido para o próximo item
    }
}

void inserirItem(TipoListaDE *lista, TipoItem novoItem) {
    TipoItem *novoNo = malloc(sizeof(TipoItem));
    *novoNo = novoItem;
    // novoNo->num = novoItem.num;
    // novoNo->letra = novoItem.letra;
    novoNo->ant = NULL;
    novoNo->prox = NULL;

    if(lista->fim == NULL) {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    }
    else {
        novoNo->ant = lista->fim;
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
    }
}

void atualizar(TipoListaDE *lista) {
    lista->fim->num++;
}

int main() {
    TipoItem item;
    TipoListaDE lista;

    char string[1023];
    scanf("%s", string);

    inicializaLista(&lista);

    item.letra = string[0];
    item.num = 1;
    inserirItem(&lista, item);

    for(int i=1; i<strlen(string); i++) {
        if(string[i] == string[i-1]) {
            atualizar(&lista);
            // item.num++;
            // inserirItem(&lista, item);
        }
        else {
            item.letra = string[i];
            item.num = 1;
            inserirItem(&lista, item);
        }
    }
    imprimeLista(&lista);

    ruido(&lista);
    imprimeLista(&lista);

    return 0;
}