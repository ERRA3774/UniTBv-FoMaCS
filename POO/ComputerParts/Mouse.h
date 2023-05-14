#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Mouse : public ComputerPart, public HasButtons
{
public:
	Mouse(int price, string name, int noOfButtons, string type);
	int GetNoOfButtons();
	void Display();
	~Mouse();
private:
	int m_NoOfButtons;
	string m_Type;
};

