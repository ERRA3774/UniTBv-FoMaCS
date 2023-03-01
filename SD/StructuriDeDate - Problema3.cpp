// Problema 3
// Se considera un vector cu *nr* elemente numere naturale din intervalul [30, 80]
// Sa se determine si sa se afiseze elementul care apare de cele mai multe ori. (1p)

#include <iostream>
#include <vector>
#include <algorithm>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void Problema3();
int ElementMaxAparitii(std::vector<int>& vec);

int main()
{
	Problema3();
}

void Problema3()
{
	std::vector<int> vec{ 31, 79, 35, 33, 33, 35, 79, 35, 35, 79, 35, 33, 33, 35, 33, 31, 31, 79, 79 };
	int rezultat = ElementMaxAparitii(vec);

	rezultat != -1
		? std::cout << "Elementul cu cele mai multe aparitii este " << rezultat << std::endl
		: std::cout << "Vectorul nu are elemente." << std::endl;
}

int ElementMaxAparitii(std::vector<int>& vec)
{
	if (vec.size() == 0)
	{
		return -1;
	}

	if (vec.size() == 1)
	{
		return vec.at(0);
	}

	sort(vec.begin(), vec.end());
	int numarMaxAparitii = 0;
	int contor = 1;

	int i = 0;
	while (i < vec.size() - 1)
	{
		if (vec.at(i) == vec.at(i + 1))
		{
			contor++;
		}
		else
		{
			numarMaxAparitii = vec.at(i);
			contor = 1;
		}
		i++;
	}

	return numarMaxAparitii;
}
