/*
Sa se creeze clase care sa poata modela animale precum 
cainele
pisica 
rata

Fiecare dintre clase sa aiba 
constructori
o metoda de afisare 
o metoda care reda sunetul specific al animalului.

Sa se creeze animale diferite si sa se retina toate in aceeasi structura. 
Sa se parcurga aceasta si sa se apeleze la parcurgere metodele de afisare si redare sunet specific().
*/

#include "Dog.h"
#include "Cat.h"
#include "Duck.h"
#include <vector>
using std::vector;

int main()
{
	Dog dog1("Beethoven");
	Dog dog2("Lassy");
	Dog dog3("Toto");

	Cat cat1("Missy");
	Cat cat2("Grumpy");
	Cat cat3("Felix");

	Duck duck1("Donald");
	Duck duck2("Daisy");
	Duck duck3("Daffy");

	vector<BaseAnimal*> animals;
	animals.emplace_back(&dog1);
	animals.emplace_back(&dog2);
	animals.emplace_back(&dog3);
	animals.emplace_back(&cat1);
	animals.emplace_back(&cat2);
	animals.emplace_back(&cat3);
	animals.emplace_back(&duck1);
	animals.emplace_back(&duck2);
	animals.emplace_back(&duck3);

	for (const auto& an : animals)
	{
		an->Speak();
		an->Display();
	}
}