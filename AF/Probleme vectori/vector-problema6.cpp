// Se citesc doua numere naturale n si m si doi vectori crescatori de lungime n, respectiv m
// Sa se creeze si sa se afiseze vectorul ordonat crescator obtinut prin reuniunea celor doi vectori
// Ex: v1 = 1,2,5,10,13,20
//     v2 = 1,6,7,9,15,25
// Afisare: 1,1,2,5,6,7,9,10,13,15,20,25
// 

#include <iostream>
#include <vector>
#include <algorithm>

void citire_vector(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
void reunire_vectori(std::vector<int>& vec1, std::vector<int>& vec2);
void print_tests();

int main()
{
    print_tests();

    std::vector<int> vec_destinatie;
    std::vector<int> vec_sursa;
    citire_vector(vec_destinatie);
    citire_vector(vec_sursa);
    reunire_vectori(vec_destinatie, vec_sursa);
    afisare_vector(vec_destinatie);
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

void afisare_vector(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void reunire_vectori(std::vector<int>& vec1, std::vector<int>& vec2)
{
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    sort(vec1.begin(), vec1.end());
}

void print_tests()
{
    std::vector<int> vec_destinatie_0{ 1,2,5,10,13,20 };
    std::vector<int> vec_sursa_0{ 1,6,7,9,15,25 };
    reunire_vectori(vec_destinatie_0, vec_sursa_0);
    afisare_vector(vec_destinatie_0);
}
