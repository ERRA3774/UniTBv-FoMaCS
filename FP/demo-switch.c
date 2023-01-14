#include <stdio.h>

int main()
{
    int op;

    printf("Meniu:\n");

    do
    {
        printf("1: Salut\n2: Reincarcare cartela\n0: Exit\n");

        printf("Introduceti optiunea: ");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Hello!\n");
            break;
        case 2:
            printf("Cartela incarcata cu succes!\n");
            break;
        case 0:
            printf("La revedere!\n");
            break;
        default:
            printf("Comanda invalida. Va rugam reincercati.");
            break;
        }
    } while (!op);
}