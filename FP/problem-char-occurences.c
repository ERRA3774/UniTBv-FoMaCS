#include <stdio.h>
#include <string.h>
#include <malloc.h>

int getNrAparitii(char *s, char c);

int *getAparitii(char *s, char c)
{
    int *a;
    char *p;

    int nr = getNrAparitii(s, c);

    a = (int *)malloc(nr * sizeof(int));
    if (a == NULL)
    {
        perror("Memorie insuficienta!");
        return NULL;
    }

    // calcul  de scos in metoda int* getAparitii(char *s, char c)
    int i = 0;
    p = strchr(s, c);
    while (p != NULL)
    {
        a[i++] = p - s + 1;
        p = strchr(++p, c);
    }

    return a;
}

int main()
{
    // declarare variabile
    int n;
    char *s;
    char c;
    int *a; // Aparitiile lui a in Mariana a[0]=1; a[1]=4; a[2]=6;

    // citire date de intrare 1
    printf("Introduceti litera:");
    scanf("%c", &c);

    printf("Numarul de caractere al cuvantului:");
    scanf("%d", &n);

    // alocare memorie
    s = (char *)malloc(n * sizeof(char));
    if (s == NULL)
    {
        perror("Memorie insuficienta!");
        return 1;
    }

    // citire date de intrare 2
    printf("Introduceti sirul de caractere:");
    scanf("%s", s);

    // calcul
    a = getAparitii(s, c);

    if (a == NULL)
    {
        perror("Memorie insuficienta!");
        return 1;
    }

    // afisare rezultat
    printf("Aparitiile literei %c in %s sunt ", c, s);
    printf("pe pozitiile: ");

    for (int i = 0; i < getNrAparitii(s, c); i++)
    {
        printf("%d ", a[i]);
    }

    // eliberare memorie
    // free(s);
    // free(a);
    return 0;
}

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