#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoArvG {
    char nome[1024];
    struct TipoArvG *pai, *filho, *irmao;
}TipoArvG;

void *inicializa(TipoArvG *arv) {
    arv->pai = NULL;
    arv->filho = NULL;
    arv->irmao = NULL;
    strcpy(arv->nome, "\\root");
}

TipoArvG *cria(char *nome){
    TipoArvG *novo = (TipoArvG *) malloc(sizeof(TipoArvG));

    strcpy(novo->nome, nome);
    novo->pai = NULL;
    novo->filho = NULL;
    novo->irmao = NULL;
    return novo;
}

void insere(TipoArvG *arv, char *nome){
    TipoArvG *subarv = cria(nome);

    subarv->irmao = arv->filho;
    arv->filho    = subarv;
    subarv->pai = arv;
}

TipoArvG *busca(TipoArvG *arv, char *nome){
    TipoArvG *p = arv->filho;

    if(p->nome == nome)
        return p;

    while(p!=NULL){
        imprime(p);
        p=p->irmao;
    }
}

void imprime(TipoArvG *arv) {
    printf("%s\n", arv->nome);
}

int main() {
    TipoArvG *arv;
    inicializa(arv);

    int N, i;
    do {
        scanf("%d", &N);
    } while(N<1 || N>1024);
    

    char comando[2], file[1025], folder[1025];
    for(i=0; i<N; i++) {
        scanf("%s", comando);
        if(comando[1] == 'a') {
            scanf("%s", folder);
            TipoArvG *pai = busca(arv, folder);
            scanf("%s", file);
            insere(pai, file);
        }

    }

    imprime(arv);

    return 0;
}