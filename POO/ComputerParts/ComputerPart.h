#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ComputerPart
{
public:
	ComputerPart(int price, string name);
	int GetPrice();
	string GetName();

	virtual void Display();

	virtual ~ComputerPart();
protected:
	int m_Price;
	string m_Name;
};

