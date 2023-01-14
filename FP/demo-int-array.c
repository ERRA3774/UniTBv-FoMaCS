#include <stdio.h>

int main()
{
    int a[10];                      // declarare variabilelor
    int n;

    n = 10;                         // citire date de intrare 1 (n)

    for (int i = 0; i < n; i++)     // citire date de intrare 2 (elem)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)     // afisare rezultat
    {
        printf("%d ", i);
    }

    return 0;
}