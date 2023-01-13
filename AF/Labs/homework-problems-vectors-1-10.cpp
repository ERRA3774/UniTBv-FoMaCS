/*pb1
1. Se citeste o matrice patratica cu n linii si n coloane (n<=100), cu
elemente numere naturale din intervalul [0,1000], avand elementele
distincte pe fiecare dintre cele doua diagonale. Interschimbati elementul
maxim de pe diagonala principala cu elementul minim de pe diagonala
secundara. Afisati matricea rezultata*/
/*
#include <iostream>
#include <vector>

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		//mat[i].resize(dim);
		for (int j = 0; j < dim; j++)
		{
			std::cin >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			std::cout << mat[i][j]<<" ";
		}
		std::cout << "\n";
	}
}

int poz_element_maxim_dp(std::vector<std::vector<int>> mat)
{
	int poz = -1, maxim = -1;
	for (int i = 0; i < mat.size(); i++)
	{
		if (mat[i][i] > maxim)
		{
			maxim = mat[i][i];
			poz = i;
		}
	}
	return poz;
}

int poz_element_minim_ds(std::vector<std::vector<int>> mat)
{
	int poz = -1, minim = 1001;
	for (int i = 0; i < mat.size(); i++)
	{
		if (mat[i][mat.size() - 1 - i] < minim)
		{
			minim = mat[i][i];
			poz = i;
		}
	}
	return poz;
}

void interschimb(std::vector<std::vector<int>> &mat)
{
	std::swap(mat[poz_element_maxim_dp(mat)][poz_element_maxim_dp(mat)], mat[poz_element_minim_ds(mat)][mat.size()-1- poz_element_minim_ds(mat)]);
}

int main() {
	int dim;
	std::cin >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	citire(mat, dim);
	interschimb(mat);
	//std::cout << mat[poz_element_maxim_dp(mat)][poz_element_maxim_dp(mat)] << "\n";
	//std::cout << mat[poz_element_minim_ds(mat)][mat.size() - 1 - poz_element_minim_ds(mat)] << "\n";
	afisare(mat);
	return 0;
}*/

/*pb2. Se citeste o matrice patratica cu n linii si n coloane (n<=100), cu
elemente numere naturale din intervalul [0,1000]. Sa se determine sumele
elementelor celor 4 triunghiuri determinate de diagonala principala si cea
secundara.*/

/*#include<vector>
#include<iostream>

int suma_elementelor(std::vector<std::vector<int>> mat) {
	int s = 0;
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
			if ((i < j && (i + j) < (mat.size() - 1)) || (i < j && (i + j) >(mat.size() - 1)) || (i > j && (i + j) < (mat.size() - 1)) || (i > j && (i + j) > (mat.size() - 1)))
				s = s + mat[i][j];
	}
	return s;
}

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		//mat[i].resize(dim);
		for (int j = 0; j < dim; j++)
		{
			std::cin >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
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

int main() {
	int dim;
	std::cin >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	citire(mat, dim);
	std::cout << "Suma elementelor care nu se afla nici de dp nici pe ds este:" << suma_elementelor(mat) << "\n";
	afisare(mat);
	return 0;
}*/


/*pb3. Se citeste o matrice cu n linii si m coloane, (n, m<=100) cu elemente
numere naturale din intervalul [0,1000]. Afisati liniile cu numar maxim
de de elemente disticte. Sa se stearga dupa aceea liniile cu numar maxim
de elemente distincte.
*/

