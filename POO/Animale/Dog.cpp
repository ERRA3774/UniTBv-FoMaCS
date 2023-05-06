#include "Dog.h"

Dog::Dog(string name, string sound) : BaseAnimal(name, sound)
{
	// Do nothing
}

void Dog::Speak()
{
	cout << BaseAnimal::GetName() << ", the dog, " << BaseAnimal::GetSound() << "ed." << endl;
}

void Dog::Display()
{
	cout
		<< "Dog" << '\n'
		<< "\tName: " << BaseAnimal::GetName() << '\n'
		<< "\tSound: " << BaseAnimal::GetSound() << '\n';
}