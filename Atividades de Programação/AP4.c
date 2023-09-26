#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RPN {
    int elemento;
    struct RPN *prox;
} RPN;

typedef struct {
    RPN *topo;
} PilhaD;

void inicializaPilha(PilhaD *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(PilhaD *pilha) {
    if(pilha->topo == NULL)
        return 1;
    return 0;
}

void push(PilhaD *pilha, RPN novo) {
    RPN *aux = malloc(sizeof(RPN));
    aux->elemento = novo.elemento;
    aux->prox = pilha->topo;
    pilha->topo = aux;
}

RPN pop(PilhaD *pilha) {
    RPN aux;
    aux.elemento = pilha->topo->elemento;
    RPN *apagar;
    apagar = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(apagar);
    return aux;
}

void imprimePilha(PilhaD *pilha) {
    RPN p;
    p = pop(pilha);
    if(pilhaVazia(pilha))
        printf("%i\n", p.elemento);
    else
        printf("Invalid Expression");
}

int main() {
    PilhaD pilha;
    inicializaPilha(&pilha);

    char expression[1025];
    scanf("%s", expression);

    RPN element;
    int i, n, x, y;
    n = strlen(expression);
    
    for(i=0; i<n; i++) {
        // printf("%d\n", i);
        if(expression[i]<='9' && expression[i]>='0') {
            element.elemento = expression[i] - 48 ;
            // printf("%d\n", n);
            push(&pilha, element);
        }
        else if(expression[i]=='+') {
            if(pilhaVazia(&pilha)) {
                printf("Invalid Expression");
                return 0;
            }
            element = pop(&pilha);
            x = element.elemento;
            if(!pilhaVazia(&pilha)){
                element = pop(&pilha);
                y = element.elemento;
                element.elemento = y + x;
                // printf("%d\n", n);
                push(&pilha, element);
            }
            else {
                printf("Invalid Expression");
                return 0;
            }
        }
        else if(expression[i]=='-') {
            if(pilhaVazia(&pilha)) {
                printf("Invalid Expression");
                return 0;
            }
            element = pop(&pilha);
            x = element.elemento;
            if(!pilhaVazia(&pilha)){
                element = pop(&pilha);
                y = element.elemento;
                element.elemento = y - x;
                // printf("%d\n", n);
                push(&pilha, element);
            }
            else {
                printf("Invalid Expression");
                return 0;
            }
        }
        else if(expression[i]=='*') {
            if(pilhaVazia(&pilha)) {
                printf("Invalid Expression");
                return 0;
            }
            element = pop(&pilha);
            x = element.elemento;
            if(!pilhaVazia(&pilha)){
                element = pop(&pilha);
                y = element.elemento;
                element.elemento = y * x;
                // printf("%d\n", n);
                push(&pilha, element);
            }
            else {
                printf("Invalid Expression");
                return 0;
            }
        }
        else if(expression[i]=='/') {
            if(pilhaVazia(&pilha)) {
                printf("Invalid Expression");
                return 0;
            }
            element = pop(&pilha);
            x = element.elemento;
            if(!pilhaVazia(&pilha)){
                element = pop(&pilha);
                y = element.elemento;
                element.elemento = y / x;
                // printf("%d\n", n);
                push(&pilha, element);
            }
            else {
                printf("Invalid Expression");
                return 0;
            }
        }
    }
    imprimePilha(&pilha);
    
    return 0;
}