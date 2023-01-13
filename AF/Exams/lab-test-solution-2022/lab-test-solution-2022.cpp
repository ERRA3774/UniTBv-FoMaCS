#include <iostream>
#include <vector>
//#include <string>
#include <fstream>

std::ifstream fin("prieteni.txt");

struct persoana {
	char nume[20];
	float inaltime;
	float greutate;
	int varsta;
	bool sex; //0 pentru baiat, 1 pentru fata
};

/*std::vector<persoana> citire()
{
	int n;
	std::cin >> n;
	std::vector<persoana> prieteni;
	for (int i = 0; i < n; i++)
	{
		persoana prieten;
		std::cout << "Nume: "; std::cin >> prieten.nume;
		std::cout << "Inaltime: "; std::cin >> prieten.inaltime;
		std::cout << "Greutate: "; std::cin >> prieten.greutate;
		std::cout << "Varsta: "; std::cin >> prieten.varsta;
		std::cout << "Sex: "; std::cin >> prieten.sex;
		prieteni.push_back(prieten);
	}
	return prieteni;
}*/

std::vector<persoana> citire()
{
	int n;
	fin >> n;
	std::vector<persoana> prieteni;
	for (int i = 0; i < n; i++)
	{
		persoana prieten;
		fin >> prieten.nume>> prieten.inaltime>>prieten.greutate>>prieten.varsta>>prieten.sex;
		prieteni.push_back(prieten);
	}
	return prieteni;
}

int numarare_baieti(std::vector<persoana> prieteni) 
{
	int nr_b = 0;
	for (int i = 0; i < prieteni.size(); i++) 
	{
		if (prieteni[i].sex == 0)
			nr_b++;
	}
	return nr_b;
}

float inaltime_medie(std::vector<persoana> prieteni)
{
	float suma_inaltimi = 0;
	for (int i = 0; i < prieteni.size(); i++)
	{
		if(prieteni[i].sex==0)
		suma_inaltimi += prieteni[i].inaltime ;
	}
	float ma = suma_inaltimi / numarare_baieti(prieteni);
	return ma;
}

void afisare(std::vector<persoana> prieteni)
{
	for (int i = 0; i < prieteni.size(); i++)
	{
		std::cout << "Nume: " << prieteni[i].nume << "\n";
		std::cout << "Inaltime: " << prieteni[i].inaltime << "\n";
		std::cout << "Greutate: " << prieteni[i].greutate << "\n";
		std::cout << "Varsta: " << prieteni[i].varsta << "\n";
		std::cout << "Sex: " << prieteni[i].sex << "\n";
	}
}

void lucru_cu_greutati(std::vector<persoana> prieteni)
{
	int nr_g = 0;
	float greutate_data;
	std::cout << "Introduceti o greutate mai mica sau egala cu 80 de kg: ";
	std::cin >> greutate_data;
	if (greutate_data > 80 && greutate_data < 0)
	{
		std::cout << "Introduceti o valoare cuprinsa intre 0 si 80 de kg! ";
		std::cin >> greutate_data;
	}
	//aici nu prea merge cautarea binara, pt ca 1)vectorul nu e sortat inca+ apoi tot ar trebui cu un while sa merg in stanga si in dreapta mijlocului sa vad cate mai sunt egale cu mijlocul gasit
	for (int i = 0; i < prieteni.size(); i++)
	{
		std::cout << prieteni[i].greutate << " ";
		if (prieteni[i].greutate == greutate_data)
			nr_g++;
	}
	std::cout << "\n";
	std::cout << "Sunt " << nr_g << " persoane cu greutatea data!\n";
}

int partitionare(std::vector<persoana>& prieteni, int st, int dr)
{
	float pivot = prieteni[dr].greutate;
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (prieteni[j].greutate <= pivot)
		{
			std::swap(prieteni[++i], prieteni[j]);
		}
	}
	std::swap(prieteni[i + 1], prieteni[dr]);
	return i + 1;
}

void quicksort(std::vector<persoana>& prieteni, int st, int dr)
{
	if (st < dr)
	{
		int poz_pivot = partitionare(prieteni, st, dr);
		quicksort(prieteni, st, poz_pivot - 1);
		quicksort(prieteni, poz_pivot + 1, dr);
	}
}

int partitionare_inaltime(std::vector<persoana>& prieteni, int st, int dr)
{
	float pivot = prieteni[dr].inaltime;
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (prieteni[j].inaltime >= pivot)
		{
			std::swap(prieteni[++i], prieteni[j]);
		}
	}
	std::swap(prieteni[i + 1], prieteni[dr]);
	return i + 1;
}

void quicksort_inaltime(std::vector<persoana>& prieteni, int st, int dr)
{
	if (st < dr)
	{
		int poz_pivot = partitionare_inaltime(prieteni, st, dr);
		quicksort_inaltime(prieteni, st, poz_pivot - 1);
		quicksort_inaltime(prieteni, poz_pivot + 1, dr);
	}
}

int nr_maxim_persoane(std::vector<persoana> prieteni)
{
	int s = 500, i = 0;
	while (s >= 0)
	{	
		if (s >= 0)
		{
			s = s - prieteni[i].greutate;
			if (s >= 0)
				i = i++;
			else
				break;
		}
	}
	return i;
}

int main()
{
	std::vector<persoana> prieteni = citire();
	afisare(prieteni);
	std::cout << "Sunt " << numarare_baieti(prieteni) << " baieti" << "\n";
	std::cout << "Media aritmetica a inaltimilor baietilor este: " << inaltime_medie(prieteni)<<"\n";
	lucru_cu_greutati(prieteni);
	quicksort(prieteni,0, prieteni.size()-1);
	afisare(prieteni);
	//quicksort_inaltime(prieteni, 0, prieteni.size() - 1);
	//afisare(prieteni);
	std::cout << "Nr maxim de persoane care incape intr-un lift de maxim 500 de kg este: " << nr_maxim_persoane(prieteni) << "\n";
	fin.close();
}