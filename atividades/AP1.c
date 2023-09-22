// Contagem de letras em strings

#include <stdio.h>
#include <string.h>

int main()
{
    char frase[256];
    int cont[27] = {0};

    fgets(frase, sizeof(frase), stdin);
    frase[strlen(frase) - 1] = '\0';

    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] <= 'z' && frase[i] >= 'a')
            frase[i] -= 32;

        if (frase[i] <= 'Z' && frase[i] >= 'A')
            cont[frase[i] - 65]++;
    }

    for (int i = 0; i < 26; i++)
        if (cont[i] > 0)
            printf("%c %i\n", i + 65, cont[i]);

    return 0;
}