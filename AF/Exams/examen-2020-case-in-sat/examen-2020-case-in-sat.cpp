#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Casa
{
	int id;
	int nr_membri;
	std::string culoare;
	bool are_etaj;
};

std::vector<Casa> citire_case(std::string nume_fisier);
void afisare_case(std::vector<Casa>& vec_case);
void interschimbare(Casa& a, Casa& b);
void quicksort(std::vector<Casa>& vec, int st, int dr);
void afisare_id_case(std::vector<Casa>& vec_case);
int diferenta_culoare_case(std::vector<Casa>& vec_case, std::string culoare1, std::string culoare2);
void afisare_diferenta_culoare_case(std::vector<Casa>& vec, std::string culoare1, std::string culoare2);
void afisare_procent_case_cu_etaj(std::vector<Casa>& vec_case);
std::vector<int> minim_ajutoare(std::vector<Casa>& vec_case, std::vector<int>& vec_ajutoare);
void afisare_minim_ajutoare(std::vector<Casa>& vec_case, std::vector<int>& vec_ajutoare);
void print_test_minim_ajutoare(std::vector<int>& vec_case, std::vector<int>& vec_ajutoare);
void print_tests();

int main()
{
	std::vector<Casa> case_in_sat = citire_case("Case.txt");
	afisare_case(case_in_sat);
	afisare_diferenta_culoare_case(case_in_sat, "VERDE", "ROSU");
	std::cout << "ID dupa sortare: " << std::endl;
	quicksort(case_in_sat, 0, case_in_sat.size() - 1);
	afisare_id_case(case_in_sat);
	afisare_procent_case_cu_etaj(case_in_sat);
	std::vector<int> ajutoare = { 5, 10, 3, 10, 2, 4, 1, 35, 9, 14, 20, 10, 14 };
	afisare_minim_ajutoare(case_in_sat, ajutoare);

	// TESTE
	print_tests();

}

std::vector<Casa> citire_case(std::string nume_fisier)
{
	int n;
	std::vector<Casa> vec_case;
	std::ifstream fisier_input(nume_fisier);
	fisier_input >> n;
	vec_case.resize(n);

	for (int i = 0; i < n; i++)
	{
		fisier_input
			>> vec_case[i].id
			>> vec_case[i].nr_membri
			>> vec_case[i].culoare
			>> vec_case[i].are_etaj;
	}

	return vec_case;
}

void afisare_case(std::vector<Casa>& vec_case)
{
	int k = 0;
	for (auto& casa : vec_case)
	{
		std::cout
			<< "Casa: " << ++k
			<< " Id: " << casa.id
			<< " Membri: " << casa.nr_membri
			<< " Culoare: " << casa.culoare
			<< " Are etaj: " << ((casa.are_etaj != 0) ? "da" : "nu")
			<< std::endl;
	}

	std::cout << std::endl;
}

// Functie ajutatoare care inlocuieste std::swap
void interschimbare(Casa& a, Casa& b)
{
	Casa temp = a;
	a = b;
	b = temp;
}

void quicksort(std::vector<Casa>& vec, int st, int dr)
{
	int i = st;
	int j = dr;
	int pivot = vec[(st + dr) / 2].nr_membri;

	while (i <= j)
	{
		while (vec[i].nr_membri < pivot)
		{
			i++;
		}

		while (vec[j].nr_membri > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			interschimbare(vec[i++], vec[j--]);
		}
	}

	if (st < j)
	{
		quicksort(vec, st, j);
	}

	if (i < dr)
	{
		quicksort(vec, i, dr);
	}
}

void afisare_id_case(std::vector<Casa>& vec_case)
{
	for (auto& casa : vec_case)
	{
		std::cout << casa.id << " ";
	}

	std::cout << std::endl;
}

// Functie ajutatoare pentru calcularea diferentei numarului de case de o anumita culoare
int diferenta_culoare_case(std::vector<Casa>& vec_case, std::string culoare1, std::string culoare2)
{
	int case_culoare1 = 0;
	int case_culoare2 = 0;

	for (int i = 0; i < vec_case.size(); i++)
	{
		if (vec_case[i].culoare == culoare1)
		{
			case_culoare1++;
		}

		if (vec_case[i].culoare == culoare2)
		{
			case_culoare2++;
		}
	}

	std::cout << "Sunt " << case_culoare2 << " case de culoare " << culoare2 << std::endl;
	std::cout << "Sunt " << case_culoare1 << " case de culoare " << culoare1 << std::endl;

	if (case_culoare2 == case_culoare1)
	{
		return 0;
	}

	return (case_culoare2 > case_culoare1) ? (case_culoare2 - case_culoare1) : (case_culoare1 - case_culoare2);
}

