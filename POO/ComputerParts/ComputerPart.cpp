#include "ComputerPart.h"

ComputerPart::ComputerPart(int price, string name) : m_Price(price), m_Name(name)
{

}

int ComputerPart::GetPrice()
{
	return m_Price;
}

string ComputerPart::GetName()
{
	return m_Name;
}

void ComputerPart::Display()
{
	cout 
		<< "\tPrice:         " << m_Price << "\n"
		<< "\tName:          " << m_Name << "\n";
}

ComputerPart::~ComputerPart()
{
	cout << "~ComputerPart call." << endl;
}
