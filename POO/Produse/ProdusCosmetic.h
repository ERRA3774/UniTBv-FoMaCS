#pragma once
#include "BaseProdus.h"
class ProdusCosmetic : public BaseProdus
{
public:
	ProdusCosmetic(string = "-", string = "-", double = 0, string = "-", string = "-");

	void Afisare();

private:
	string m_DataExpirare;
	string m_Tip;
};

