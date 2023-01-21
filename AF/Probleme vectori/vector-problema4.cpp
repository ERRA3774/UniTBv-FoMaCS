// Se citesc doua numere naturale n si k, si cele n elemente ale unui vector
// Sa se deplaseze spre dreapta elementele vectorilor cu k-pozitii
// Primele k elemente ale vectorului vor fi 
// a) zero-izate iar dimensiunea vectorului va creste cu k elemente
// EX: v = [1,2,3,4,5,6,7], k = 3, afisare: [0,0,0,1,2,3,4,5,6,7]
// b) inlocuieste cu ultimele k elemente din vector astfel dimensiunea vectorului nu va suferi modificari
// EX: v = [1,2,3,4,5,6,7], k = 3, afisare: [5,6,7,1,2,3,4]
//

#include <iostream>
#include <vector>

void citire_vector(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
int citire_k();
void shift_dreapta(std::vector<int>& vec);
void shift_dreapta(std::vector<int>& vec, int k);
void cycle_dreapta(std::vector<int>& vec);
void cycle_dreapta(std::vector<int>& vec, int k);
void print_tests();

int main()
{
	print_tests();

	std::vector<int> vec;
	citire_vector(vec);
	shift_dreapta(vec);
	afisare_vector(vec);
	cycle_dreapta(vec);
	afisare_vector(vec);
}

void citire_vector(std::vector<int>& vec)
{
	int n;
	std::cout << "Introduceti un numar natural.\nn = ";
	std::cin >> n;

	vec.resize(n);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cin >> vec[i];
	}
}

void afisare_vector(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int citire_k()
{
	int k;

	std::cout << "Introduceti un numar natural.\nk = ";
	std::cin >> k;

	return k;
}

void shift_dreapta(std::vector<int>& vec)
{
	int k = citire_k();

	vec.resize(vec.size() + k);

	for (int i = 0; i < k; i++)
	{
		vec.insert(vec.begin(), 0);
		vec.pop_back();
	}
}

void shift_dreapta(std::vector<int>& vec, int k)
{
	vec.resize(vec.size() + k);

	for (int i = 0; i < k; i++)
	{
		vec.insert(vec.begin(), 0);
		vec.pop_back();
	}
}

void cycle_dreapta(std::vector<int>& vec)
{
	int k = citire_k();
	int poz = vec.size() - 1;

	if (k >= vec.size())
	{
		k = k % vec.size();
	}

	for (int i = 0; i < k; i++)
	{
		vec.insert(vec.begin(), vec[poz]);
		vec.pop_back();
	}
}

void cycle_dreapta(std::vector<int>& vec, int k)
{
	int poz = vec.size() - 1;

	if (k >= vec.size())
	{
		k = k % vec.size();
	}

	for (int i = 0; i < k; i++)
	{
		vec.insert(vec.begin(), vec[poz]);
		vec.pop_back();
	}
}

void print_tests()
{
	std::vector<int> vec0{ 1,2,3,4,5,6,7 };
	shift_dreapta(vec0, 3);
	afisare_vector(vec0);

	std::vector<int> vec1{ 12, 34, 56};
	shift_dreapta(vec1, 5);
	afisare_vector(vec1);

	std::vector<int> vec2{ 1,2,3,4,5,6,7 };
	cycle_dreapta(vec2, 3);
	afisare_vector(vec2);

	std::vector<int> vec3{ 4,5,6,7,8,9 };
	cycle_dreapta(vec3, 123);
	afisare_vector(vec3);
}
