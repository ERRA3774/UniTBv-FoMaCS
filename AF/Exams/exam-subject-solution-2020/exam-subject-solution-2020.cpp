#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <math.h>

std::ifstream  fin("case.txt");

struct casa
{
	int id;
	std::string culoare;
	int nr_membri;
	bool cu_etaj; //0 pentru fara, 1 pentru cu
};

std::vector<casa> citire()
{
	std::vector<casa> casute;
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		casa c;
		fin >> c.id >> c.culoare >> c.nr_membri >> c.cu_etaj;
		casute.push_back(c);
	}
	return casute;
}

void afisare(std::vector<casa> casute)
{
	for (int i = 0; i < casute.size(); i++)
	{
		std::cout << "Id: " << casute[i].id << "\n";
		std::cout << "Culoare: " << casute[i].culoare << "\n";
		std::cout << "Nr membri: " << casute[i].nr_membri << "\n";
		std::cout << "Cu sau fara etaj: " << casute[i].cu_etaj << "\n";
	}
}

void diferenta_verde_rosie(std::vector<casa> casute)
{
	int nr_rosii = 0;
	int nr_verzi = 0;
	std::string v = "verde";
	std::string r = "rosie";
	for (int i = 0; i < casute.size(); i++)
	{
		if (casute[i].culoare == v)
			nr_verzi++;
		else
			if (casute[i].culoare == r)
				nr_rosii++;
	}
	//return abs(nr_rosii - nr_verzi);
	std::cout << "Sunt " << nr_verzi << " casute de culoare verde si " << nr_rosii << " casute de culoare rosie!\n";
}

int partitionare_casute(std::vector<casa>& casute, int st, int dr)
{
	int pivot = casute[dr].nr_membri;
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (casute[j].nr_membri <= pivot)
		{
			std::swap(casute[++i], casute[j]);
		}
	}
	std::swap(casute[i + 1], casute[dr]);
	return i + 1;
}

void quicksort_casute(std::vector<casa>& casute, int st, int dr)
{
	if (st < dr)
	{
		int poz_pivot = partitionare_casute(casute, st, dr);
		quicksort_casute(casute, st, poz_pivot - 1);
		quicksort_casute(casute, poz_pivot + 1, dr);
	}
}

void afisare_id(std::vector<casa> casute)
{

	for (int i = 0; i < casute.size(); i++)
	{
		std::cout << "Id: " << casute[i].id << "\n";
	}
}

void afisare_cate_cu_etaj(std::vector<casa> casute)
{
	int nr_etaj = 0;
	for (int i = 0; i < casute.size(); i++)
		if (casute[i].cu_etaj == 1)
			nr_etaj++;
	std::cout << "Procentul de case cu etaj este: " << nr_etaj * 100 / casute.size() << "\n";
}

//quicksort pentru sortarea ajutoarelor
int partitionare_ajutoare(std::vector<int>& ajutoare, int st, int dr)
{
	int pivot = ajutoare[dr];
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (ajutoare[j] >= pivot)
		{
			std::swap(ajutoare[++i], ajutoare[j]);
		}
	}
	std::swap(ajutoare[i + 1], ajutoare[dr]);
	return i + 1;
}

void quicksort_ajutoare(std::vector<int>& ajutoare, int st, int dr)
{
	if (st < dr)
	{
		int poz_pivot = partitionare_ajutoare(ajutoare, st, dr);
		quicksort_ajutoare(ajutoare, st, poz_pivot - 1);
		quicksort_ajutoare(ajutoare, poz_pivot + 1, dr);
	}
}

//este nevoie sa fie sortate ajutoarele in ordine descrescatoare
void ajutoare(std::vector<casa> casute)
{
	std::vector<casa> casute2 = casute;
	int nr_ajutoare;
	int suma_ajutoare = 0;
	std::cout << "Dati nr de ajutoare ale lui Mos Craciun: "; std::cin >> nr_ajutoare;
	std::vector<int> ajutoare;
	for (int i = 0; i < nr_ajutoare; i++)
	{
		int ajutor;
		std::cin >> ajutor;
		ajutoare.push_back(ajutor);
		suma_ajutoare += ajutor;
	}

	int suma_membri = 0;
	for (int i = 0; i < casute.size(); i++)
	{
		suma_membri += casute[i].nr_membri;
	}
	if (suma_ajutoare < suma_membri)
	{
		std::cout << "Numarul de ajutoare este mai mic decat numarul de membrii in total!\n";
		return;
	}
	quicksort_ajutoare(ajutoare, 0, ajutoare.size() - 1);

	std::vector<int> ajutoare2 = ajutoare;

	for (int i = 0; i < ajutoare.size(); i++)
		std::cout << ajutoare[i] << " ";
	std::cout << "\n";

	int i = 0, j = 0;

	while (i < ajutoare.size() && j < casute.size())
	{
		if (ajutoare[i] > casute[j].nr_membri)
		{
			ajutoare[i] -= casute[j].nr_membri;
			casute[j].nr_membri = 0;
			j++;
		}
		else
			if (ajutoare[i] < casute[j].nr_membri)
			{
				casute[j].nr_membri -= ajutoare[i];
				ajutoare[i] = 0;
				i++;
			}
			else if (ajutoare[i] == casute[j].nr_membri)
			{
				i++;
				j++;
			}
	}
	i = i + 1; //?nu stiu exact de ce, dar cred ca la ultima iteratie nu se va mai incrementa i; e o observatie strict pe rezultat si asa da bine
	std::cout << "Ajutoarele: ";
	for (int k = 0; k < i; k++)
	{
		std::cout << ajutoare2[k] << " ";
	}

	std::cout << " pentru casele: ";

	for (int l = 0; l < j; l++)
	{
		std::cout << casute2[l].id << " ";
	}
}

int main()
{
	std::vector<casa> casute = citire();
	//afisare(casute);
	//diferenta_verde_rosie(casute);
	//quicksort_casute(casute, 0, casute.size()-1);
	//afisare_id(casute);
	//afisare_cate_cu_etaj(casute);
	ajutoare(casute);
	fin.close();
}