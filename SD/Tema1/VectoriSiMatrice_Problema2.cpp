// Problema 2
// Sa se verifice si sa se afiseze daca un vector este superior sau inferior
// Un vector este superior daca acesta contine mai multe elemente cu valoarea mai mare decat media aritmetica a intregului vector si inferior altfel. (1p)

#include <iostream>
#include <vector>
#include <algorithm>
#define ASSERT(x,y) (x == y) ? std::cout << "Test Passed!" << std::endl : std::cout << "Test Failed!"<< std::endl;

void problema2();
bool esteSuperior(std::vector<int> vec);
void tests();

int main()
{
	tests();
}

void problema2()
{
	std::vector<int> vec{ 1,9,9,9,9 };

	esteSuperior(vec)
		? std::cout << "Superior." << std::endl
		: std::cout << "Inferior." << std::endl;
}

bool esteSuperior(std::vector<int> vec)
{
	float media = 0;
	int contorMici = 0;
	int contorMari = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		media += vec[i];
	}

	media = media / vec.size();

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > media)
		{
			contorMari++;
		}
		else
		{
			contorMici++;
		}
	}

	return contorMari > contorMici;
}

void tests()
{
	std::vector<int> vec0{1,9,9,9};
	ASSERT(esteSuperior(vec0), true);

	std::vector<int> vec1{ 1,2,3,4,5,6,7,8,9 };
	ASSERT(esteSuperior(vec1), false);
}
