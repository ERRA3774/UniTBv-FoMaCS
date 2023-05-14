#include "Keyboard.h"

Keyboard::Keyboard(int price, string name, int noOfButtons) : ComputerPart(price, name), m_NoOfButtons(noOfButtons)
{
	
}

int Keyboard::GetNoOfButtons()
{
	return m_NoOfButtons;
}

void Keyboard::Display()
{
	cout << "Keyboard:\n";
	ComputerPart::Display();
	cout 
		<< "\tNo of buttons: " << m_NoOfButtons << "\n";
}

Keyboard::~Keyboard()
{
	cout << "~Keyboard call." << endl;
}
