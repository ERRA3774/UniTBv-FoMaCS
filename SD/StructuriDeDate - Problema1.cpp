// Problema 1
// Numim perechea (x,y) pereche ordonata daca x < y
// a) Sa se verifice daca un vector contine doar perechi ordonate (care satisfac conditia de mai sus. (0.5p)
// !!! vec = {1,2,3,4}, se verifica {1,2}, {2,3}, {3,4}
// b) Sa se verifice daca oricare x din prima jumatate a vectorului formeaza o pereche ordonata cu oricare y din cea de-a doua jumatate. (1p)

#include <iostream>
#include <vector>
#include <algorithm>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void Problema1A();
bool ContineDoarPerechiOrdonate(std::vector<int>& vec);
void Problema1B();
bool FormeazaPerecheOrdonata(std::vector<int>& vec);

int main()
{
	Problema1A();
	Problema1B();
}

void Problema1A()
{
	std::vector<int> vec{ 0, 1, 4, 5, 8, 9, 12, 13, 16, 19 };

	ContineDoarPerechiOrdonate(vec)
		? std::cout << "Contine doar perechi ordonate." << std::endl
		: std::cout << "NU contine doar perechi ordonate." << std::endl;
}

bool ContineDoarPerechiOrdonate(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		LOG(vec[i], vec[i + 1]);
		if (vec[i] >= vec[i + 1])
		{
			return false;
		}
	}

	return true;
}

void Problema1B()
{
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 4 };

	FormeazaPerecheOrdonata(vec)
		? std::cout << "Oricare x si y formeaza perechi ordonate." << std::endl
		: std::cout << "Oricare x si y NU formeaza perechi ordonate." << std::endl;
}

bool FormeazaPerecheOrdonata(std::vector<int>& vec)
{
	int mij = vec.size() / 2;
	std::vector<int> vec1;
	std::vector<int> vec2;
	vec1.assign(vec.begin(), vec.begin() + mij);
	vec2.assign(vec.begin() + mij, vec.end());

	for (int i = 0; i < vec1.size(); i++)
	{
		for (int j = 0; j < vec2.size(); j++)
		{
			LOG(vec1[i], vec2[j]);
			if (vec1[i] >= vec2[j])
			{
				return false;
			}
		}
	}

	return true;
}
