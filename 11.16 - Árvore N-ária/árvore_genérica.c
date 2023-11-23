#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TipoArvG{
    char info;
    struct TipoArvG *filho;
    struct TipoArvG *irmao;
}TipoArvG;

// Cria uma nova árvore com apenas um nó
TipoArvG *cria(char c){
    TipoArvG *novo = (TipoArvG *) malloc(sizeof(TipoArvG));
    novo->info  = c;
    novo->filho = NULL;
    novo->irmao = NULL;
    return novo;
}

//Insere uma subárvore como primeiro filho
//Inserção no início da lista
void insere(TipoArvG *arv, TipoArvG *subarv){
    subarv->irmao = arv->filho;
    arv->filho    = subarv;
}

// Impressão em pré-ordem
void imprimePre(TipoArvG *arv){
    TipoArvG *p = arv->filho;
    printf("%c\n",arv->info);
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

int main()
{
    TipoArvG *r1 = cria('a');
    TipoArvG *r2 = cria('b');
    TipoArvG *r3 = cria('c');
    TipoArvG *r4 = cria('d');
    TipoArvG *r5 = cria('e');
    TipoArvG *r6 = cria('f');
    TipoArvG *r7 = cria('g');

    insere(r1,r4);
    insere(r1,r3);
    insere(r1,r2);

    insere(r2,r6);
    insere(r5,r7);
    insere(r2,r5);

    imprimePre(r1);
    libera(r1);
    return 0;
}
