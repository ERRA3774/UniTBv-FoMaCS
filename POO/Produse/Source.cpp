/*
BaseProdus
-denumire
-producator
-pret

	ProdusAlimentar
	-dataExpirare
	-unitateMasura
	-cantitate

	ProdusCosmetic
	-dataEpirare
	-tip

	ProducElectronic
	-model
	-consum
*/

#include "ProdusAlimentar.h"
#include "ProdusCosmetic.h"
#include "ProdusElectronic.h"
#include <vector> 
using std::vector;

void TestProduse()
{
	ProdusAlimentar pa1("Lapte", "Dorna", 8.5, "25/5/2023", "litru", 1);
	ProdusAlimentar pa2("Paine", "Vel Pitar", 16.5, "10/5/2023", "gram", 500);
	ProdusCosmetic pc1("Sampon", "L'Oreal", 14, "31/12/2023", "Par Vopsit");
	ProdusElectronic pe1("Telefon", "Samsung", 950, "S15", 1);
	pa1.Afisare();
	pc1.Afisare();
	pe1.Afisare();

	cout << "---------------------------------------------" << endl;
	BaseProdus bp1;

	bp1 = pa1;

	bp1.Afisare();
	cout << "---------------------------------------------" << endl;
	ProdusAlimentar* ppa1 = &pa1, * ppa2 = &pa2;
	ProdusCosmetic* ppc1 = &pc1;
	ProdusElectronic* ppe1 = &pe1;

	BaseProdus* pbp1 = &bp1;
	pbp1 = ppe1;
	pbp1->Afisare();
	cout << "---------------------------------------------" << endl;
	vector<BaseProdus> produse;
	produse.push_back(pa1);
	produse.push_back(pc1);
	produse.push_back(pe1);

	for (int i = 0; i < produse.size(); i++)
	{
		produse[i].Afisare();
	}
	cout << "---------------------------------------------" << endl;
	vector<BaseProdus*> pProduse;
	pProduse.push_back(ppa1);
	pProduse.push_back(ppc1);
	pProduse.push_back(ppe1);
	for (int i = 0; i < pProduse.size(); i++)
	{
		pProduse[i]->Afisare();
	}
	cout << "---------------------------------------------" << endl;
}

int main()
{
	return EXIT_SUCCESS;
}