/*#include <iostream>
#include <vector>

void citire(std::vector<std::vector<int>>& mat, int l, int c)
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cin >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
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

//mai tarziu mi-am dat seama ca puteam face sortare pe vector dar mi-e lene sa modific :))
void sortare_pe_linie(std::vector<std::vector<int>>& mat)
{
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size() - 1; j++)
			for (int k = j + 1; k < mat[i].size(); k++)
			{
				if (mat[i][j] > mat[i][k])
				{
					int aux = mat[i][j];
					mat[i][j] = mat[i][k];
					mat[i][k] = aux;
				}
			}
	}
}

std::vector<int> prelucrare(std::vector<std::vector<int>> mat)
{
	std::vector<int> max_pe_linie(mat.size(),1);
	sortare_pe_linie(mat);
	for(int i=0;i<mat.size();i++)
	{
		int a = mat[i][0];
		for (int j = 1; j < mat[i].size(); j++)
		{
			if (mat[i][j] != a)
			{
				a = mat[i][j];
				max_pe_linie[i]++;
			}
		}
	}
	return max_pe_linie;
}

std::vector<int> linii_maxime(std::vector<std::vector<int>> mat)
{
	std::vector<int> max_pe_linie = prelucrare(mat);
	std::vector<int> v_linii;
	int max = max_pe_linie[0];
	for (int i = 1; i < max_pe_linie.size(); i++)
	{
		if(max_pe_linie[i]>max)
		{
			max = max_pe_linie[i];
		}
	}

	for (int i = 0; i < max_pe_linie.size(); i++)
	{
		if(max_pe_linie[i]==max)
			v_linii.push_back(i);
	}
	return v_linii;
}

void afisare_linii_nr_maxim_elemenete(std::vector<std::vector<int>> mat) {
	std::vector<int> linii_bune = linii_maxime(mat);

	for (int i = 0; i < linii_bune.size(); i++)
	{
		for (int j = 0; j < mat[linii_bune[i]].size(); j++) {
			std::cout << mat[linii_bune[i]][j] << " ";
		}
		std::cout << "\n";
	}
}

void stergere_linii_nemaxime(std::vector<std::vector<int>>& mat)
{
	std::vector<int> max_pe_linie = prelucrare(mat);
	int max = max_pe_linie[0];
	for (int i = 1; i < max_pe_linie.size(); i++)
	{
		if (max_pe_linie[i] > max)
		{
			max = max_pe_linie[i];
		}
	}

	for (int i = 0; i < max_pe_linie.size(); i++)
	{
		if (max_pe_linie[i] != max)
			mat[i].clear();
	}
}

int main()
{
	int l, c;
	std::cin >> l >> c;
	std::vector<std::vector<int>> mat(l, std::vector<int>(c));
	citire(mat, l, c);
	afisare(mat);
	std::cout << "\n";
	//afisare_linii_nr_maxim_elemenete(mat);
	stergere_linii_nemaxime(mat);
	afisare(mat);
	return 0;
}*/

/*pb4. Se citeste o matrice patratica cu n linii si n coloane (n<=100), cu
elemente numere naturale din intervalul [0,1000]. Ordonati crescator
elementele de pe diagonala principala prin interschimbari de linii si
coloane. Afisati matricea rezultata.*/

/*
#include <fstream>
#include <vector>
#include <iostream>

std::ifstream fin("matrice.in");
std::ofstream fout("matrice.out");

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i <dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			fin >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
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

void prelucrare(std::vector<std::vector<int>>& mat)
{
	for (int i = 0; i < mat.size()-1; i++)
		for (int j = i + 1; j < mat.size(); j++)
			if (mat[i][i] > mat[j][j])
			{
				for (int k = 0; k < mat.size(); k++)
				{
					int aux = mat[i][k]; mat[i][k] = mat[j][k]; mat[j][k] = aux;
				}
				for (int k = 0; k < mat.size(); k++)
				{
					int aux = mat[k][i]; mat[k][i] = mat[k][j]; mat[k][j] = aux;
				}
			}
}

int main()
{
	int dim;
	fin >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	citire(mat, dim);
	prelucrare(mat);
	afisare(mat);
	return 0;
}*/

/*pb5. Sa se roteasca o matrice patratica, cu n linii si n coloane, cu 90 de grade
in sensul acelor de ceas.*/

/*#include <fstream>
#include <vector>
#include <iostream>

std::ifstream fin("matrice.in");
std::ofstream fout("matrice.out");

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			fin >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
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

void rotire(std::vector<std::vector<int>>& mat)
{
	int i, j, aux;
	for (i = 1; i < mat.size(); i++)
		for (j = 0; j < i; j++)
		{
			aux = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = aux;
		}
	for (i = 0; i < mat.size(); i++)
		for (j = 0; j < mat.size()/2; j++)
		{
			aux = mat[i][j];
			mat[i][j] = mat[i][mat.size() - 1 - j];
			mat[i][mat.size() - 1 - j] = aux;
		}
}

int main()
{
	int dim;
	fin >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	citire(mat, dim);
	rotire(mat);
	afisare(mat);
	return 0;
}*/

/*Construiti si afisati o matrice patratica de ordin n dupa modelul de mai
jos pentru care n=5:
1 2 3 4 5
2 1 2 3 4
3 2 1 2 3
4 3 2 1 2
5 4 3 2 1*/

