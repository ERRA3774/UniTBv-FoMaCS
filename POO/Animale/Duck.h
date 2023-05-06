#pragma once
#include "BaseAnimal.h"
class Duck :
    public BaseAnimal
{
public:
    Duck(string, string = "quack");

    void Speak();
    void Display();

private:
    string m_Name;
};

