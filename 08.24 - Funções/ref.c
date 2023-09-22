#include <stdio.h>

int multiplica(int x, int y){
    return x * y;
}

void incrementa (int *x){
    (*x)++;
}

int main(){
    int x=10, y=20;

    printf("%i\n", multiplica(x, y));

    incrementa(&x);

    printf("%i\n", x);

    return 0;
}