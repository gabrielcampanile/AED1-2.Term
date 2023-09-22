#include <stdio.h>

int main(){
    int x=10, y=20, *p;

    p = &y;
    x = x + *p;
    *p = x/2;
    p = &x;

    printf("%d %d %d\n", x, y, *p);

    return 0;
}