#include <iostream>
#include <vector>
#include <stdlib.h>


/*Se da un vector de numere intregi pozitive de dimensiune “dim”. Sa se sorteze
elementele palindroame din vectorul dat.*/
/*
using namespace std;

void citire_vector(int*& v, int& n) {
	cin >> n;
	v = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
}
void afisare_vector(int* v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	} cout << "\n";
}
void dealore_vector(int*& v, int n) {
	delete[] v;
}
bool este_palindrom(int numar) {
	int copie = numar;
	int oglindit = 0;
	while (numar) {
		oglindit = oglindit * 10 + numar % 10;
		numar = numar / 10;
	}
	return (copie == oglindit);
}
void sortare_vector(int*& v, int n) {
	for (int i = 0; i < n; i++) {
		if (este_palindrom(v[i])) {
			for (int j = i + 1; j < n; j++) {
				if (este_palindrom(v[j]) && v[i] > v[j]) std::swap(v[i], v[j]);
			}
		}
	}
}

int main()
{
	int* vector, n;
	citire_vector(vector, n);
	sortare_vector(vector, n);
	afisare_vector(vector, n);
	dealore_vector(vector, n);
}*/
/*
* 2. Se da un vector de numere intregi pozitive de dimensiune “dim”. Sa se sorteze
elementele crescator pana la jumatatea sirului, iar de la jumatate la final toate elementele
sa se sorteze descrescator.
*/
/*
int partitionare(std::vector<int>& vect, int st, int dr, bool cresc)
{
	int pivot = vect[dr];
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (cresc ? vect[j] <= pivot : vect[j]>=pivot)
		{
			std::swap(vect[++i], vect[j]);
		}
	}
	std::swap(vect[i + 1], vect[dr]);
	return i + 1;
}

void quicksort(std::vector<int>& vect, int st, int dr, bool cresc)
{
	if (st < dr)
	{
		int poz_pivot = partitionare(vect, st, dr, cresc);
		quicksort(vect, st, poz_pivot - 1, cresc);
		quicksort(vect, poz_pivot + 1, dr, cresc);
	}
}

void afisare(std::vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i]<<" ";
	}
}

int main()
{
	std::vector<int> vect = { 0,5,1,6,2,7,3,2,4 };
	bool cresc = 1;
	quicksort(vect,0, (vect.size()-1)/2, cresc);
	quicksort(vect, (vect.size() - 1) / 2 + 1, vect.size() - 1, !cresc);
	afisare(vect);
}
*/

/*3. Sa se genereze un sir de numere cu ajutorul funcției rand din stdlib.h.Sa se sorteze
crescator toate elementele de pe poziții pare din acest sir de numere.*/

/*void afisare(std::vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";
}

std::vector<int> generare()
{
	int dim;
	std::cin >> dim;
	std::vector<int> vect;
	for (int i = 0; i < dim; i++)
	{
		vect.push_back(rand() % 100);
	}
	return vect;
}

void merge_sort(std::vector<int>& vect, int st, int dr)
{
	std::vector<int> temp;
	temp.resize(dr - st + 1);
	if (st < dr)
	{
		//se sorteaza cele 2 jumatati ale vectorului ex: 0, 2, 3, 7 || 1, 4, 5, 6
		int mij = (st + dr) / 2;
		merge_sort(vect, st, mij);
		merge_sort(vect, mij + 1, dr);
		//interclasare
		int i = st, j = mij + 1, k = 0;
		while (i <= mij && j <= dr)
		{
			if (vect[i] < vect[j])
			{
				temp[k++] = vect[i++];
			}
			else
			{
				temp[k++] = vect[j++];
			}
		}
		while (i <= mij)
		{
			temp[k++] = vect[i++];
		}
		while (j <= dr)
		{
			temp[k++] = vect[j++];
		}
		for (i = st, k = 0; i <= dr; i++, k++)
			vect[i] = temp[k];
	}
}

int main()
{
	std::vector<int>vect = generare(), vect_nou;
	afisare(vect);
	for (int i = 0; i < vect.size(); i = i + 2)
		vect_nou.push_back(vect[i]);
	merge_sort(vect_nou, 0, vect_nou.size() - 1);
	for (int i = 0; i < vect.size(); i=i+2)
	{
		vect[i] = vect_nou[i / 2];
	}
	afisare(vect);
}*/

/*4. Sa se testeze daca un vector de numere intregi dat este sortat crescator.
a.Daca da, atunci fiind dat un element “elem”, sa se insereze elementul la locul lui,
adica astfel incat sa ramana un sir sortat crescator.
b.Daca nu este sortat crescator, atunci sa se identifice daca exista un eventual element
care strica “ordinea”, iar daca exista unul singur, atunci sa se elimine acel element.
*/

