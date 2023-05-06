#include "BaseAnimal.h"

BaseAnimal::BaseAnimal(string name, string sound) : m_Name(name), m_Sound(sound)
{
	// Do nothing
}

string BaseAnimal::GetName()
{
	return m_Name;
}

string BaseAnimal::GetSound()
{
	return m_Sound;
}

void BaseAnimal::Speak()
{
	cout << "BaseAnimal Speaks" << endl;
}

void BaseAnimal::Display()
{
	cout
		<< "Animal name: " << m_Name << "\n"
		<< "Animal sound: " << m_Sound << "\n";
}