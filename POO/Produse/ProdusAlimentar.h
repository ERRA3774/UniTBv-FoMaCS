#pragma once
#include "BaseProdus.h"
class ProdusAlimentar : public BaseProdus
{
public:
	ProdusAlimentar(string = "-", string = "-", double = 0, string = "-", string = "-", double = 0);
	
	void Afisare();

	~ProdusAlimentar();
private:
	string m_DataExpirare;
	string m_UnitMasura;
	double m_Cantitate;
};

