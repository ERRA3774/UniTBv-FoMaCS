// Problema 4
// Se considera un vector V cu *nr* elemente numere naturale.
// Sa se construiasca un al doilea vector W, care contine fiecare element din V, care are in componenta doar cifre impare, duplicandu-le (1p)
// Exemplu: V = [1, 2, 5, 13, 27, 3, 57] -> W = [1, 1, 5, 5, 13, 13, 3, 3, 57, 57]

#include <iostream>
#include <vector>
#include <algorithm>

void problema4();
bool areCifreImpare(int x);
std::vector<int> vectorNumereleImpareDublate(std::vector<int>& V);
void afiseazaVector(std::vector<int>& vec);

int main()
{
	problema4();
}

void problema4()
{
	std::vector<int> V{ 1,2,5,13,27,3,57 };

	V = vectorNumereleImpareDublate(V);

	afiseazaVector(V);
}

bool areCifreImpare(int x)
{
	while (x > 10)
	{
		if (x % 2 == 0)
		{
			return false;
		}
		x /= 10;
	}

	return x % 2 == 1;
}

std::vector<int> vectorNumereleImpareDublate(std::vector<int>& V)
{
	std::vector<int> W{};

	for (std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
	{
		if (areCifreImpare(*it))
		{
			W.insert(W.end(), 2, *it);
		}
	}

	return W;
}

void afiseazaVector(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
