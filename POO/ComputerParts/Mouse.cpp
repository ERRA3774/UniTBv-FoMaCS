#include "Mouse.h"

Mouse::Mouse(int price, string name, int noOfButtons, string type) : ComputerPart(price, name), m_NoOfButtons(noOfButtons), m_Type(type)
{

}

int Mouse::GetNoOfButtons()
{
	return m_NoOfButtons;
}

void Mouse::Display()
{
	cout << "Mouse:\n";
	ComputerPart::Display();
	cout
		<< "\tNo of buttons: " << m_NoOfButtons << "\n"
		<< "\tType:          " << m_Type << "\n";
}

Mouse::~Mouse()
{
	cout << "~Mouse call." << endl;
}