/*#include <fstream>
#include <vector>
#include <iostream>

std::ifstream fin("matrice.in");
std::ofstream fout("matrice.out");

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			fin >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
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

void prelucrare(std::vector<std::vector<int>>& mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		mat[i][i] = 1;
	}

	for (int i = 1; i < mat.size(); i++)
	{
		for (int j = 0; j < mat.size() - 1; j++)
		{
			if (j < i)
			{
				mat[i][j] = mat[j][i] = i - j + 1;
			}
		}
	}
}

int main()
{
	int dim;
	fin >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	//citire(mat, dim);
	prelucrare(mat);
	afisare(mat);
	return 0;
}*/

/* 8. Se citeste o matrice patratica de ordin n. Parcurgeti si afisati elementele
din matrice incepand cu elementul din coltul stanga sus, mergand paralel
cu diagonala secundara, ca in exemplu.
Exemplu
n=4,
matricea:
1 3 4 10
2 5 9 11
6 8 12 15
7 13 14 16
In urma parcurgerii se vor afisa numerele: 1 2 3 4 5 6 7 8 9 10 11 12
13 14 15 16*/

/*8. Se citeste o matrice patratica de ordin n. Parcurgeti si afisati elementele
din matrice incepand cu elementul din coltul stanga sus, mergand paralel
cu diagonala secundara, ca in exemplu.
Exemplu
n=4,
matricea:
1 3 4 10
2 5 9 11
6 8 12 15
7 13 14 16
In urma parcurgerii se vor afisa numerele: 1 2 3 4 5 6 7 8 9 10 11 12
13 14 15 16*/

/*
#include <fstream>
#include <vector>
#include <iostream>

std::ifstream fin("matrice.in");
std::ofstream fout("matrice.out");

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			fin >> mat[i][j];
		}
	}
}

void parcurgere_afisare(std::vector<std::vector<int>>& mat)
{
	bool sens = false;
	//liniile de deasupra ds si ds
	for (int i = 0; i < mat.size(); i++) {
		if (sens)
			for (int j = 0; j <= i; j++)
			{
				std::cout << mat[i - j][j] << ' ';
			}
		else
			for (int j = i; j >= 0; j--)
			{
				std::cout << mat[i - j][j] << ' ';
			}
		sens = !sens;
	}

	//liniile de dedesubtul ds
	for (int i = 0; i < mat.size(); i++) {
		if (sens)
			for (int j = 0; j < mat.size() - i - 1; j++)
				std::cout << mat[mat.size() - j - 1][i + j + 1] << ' ';
		else
			for (int j = mat.size() - i; j >= 2; j--)
				std::cout << mat[mat.size() - j + 1][i + j - 1] << ' ';
		sens = !sens;
	}
}

int main()
{
	int dim;
	fin >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	citire(mat, dim);
	parcurgere_afisare(mat);
	fin.close();
	return 0;
}
*/

/*5. Sa se roteasca o matrice patratica, cu n linii si n coloane, cu 90 de grade
in sensul acelor de ceas.
*/

/*
#include <iostream>
#include <fstream>
#include <vector>
std::ifstream f("matrice.in");

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			f >> mat[i][j];
		}
	}
}

void afisare(std::vector<std::vector<int>> mat)
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

void rotire(std::vector<std::vector<int>>& mat)
{
		int i, j, aux;
		for (i = 1; i < mat.size(); i++)
			for (j = 0; j < i; j++)
			{
				aux = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = aux;
			}
		for (i = 0; i < mat.size(); i++)
			for (j = 0; j < mat.size() / 2; j++)
			{
				aux = mat[i][j];
				mat[i][j] = mat[i][mat.size() - 1 - j];
				mat[i][mat.size() - 1 - j] = aux;
			}
}



int main()
	{
		int dim;
		f >> dim;
		std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
		citire(mat, dim);
		rotire(mat);
		afisare(mat);
		f.close();
		return 0;
	}
*/

/*10. Se da o matrice patratica de dimensiune n, matrice care trebuie sa contina
toate numerele intre 0 si n^2-1.
a. sa se verifice daca matricea data respecta conditia ceruta
b. sa se localizeze punctul cu valoarea 0 (pentru matricile valide) si sa se scrie o
functie care returneaza toate cele maxim 4 matrici care se pot forma mutand 0
N, S, E V.*/

