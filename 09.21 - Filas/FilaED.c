// Fila - Lista Encadeada Dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

typedef struct {
    int chave;
    char nome[51];
}TipoItem;

typedef struct {
    TipoItem *inicio, *fim;
}TipoFilaD;