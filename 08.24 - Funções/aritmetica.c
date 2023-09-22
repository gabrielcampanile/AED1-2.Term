#include <stdio.h>

int main()
{
    int vetor[100], *p;

    for (int i = 0; i < 100; i++)
        vetor[i] = i * 2;

    for (int i = 0, p = vetor; i < 100; i++, p++)
        printf("%d: %i\n", i, *p);
        // *p => equivalente a acessar vetor[i]

    p = vetor + 10;
    printf("%d\n", *p);
    // *p => equivalente a acessar vetor[10]

    return 0;
}