/*#include <iostream>
#include <fstream> 
#include <vector>
std::ifstream f("matrice.in");

void citire(std::vector<std::vector<int>>& mat, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			f >> mat[i][j];
		}
	}
}

int verificare(std::vector<std::vector<int>> mat)
{
	std::vector<int> v_frcv(mat.size() * mat.size());
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i][j] >= 0 && mat[i][j] < mat.size() * mat.size())
				v_frcv[mat[i][j]]++;
			else
				return 0;
		}
	}

	for (int i = 0; i < v_frcv.size(); i++)
	{
		if (v_frcv[i] != 1)
			return 0;
	}
	return 1;
}

std::vector<int> cauta_zero(std::vector<std::vector<int>> mat)
{
	std::vector<int> v_poz(2);
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i][j] == 0)
			{
				v_poz[0] = i;
				v_poz[1] = j;
				return v_poz;
			}

		}
	}
}

std::vector<std::vector<int>> muta_nord(int i, int j, std::vector<std::vector<int>> mat)
{
	std::vector<std::vector<int>> matrice_N;
	int aux = mat[i][j];
	mat[i][j] = mat[i - 1][j];
	mat[i - 1][j] = aux;
	matrice_N = mat;
	return matrice_N;
}

std::vector<std::vector<int>> muta_est(int i, int j, std::vector<std::vector<int>> mat)
{
	std::vector<std::vector<int>> matrice_E;
	int aux = mat[i][j];
	mat[i][j] = mat[i][j + 1];
	mat[i][j + 1] = aux;
	matrice_E = mat;
	return matrice_E;
}

std::vector<std::vector<int>> muta_vest(int i, int j, std::vector<std::vector<int>> mat)
{
	std::vector<std::vector<int>> matrice_V;
	int aux = mat[i][j];
	mat[i][j] = mat[i][j - 1];
	mat[i][j - 1] = aux;
	matrice_V = mat;
	return matrice_V;
}

std::vector<std::vector<int>> muta_sud(int i, int j, std::vector<std::vector<int>> mat)
{
	std::vector<std::vector<int>> matrice_S;
	int aux = mat[i][j];
	mat[i][j] = mat[i + 1][j];
	mat[i + 1][j] = aux;
	matrice_S = mat;
	return matrice_S;
}

std::vector<std::vector<std::vector<int>>> prelucrare(std::vector<std::vector<int>>& mat)
{
	std::vector<std::vector<std::vector<int>>> vector_de_matrici(4);
	std::vector<int> v_poz = cauta_zero(mat);
	if (v_poz[0] != 0 && v_poz[1] != 0 && v_poz[0] != mat.size() - 1 && v_poz[1] != mat.size() - 1)
	{
		//V
		vector_de_matrici[0] = muta_vest(v_poz[0], v_poz[1], mat);

		//N
		vector_de_matrici[1] = muta_nord(v_poz[0], v_poz[1], mat);

		//E
		vector_de_matrici[2] = muta_est(v_poz[0], v_poz[1], mat);

		//S
		vector_de_matrici[3] = muta_sud(v_poz[0], v_poz[1], mat);

	}
	else
		if (v_poz[0] == 0 && v_poz[1] != 0 && v_poz[1] != mat.size() - 1)
		{	
			vector_de_matrici.resize(3);
			//V
			vector_de_matrici[0] = muta_vest(v_poz[0], v_poz[1], mat);

			//E
			vector_de_matrici[1] = muta_est(v_poz[0], v_poz[1], mat);

			//S
			vector_de_matrici[2] = muta_sud(v_poz[0], v_poz[1], mat);
		}
		else
			if (v_poz[0] == mat.size()-1 && v_poz[1] != 0 && v_poz[1] != mat.size() - 1)
			{
				vector_de_matrici.resize(3);
				//V
				vector_de_matrici[0] = muta_vest(v_poz[0], v_poz[1], mat);

				//E
				vector_de_matrici[1] = muta_est(v_poz[0], v_poz[1], mat);

				//N
				vector_de_matrici[2] = muta_nord(v_poz[0], v_poz[1], mat);
			}
			else
				if (v_poz[1] == mat.size() - 1 && v_poz[0] != 0 && v_poz[0] != mat.size() - 1)
				{
					vector_de_matrici.resize(3);
					//V
					vector_de_matrici[0] = muta_vest(v_poz[0], v_poz[1], mat);

					//S
					vector_de_matrici[1] = muta_sud(v_poz[0], v_poz[1], mat);

					//N
					vector_de_matrici[2] = muta_nord(v_poz[0], v_poz[1], mat);
				}
				else
					if (v_poz[1] == 0 && v_poz[0] != 0 && v_poz[0] != mat.size() - 1)
					{
						vector_de_matrici.resize(3);

						//E
						vector_de_matrici[0] = muta_est(v_poz[0], v_poz[1], mat);

						//S
						vector_de_matrici[1] = muta_sud(v_poz[0], v_poz[1], mat);

						//N
						vector_de_matrici[2] = muta_nord(v_poz[0], v_poz[1], mat);
					}
					else
						if (v_poz[1] == 0 && v_poz[0] == 0) {

							vector_de_matrici.resize(2);

							//E
							vector_de_matrici[0] = muta_est(v_poz[0], v_poz[1], mat);

							//S
							vector_de_matrici[1] = muta_sud(v_poz[0], v_poz[1], mat);
						}
						else
							if (v_poz[1] == mat.size()-1 && v_poz[0] == mat.size()-1)
							{

								vector_de_matrici.resize(2);

								//V
								vector_de_matrici[0] = muta_vest(v_poz[0], v_poz[1], mat);

								//N
								vector_de_matrici[1] = muta_nord(v_poz[0], v_poz[1], mat);
							}
							else
								if (v_poz[1] == mat.size() - 1 && v_poz[0] == 0)
								{

									vector_de_matrici.resize(2);

										//V
										vector_de_matrici[0] = muta_vest(v_poz[0], v_poz[1], mat);

										//S
										vector_de_matrici[1] = muta_sud(v_poz[0], v_poz[1], mat);
								}
								else
									if (v_poz[1] == 0 && v_poz[0] == mat.size() - 1)
									{

										vector_de_matrici.resize(2);

										//E
										vector_de_matrici[0] = muta_est(v_poz[0], v_poz[1], mat);

										//N
										vector_de_matrici[1] = muta_nord(v_poz[0], v_poz[1], mat);
									}
	return vector_de_matrici;
}

void afisare(std::vector<std::vector<int>> mat)
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

void afisare_matrici(std::vector<std::vector<int>> mat)
{
	std::vector<std::vector<std::vector<int>>> vector_mat = prelucrare(mat);
	for (int i = 0; i < vector_mat.size(); i++)
	{
		afisare(vector_mat[i]);
		std::cout << "\n";
	}

}
int main()
{
	int dim;
	f >> dim;
	std::vector<std::vector<int>> mat(dim, std::vector<int>(dim));
	citire(mat, dim);
	if (verificare(mat)) {
		afisare_matrici(mat);
	}
	f.close();
	return 0;
}*/

