#pragma once
#include "BaseAnimal.h"
class Cat :
    public BaseAnimal
{
public:
    Cat(string, string = "meow");

    void Speak();
    void Display();

private:
    string m_Name;
};

