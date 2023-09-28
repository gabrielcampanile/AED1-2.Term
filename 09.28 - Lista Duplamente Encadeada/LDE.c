#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
	int num;
 	struct TipoItem *ant,*prox;
}TipoItem;

typedef struct{
	TipoItem *inicio,*fim; 
}TipoListaDE;
