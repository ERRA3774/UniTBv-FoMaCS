// Se citeste un numar natural n cu numar par de cifre
// Calculati si afisati numarul obtinut din n 
// inversand cifra unitatilor cu a zecilor
// cea a sutelor cu cea a miilor, etc
// Exemplu: n = 123456
// Rezulta: n = 214365

#include <iostream>

void print_other_test_cases();

int reverse(int n)
{
	int result = 0;

	while (n > 0)
	{
		int digit = n % 10;
		result = result * 10 + digit;
		n /= 10;
	}

	return result;
}

int switch_digits(int n)
{
	int result = 0;

	while (n > 0)
	{
		int first = n % 10;
		int second = (n / 10) % 10;
		result = (result * 10 + second) * 10 + first;
		n /= 100;
	}

	return reverse(result);
}

int main()
{
	int n;

	do {
		std::cout << "Please input a natural number.\nn = ";
		std::cin >> n;
		if (n % 2 != 0)
		{
			std::cout << "Error: Input must be an even number." << std::endl;

		}
	} while (n % 2 != 0);

	std::cout << switch_digits(n) << std::endl;

	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	std::cout << switch_digits(123456) << std::endl;
	std::cout << switch_digits(0) << std::endl;
	std::cout << switch_digits(100000) << std::endl;
	std::cout << switch_digits(100010) << std::endl;
	std::cout << switch_digits(102030) << std::endl;
	std::cout << switch_digits(987654) << std::endl;
	std::cout << switch_digits(10) << std::endl;
}
