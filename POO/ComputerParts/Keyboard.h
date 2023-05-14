#pragma once
#include "ComputerPart.h"
#include "HasButtons.h"

class Keyboard :
    public ComputerPart, public HasButtons
{
public:
    Keyboard(int price, string name, int noOfButtons);
    int GetNoOfButtons();
    void Display();
    ~Keyboard();

private:
    int m_NoOfButtons;

};