/*9. Se citeste un numar natural n patrat perfect si apoi n numere naturale. Sa
se creeze o matrice patratica care sa contina toate cele n numere citite, in
care elementele sa fie completate:.
a) in spirala in sens invers al acelor de ceas (in sens trigonometric) incepand
din coltul stanga sus
b) in spirala in sensul acelor de ceas incepand din interior/mijloc/pozitie
centrala (pentru n=impar)
Sa se afiseze matricea construita.
Exemplu a):
2 6 7 3 7 1 7 1 5
2 1 7
6 5 1
7 3 7*/

/*#include <iostream>
#include <cmath>
#include <vector>

void citire_vector(std::vector<int>& v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void prelucrare(std::vector<int> v, std::vector<std::vector<int>>& a)
{	
	int k = 0;
	int start = 0;
	int stop = int(sqrt(v.size())) - 1;
	while (k < v.size() - 1 && start != stop) {
		for (int i = start; i < stop; i++)
		{
			if (k > v.size() - 1)
				break;
			else
			{
				a[i][start] = v[k];
				k++;
			}
		}
		for (int j = start; j < stop; j++)
		{
			if (k > v.size() - 1)
				break;
			else
			{
				a[stop][j] = v[k];
				k++;
			}
		}
		for (int i = stop; i >= start + 1; i--)
		{
			if (k > v.size() - 1)
				break;
			else
			{
				a[i][stop] = v[k];
				k++;
			}
		}
		for (int j = stop; j >= start + 1; j--)
		{
			if (k > v.size() - 1)
				break;
			else
			{
				a[start][j] = v[k];
				k++;
			}
		}
		start = start + 1;
		stop = stop - 1;
	}
	if (int(sqrt(v.size())) % 2 == 1)
		a[int(sqrt(v.size())) / 2][int(sqrt(v.size())) / 2] = v[k];
}

void afisare(std::vector<std::vector<int>> a)
{
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> vector;
	int a = int(sqrt(n));
	std::vector<std::vector<int>> mat(a, std::vector<int>(a));
	citire_vector(vector, n);
	prelucrare(vector, mat);
	afisare(mat);
	return 0;
}
*/