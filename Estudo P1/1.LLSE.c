#include <stdio.h>

#define max 10

typedef struct {
    int chave;
    char nome[50];
}TipoItem;

typedef struct {
    TipoItem itens[max];
    int ultimo;
}TipoListaSE;

void inicializaLista(TipoListaSE *lista) {
    lista->ultimo = 0;
}

int inserirNoFinal(TipoListaSE *lista, TipoItem novoItem) {
    int pos = lista->ultimo;
    if(pos < max) {
        lista->itens[pos] = novoItem;
        lista->ultimo++;
        return 1;
    }
    else return 0;
}

void imprimeLista(TipoListaSE *lista) {
    for(int i=0; i<lista->ultimo; i++) {
        printf("%d %s\n", lista->itens[i].chave, lista->itens[i].nome);
    }
}

int main() {
    int n, i;
    TipoItem item;
    TipoListaSE lista;

    inicializaLista(&lista);

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d %s", &item.chave, item.nome);
        if(!inserirNoFinal(&lista, item)) {
            printf("ERRO! Tamanho limite excedido.\n");
            break;
        }
    }

    imprimeLista(&lista);

    return 0;   
}