/*std::vector<int> merge_sort(std::vector<int>& vect, int st, int dr)
{
	std::vector<int> temp;
	temp.resize(dr - st + 1);
	if (st < dr)
	{
		//se sorteaza cele 2 jumatati ale vectorului ex: 0, 2, 3, 7 || 1, 4, 5, 6
		int mij = (st + dr) / 2;
		merge_sort(vect, st, mij);
		merge_sort(vect, mij + 1, dr);
		//interclasare
		int i = st, j = mij + 1, k = 0;
		while (i <= mij && j <= dr)
		{
			if (vect[i] < vect[j])
			{
				temp[k++] = vect[i++];
			}
			else
			{
				temp[k++] = vect[j++];
			}
		}
		while (i <= mij)
		{
			temp[k++] = vect[i++];
		}
		while (j <= dr)
		{
			temp[k++] = vect[j++];
		}
	}
	return temp;
}

void afisare(std::vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";
}

void prelucrare()
{
	int elem = 3;
	std::vector<int> vect = { 0,1,2,8,8,5,6,7 }, vect_comp;
	vect_comp = merge_sort(vect, 0, (vect.size() - 1));
	afisare(vect_comp);
	if (vect_comp == vect)
	{
		int st = 0, dr = vect.size() - 1, mijl = (st + dr) / 2;
		while (dr > st)
		{
			if (elem > vect[mijl] && elem < vect[mijl + 1])
			{
				vect.insert(vect.begin() + mijl + 1, elem);
				break;
			}
			else
				if (elem > vect[mijl])
				{
					st = mijl + 1;
				}
				else
					if (elem < vect[mijl])
					{
						dr = mijl - 1;
					}
			mijl = (st + dr) / 2;
		}
	}
	else
	{
		int nr = 0, aux = -1;
		for (int i = 1; i < vect.size() - 1; i++)
		{
			if (vect[i] > vect[i - 1] && vect[i] > vect[i + 1])
			{
				nr++;
				aux = i;
			}
		}
		if (nr == 1)
			vect.erase(vect.begin() + aux);
	}
	afisare(vect);
}

int main()
{
	prelucrare();
}
*/

/*
5. Se citeste un vector de n numere intregi ordonat descrescator din fisier. Se citeste un al
doilea vector de m numere intregi din consola. Folosind cautarea binara sa se determine
care elemente din al doilea vector apar in primul si pe ce poziții. Rezultatul se va scrie
in fisier.
Intrebare: cum fac sa afisez ambele pozitii ale unui element daca apare de mai multe ori?
*/
/*
#include<fstream>

std::ifstream fin("vectorin.txt");
std::ofstream gout("vectorout.txt");

std::vector<int> citire_fis()
{
	int n;
	fin >> n;
	std::vector<int> vect(n);
	for(int i=0;i<n;i++)
		fin >> vect[i];
	return vect;
}

std::vector<int> citire_cons()
{
	int m;
	std::cin >> m;
	std::vector<int> vect(m);
	for (int i = 0; i < m; i++)
		std::cin >> vect[i];
	return vect;
}

void cautare_binara(std::vector<int> vect1, std::vector<int> vect2)
{
	for (int i = 0; i < vect2.size(); i++)
	{
		int st = 0, dr = vect1.size() - 1;
		int mijl = (st + dr) / 2;
		while (dr>=st)
		{
			if (vect2[i] < vect1[mijl])
			{
				st = mijl + 1;
				//std::cout << st;
			}
			else
				if (vect2[i] > vect1[mijl])
				{
					dr = mijl - 1;
					//std::cout << dr;
				}
				else
				{
					//std::cout << vect1[mijl] << " apare pe pozitia " << mijl << "\n";
					gout << vect1[mijl] << " apare pe pozitia " << mijl << "\n";
					break;
				}
			mijl = (st + dr) / 2;
		}
	}
}

void afisare(std::vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
		 std::cout<< vect[i]<<" ";
	std::cout << "\n";
}

int main()
{
	std::vector<int> vect1 = citire_fis();
	std::vector<int> vect2 = citire_cons();
	//afisare(vect1);
	//afisare(vect2);
	cautare_binara(vect1, vect2);
	fin.close();
	gout.close();
}
*/

/*
* 6. Se citeste o matrice cu n linii si m coloane. Sa se genereze un sir de 100 numere random
si sa se afiseze câte dintre aceste elemente sunt pe prima linie a matricei.
Obs: Se va aplica o operație de sortare asupra liniilor matricei astfel incât prima coloana
sa fie sortata crescator, ulterior se va apela cautarea binara.
*/

