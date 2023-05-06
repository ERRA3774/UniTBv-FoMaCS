#include "ProdusCosmetic.h"

ProdusCosmetic::ProdusCosmetic(string denu, string prod, double pret, string data, string tip) : 
	BaseProdus(denu, prod, pret), m_DataExpirare(data), m_Tip(tip)
{
	// Do Nothing
}

void ProdusCosmetic::Afisare()
{
	BaseProdus::Afisare();
	cout
		<< "DataExpirare: " << m_DataExpirare << '\n'
		<< "Tip: " << m_Tip << '\n';
}