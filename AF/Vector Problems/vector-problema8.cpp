// Un numar natural se retine intr-un vector (numar mare)
// astfel incat fiecare componenta a vectorului contine cate o cifra a numarului
// Sa se inmulteasca numarul cu un numar intre 1 si 9 (generat random).

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<int> vector_din_nr_random();
void inmultire_cu_nr_random(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
void print_tests();

int main()
{
    print_tests();

    std::vector<int> vec = vector_din_nr_random();
    afisare_vector(vec);
    inmultire_cu_nr_random(vec);
    afisare_vector(vec);
}

std::vector<int> vector_din_nr_random()
{
    std::srand(std::time(0));
    int nr_random = std::rand();
    std::vector<int> vec;

    while (nr_random > 0)
    {
        vec.push_back(nr_random % 10);
        nr_random /= 10;
    }

    return vec;
}

void inmultire_cu_nr_random(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int nr_random = (std::rand() % 9) + 1;
        std::cout << vec[i] << " * " << nr_random << " = " << vec[i] * nr_random << std::endl;
        vec[i] *= nr_random;
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

void print_tests()
{
    std::vector<int> vec0{ 0,1,2,3,4,5,6,7,8,9 };
    afisare_vector(vec0);
    inmultire_cu_nr_random(vec0);
    afisare_vector(vec0);
}

