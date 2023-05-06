#include "Duck.h"

Duck::Duck(string name, string sound) : BaseAnimal(name, sound)
{
	// Do nothing
}

void Duck::Speak()
{
	cout << BaseAnimal::GetName() << ", the duck, " <<BaseAnimal::GetSound() << "ed." << endl;
}

void Duck::Display()
{
	cout
		<< "Duck" << '\n'
		<< "\tName: " << BaseAnimal::GetName() << '\n'
		<< "\tSound: " << BaseAnimal::GetSound() << '\n';
}