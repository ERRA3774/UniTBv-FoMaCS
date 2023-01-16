// Se citesc un numar natural n de maxim 3 cifre si o cifra c
// Eliminati toate aparitiile cifrei c din numarul n si afisati numarul obtinut
// Exemplu: n = 2345324 
//          c =       2
// Rezulta        34534

#include <iostream>

void print_other_test_cases();

int remove_digit(int n, int c)
{
	int reversed_n = 0;

	while (n > 0)
	{
		int d = n % 10;

		if (d != c)
		{
			reversed_n = reversed_n * 10 + d;
		}
		n /= 10;
	}

	int result = 0;

	while (reversed_n > 0)
	{
		int d = reversed_n % 10;
		result = result * 10 + d;
		reversed_n /= 10;
	}

	return result;
}

int main()
{
	int n, c;
	std::cout << "Please input a natural number.\nn = ";
	std::cin >> n;

	do {
		std::cout << "Please input a digit to remove.\nc = ";
		std::cin >> c;
		if (c > 9)
		{
			std::cout << "Error: Input must be a positive number less than 10." << std::endl;
		}
	} while (c > 9);

	std::cout << remove_digit(n, c) << std::endl;
	
	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	std::cout << remove_digit(2345324, 2) << std::endl;
	std::cout << remove_digit(1111111, 0) << std::endl;
	std::cout << remove_digit(1111111, 1) << std::endl;
	std::cout << remove_digit(1234567, 2) << std::endl;
	std::cout << remove_digit(1230123, 3) << std::endl;
	std::cout << remove_digit(1230507, 0) << std::endl;
	std::cout << remove_digit(1020304, 1) << std::endl;
}

