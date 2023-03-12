// Sa se afiseze elementul minimul dintr-un vector folosind o functie template
#include <iostream>

template <class T>
T minim(T* vec, int n)
{
	T min = vec[0];

	for (int i = 1; i < n; i++)
	{
		if (vec[i] < min)
		{
			min = vec[i];
		}
	}

	return min;
};

int main()
{
	int* vec1 = new int[5] {9, 8, 1, 2, 3};
	double* vec2 = new double[5] {9.5, 8.6, 1.7, 2.8, 3.9};
	float* vec3 = new float[5] {3.2f, 5.4f, 2.1f, 4.3f, 6.5f};
	char* vec4 = new char[5] {'m', 'e', 't', 'a', 'L'};

	std::cout << minim(vec1, 5) << std::endl;
	std::cout << minim(vec2, 5) << std::endl;
	std::cout << minim(vec3, 5) << std::endl;
	std::cout << minim(vec4, 5) << std::endl;
}
