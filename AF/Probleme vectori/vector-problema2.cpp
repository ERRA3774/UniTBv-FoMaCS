// Se citeste un numar natural n si cele n elemente ale unui vector
// Sa se stearga din vector acele elemente care sunt egale cu suma vecinilor sai.

#include <iostream>
#include <vector>
#include <algorithm>

void citire_vector(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
void afisare_vector(std::vector<int>& vec);
bool este_egal_cu_suma_veciniilor(std::vector<int>& vec, int target, int start);
void sterge_elemente(std::vector<int>& vec);
void print_other_test_cases();

int main() 
{
    print_other_test_cases();

    std::vector<int> vec;
    citire_vector(vec);
    sterge_elemente(vec);
}

void citire_vector(std::vector<int>& vec)
{
    int n;

    std::cout << "Please input a natural number.\nn = ";
    std::cin >> n;

    vec.resize(n);

    for (int i = 0; i < n; i++)
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

bool este_egal_cu_suma_veciniilor(std::vector<int>& vec, int target, int start)
{
    return target == (vec[start - 1] + vec[start + 1]);
}

void sterge_elemente(std::vector<int>& vec)
{
    int start = 1;

    while (start != vec.size() - 1 )
    {
        int target = vec[start];
        if (este_egal_cu_suma_veciniilor(vec, target, start))
        {
            vec.erase(vec.begin() + start);
            afisare_vector(vec);
            start--;
        }
        else
        {
            start++;
        }

        if (start == 0)
        {
            start = 1;
        }
    }
}

void print_other_test_cases()
{
    std::vector<int> vec0{ 1, 2, 1 }; // -> 1 1
    afisare_vector(vec0);
    sterge_elemente(vec0);
    std::vector<int> vec1{ 1, 2, 1, 2, 1 }; // -> 1 1 1
    afisare_vector(vec1);
    sterge_elemente(vec1);
    std::vector<int> vec2{ 0, 0, 0, 0, 0 }; // -> 0 0 
    afisare_vector(vec2);
    sterge_elemente(vec2);
    std::vector<int> vec3{ 1, 1, 6, 8, 2, 1, 3, 4, 1 }; // -> 1 1 6 2 1 4 1
    afisare_vector(vec3);
    sterge_elemente(vec3);
    std::vector<int> vec4{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1}; // -> 1 1
    afisare_vector(vec4);
    sterge_elemente(vec4);
}