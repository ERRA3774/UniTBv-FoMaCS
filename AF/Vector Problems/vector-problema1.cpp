// Se citeste un numar natural n si cele n elemente ale vectorului
// Sa se inlocuiasca elementele de pe pozitii pare cu cea mai mica cifra din numar
// iar cele de pe pozitii impare 
// cu 0 daca numarul e prim
// cu 1 altfel

#include <iostream>
#include <vector>
#include <cmath>

void citire_vector(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
bool este_prim(int x);
int min_cifra(int x);
void inlocuieste_elementele(std::vector<int>& vec);
void print_other_test_cases();

int main()
{
    print_other_test_cases();

    std::vector<int>vec;
    citire_vector(vec);
    inlocuieste_elementele(vec);
    afisare_vector(vec);
}

void citire_vector(std::vector<int>& vec)
{
    int n;
    std::cout << "Please input a natural number.\nn = ";
    std::cin >> n;

    vec.resize(n);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cin >> vec[i];
    }
}

void afisare_vector(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
}

bool este_prim(int x)
{
    if (x <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int min_cifra(int x)
{
    int min = x % 10;
    x /= 10;
    while (x != 0)
    {
        if (min > x % 10)
        {
            min = x % 10;
        }
        x /= 10;
    }
    return min;
}

void inlocuieste_elementele(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (i % 2 == 0)
        {
            vec[i] = min_cifra(vec[i]);
        }
        else
        {
            este_prim(vec[i]) ? vec[i] = 0 : vec[i] = 1;
        }
    }
}

void print_other_test_cases()
{                                                     
    std::vector<int> vec0{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };           // -> 0 1 0 1 0 1 0 1 0 1
    inlocuieste_elementele(vec0);
    afisare_vector(vec0);

    std::vector<int> vec1{ 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 }; // -> 0 1 2 0 2 1 2 1 2 0
    inlocuieste_elementele(vec1);
    afisare_vector(vec1);

    std::vector<int> vec2{ 11, 62, 45, 39, 90, 73, 86, 78, 81, 21 }; // -> 1 1 4 1 0 0 6 1 1 1
    inlocuieste_elementele(vec2);
    afisare_vector(vec2);
}