void afisare_diferenta_culoare_case(std::vector<Casa>& vec, std::string culoare1, std::string culoare2)
{
	int diferenta_culori = diferenta_culoare_case(vec, culoare1, culoare2);

	if (diferenta_culori == 0)
	{
		std::cout
			<< "Numarul caselor de culoare "
			<< culoare1 << " si " << culoare2
			<< " este egal."
			<< std::endl;
	}
	else
	{
		std::cout
			<< "Diferenta caselor de culoare "
			<< culoare1 << " si cea a caselor de culoare " << culoare2
			<< " este de " << diferenta_culori
			<< std::endl;
	}
}

void afisare_procent_case_cu_etaj(std::vector<Casa>& vec_case)
{
	float case_cu_etaj = 0;

	for (auto& casa : vec_case)
	{
		if (casa.are_etaj)
		{
			case_cu_etaj++;
		}
	}

	std::cout << (case_cu_etaj / (float)vec_case.size()) * 100 << "% din case au etaj" << std::endl;
}

std::vector<int> minim_ajutoare(std::vector<Casa>& vec_case, std::vector<int>& vec_ajutoare)
{
	std::vector<int> minim_ajutoare;
	int nr_membri = 0;

	for (int i = 0; i < vec_case.size(); i++)
	{
		nr_membri += vec_case[i].nr_membri;
	}

	sort(vec_ajutoare.begin(), vec_ajutoare.end(), std::greater<int>());

	int i = 0;
	while (nr_membri >= 0 && i < vec_ajutoare.size())
	{
		minim_ajutoare.push_back(vec_ajutoare[i]);
		nr_membri -= vec_ajutoare[i];
		i++;
	}

	if (nr_membri > 0)
	{
		std::cout << "Mos Craciun nu are suficiente ajutoare." << std::endl;
		exit(0);
	}

	return minim_ajutoare;
}

void afisare_minim_ajutoare(std::vector<Casa>& vec_case, std::vector<int>& vec_ajutoare)
{
	std::vector<int> vec_min_ajutoare = minim_ajutoare(vec_case, vec_ajutoare);

	std::cout << "Minimul de ajutoare de care are nevoie Mos Craciun:" << std::endl;

	for (int i = 0; i < vec_min_ajutoare.size(); i++)
	{
		std::cout << vec_min_ajutoare[i] << " ";
	}

	std::cout << std::endl;
}

//--------------------------------------------------------------------------------- TESTE
void print_test_minim_ajutoare(std::vector<int>& vec_case, std::vector<int>& vec_ajutoare)
{
	std::vector<int> minim_ajutoare;
	int locuitori = 0;
	for (int i = 0; i < vec_case.size(); i++)
	{
		locuitori += vec_case[i];
	}

	sort(vec_ajutoare.begin(), vec_ajutoare.end(), std::greater<int>());

	int i = 0;
	while (locuitori >= 0 && i < vec_ajutoare.size())
	{
		minim_ajutoare.push_back(vec_ajutoare[i]);
		locuitori -= vec_ajutoare[i];
		i++;
	}
	if (locuitori > 0)
	{
		std::cout << "Mos Craciun nu are suficiente ajutoare.";
		exit(0);
	}

	for (int i = 0; i < minim_ajutoare.size(); i++)
	{
		std::cout << minim_ajutoare[i] << " ";
	}

	std::cout<<std::endl;
}

void print_tests()
{
	std::cout << std::endl;
	std::cout << "Test 1: \n10, 7, 2, 5\n5, 10, 3, 10, 2, 4, 1" << std::endl;
	std::vector<int> case0{ 10, 7, 2, 5 };
	std::vector<int> ajut0{ 5, 10, 3, 10, 2, 4, 1 };
	print_test_minim_ajutoare(case0, ajut0);
	std::cout << std::endl;
	
	std::cout << "Test 2: \n30, 10, 5\n35, 9, 14" << std::endl;
	std::vector<int> case1{ 30, 10, 5 };
	std::vector<int> ajut1{ 35, 9, 14 };
	print_test_minim_ajutoare(case1, ajut1);
	std::cout << std::endl;

	std::cout << "Test 3: \n12, 14, 10\n20, 10, 14" << std::endl;
	std::vector<int> case2{ 12, 14, 10 };
	std::vector<int> ajut2{ 20, 10, 14 };
	print_test_minim_ajutoare(case2, ajut2);
	std::cout << std::endl;

	std::cout << "Test 3: \n10, 20, 15, 13, 12\n5, 2, 10, 3" << std::endl;
	std::vector<int> case3{ 10, 20, 15, 13, 12 };
	std::vector<int> ajut3{ 5, 2, 10, 3 };
	print_test_minim_ajutoare(case3, ajut3);
}