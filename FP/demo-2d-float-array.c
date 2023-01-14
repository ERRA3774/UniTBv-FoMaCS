#include <stdio.h>
#include <malloc.h>

// TODO - convert to matrix

float maxim(float**, int, int);

int main()
{
	// declarare variabilelor
	float** a;
	int n, m;
	float max = 0;

	// citire date de intrare 1 ( m si n )
	printf("Nr linii = ");
	scanf("%d", &m);

	printf("Nr coloane = ");
	scanf("%d", &n);

	if (m < 1 || n < 1)
	{
		printf("Numarul elementelor trebuie sa fie cel putin 1");
		return 1;
	}

	// alocare memorie
	a = (float**)malloc(m * sizeof(float*));

	// verificare alocare
	if (a == NULL)
	{
		perror("Nu s-a putut aloca memorie. Memorie insuficienta!");
		return 1; // exit(1);
	}

	// alocare memorie pe linii
	for (int i = 0; i < m; i++)
	{
		a[i] = (float*)malloc(n * sizeof(float));
	}

	// citire date de intrare 2 (elem)
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%.2f", &a[i][j]);
		}
	}

	// calcul

	max = maxim(a, m, n);

	// afisare rezultat

	printf("Numerele matricei sunt: \n");

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.2f ", a[i][j]);
		}
		printf('\n');
	}

	printf("\nMaximul este: %.2f", max);

	// eliberare memorie
	free(a);
	for (int i = 0; i < m; i++)
	{
		free(a[i]);
	}



	return 0;
}

float maxim(float** v, int m, int n)
{
	float max = v[0][0];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] > max)
			{
				max = v[i][j];
			}
		}
	}

	return max;
}