/*#include<fstream>

std::ifstream fisin("matricein.txt");

std::vector<std::vector<int>> citire_matrice()
{
	int n, m;
	fisin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			fisin >> a[i][j];
		}
	return a;
}

std::vector<int> generare()
{
	std::vector<int> vect;
	for (int i = 0; i < 100; i++)
	{
		vect.push_back(rand() % 100);
	}
	return vect;
}

int partitionare(std::vector<int>& vect, int st, int dr)
{
	int pivot = vect[dr];
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (vect[j] <= pivot)
		{
			std::swap(vect[++i], vect[j]);
		}
	}
	std::swap(vect[i + 1], vect[dr]);
	return i + 1;
}

void quicksort(std::vector<int>& vect, int st, int dr)
{
	if (st < dr)
	{
		int poz_pivot = partitionare(vect, st, dr);
		quicksort(vect, st, poz_pivot - 1);
		quicksort(vect, poz_pivot + 1, dr);
	}
}

void cautare_binara(std::vector<int> vect1, std::vector<int> vect2)
{
	int nr = 0;
	std::vector<int> vect(100, 0);
	for (int i = 0; i < vect2.size(); i++)
	{
		//std::cout << vect2[i] << " ";
		int st = 0, dr = vect1.size() - 1;
		int mijl = (st + dr) / 2;
		while (dr >= st)
		{
			if (vect2[i] > vect1[mijl])
			{
				st = mijl + 1;
				//std::cout << st;
			}
			else
				if (vect2[i] < vect1[mijl])
				{
					dr = mijl - 1;
					//std::cout << dr;
				}
				else
				{
					if (vect[vect2[i]] == 0)
					{
						//std::cout << vect2[i] << " apare pe pozitia " << mijl << "\n";
						nr++;
						vect[vect2[i]] = 1;
					}

					break;
				}
			mijl = (st + dr) / 2;
		}
	}
	std::cout << nr;
}

void afisare(std::vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n";
}

int main()
{
	std::vector<std::vector<int>> mat = citire_matrice();
	//afisare(mat[0]);
	std::vector<int> vect = generare();
	//afisare(vect);
	quicksort(mat[0], 0, mat[0].size() - 1);
	//afisare(mat[0]);
	quicksort(vect, 0, vect.size() - 1);
	//afisare(vect);
	cautare_binara(mat[0], vect);
}*/

//___________________________________________________________________________
//La laborator cu profa:

/*
#include<fstream>
#include <iostream>
struct Data_cal
{
	int zi, luna, an;
};

//pentru structura definita operatorii relationali nu functioneaza in mod implicit
//Var: Putem supraincarca operatorii: <=,<,>,>=;

bool operator <= (Data_cal d1, Data_cal d2) // d1 <= d2
{
	if (d1.an > d2.an)
		return false;
	if (d1.an == d2.an)
	{
		if (d1.luna > d2.luna)
			return false;
		if (d1.luna = d2.luna)
			return (d1.zi == d2.zi);
	}
	return true;
}

void citire_date(Data_cal date[25], int& dim)
{
	std::ifstream fin("Date.txt");
	fin >> dim;
	for (int i = 0; i < dim; i++)
	{
		fin >> date[i].zi >> date[i].luna >> date[i].an;
	}
}

void afisare_date(Data_cal date[25], int& dim)
{
	for (int i = 0; i < dim; i++)
	{
		std::cout << date[i].zi << " " << date[i].luna << " " << date[i].an << "\n";
	}
	std::cout << "\n";
}

//TO DO: de rafinat metoda de validare
bool validare(Data_cal data)
{
	if (data.luna <= 0 || data.luna > 12)
		return false;
	if (data.an <= 0 || data.an > 2022)
		return false;
	if (data.zi <= 0)
		return false;
	if (data.luna == 4 || data.luna == 6 || data.luna == 9 || data.luna == 31)
	{
		if (data.zi > 30) return false;
	}
	else if (data.luna != 2)
	{
		if (data.zi > 31) return false;
	}
	else
	{
		if (data.an % 4 == 0) {
			if (data.zi > 29) return false;
		}
		else
			if (data.zi > 28) return false;
	}
	return true;
}

void selectie_date(Data_cal date[], int& dim)
{
	Data_cal date_valide[25];
	int dim1 = 0;
	for (int i = 0; i < dim; i++)
	{
		if (validare(date[i]))
		{
			date_valide[dim1++] = date[i];
		}
	}
	for (int i = 0; i < dim1; i++)
	{
		date[i] = date_valide[i];
	}
	dim = dim1;
}

int partitionare(Data_cal vect[], int st, int dr)
{
	Data_cal pivot = vect[dr];
	int i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (vect[j] <= pivot)
		{
			std::swap(vect[++i], vect[j]);
		}
	}
	std::swap(vect[i + 1], vect[dr]);
	return i + 1;
}

void quicksort(Data_cal vect[], int st, int dr)
{
	if (st < dr)
	{
		int poz_pivot = partitionare(vect, st, dr);
		quicksort(vect, st, poz_pivot - 1);
		quicksort(vect, poz_pivot + 1, dr);
	}
}

int main()
{
	Data_cal date[25];
	int dim;
	citire_date(date, dim);
	selectie_date(date, dim);
	afisare_date(date, dim);
	quicksort(date, 0, dim - 1);
	afisare_date(date, dim);
}
*/

