//inca din lab 2

/*
vectori
-static (
->alocarea de memorie se face la compilare
->zona de mem alocata este nemodificabila i timpul rularii aplicatiei
tip_date nume_vector[dim_max] dim max=ct

-alocat dinamic
->alocarea de mem se face in momentul rularii aplicatiei in functie de necesarul de memorie in acel moment
->AVANTAJ: redimensionarea zonei de memorie asociata vectorului poate fi facuta in timpul rularii aplicatiei
->DEZAVANTAJ: redimensionarea/dealocarea sunt in atributiile programatorului
->alocare: se foloseste operatorul new; el returneaza adresa zonei de memorie unde a fost rezervat spatiu pentru variabila/vectorul nostru
->alocare pt o var:
double* adresa = new double
->alocare pt vector
double* vect=new double[dim]

->dealocarea zonei de mem se face fol operatorul delete:
->o var:
delete adresa
--> un vector
delete[] vector
*/

#include "Citiri_afisari.h"
#include <iostream>


void eliminare_element(int poz, int& dim, int*& vect) {
	if (poz > dim - 1) {
		std::cout << "Pozitia specificata este invalida";
		return;
	}
	int* vect_nou = new int[dim - 1];
	for (int i = 0; i < poz; i++)
	{
		vect_nou[i] = vect[i];
	}
	for (int i = poz+1; i < dim; i++)
	{
		vect_nou[i-1] = vect[i];
	}
	delete[] vect;
	vect = vect_nou;
	dim--;
}

void stergere_elemente(int& dim, int*& vect) 
{
	int* vect_poz = new int[dim - 2];
	int k = 0;
	//determinarea pozitiilor care trebuie sterse
	for (int i = 1; i < dim-1; i++) {
		if (vect[i] == vect[i - 1] + vect[i + 1]) 
		{
			vect_poz[k++] = i;
		}
	}
	int contor = 0;
	for (int i = 0; i < k; i++) {
		eliminare_element(vect_poz[i]-contor, dim, vect);
		contor++;
	}
}

//deplasarea elementelor cu k pozitii spre dreapta - primele k elemente devin 0
int* inserare_zerouri(int dim, int* vect, int& dim_vector_nou) 
{
	int k;
	std::cout << "Introduceti nr de zerouri de inserat: ";
	std::cin >> k;
	int* vect_nou = new int[dim + k];
	for (int i = 0; i < dim; i++)
	{
		vect_nou[i + k] = vect[i];
	}
	for (int i = 0; i < k; i++) {
		vect_nou[i] = 0;
	}
	dim_vector_nou = dim + k;
	return vect_nou;
}

//permutarea circulara cu k pozitii; facem permutari circulare de cate o pozitie si repetam de k ori
void permutare(int dim, int* vector) {
	//nu transmitem prin referinta ca adresa de inceput nu se modifica
	int k;
	std::cout << "Introduceti nr de pozitii ";
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		int aux = vector[dim - 1];
		for(int j=dim-1;j>0;j--)
		{
			vector[j] = vector[j - 1];
		}
		vector[0] = aux;
	}
}


int main() {
	/*int dim; // vect[10];
	int* vect = nullptr;
	citire_vector(dim, vect);
	afisare_vector(dim, vect);*/
	//declararea unui vector stl
	//std::vector<int> myVector;

	/*
	//dim vectorului este data de size()
	std::cout << myVector.size() << " ";

	//adaugarea in vector - la sfarsit
	myVector.push_back(10);
	myVector.push_back(5);

	//std::cout << myVector.size() << " ";

	//adaugare/inserare pe pozitie specificata
	//poz se speciffica ca si adresa
	myVector.insert(myVector.begin() + 1, 7);
	myVector.insert(myVector.begin(), 3);
	
	//stergere din vector - de la sfarsit
	myVector.pop_back();

	//stergere din vector de pe o anumita pozitie specificata ca si adresa
	myVector.erase(myVector.begin());

	//dimensionarea vectorului
	myVector.resize(7);//daca dim e mai mica taie si reduce dim, nu pune si 3 pe poz aia

	for (int i = 0; i < myVector.size(); i++)
		std::cout << myVector[i] << " ";*/

	int* vector = nullptr;
	int dim;
	/*
	//pb2
	citire_vector(dim, vector);
	//eliminare_element(1, dim, vector);
	stergere_elemente(dim, vector);
	afisare_vector(dim, vector);*/
	
	//citire_vector(dim, vector);
	//int dim_vector_nou=0;
	//int* vect_nou = inserare_zerouri(dim, vector, dim_vector_nou);
	//afisare_vector(dim_vector_nou, vect_nou);

	citire_vector(dim, vector);
	permutare(dim, vector);
	afisare_vector(dim, vector);
}

//tema ne gandim cum facem permutarile deodata