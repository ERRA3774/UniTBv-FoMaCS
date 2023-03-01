// Problema 4
// Se considera un vector V cu *nr* elemente numere naturale.
// Sa se construiasca un al doilea vector W, care contine fiecare element din V, care are in componenta doar cifre impare, duplicandu-le (1p)
// Exemplu: V = [1, 2, 5, 13, 27, 3, 57] -> W = [1, 1, 5, 5, 13, 13, 3, 3, 57, 57]

#include <iostream>
#include <vector>
#include <algorithm>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void Problema4();
bool AreCifreImpare(int x);
std::vector<int> VectorNumereleImpareDublate(std::vector<int>& V);
void AfiseazaVector(std::vector<int>& vec);

int main()
{
	Problema4();
}

void Problema4()
{
	std::vector<int> V{ 1,2,5,13,27,3,57 };

	V = VectorNumereleImpareDublate(V);

	AfiseazaVector(V);
}

bool AreCifreImpare(int x)
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

std::vector<int> VectorNumereleImpareDublate(std::vector<int>& V)
{
	std::vector<int> W{};

	for (std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
	{
		if (AreCifreImpare(*it))
		{
			W.insert(W.end(), 2, *it);
		}
	}

	return W;
}

void AfiseazaVector(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
