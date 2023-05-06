#include "ProdusElectronic.h"

ProdusElectronic::ProdusElectronic(string denu, string prod, double pret, string mode, int cons) :
	BaseProdus(denu, prod, pret), m_Model(mode), m_Consum(cons)
{
	// Do Nothing
}

void ProdusElectronic::Afisare()
{
	BaseProdus::Afisare();
	cout
		<< "Model: " << m_Model << '\n'
		<< "Consum: " << m_Consum << '\n';
}