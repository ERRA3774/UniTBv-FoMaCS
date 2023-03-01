// Problema 2
// Sa se verifice si sa se afiseze daca un vector este superior sau inferior
// Un vector este superior daca acesta contine mai multe elemente cu valoarea mai mare decat media aritmetica a intregului vector si inferior altfel. (1p)
// ??? vec = {1,9,9,9}, media = 7, vectorul contine 3 elemente mai mari ca 7 => superior?

#include <iostream>
#include <vector>
#include <algorithm>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void Problema2();
bool EsteSuperior(std::vector<int>& vec);

int main()
{
	Problema2();
}

void Problema2()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	EsteSuperior(vec)
		? std::cout << "Superior." << std::endl
		: std::cout << "Inferior." << std::endl;
}

bool EsteSuperior(std::vector<int>& vec)
{
	float media = 0;
	int contor = 0;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		media += *it;
	}

	media /= vec.size();

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it > media)
		{
			contor++;
		}
	}

	return contor > media;
}
