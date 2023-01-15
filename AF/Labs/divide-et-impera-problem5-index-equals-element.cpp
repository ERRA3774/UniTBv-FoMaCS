// Se da un sir de n elemente. Sirul este sortat descrescator si are elementele distincte.
// Se doreste identificarea urmatoarei situatii:
// Exista un index i pentru care a[i] = i.
// Sa se elaboreze un algoritm D&I cu complexitate O(log n)

#include <iostream>
#include <vector>
#include <algorithm>

void print_other_test_cases();

int solutie_iterativ(std::vector<int>& vec)
{
	int st = 0;
	int dr = vec.size() - 1;

	while (st <= dr)
	{
		int mij = (st + dr) / 2;
		if (vec[mij] == mij)
		{
			return mij;
		}
		else if (vec[mij] > mij)
		{
			dr = mij - 1;
		}
		else
		{
			st = mij + 1;
		}
	}

	return -1;
}

int solutie_recursiv(std::vector<int>& vec, int st, int dr)
{
	if (st > dr)
	{
		return -1;
	}

	int mij = (st + dr) / 2;
	if (vec[mij] == mij)
	{
		return mij;
	}
	else if (vec[mij] > mij)
	{
		return solutie_recursiv(vec, st, mij - 1);
	}
	else
	{
		return solutie_recursiv(vec, mij + 1, dr);
	}
}

void citire_vector(std::vector<int>& vec)
{
	int n;

	std::cout << "Introduceti numarul de elemente:\nn = ";
	std::cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), std::greater<int>()); // reverse
}

void afisare_vector(std::vector<int>& vec)
{
	for (auto i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;
}

void afisare_solutie_iterativ(std::vector<int>& vec)
{
	int sol = solutie_iterativ(vec);

	if (sol == -1) {
		std::cout << "Nu avem solutie." << std::endl;
	}
	else {
		std::cout << "Solutie gasita la index: " << sol << std::endl;
	}
}

void afisare_solutie_recursiv(std::vector<int>& vec)
{
	int sol = solutie_recursiv(vec, 0, vec.size() - 1);

	if (sol == -1) {
		std::cout << "Nu avem solutie." << std::endl;
	}
	else {
		std::cout << "Solutie gasita la index: " << sol << std::endl;
	}
}

int main()
{
	print_other_test_cases();

	std::vector<int> vec;
	citire_vector(vec);
	afisare_vector(vec);
	afisare_solutie_iterativ(vec);

	return 0;
}

void print_other_test_cases()
{
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6};
	sort(vec.begin(), vec.end(), std::greater<int>());
	afisare_vector(vec);
	afisare_solutie_iterativ(vec);
	afisare_solutie_recursiv(vec);

	std::vector<int> vec1 = { 9, 7, 4, 3, 1, 2, 0 };
	sort(vec1.begin(), vec1.end(), std::greater<int>());
	afisare_vector(vec1);
	afisare_solutie_iterativ(vec1);
	afisare_solutie_recursiv(vec1);

	std::vector<int> vec2 = {33,23,67,95,59,19,15,7,0,1,2,3,4,5,6  };
	sort(vec2.begin(), vec2.end(), std::greater<int>());
	afisare_vector(vec2);
	afisare_solutie_iterativ(vec2);
	afisare_solutie_recursiv(vec2);

	std::cout << std::endl;
}
