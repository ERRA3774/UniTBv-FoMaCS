#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Obiect
{
	float greutate, pret, procent_obiect;
};

std::vector<Obiect> citire_ob(std::string nume_fisier)
{
	int n;
	std::vector<Obiect> obiecte;
	std::ifstream fisier_intrare(nume_fisier);
	fisier_intrare >> n;
	obiecte.resize(n);
	for (int i = 0; i < n; i++)
	{
		fisier_intrare >> obiecte[i].greutate >> obiecte[i].pret;
		obiecte[i].procent_obiect = 100; // obiectele sunt intregi
	}
	return obiecte;
}

// 10/200 == 20/400
bool comparator_pret_unitate(Obiect o1, Obiect o2)
{
	if (o1.pret / o1.greutate > o2.pret / o2.greutate)
	{
		return true;
	}

	if (o1.pret / o1.greutate == o2.pret / o2.greutate)
	{
		return o1.greutate > o2.greutate;
	}

	return false;
}

std::vector<Obiect> umplere_rucsac_discret(std::vector<Obiect> obiecte, float greutate_rucsac)
{
	std::sort(obiecte.begin(), obiecte.end(), comparator_pret_unitate);

	std::vector<Obiect> sol;

	int i = 0;
	float profit = 0;
	while (greutate_rucsac && i < obiecte.size())
	{
		if (obiecte[i].greutate <= greutate_rucsac) // daca obiectul curent mai incape in rucsac
		{
			sol.push_back(obiecte[i]); // adaug obiectul curent la solutie
			greutate_rucsac -= obiecte[i].greutate;
			profit += obiecte[i].pret;
		}
		i++;
	}
	std::cout << "Profit: " << profit << std::endl;
	return sol;
}

std::vector<Obiect> umplere_rucsac_continuu(std::vector<Obiect> obiecte, float greutate_rucsac)
{
	std::sort(obiecte.begin(), obiecte.end(), comparator_pret_unitate);

	std::vector<Obiect> sol;

	int i = 0;
	float profit = 0;
	while (greutate_rucsac && i < obiecte.size())
	{
		if (obiecte[i].greutate <= greutate_rucsac) // daca obiectul curent mai incape in rucsac
		{
			sol.push_back(obiecte[i]); // adaug obiectul curent la solutie
			greutate_rucsac -= obiecte[i].greutate;
			profit += obiecte[i].pret;
		}
		else
		{
			float procent = greutate_rucsac * 100 / obiecte[i].greutate;
			profit += procent / 100 * obiecte[i].pret;
			obiecte[i].procent_obiect = procent;
			sol.push_back(obiecte[i]);
			greutate_rucsac -= (procent / 100) * obiecte[i].greutate; // greutate = 0;
		}
		i++;
	}
	std::cout << "Profit: " << profit << std::endl;
	return sol;
}

int main()
{
	std::vector<Obiect> obiecte = citire_ob("Obiecte.txt");
	float greutate;
	std::cout << "Introduceti greutatea.\ngreutate = ";
	std::cin >> greutate;

	std::cout << std::endl;
	std::cout << "Metoda dicreta:" << std::endl;

	std::vector<Obiect> sol_discreta = umplere_rucsac_discret(obiecte, greutate);

	for (int i = 0; i < sol_discreta.size(); i++)
	{
		std::cout << sol_discreta[i].greutate << " " << sol_discreta[i].pret << "\n";

	}

	std::cout << std::endl;
	std::cout << "Metoda continua:" << std::endl;

	std::vector<Obiect> sol_continua = umplere_rucsac_continuu(obiecte, greutate);

	for (int i = 0; i < sol_continua.size(); i++)
	{
		std::cout << sol_continua[i].greutate << " " << sol_continua[i].pret << " " << sol_continua[i].procent_obiect << "%\n";
	}
}
