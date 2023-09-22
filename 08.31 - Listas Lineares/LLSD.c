#include <stdio.h>
#include <stdlib.h>

#define ALOCA_TAM 10 //aloca a cada 10

typedef struct 
{
    int chave;
    char nome[50];
    // outros componentes
}TipoItem;

typedef struct 
{
    TipoItem *itens;
    int ultimo; // indica a próxima posição vazia
    int tamanho; // indica o tamanho do vetor alocado
}ListaLinearSD;

int inicializaLLSD(ListaLinearSD *lista) {
    lista->ultimo = 0;
    lista->tamanho = ALOCA_TAM;
    lista->itens = malloc(ALOCA_TAM*sizeof(TipoItem));
    if(lista->itens == NULL) return -1;
    return 0;
}

void imprimeLLSD(ListaLinearSD *lista) {
    int i=0;
    for(i=0; i<lista->ultimo; i++)
        printf("%d %s\n", lista->itens[i].chave, lista->itens[i].nome);
}

// inserção no final
/*int insereNoFinalLLSD(ListaLinearSD *lista, TipoItem novoItem) {
    int pos = lista->ultimo, i;

    if(pos==lista->tamanho) {
        TipoItem *aux = lista->itens; // guarda endereço antigo
        TipoItem *novaLista = malloc((lista->tamanho+ALOCA_TAM)*sizeof(TipoItem));
        if(novaLista == NULL) return -1;
        for(i=0; i<pos; i++)
            novaLista[i] = lista->itens[i];
        lista->itens = novaLista;
        lista->tamanho += ALOCA_TAM;
        if(aux!=NULL)
            free(aux); // libera memoria
    }
    lista->itens[pos] = novoItem;
    lista->ultimo++;
    return 0;
}*/

int insereNoFinalLLSD(ListaLinearSD *lista, TipoItem novoItem) {
    int pos = lista->ultimo, i;

    if(pos == lista->tamanho) {
        TipoItem *novaLista = realloc(lista->itens, (lista->tamanho+ALOCA_TAM)*sizeof(TipoItem));
        if(novaLista == NULL) {
            printf("ERRO! Não foi possível alocar memória.\n");
            return -1;
        }
        lista->tamanho += ALOCA_TAM;
    }
    lista->itens[pos] = novoItem;
    lista->ultimo++;
    return 0;
}

int main() {
    int i, n;
    ListaLinearSD lista;
    TipoItem item;

    if(inicializaLLSD(&lista) < 0) {
        printf("ERRO! Não foi possível alocar memória.\n");
        exit(1);
    }
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %s", &item.chave, item.nome);
        insereNoFinalLLSD(&lista, item);
    }
    imprimeLLSD(&lista);
    return 0;
}