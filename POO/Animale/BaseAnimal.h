#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class BaseAnimal
{
public:
	BaseAnimal(string, string);

	string GetName();
	string GetSound();

	virtual void Speak();
	virtual void Display();
private:
	string m_Name;
	string m_Sound;
};

