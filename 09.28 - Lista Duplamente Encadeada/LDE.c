#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
	int num;
 	struct TipoItem *ant,*prox;
}TipoItem;

typedef struct{
	TipoItem *inicio,*fim; 
}TipoListaDE;

void inicializarListaDE(TipoListaDE *lista){
    lista->inicio = NULL;
    lista->fim    = NULL;
}

void imprimirListaDE(TipoListaDE *lista){
    TipoItem *p=lista->inicio;
    while(p!=NULL){
        printf("%d\n",p->num);
        p=p->prox;
    }
}

void insereOrdenadoListaDE(TipoListaDE *lista, TipoItem novo){
	TipoItem *novoItemPtr;
	TipoItem *p1 = lista->inicio;
	TipoItem *p2 = NULL; //aponta para item anterior
	novoItemPtr = (TipoItem *) malloc(sizeof(TipoItem));
	if(novoItemPtr == NULL) exit(1); //verifica alocacao
	*novoItemPtr = novo;
	if(p1==NULL){ //Lista vazia
		lista->inicio = novoItemPtr;
		lista->fim    = novoItemPtr;
	}
	else{
		while(p1!=NULL && p1->num <= novo.num){
			p2 = p1;
			p1 = p1->prox;
		}		
		novoItemPtr->prox = p1; //insere depois de p2 e antes de p1
        novoItemPtr->ant  = p2;
		if(p1 == lista->inicio){ //antes do inicio
			p1->ant       = novoItemPtr;
			lista->inicio = novoItemPtr;
		}
		else if(p2 == lista->fim){ //apos o fim
            	p2->prox   = novoItemPtr;
		        lista->fim = novoItemPtr;
		}
		else{//p1 e p2 != NULL
	            p2->prox = novoItemPtr;
         	   p1->ant  = novoItemPtr;
		}
	}
}

void removeListaDE(TipoListaDE *lista, int num) {
    TipoItem *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->num == num) {
            if (atual == lista->inicio) {
                lista->inicio = atual->prox;
                if (lista->inicio != NULL) {
                    lista->inicio->ant = NULL;
                } else {
                    lista->fim = NULL;
                }
            } else if (atual == lista->fim) {
                lista->fim = atual->ant;
                if (lista->fim != NULL) {
                    lista->fim->prox = NULL;
                } else {
                    lista->inicio = NULL;
                }
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
            }
            free(atual);
            return;
        }
        atual = atual->prox;
    }
    printf("Elemento com valor %d não encontrado na lista.\n", num);
}

int main() {
    TipoListaDE lista;
    TipoItem novo;
    int opcao, num;

    inicializarListaDE(&lista);

    while (1) {
        printf("Menu:\n");
        printf("1. Inserir ordenado\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &novo.num);
                insereOrdenadoListaDE(&lista, novo);
                break;
            case 2:
                printf("Informe o valor a ser removido: ");
                scanf("%d", &num);
                removeListaDE(&lista, num);
                break;
            case 3:
                if (lista.inicio != NULL) {
                    printf("Elementos na lista:\n");
                    imprimirListaDE(&lista);
                } else {
                    printf("A lista está vazia.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
