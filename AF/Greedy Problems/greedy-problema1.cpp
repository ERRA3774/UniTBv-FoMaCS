// Avem un numar nelimitat de bancnote de diferite sume fiecare {1, 5, 10, 20, 50, 100, 200, 500}
// Dormin sa aflam care este numarul minim de bancnote utilizate pentru a obtine o suma X citita de la tastatura
// Suma = 70 -> result: 50, 20

#include <iostream>
#include <vector>
#include <algorithm>

struct Bancnota
{
    int val;
    int nr;
};

void citire_val_bancnote(std::vector<int>& val_bancnote)
{
    val_bancnote.clear();
    std::cout << "Cate tipuri de bancnote folositi?" << std::endl;
    int n;
    std::cin >> n;
    val_bancnote.resize(n);
    std::cout << "Introduceti valorile bancnotelor:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val_bancnote[i];
    }
}

std::vector<Bancnota> nrMinimBancnote_generic(std::vector<int> val_bancnote, int suma)
{
    // Se sorteaza descrescator vectorul cu valorile bancnotelor
    std::sort(val_bancnote.begin(), val_bancnote.end(), std::greater<int>());

    int i = 0;
    std::vector<Bancnota> solutie;
    while (suma > 0 && i < val_bancnote.size())
    {
        if (val_bancnote[i] <= suma) // Pot folosi bancnota sa platesc suma
        {
            Bancnota b;
            b.val = val_bancnote[i];
            b.nr = suma / val_bancnote[i];
            solutie.push_back(b);
            suma -= val_bancnote[i] * (suma / val_bancnote[i]);
        }
        i++;
    }

    if (suma != 0) // Nu avem solutie
    {
        std::cout << "Error: Plata nu poate fi facuta." << std::endl;
        solutie.clear();
    }

    return solutie;
}

// Metoda functioneaza daca printre bancnote exista si bancnota cu valoarea 1. In acest fel este asigurata EXISTENTA solutiei
int test_nrMinimBancnote(std::vector<int> val_bancnote, int suma)
{
    int nrBancnote = 0;
    // Se sorteaza descrescator vectorul cu valorile bancnotelor
    std::sort(val_bancnote.begin(), val_bancnote.end(), std::greater<int>());

    int i = 0;
    while (suma > 0)
    {
        if (val_bancnote[i] <= suma) // Pot folosi bancnota sa platesc suma
        {
            nrBancnote += suma / val_bancnote[i];
            std::cout << "S-a folosit bancnota cu valoarea: " << val_bancnote[i] << " de " << suma / val_bancnote[i] << " ori." << std::endl;
            suma -= val_bancnote[i] * (suma / val_bancnote[i]);
        }
        i++;
    }

    return nrBancnote;
}

int main()
{
    std::vector<int> val_bancnote;
    int suma;

    citire_val_bancnote(val_bancnote);
    std::cout << "Introduceti valoarea sumei:\nsuma = ";
    std::cin >> suma;
    
    std::vector<Bancnota> solutie = nrMinimBancnote_generic(val_bancnote, suma);

    if (solutie.empty())
    {
        std::cout << "Nu exista solutie." << std::endl;
    } 
    else 
    {
        for (int i = 0; i < solutie.size(); i++)
        {
            std::cout << "S-a folosit bancnota cu valoarea: " << solutie[i].val << " de " << solutie[i].nr << " ori." << std::endl;
        }
    }

    return 0;
}

/*
Cate tipuri de bancnote folositi?
3
Introduceti valorile bancnotelor:
1 6 10
Introduceti valoarea sumei:
suma = 18
S-a folosit bancnota cu valoarea: 10 de 1 ori.
S-a folosit bancnota cu valoarea: 6 de 1 ori.
S-a folosit bancnota cu valoarea: 1 de 2 ori.
*/

/*
Cate tipuri de bancnote folositi?
8
Introduceti valorile bancnotelor:
1 5 10 20 50 100 200 500
Introduceti valoarea sumei:
suma = 70
S-a folosit bancnota cu valoarea: 50 de 1 ori.
S-a folosit bancnota cu valoarea: 20 de 1 ori.
*/

/*
Cate tipuri de bancnote folositi?
3
Introduceti valorile bancnotelor:
2 6 10
Introduceti valoarea sumei:
suma = 15
Error: Plata nu poate fi facuta.
Nu exista solutie.
*/

