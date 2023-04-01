// Problema 1
// Numim perechea (x,y) pereche ordonata daca x < y
// a) Sa se verifice daca un vector contine doar perechi ordonate (care satisfac conditia de mai sus. (0.5p)
// b) Sa se verifice daca oricare x din prima jumatate a vectorului formeaza o pereche ordonata cu oricare y din cea de-a doua jumatate. (1p)

#include <iostream>
#include <vector>
#include <algorithm>

void problema1A();
bool contineDoarPerechiOrdonate(std::vector<int>& vec);
void problema1B();
bool formeazaPerecheOrdonata(std::vector<int>& vec);
void tests();
#define ASSERT(x,y) (x == y) ? std::cout << "Test Passed!" << std::endl : std::cout << "Test Failed!"<< std::endl;

int main()
{
	tests();
}

void problema1A()
{
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	contineDoarPerechiOrdonate(vec)
		? std::cout << "Contine doar perechi ordonate." << std::endl
		: std::cout << "NU contine doar perechi ordonate." << std::endl;
}

void problema1B()
{
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 4 };

	formeazaPerecheOrdonata(vec)
		? std::cout << "Oricare x si y formeaza perechi ordonate." << std::endl
		: std::cout << "Oricare x si y NU formeaza perechi ordonate." << std::endl;
}

bool contineDoarPerechiOrdonate(std::vector<int>& vec)
{
	if (vec.size() == 0)
	{
		return false;
	}

	for (int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] >= vec[i + 1])
		{
			return false;
		}
	}

	return true;
}

bool formeazaPerecheOrdonata(std::vector<int>& vec)
{
	if (vec.size() == 0)
	{
		return false;
	}

	int mij = vec.size() / 2;

	for (int i = 0; i < mij; i++)
	{
		for (int j = mij; j < vec.size(); j++)
		{
			if (vec[i] >= vec[j])
			{
				return false;
			}
		}
	}

	return true;
}

void tests()
{
	std::vector<int> vec0{ 1,2,3,4,5,6,7,8,9 };
	ASSERT(formeazaPerecheOrdonata(vec0), true);
	ASSERT(contineDoarPerechiOrdonate(vec0), true);

	std::vector<int> vec1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 4 };
	ASSERT(formeazaPerecheOrdonata(vec1), false);
	ASSERT(contineDoarPerechiOrdonate(vec1), false);

	std::vector<int> vec2{ 9,8,7,6,5,4,1,2,3 };
	ASSERT(formeazaPerecheOrdonata(vec2), false);
	ASSERT(contineDoarPerechiOrdonate(vec2), false);

	std::vector<int> vec3{ 1,1,1,1,1,1,1,1};
	ASSERT(formeazaPerecheOrdonata(vec3), false);
	ASSERT(formeazaPerecheOrdonata(vec3), false);

	std::vector<int> vec4;
	ASSERT(formeazaPerecheOrdonata(vec4), false);
	ASSERT(formeazaPerecheOrdonata(vec4), false);
}
