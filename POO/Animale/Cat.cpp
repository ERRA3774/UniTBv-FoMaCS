#include "Cat.h"

Cat::Cat(string name, string sound) : BaseAnimal(name, sound)
{
	// Do nothing
}

void Cat::Speak()
{
	cout << BaseAnimal::GetName() << ", the cat, " << BaseAnimal::GetSound() << "ed." << endl;
}

void Cat::Display()
{
	cout
		<< "Cat" << '\n'
		<< "\tName: " << BaseAnimal::GetName() << '\n'
		<< "\tSound: " << BaseAnimal::GetSound() << '\n';
}