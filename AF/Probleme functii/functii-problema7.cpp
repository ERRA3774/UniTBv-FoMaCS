// Sa se verifice daca cifrele lui n sunt in progresie aritmetica
// Exemplu n = 2596
// Se va afisa: Cifrele lui 2596 nu sunt in progresie aritmetica
// Exemplu n = 2468
// Se va afisa: Cifrele lui 2468 sunt in progresie aritmetica

#include <iostream>

void print_other_test_cases();

void print_number_with_digits_in_artihmetic_progression(int n)
{
    int temp_n = n;
    int d = temp_n % 10;
    temp_n /= 10;
    int diff = -1;
    while (temp_n > 0)
    {
        int prev_d = d;
        d = temp_n % 10;
        int diff_d = d - prev_d;
        if (diff == -1)
        {
            diff = diff_d;
        }
        else if (diff_d != diff)
        {
            std::cout << n << "'s digits are NOT in an artihmetic progression." << std::endl;
            std::cout << std::endl;
            return;
        }
        temp_n /= 10;
    }

    std::cout << n << "'s digits are in an arithmetic progression." << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << "Please input a natural number.\nn = ";
    int n;
    std::cin >> n;

    print_number_with_digits_in_artihmetic_progression(n);

    print_other_test_cases();

    return 0;
}

void print_other_test_cases()
{
    print_number_with_digits_in_artihmetic_progression(2468);
    print_number_with_digits_in_artihmetic_progression(2596);
    print_number_with_digits_in_artihmetic_progression(1234);
    print_number_with_digits_in_artihmetic_progression(4321);
    print_number_with_digits_in_artihmetic_progression(1111);
    print_number_with_digits_in_artihmetic_progression(1010);
}
