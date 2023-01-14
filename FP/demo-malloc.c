#include <stdio.h>
#include <malloc.h> // malloc, calloc, realloc - toare returneaza void*

int maxim(int *, int);

int main()
{
    // declarare variabilelor
    int *a;
    int n, max = 0;

    // citire date de intrare 1 (n)
    printf("n = ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Numarul elementelor trebuie sa fie cel putin 1");
        return 1;
    }

    // alocare memorie
    a = (int *)malloc(n * sizeof(int));

    // verificare alocare
    if (a == NULL)
    {
        perror("Nu s-a putut aloca memorie. Memorie insuficienta!");
        return 1; // exit(1);
    }

    // citire date de intrare 2 (elem)
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // calcul
    max = maxim(a, n);

    // afisare rezultat
    printf("Numerele sunt: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
    }

    printf("\nMaximul este: %d", max);

    // eliberare memorie
    free(a);

    return 0;
}

int maxim(int *v, int n)
{
    int max = v[0];

    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    return max;
}