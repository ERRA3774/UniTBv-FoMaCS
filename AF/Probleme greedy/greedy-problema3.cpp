// Se da o bucata de hartie de dimensiune A x B.
// Hartia se taie in patrate de orice dimensiune.
// Gasiti numarul mini de patrate in care poate taia
// Exemplu: 13 x 29 = 2 (13x13) + 4 (3x3) + 3(1x1) = 9 bucati
// Dreptunghi:
// A = 13
// B = 29

#include <iostream>
#include <vector>
#include <algorithm>

struct Hartie
{
    int lungime;
    int latime;
};

void citire_hartie(Hartie& hartie)
{
    std::cout << "Introduceti dimensiunile hartiei.\nlungime = ";
    std::cin >> hartie.lungime;
    std::cout << "latime = ";
    std::cin >> hartie.latime;
}

int nr_patrate(Hartie& hartie)
{
    int patrate = 1;
    while (hartie.lungime != 1 || hartie.latime != 1)
    {
        if (hartie.latime > hartie.lungime)
        {
            std::swap(hartie.lungime, hartie.latime);
        }

        while (hartie.lungime > hartie.latime)
        {
            hartie.lungime -= hartie.latime;
            patrate++;
        }
    }
    return patrate;
}

int main()
{
    Hartie hartie;
    citire_hartie(hartie);
    std::cout << nr_patrate(hartie);
}

