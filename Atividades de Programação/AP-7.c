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
    novo->esq = novo->dir = NULL;
    
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

int search(TipoNo* no, int busca){
<<<<<<< HEAD
    if(no==NULL) return 0;

    if(busca == no->num){
        return 1;
    }
    else if(busca < no->num){
        return search(no->esq, busca);
    }
    else {
        return search(no->dir, busca);
    }
}

void imprime(TipoNo* no, int busca){
    if(no==NULL) return;

    if(busca == no->num){
        printf("%d ", no->num);
    }
    else if(busca < no->num){
        printf("%d ", no->num);
        imprime(no->esq, busca);
    }
    else {
        printf("%d ", no->num);
        imprime(no->dir, busca);
=======
    if(no==NULL) return -1;

    if(busca == no->num){
        printf("%d ", no->num);
        return no->num;
    }
    else if(busca < no->num){
        int resultEsq = search(no->esq, busca);
        if(resultEsq != -1)
            printf("%d ", no->num);
        return resultEsq;
    }
    else {
        int resultDir = search(no->dir, busca);
        if(resultDir != -1)
            printf("%d ", no->num);
        return resultDir;
>>>>>>> 0950522a0584a470600f626177c60fc4019e2558
    }
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

    printf("\n");
    preOrdem(arv->raiz);
    printf("\n");
    emOrdem(arv->raiz);
    printf("\n");
    posOrdem(arv->raiz);
    printf("\n");

<<<<<<< HEAD
    int p = search(arv->raiz, busca);
    if(p==0)
        printf("-1");
    else
        imprime(arv->raiz, busca);
=======
    busca = search(arv->raiz, busca);
    if(busca==-1)
        printf("-1");
>>>>>>> 0950522a0584a470600f626177c60fc4019e2558
    printf("\n");

    int altura_atual = 0, altura_maxima = 0;
    altura_maxima = alturaArv(arv->raiz, altura_atual, &altura_maxima);
    printf("%d\n", altura_maxima);

    arv->raiz=libera(arv->raiz);
    
    return 0;
}