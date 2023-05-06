#include "ProdusAlimentar.h"

ProdusAlimentar::ProdusAlimentar(string denu, string prod, double pret, string data, string unit, double cant) : 
	BaseProdus(denu, prod, pret), m_DataExpirare(data), m_UnitMasura(unit), m_Cantitate(cant)
{
	// Do Nothing
}

ProdusAlimentar::~ProdusAlimentar()
{
	cout << "Apel al destructorului clasei ProdusAlimentar." << endl;
}

void ProdusAlimentar::Afisare()
{
	BaseProdus::Afisare();
	cout
		<< "Data expirare: " << m_DataExpirare << '\n'
		<< "Unitate masura: " << m_UnitMasura << '\n'
		<< "Cantitate: " << m_Cantitate << '\n';
}