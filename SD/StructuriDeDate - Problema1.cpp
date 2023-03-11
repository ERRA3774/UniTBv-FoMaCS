// Problema 1
// Numim perechea (x,y) pereche ordonata daca x < y
// a) Sa se verifice daca un vector contine doar perechi ordonate (care satisfac conditia de mai sus. (0.5p)
// !!! vec = {1,2,3,4}, se verifica {1,2}, {2,3}, {3,4}
// b) Sa se verifice daca oricare x din prima jumatate a vectorului formeaza o pereche ordonata cu oricare y din cea de-a doua jumatate. (1p)

#include <iostream>
#include <vector>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void problema1A();
bool contineDoarPerechiOrdonate(std::vector<int>& vec);
void problema1B();
bool formeazaPerecheOrdonata(std::vector<int>& vec);

int main()
{
	problema1A();
	problema1B();
}

void problema1A()
{
	std::vector<int> vec{ 0, 1, 4, 5, 8, 9, 12, 13, 16, 19 };

	contineDoarPerechiOrdonate(vec)
		? std::cout << "Contine doar perechi ordonate." << std::endl
		: std::cout << "NU contine doar perechi ordonate." << std::endl;
}

bool contineDoarPerechiOrdonate(std::vector<int>& vec)
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

void problema1B()
{
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 4 };

	formeazaPerecheOrdonata(vec)
		? std::cout << "Oricare x si y formeaza perechi ordonate." << std::endl
		: std::cout << "Oricare x si y NU formeaza perechi ordonate." << std::endl;
}

bool formeazaPerecheOrdonata(std::vector<int>& vec)
{
	int mij = vec.size() / 2;

	for (int i = 0; i < mij; i++)
	{
		for (int j = mij; j < vec.size(); j++)
		{
			LOG(vec[i], vec[j]);
			if (vec[i] >= vec[j])
			{
				return false;
			}
		}
	}

	return true;
}