#include<algorithm> // pt std::sort
/* sort(adresa_start, adresa_sfarsit, comparator)
unde:
adresa_start = adresa de la care vreti sa faceti sortarea
adresa_sfarsit = adresa la care se face sortarea

optional:
	comparator - reprezinta  modul/specificarea modului
	in care se face compararea
	(in mod implicit sortarea se face crescator)
*/

/*
#include <fstream>
struct Obiect
{
	double greutate;
	int id, valoare;
};

//se pot supraincarca operatorii relationali DAR
//nu pot cuprinde in aceasta supraincarcare
//toate variantele posibile de sorate
bool operator <=(Obiect o1, Obiect o2)
{
	return (o1.greutate <= o2.greutate);
}

bool operator <(Obiect o1, Obiect o2)
{
	return (o1.greutate < o2.greutate);
}

bool operator >=(Obiect o1, Obiect o2)
{
	return (o1.greutate >= o2.greutate);
}

bool operator >(Obiect o1, Obiect o2)
{
	return (o1.greutate > o2.greutate);
}

bool operator ==(Obiect o1, Obiect o2)
{
	return (o1.greutate == o2.greutate);
}

//in locul operatorilor se pot scrie
//functii care sa precizieze cum se face comparare
//comparatori putem avea cat este necesar pt obiectele cu care lucram

bool comparator_greutatae_descrescator(Obiect o1, Obiect o2)
{
	return (o1.greutate > o2.greutate);
}

bool comparator_valoare_crescator(Obiect o1, Obiect o2)
{
	return (o1.valoare < o2.valoare);
}

void citire(Obiect*& obiecte, int &dim)
{
	std::ifstream f("Obiecte.txt");
	f >> dim;
	if (dim > 0)
	{
		obiecte = new Obiect[dim];
		for (int i = 0; i < dim; i++)
		{
			f >> obiecte[i].id >> obiecte[i].greutate >> obiecte[i].valoare;
		}
	}
}

void afisare(Obiect*& obiecte, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		std::cout << obiecte[i].id << " " << obiecte[i].greutate << " "<<obiecte[i].valoare<<"\n";
	}
}



void test_sortare_obiecte()
{
	Obiect* obiecte = nullptr;
	int dim;
	citire(obiecte, dim);
	//sortare dupa greutate (pe baza operatorilor relationali)
	//std::sort(obiecte, obiecte + dim);
	std::cout << "\n";
	std::sort(obiecte, obiecte + dim, comparator_greutatae_descrescator);
	afisare(obiecte, dim);
}




int main()
{
	test_sortare_obiecte();
	std::cout << "\n";
	//sortare vector static
	int vect[] = { 2,0,13,5,6,8,17,4,9,-66 };
	int dim = sizeof(vect) / sizeof(vect[0]);

	//std::sort(vect, vect + dim/2);

	int* vect_din = new int[dim];
	for (int i = 0; i < dim; i++)
	{
		vect_din[i]=vect[i];
	}

	std::sort(vect_din, vect_din + dim);

	//sortare vector stl
	std::vector<int> vect_stl= { 2,0,13,5,6,8,17,4,9,-66 };

	std::sort(vect_stl.begin(), vect_stl.end());

	//for (int i = 0; i < dim; i++)
	//{
	//	std::cout << vect_din[i] << " ";
	//}

	for (int i = 0; i < vect_stl.size(); i++)
		{
			std::cout << vect_stl[i] << " ";
		}
	std::cout << "\n";

	//sortarea descresctaoare a unui vector ce contine elemente de tip primitiv C++
	//trebuie adaugat in apelul metodei sort comparatorul
	std::sort(vect_stl.begin(), vect_stl.end(), std::greater<int>());
		for (int i = 0; i < vect_stl.size(); i++)
		{
			std::cout << vect_stl[i] << " ";
		}
}*/