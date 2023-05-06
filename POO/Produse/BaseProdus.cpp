#include "BaseProdus.h"

BaseProdus::BaseProdus(string denu, string prod, double pret) : m_Denumire(denu), m_Producator(prod), m_Pret(pret)
{
	// Do Nothing
}

BaseProdus::~BaseProdus()
{
	cout << "Apel al destructorului clasei Produs." << endl;
}

void BaseProdus::Afisare()
{
	cout
		<< "Denumire: " << m_Denumire << '\n'
		<< "Producator: " << m_Producator << '\n'
		<< "Pret: " << m_Pret << '\n';
}