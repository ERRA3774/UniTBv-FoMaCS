#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Monitor : public ComputerPart, public HasButtons
{
public:
	Monitor(int price, string name, int noOfButtons, string type);
	int GetNoOfButtons();
	void Display();
	~Monitor();
private:
	int m_NoOfButtons;
	string m_Type;
};

