#include <stdio.h>
#include <malloc.h>

int nrNegative(float **a, int m, int n);

int main()
{
    // declarare variabile
    int m, n;
    float **a;
    int nr;

    // citire 1
    printf("Introduceti numarul de linii si coloane:");
    scanf("%d%d", &m, &n);

    // alocare memorie 1
    a = (float **)malloc(m * sizeof(float *));
    if (a == NULL)
    {
        perror("Memorie insuficienta!");
        return 1;
    }

    // alocare memorie 2
    for (int i = 0; i < m; i++)
    {
        a[i] = (float *)malloc(n * sizeof(float));

        if (a[i] == NULL)
        {
            perror("Memorie insuficienta!");
            return 1;
        }
    }

    // citire 2-elementele matricii
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // calcul
    nr = nrNegative(a, m, n);

    // afisare rezultat
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }

    printf("Dintre element(e), %d sunt negative.", nr);

    // eliberare memorie
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}

int nrNegative(float **a, int m, int n)
{
    int nr = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 0)
                nr++;
        }
    }
    return nr;
}