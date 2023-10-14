#include "Citiri_afisari.h"
#include <iostream>

void citire_vect(int& dim, int vect[])
{
	std::cin >> dim;
	for (int i = 0; i < dim; i++) {
		std::cin >> vect[i];
	}
}

void afisare_vect(int dim, int vect[])
{
	for (int i = 0; i < dim; i++)
		std::cout << vect[i] << " ";
	std::cout << "\n";
}

void citire_vector(int& dim, int*& vect)
{
	std::cin >> dim;
	if (vect != nullptr)
		delete[] vect;
	vect = new int[dim];//aici se modifica adresa
	for (int i = 0; i < dim; i++) 
	{
		std::cin >> vect[i];
	}

}

void afisare_vector(int dim, int* vect)
{
	for (int i = 0; i < dim; i++)
		std::cout << vect[i] << " ";
	std::cout << "\n";
}

void citire_vect(std::vector<int>& vect)
{
	int dim;
	std::cin >> dim;
	vect.resize(dim);
	for (int i = 0; i < vect.size(); i++)
	{
		std::cin >> vect[i];
	}
}

/*void citire_vect(std::vector<int>& vect); {
	int dim;
	std::cin >> dim;
	vect.clear();
	int x;
	for (int i = 0; i < dim; i++)
	{
		std::cin >> x;
		vect.push_back(x);
	}
}*/


void afisare_vect(std::vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n";
}
