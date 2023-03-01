// Problema 5
// Un numar de baza b este retinut intr-un std::pair<int, int> ce contine valoarea si baza de numeratie in care acesta este reprezentat
// Se citesc mai multe astfel de numere reprezentate in baze diferite.
// Sa se determine perechile de valori egale (1.5p)
// Exemplu: pair1.first = 10, pair1.second = 8 pair2.first = 2 pair2.second = 1000 -> pair1 == pair2

#include <iostream>
#include <vector>
#include <algorithm>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void Problema5();
std::pair<int, int> CitestePereche();
int SchimbaInZecimal(int b, int nr);
void AfiseazaVectorPerechi(std::vector<std::pair<int, int>>& vec);

int main()
{
	Problema5();
}

void Problema5()
{
	std::vector<std::pair<int, int>> vecPer;
	std::vector<std::pair<int, int>> vecPerEgale;
	int n;
	std::cout << "n = ";
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		vecPer.push_back(CitestePereche());
	}

	while (vecPer.size() > 0)
	{
		vecPerEgale.push_back(vecPer[0]);
		vecPer.erase(vecPer.begin());
		int i = 0;
		while (i < vecPer.size())
		{
			if (SchimbaInZecimal(vecPerEgale[0].first, vecPerEgale[0].second) == SchimbaInZecimal(vecPer[i].first, vecPer[i].second))
			{
				vecPerEgale.push_back(vecPer[i]);
				vecPer.erase(vecPer.begin() + i);
			}
			else
			{
				i++;
			}
		}
		AfiseazaVectorPerechi(vecPerEgale);
		vecPerEgale.clear();
	}
}

std::pair<int, int> CitestePereche()
{
	std::pair<int, int> per;
	bool esteValid;

	std::cout << "Introduceti baza si numarul: " << std::endl;
	std::cout << "b = ";
	std::cin >> per.first;

	do
	{
		esteValid = true;
		std::cout << "nr = ";
		std::cin >> per.second;
		int temp = per.second;

		while (temp > 0)
		{
			if (temp % 10 >= per.first)
			{
				esteValid = false;
			}
			temp /= 10;
		}

		if (!esteValid)
		{
			std::cout << "[\\E] Numarul nu este in baza " << per.first << std::endl;
		}

	} while (!esteValid);

	return per;
}

void AfiseazaVectorPerechi(std::vector<std::pair<int, int>>& vec)
{
	if (vec.size() == 0)
	{
		std::cout << "Vectorul nu are elemente." << std::endl;
	}

	if (vec.size() == 1)
	{
		std::cout << "(Baza " << vec[0].first << ") " << vec[0].second << " nu are pereche." << std::endl;
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << "(Baza " << vec[i].first << ") " << vec[i].second;
			if (i < vec.size() - 1)
			{
				std::cout << " = ";
			}
		}
		std::cout << std::endl;
	}
}

int SchimbaInZecimal(int baza, int nr)
{
	if (baza == 0)
	{
		return nr;
	}

	int exp = 0;
	int nrZecimal = 0;

	while (nr > 0)
	{
		nrZecimal += (nr % 10 * pow(baza, exp));
		nr /= 10;
		exp++;
	}

	return nrZecimal;
}
