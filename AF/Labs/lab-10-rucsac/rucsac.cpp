#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Obiect
{
    float greutate, pret;
};

std::vector<Obiect> citire_ob(std::string nume_fisier)
{
    int n;
    std::vector<Obiect> obiecte;
    std::ifstream fisier_intrare(nume_fisier);
    fisier_intrare >> n;
    obiecte.resize(n);
    for (int i = 0; i < n; i++)
    {
        fisier_intrare >> obiecte[i].greutate >> obiecte[i].pret;
    }
    return obiecte;
}

// 10/200 == 20/400
bool comparator_pret_unitate(Obiect o1, Obiect o2)
{
    if (o1.pret / o1.greutate > o2.pret / o2.greutate)
    {
        return true;
    }

    if (o1.pret / o1.greutate == o2.pret / o2.greutate)
    {
        return o1.greutate > o2.greutate;
    }

    return false;
}

std::vector<Obiect> umplere_rucsac_discret(std::vector<Obiect> obiecte, float greutate_rucsac)
{
    std::sort(obiecte.begin(), obiecte.end(), comparator_pret_unitate);

    std::vector<Obiect> sol;

    int i = 0;
    int profit = 0;
    while (greutate_rucsac && i < obiecte.size())
    {
        if (obiecte[i].greutate <= greutate_rucsac) // daca obiectul curent mai incape in rucsac
        {
            sol.push_back(obiecte[i]); // adaug obiectul curent la solutie
            greutate_rucsac -= obiecte[i].greutate;
            profit += obiecte[i].pret;
        }
        i++;
    }
    std::cout << "Profit: " << profit << std::endl;
    return sol;
}

int main()
{
    std::vector<Obiect> obiecte = citire_ob("Obiecte.txt");
    float greutate;
    std::cout << "Introduceti greutatea.\ngreutate = ";
    std::cin >> greutate;

    std::vector<Obiect> sol = umplere_rucsac_discret(obiecte, greutate);

    std::cout << std::endl;
    for (int i = 0; i < sol.size(); i++)
    {
        std::cout << sol[i].greutate << " " << sol[i].pret << "\n";
    }
}
