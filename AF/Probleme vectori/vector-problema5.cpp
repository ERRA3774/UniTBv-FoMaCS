// Se da un vector v cu n elemente.
// Sa se elimine din vector elementul cu indicele de pozitie p (citit de la tastatura)
// iar p sa se insereze la inceputul vectorului
// Sa se afiseze noul vector
// Ex: v = 2, 51, 2, 91, 3; p = 3, afiseaza: 3, 2, 51, 2, 3

#include <iostream>
#include <vector>

void citire_vector(std::vector<int>& vec);
int citire_pozitie();
void afisare_vector(std::vector<int>& vec);
void eliminare_inserare(std::vector<int>& vec);
void eliminare_inserare(std::vector<int>& vec, int p);
void print_tests();

int main()
{
    print_tests();
    std::vector<int> vec;
    citire_vector(vec);
    eliminare_inserare(vec);
    afisare_vector(vec);
}

void citire_vector(std::vector<int>& vec)
{
    int n;

    std::cout << "Introduceti un numar natural.\nn = ";
    std::cin >> n;

    vec.resize(n);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cin >> vec[i];
    }
}

int citire_pozitie()
{
    int p;

    std::cout << "Introduceti un numar natural.\np = ";
    std::cin >> p;

    return p;
}

void afisare_vector(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
}

void eliminare_inserare(std::vector<int>& vec)
{
    int p = citire_pozitie();
    vec.erase(vec.begin() + p);
    vec.insert(vec.begin(), p);
}

void eliminare_inserare(std::vector<int>& vec, int p)
{
    vec.erase(vec.begin() + p);
    vec.insert(vec.begin(), p);
}

void print_tests()
{
    std::vector<int> vec0{ 2,51,2,91,3 };
    eliminare_inserare(vec0, 3);
    afisare_vector(vec0);

    std::vector<int> vec1{ 1, 2, 3, 4, 5, 6, 0, 7 };
    eliminare_inserare(vec1, 6);
    afisare_vector(vec1);
}

