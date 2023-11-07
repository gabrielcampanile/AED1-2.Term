<<<<<<< HEAD
// seja RAIZ o nó

<raiz sae sad>

=======
#include <stdio.h>
#include <stdlib.h>

typedef struct TipoNo{
    int num;
    struct TipoNo *esq,*dir;
}TipoNo;

typedef struct{
    TipoNo *raiz;
}TipoArv;

void inicializaArv(TipoArv *arv){
    arv->raiz = NULL;
}

TipoNo *novoNo(int n){
    TipoNo *novo = (TipoNo*) malloc(sizeof(TipoNo));
    novo->num = n;
    novo->esq  = NULL;
    novo->dir  = NULL;
    return novo;
}

TipoNo* insert(TipoNo* no, int n)
{
    if(no == NULL)
        no = novoNo(n);
    else if(n >= no->num)
        no->dir = insert(no->dir, n);
    else 
        no->esq = insert(no->esq, n);
    return no;
}

int alturaArv(TipoNo *no, int altura_atual, int *altura_maxima)
{
    if (no != NULL)
    {
        if (altura_atual > *altura_maxima)
            *altura_maxima = altura_atual;
        alturaArv(no->esq, altura_atual + 1, altura_maxima);
        alturaArv(no->dir, altura_atual + 1, altura_maxima);
    }

    return *altura_maxima;
}

void preOrdem(TipoNo *no){
    if(no==NULL)
        return;
    printf("%d ",no->num); 
    preOrdem(no->esq);    
    preOrdem(no->dir);
}

void emOrdem(TipoNo *no){
    if(no==NULL)
        return;
    emOrdem(no->esq);
    printf("%d ",no->num);
    emOrdem(no->dir);
}

void posOrdem(TipoNo *no){
    if(no==NULL)
        return;
    posOrdem(no->esq);    
    posOrdem(no->dir);
    printf("%d ",no->num);
}

// void imprime(TipoNo *raiz){
//     if(raiz!=NULL){
//         printf("%c",raiz->num);
//         imprime(raiz->esq);
//         imprime(raiz->dir);
//     }
// }

TipoNo *libera(TipoNo *raiz){
    if(raiz!=NULL){
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
    }
    return NULL;
}

int main(){
    TipoArv *arv = (TipoArv*)malloc(sizeof(TipoArv));
    inicializaArv(arv);

    int elementos, busca, n;
    scanf("%i %i", &elementos, &busca);
    if (busca < 0 || busca > 1024)
        return 0;

    for(int i=0; i<elementos; i++) {
        scanf("%d", &n);
        arv->raiz = insert(arv->raiz, n);
    }

    int altura_atual = 0, altura_maxima = 0;
    altura_maxima = alturaArv(arv->raiz, altura_atual, &altura_maxima);

    printf("\n");
    preOrdem(arv->raiz);
    printf("\n");
    emOrdem(arv->raiz);
    printf("\n");
    posOrdem(arv->raiz);
    printf("\n");

    // imprime(arv.raiz);
    // printf("\n");
    printf("%d\n", altura_maxima);

    arv->raiz=libera(arv->raiz);
    
    return 0;
}
>>>>>>> 0950522a0584a470600f626177c60fc4019e2558
