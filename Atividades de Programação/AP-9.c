#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TipoArvG{
    char nome[1025];
    struct TipoArvG *pai;
    struct TipoArvG *filho;
    struct TipoArvG *irmao;
}TipoArvG;

TipoArvG *cria(char *nome){
    TipoArvG *novo = (TipoArvG *) malloc(sizeof(TipoArvG));

    strcpy(novo->nome, nome);
    novo->pai = NULL;
    novo->filho = NULL;
    novo->irmao = NULL;
    return novo;
}

//Insere uma subárvore como primeiro filho
//Inserção no início da lista
void insere(TipoArvG *arv, char *nome){
    TipoArvG *subarv = cria(nome);

    subarv->irmao = arv->filho;
    arv->filho    = subarv;
    subarv->pai = arv;
}

// Impressão em pré-ordem
TipoArvG *busca(TipoArvG *arv, char *nome){
    TipoArvG *p = arv->filho;

    if(p->nome == nome)
        return p;

    while(p!=NULL){
        imprimePre(p);
        p=p->irmao;
    }
}

// Liberar memória
// Remover primeiro as folhas
void libera(TipoArvG *arv){ 
    TipoArvG *p=arv->filho;
    while(p!=NULL){
        TipoArvG *aux=p->irmao;
        libera(p);
        p=aux;
    }
    free(arv);
}

// verificação para buscar o pai ou arquivo e retornar NULL, não faz nada

int main() {
    TipoArvG *arv;

    //strcpy(arv.nome, "/root");

    arv = cria("\\root");

    int N, i;
    do {
        scanf("%d", &N);
    } while(N<1 || N>1024);

    char nome[1025];
    for(i=0; i<N; i++) {
        scanf("%s", nome);
        insere(arv, nome);
    }

    imprimePre(arv);
    libera(arv);

    return 0;
}