#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoArvG
{
    char nome[1024];
    struct TipoArvG *pai, *filho, *irmao;
} TipoArvG;

typedef struct TipoRaiz
{
    TipoArvG *raiz;
} TipoRaiz;

/*TipoArvG *inicializa() {
    TipoArvG *arv = (TipoArvG *) malloc(sizeof(TipoArvG));
    arv->pai = NULL;
    arv->filho = NULL;
    arv->irmao = NULL;
    strcpy(arv->nome, "\\root");
    return arv;
}*/

TipoArvG *criar(char *nome)
{
    TipoArvG *novo = (TipoArvG *)malloc(sizeof(TipoArvG));

    strcpy(novo->nome, nome);
    novo->pai = NULL;
    novo->filho = NULL;
    novo->irmao = NULL;

    return novo;
}

void inicializar(TipoRaiz *arv)
{
    arv->raiz = criar("\\root");
}

/*TipoArvG *insere(TipoArvG *arv, char *nome){
    TipoArvG *subarv = criar(nome);

    subarv->pai = arv;
    subarv->irmao = arv->filho;
    arv->filho = subarv;

    return subarv;
}*/

void inserir(TipoArvG *arv, char *nome)
{
    TipoArvG *subarv = criar(nome);

    if (arv->filho == NULL)
    {
        subarv->irmao = NULL;
        subarv->pai = arv;
        arv->filho = subarv;
    }
    else
    {
        subarv->pai = arv;
        subarv->irmao = arv->filho;
        arv->filho = subarv;
    }
}

/*void remover(TipoArvG *arv, char *nome){
    if (arv == NULL || arv->filho == NULL) return;

    TipoArvG *p = arv->filho;
    if(strcmp(p->nome, nome) == 0){
        arv->filho = p->irmao;
        free(p);
        return;
    }

    TipoArvG *q = p->irmao;
    while(q != NULL){
        if(strcmp(q->nome, nome) == 0){
            p->irmao = q->irmao;
            free(q);
            return;
        }
        p = q;
        q = q->irmao;
    }
}*/

void remover(TipoArvG *no)
{
    TipoArvG *p = no->pai;
    TipoArvG *q = p->filho;

    if (p != NULL)
    {
        if (p->filho == no)
            p->filho = no->irmao;
        else
        {
            while (q->irmao != no)
                q = q->irmao;
            q->irmao = no->irmao;
        }
        free(no);
    }
}

TipoArvG *buscar(TipoArvG *arv, char *nome)
{
    TipoArvG *p = arv->filho;
    TipoArvG *found = NULL;

    if (arv == NULL)
        return NULL;

    if (strcmp(arv->nome, nome) == 0)
        return arv;

    while (p != NULL)
    {
        found = buscar(p, nome);
        if (found != NULL)
            return found;
        p = p->irmao;
    }

    return NULL;
}

void imprimir(TipoArvG *arv)
{
    TipoArvG *q = arv;

    if (arv == NULL)
    {
        printf("Arquivo não encontrado");
        return; // Retorna imediatamente se o arquivo não for encontrado
    }

    while (q != NULL)
    {
        printf("%s ", q->nome);
        q = q->pai;
    }
}

int main()
{
    TipoRaiz arv;
    int N, i;
    char search[1025];
    char searchOriginal[1025];
    char command[2], file[1025], folder[1025];

    inicializar(&arv);

    scanf("%d", &N);
    scanf("%s", search);
    strcpy(searchOriginal, search);

    printf("%i\n", N);
    printf("%s\n", search);
    printf("%s\n", searchOriginal);

    /*
    -a -> add
    -m -> move
    -r -> remove
    */

    for (i = 0; i < N; i++)
    {
        scanf("%s", command);

        if (command[1] == 'a')
        {
            scanf("%s", file);
            scanf("%s", folder);
            TipoArvG *pai = buscar(arv.raiz, folder);
            if (pai != NULL)
                inserir(pai, file);
            // imprimir(pai);
        }

        else if (strcmp(command, "-m") == 0)
        {
            scanf("%s", file);
            scanf("%s", folder);
            TipoArvG *pai = buscar(arv.raiz, folder); // pai do arquivo
            if (pai == NULL)
            {
                // printf("Pai nao encontrado\n");
            }
            else
            {
                TipoArvG *no = buscar(arv.raiz, file);
                remover(no);
                inserir(pai, file);
                // imprimir(no);
            }
        }

        else if (strcmp(command, "-r") == 0)
        {
            scanf("%s", file);
            scanf("%s", folder);
            TipoArvG *no = buscar(arv.raiz, file);
            if (no != NULL)
                remover(no);
            // imprimir(no);
        }
    }

    // // printf("oi\n");
    // printf("%s \n", search);
    // printf("%s \n", searchOriginal);
    // printf("%s\n", file);

    // TipoArvG *b = buscar(arv.raiz, search);

    // if (b == NULL)
    //     printf("Arquivo nao encontrado!\n");
    // else {
    //     // printf("%s\n", b->nome);
    //     imprimir(b);
    // }
    // printf("tchau\n");

    printf("Arquivo nao encontrado!\n");

    return 0;
}