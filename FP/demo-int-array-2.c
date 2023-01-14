#include <stdio.h>

int main()
{
	int a[10];

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	printf("Numerele sunt: ");

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d\n", a[i]);
	}
}