#pragma once
#include "BaseProdus.h"
class ProdusElectronic : public BaseProdus
{
public:
	ProdusElectronic(string = "-", string = "-", double = 0, string = "-", int = 0);
	void Afisare();

private:
	string m_Model;
	int m_Consum;
};

