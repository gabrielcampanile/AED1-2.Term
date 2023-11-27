#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoArvG{
    char nome[1024];
    struct TipoArvG *pai, *irmao, *filho;
} TipoArvG;

typedef struct TipoRaiz{
    TipoArvG *raiz;
} TipoRaiz;


TipoArvG *Cria(char no[1024]){
    TipoArvG *novo = (TipoArvG *) malloc(sizeof(TipoArvG));
    strcpy(novo->nome, no);
    novo->filho = NULL;
    novo->irmao = NULL;
    novo->pai = NULL;

    return novo;
}


void Inicializa(TipoRaiz *arv){
    char raiz[1024] = "\\root";
    arv->raiz = Cria(raiz);
}


TipoArvG *Busca(TipoArvG *no, char nome[1024]){
    if(no == NULL)
        return NULL;

    if(strcmp(no->nome, nome) == 0)
            return no;

   TipoArvG *p = no->filho;
    while(p!=NULL){
        TipoArvG *res = Busca(p, nome);
        if(res != NULL)
            return res;
        p=p->irmao;
    }

    return NULL;
}


void Adiciona(TipoArvG *raiz, char no[1024], char NoPai[1024]){
    
    TipoArvG *x = Cria(no);
    TipoArvG *y = Busca(raiz, NoPai);
        if(y->filho == NULL){
            y->filho = x;
            x->irmao = NULL;
            x->pai = y;
        }
        else{
            x->irmao = y->filho;
            y->filho = x;
            x->pai = y;
        }   
}


void Remove(TipoArvG *raiz, char no[1024]){

    TipoArvG *x = Busca(raiz, no);
    TipoArvG *y = x->pai;
    if(y != NULL){
        if(y->filho == x)
            y->filho = x->irmao;
        else{
            TipoArvG *tmp = y->filho;
            while (tmp->irmao != x){
                tmp = tmp->irmao;
            }
            tmp->irmao = x->irmao;
        }
        free(x);
    }
}


void imprime(TipoRaiz *arv, char no[1024]){
    TipoArvG *f = Busca(arv->raiz, no);
    if(f == NULL)
        printf("Arquivo nao encontrado!");
    else{
        printf("%s ", f->nome);
        TipoArvG *temp = f->pai;
        while(temp != NULL){
            printf("%s ", temp->nome);
            temp = temp->pai;
        }
    }
}


void libera(TipoArvG *arv){
    TipoArvG *p=arv->filho;
    while(p!=NULL){
        TipoArvG *aux=p->irmao;
        libera(p);
        p=aux;
    }
    free(arv);
}



int main(){

    TipoRaiz Arv;

    Inicializa(&Arv);

    int Nopr;
    scanf("%d", &Nopr);

    char file[1024];
    scanf("%s", file);


    for(int i=0; i<Nopr; i++){
        char opr[1024], doc[1024], folder[1024];
        scanf("%s", opr);

        if(strcmp(opr, "-r") == 0){
            scanf("%s", doc);
            TipoArvG *no = Busca(Arv.raiz, doc);
                if(no != NULL)
                Remove(Arv.raiz, doc);
        }
        else{
            if(strcmp(opr, "-a") == 0){
                scanf("%s %s", doc, folder);
                TipoArvG *pai = Busca(Arv.raiz, folder);
                if(pai != NULL)
                    Adiciona(Arv.raiz, doc, folder);
            }
            else{
                scanf("%s %s", doc, folder);
                TipoArvG *pai = Busca(Arv.raiz, folder);
                if(pai != NULL){
                    Remove(Arv.raiz, doc);
                    Adiciona(Arv.raiz, doc, folder);
                }
            }
        }
    }

    imprime(&Arv, file);

    libera(Arv.raiz);

    return 0;
}