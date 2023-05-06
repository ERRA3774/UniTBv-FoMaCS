#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class BaseProdus
{
public:
	BaseProdus(string = "-", string = "-", double = 0);

	string GetDenumire();
	virtual void Afisare();

	~BaseProdus();
protected:
	string m_Producator;
	string m_Denumire;
	double m_Pret;
	
private:
};
