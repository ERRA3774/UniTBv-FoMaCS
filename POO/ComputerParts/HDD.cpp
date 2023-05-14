#include "HDD.h"

HDD::HDD(int price, string name, int capacity) : ComputerPart(price, name), m_Capacity(capacity)
{

}

int HDD::GetCapacity()
{
	return m_Capacity;
}

void HDD::Display()
{
	cout << "HDD:\n";
	ComputerPart::Display();
	cout 
		<< "\tCapacity:      " << m_Capacity << "\n";
}

HDD::~HDD()
{
	cout << "~HDD call." << endl;
}
