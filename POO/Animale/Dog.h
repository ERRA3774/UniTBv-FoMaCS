#pragma once
#include "BaseAnimal.h"
class Dog :
    public BaseAnimal
{
public:
    Dog(string, string sound = "bark");

    void Speak();
    void Display();

private:
    string m_Name;
};

