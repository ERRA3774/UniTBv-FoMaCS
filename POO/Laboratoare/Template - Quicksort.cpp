// Sa se implementeze un algoritm de sortare folosind functii template
#include <iostream>

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
int partitionare(T vec[], int st, int dr)
{
	T piv = vec[dr];
	int poz = st - 1;

	for (int i = st; i < dr; i++)
	{
		if (piv >= vec[i])
		{
			swap(vec[++poz], vec[i]);
		}
	}
	swap(vec[poz + 1], vec[dr]);

	return poz + 1;
}

template <class T>
void quicksort(T vec[], int st, int dr)
{
	if (st < dr)
	{
		int piv = partitionare(vec, st, dr);
		quicksort(vec, st, piv - 1);
		quicksort(vec, piv + 1, dr);
	}
}

template <class T>
void afisare(T vec[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int	n = 10;
	int* vec1 = new int[n] { 3, 4, 0, 7, 8, 9, 2, 1, 6, 5 };
	float* vec2 = new float[n] { 3.1f, 4.2f, 0.3f, 7.4f, 8.5f, 9.6f, 2.7f, 1.8f, 6.9f, 5.0f };
	double* vec3 = new double[n] { 3.19, 4.28, 0.37, 7.46, 8.55, 9.64, 2.73, 1.82, 6.91, 5.00 };
	char* vec4 = new char[n] {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};

	quicksort(vec1, 0, n - 1);
	quicksort(vec2, 0, n - 1);
	quicksort(vec3, 0, n - 1);
	quicksort(vec4, 0, n - 1);

	afisare(vec1, n);
	afisare(vec2, n);
	afisare(vec3, n);
	afisare(vec4, n);

	delete[] vec1;
	delete[] vec2;
	delete[] vec3;
	delete[] vec4;
}