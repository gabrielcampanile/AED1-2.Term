#include <stdio.h>
#include <stdlib.h>

int len(char *x, int l1) {
    int l=0;
    for(int i=0; i<l1; i++) {
        if(x[i]=='\0')
            return l;
        else
            l++;
    }
}

int main()
{
    int l1, l2, l3, letra = 0;
    char *x, *y, *z, c;

    scanf("%i %i %c", &l1, &l2, &c);

    x = malloc((l1 + 1) * sizeof(char));
    y = malloc((l2 + 1) * sizeof(char));

    scanf("%s %s", x, y);

    l1 = len(x, l1+1);
    l2 = len(y, l2+1);
    l3 = l1 + l2;
    z = malloc((l3 + 1) * sizeof(char));

    for (int i = 0; i < l1; i++)
    {
        z[i] = x[l1 - 1 - i];
    }
    for (int i = 0; i < l2; i++)
    {
        z[l1 + i] = y[l2 - 1 - i];
    }
    z[l3+1] = '\0';

    for (int i = 0; i < l3; i++)
    {
        if (z[i] == c)
            letra++;
    }

    printf("%s\n", z);
    printf("%i\n", l3);
    printf("%i\n", letra);

    free(x);
    free(y);
    free(z);

    return 0;
}
