/*Matrici/tablouri bidimensionale

-sunt niste structuri de date 
dintre cele mai folosite, 
utilizate pentru a pastra 
colectii de date de acelasi 
tip organizate pe linii si coloane

A=
1  2 1 10
-1 5 7 9
3  4 2 6

- liniile si coloanele intr-o matrice 
sunt indexate de la 0

-matricile patratice suntg cele in care 
nr de linii coincide cu nr de coloane

-parcurgerea unei matrici pe directia 
liniilor (linie cu linie) sau 
pe directia coloanelor

-in cazul matricelor patratice exista un caz 
particular de parcurgeri:
a00 a01 a02 a03 a04
a10 a11 a12 a13 a14
a20 a21 a22 a23 a24
a30 a31 a32 a33 a34
a40 a41 a42 a43 a44

->diagonala principala: a[i][i] i=0,dim-1
-se poate face parcurgerea cu un sigur for

->sub diagonala principala: a[i][j] cu j<i; i=1,dim-1

->deasupra diagonalei principale: a[i][j] j>i

->diagonala secundara: a[i][j] unde i+j=dim-1
-unul din indici se poate scrie in fct de cellalt
j=dim-1-i => a[i][dim-1-i] => diag secund poate fi
parcursa cu un singur for

->sub diagonala secundara: i+j>dim-1

->desupra diagonalei secundare: i+j<dim-1


Variante de a folosi matrice in c++:
->Folosim tablouri bidimensionale alocate static
->folosim tablouri bidim alocate dinamic
->folosim vector de vector (STL vector)

Simetrifie fata de diag principala a[i][j] a[j][i]

*/

#include <iostream>
/*#include <vector>
//using namespace std;

//tablourile statica sunt implicit transmise prin referinat
void citire_matrice(int& nr_linii, int& nr_col, int matrice[25][25])
{
	std::cout << "introduceti nr linii/col";
	std::cin >> nr_linii >> nr_col;
	std::cout << "introduceti elementele matricii";
	for(int i=0;i<nr_linii;i++)
	{
		for (int j = 0; j < nr_col; j++)
		{
			std::cin >> matrice[i][j];
		}
	}
}

void afisare_matrice(int& nr_linii, int& nr_col, int matrice[25][25])
{
	for (int i = 0; i < nr_linii; i++)
	{
		for (int j = 0; j < nr_col; j++)
		{
			std::cout<< matrice[i][j]<<" ";
		}
		std::cout << "\n";
	}
}

std::vector<std::vector<int>> citire_matrice()
{
	int nr_linii, nr_col;
	std::vector<std::vector<int>> mat;

	std::cout << "introduceti nr linii/col";
	std::cin >> nr_linii >> nr_col;
	mat.resize(nr_linii);

	std::cout << "introduceti elementele matricii";
	for (int i = 0; i < nr_linii; i++)
	{
		mat[i].resize(nr_col);
		//mat[i].resize(i+1);
		for (int j = 0; j < nr_col; j++)
		//for (int j = 0; j < i+1; j++)
		{	
			std::cin >> mat[i][j];
		}
	}
	return mat;
}

void afisare_matrice(std::vector<std::vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int main()
{
	//alocare statica
	//int matrice[25][25], nr_linii, nr_col;
	//citire_matrice(nr_linii, nr_col, matrice);
	//afisare_matrice(nr_linii, nr_col, matrice);

	//matrice de vector de vectori; 
	//avantaj nu aloc mai mult decta am nevoie
	std::vector<std::vector<int>> mat =citire_matrice();
	afisare_matrice(mat);

}*/

void citire_matrice(int& dim, int matrice[25][25])
{
	std::cout << "introduceti nr linii/col";
	std::cin >> dim;
	std::cout << "introduceti elementele matricii";
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			std::cin >> matrice[i][j];
		}
	}
}

void afisare_matrice(int& dim, int matrice[25][25])
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			std::cout << matrice[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int pozitie_max_diagon_princ(int dim, int mat[25][25])
{
	int max = 0;
	int poz_max = 0;
	//parcurgem diagonala principala
	for (int i = 0; i < dim; i++) 
	{
		if (mat[i][i] > max)
		{
			max = mat[i][i];
			poz_max = i;
		}
	}
	return poz_max;
}
//cautam un minim pe diagonala secundara
int poz_min_diag_sec(int dim, int mat[25][25])
{
	int min = 1000;
	int poz_min = 0;
	//parcurgem diag sec
	for (int i = 0; i < dim; i++) 
	{
		if(min>mat[i][dim-1-i])
		{
			min = mat[i][dim - 1 - i];
			poz_min = i;
		}
	}
	return poz_min;
}

void interschimbare(int dim, int mat[25][25])
{
	int lin_max = pozitie_max_diagon_princ(dim, mat);
	int lin_min = poz_min_diag_sec(dim, mat);
	std::swap(mat[lin_max][lin_max], mat[lin_min][dim - 1 - lin_min]);
}

int main()
{
	//alocare statica
	int mat[25][25], dim;
	citire_matrice(dim, mat);
	std::cout << "poz_max="<<pozitie_max_diagon_princ(dim, mat);
	//afisare_matrice(dim, matrice);
}