#include <stdio.h>
#include <string.h>
#include <malloc.h>

int getNrAparitii(char *s, char c)
{
    int nr = 0;

    while (strchr(s, c) != NULL)
    {
        s = strchr(s, c) + 1;
        nr++;
    }

    return nr;
}

int main()

{
    // declarare variabile
    int n;
    char *s;
    char c;
    int nr;

    // citire date de intrare 1
    printf("Introduceti litera:");
    scanf("%c", &c);

    // printf("Numarul de caractere al cuvantului:");

    // scanf("%d", &n);

    n = 10;

    // alocare memorie
    s = (char *)malloc(n * sizeof(char));

    // verificare alocare
    if (s == NULL)
    {
        perror("Memorie insuficienta!");
        return 1;
    }

    // citire date de intrare 2
    printf("Introduceti sirul de caractere:");
    scanf("%s", s);

    // calcul
    nr = getNrAparitii(s, c);

    // afisare rezultat
    printf("Numarul de aparitii ale literei %c in %s este %d", c, s, nr);

    // eliberare memorie
    free(s);

    return 0;
}