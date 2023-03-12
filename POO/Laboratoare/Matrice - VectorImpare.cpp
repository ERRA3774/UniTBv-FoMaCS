// Sa se scrie o functie de tip void care primeste printre parametri o matrice de int m * n. 
// Functia va construi un vector format numai cu elementele impare ale matricei si va returna acest vector impreuna cu lungimea lui. 
// Se foloseste alocare dinamica. 

#include <iostream>
void impare(int** mat, int& m, int& n, int& k, int*& vec)
{
	k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] % 2 == 1)
			{
				k++;
			}
		}
	}

	vec = new int[k];
	k = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] % 2 == 1)
			{
				vec[k++] = mat[i][j];
			}
		}
	}
}

int main()
{
	int m, n;
	std::cout << "m = ";
	std::cin >> m;
	std::cout << "n = ";
	std::cin >> n;

	int** mat = new int* [m];

	std::cout << "Citire matrice:" << std::endl;
	for (int i = 0; i < m; i++)
	{
		mat[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> mat[i][j];
		}
	}

	int k;
	int* vec;

	impare(mat, m, n, k, vec);

	std::cout << k << std::endl;

	for (int i = 0; i < k; i++)
	{
		std::cout << vec[i] << " ";
	}

	delete[] vec;

	for (int i = 0; i < m; i++)
	{
		delete mat[i];
	}

	delete[] mat;

	return 0;
}