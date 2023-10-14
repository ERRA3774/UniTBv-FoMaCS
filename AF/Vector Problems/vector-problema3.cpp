// Se citeste un numar natural n si cele n elemente alea unui vector.
// Sa se insereze in vector intre oricare doua valori vecine suma si produsul acestora
// Obs: Determinarea sumei si a produsului a doua numere se va realiza in cadrul unei singure functii

#include <iostream>
#include <vector>

void citire_vector(std::vector<int>& vec);
int validare_pozitie(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
std::pair<int, int> pereche_suma_produs(int a, int b);
void insereaza_pereche(std::vector<int>& vec);
void print_other_test_cases();

int main()
{
	print_other_test_cases();

	int poz;
	std::vector<int>vec;
	citire_vector(vec);
	insereaza_pereche(vec);
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

std::pair<int, int> pereche_suma_produs(int a, int b)
{
	std::pair<int, int> p;
	p.first = a + b;
	p.second = a * b;
	return p;
}

int validare_pozitie(std::vector<int>& vec)
{
	int poz;

	do {
		std::cout << "Introduceti un numar natural mai mic ca " << vec.size() - 1 << ".\npoz = ";
		std::cin >> poz;

		if (poz < 0 || poz >= vec.size() - 1)
		{
			std::cout << "Error: Index invalid." << std::endl;
		}
	} while (poz < 0 || poz >= vec.size() - 1);

	return poz;
}

void insereaza_pereche(std::vector<int>& vec)
{
	int poz = validare_pozitie(vec);
	int sum = pereche_suma_produs(vec[poz], vec[poz + 1]).first;
	int prod = pereche_suma_produs(vec[poz], vec[poz + 1]).second;

	std::cout << "Am inserat intre " << vec[poz] << " si " << vec[poz + 1] << ", suma = " << sum << " si produsul = " << prod << std::endl;

	vec.insert(vec.begin() + poz + 1, { sum, prod });
}

void insereaza_pereche(std::vector<int>& vec, int poz)
{
	int sum = pereche_suma_produs(vec[poz], vec[poz + 1]).first;
	int prod = pereche_suma_produs(vec[poz], vec[poz + 1]).second;
	std::cout << "Am inserat intre " << vec[poz] << " si " << vec[poz + 1] << ", suma = " << sum << " si produsul = " << prod << std::endl;
	vec.insert(vec.begin() + poz + 1, { sum, prod });
}

void print_other_test_cases()
{
	std::vector<int>vec0{ 1, 4, 5, 22, 33, 2, 11, 89, 49 };
	insereaza_pereche(vec0, 0);
	afisare_vector(vec0);

	insereaza_pereche(vec0, 2);
	afisare_vector(vec0);

	insereaza_pereche(vec0, 3);
	afisare_vector(vec0);

	insereaza_pereche(vec0, 4);
	afisare_vector(vec0);

	insereaza_pereche(vec0, 15);
	afisare_vector(vec0);

}
