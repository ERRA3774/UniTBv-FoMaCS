#include "Monitor.h"

Monitor::Monitor(int price, string name, int noOfButtons, string type) : ComputerPart(price, name), m_NoOfButtons(noOfButtons), m_Type(type)
{

}

int Monitor::GetNoOfButtons()
{
	return m_NoOfButtons;
}

void Monitor::Display()
{
	cout << "Monitor:\n";
	ComputerPart::Display();
	cout 
		<< "\tNo of buttons: " << m_NoOfButtons << "\n"
		<< "\tType:          " << m_Type << "\n";
}

Monitor::~Monitor()
{
	cout << "~Monitor call" << endl;
}
