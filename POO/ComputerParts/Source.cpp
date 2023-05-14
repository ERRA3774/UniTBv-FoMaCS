// Sa se scrie o ierarhie de computer parts
// Clasa ComputerPart sa aiba doua metode: 
//	GetPrice() 
//	GetName()
// Derivat din ComputerParts sa fie: 
//	HDD
//	Display
//	Mouse
//	Keyboard
// Sa se scrie doua clase abstracte (interfete) :
// HasButtons -> cu metoda GetNoOfButtons()
// HasMemory -> cu metoda GetCapacity()
// 
// Unde este cazul, clasele derivate din ComputerPart trebuie sa implementeze si una din cele doua interfete
// Sa se creeze un vector cu ComputerPart 
//

#include <iostream>
#include <vector>

#include "Monitor.h"
#include "Mouse.h"
#include "HDD.h"
#include "Keyboard.h"

using std::vector;
int main()
{
	vector<ComputerPart*> components;

	Monitor monitor1(20, "DELL", 4, "LED");
	Keyboard keyboard1(50, "RAZER", 200);
	Mouse mouse1(5, "RAZER", 12, "Gaming");
	HDD hdd1(300, "Kingston", 2);

	Keyboard* keyboard2 = new Keyboard(10, "jsa", 123);
	ComputerPart* compPart = keyboard2;

	components.emplace_back(&monitor1);
	components.emplace_back(&keyboard1);
	components.emplace_back(&mouse1);
	components.emplace_back(&hdd1);


	for (auto& comp : components)
	{
		comp->Display();
	}
	cout << "-------------------------------------" << endl;

	vector<Keyboard*> keyboards;

	for (auto& comp : components)
	{
		if (dynamic_cast<HasButtons*>(comp))
		{
			keyboards.emplace_back(dynamic_cast<Keyboard*>(comp));
			comp->Display();
		}
	}

	delete compPart;

	std::cin.get();

	return EXIT_SUCCESS;
}
