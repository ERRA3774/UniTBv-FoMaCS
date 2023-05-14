#pragma once
#include "ComputerPart.h"
#include "HasMemory.h"

class HDD :
    public ComputerPart, public HasMemory
{
public:
    HDD(int price, string name, int capacity);
    int GetCapacity();
    void Display();
    ~HDD();
private:
    int m_Capacity;
};

