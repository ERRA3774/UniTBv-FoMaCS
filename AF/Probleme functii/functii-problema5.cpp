// Se citeste un numar natural k din intervalul [1,9]
// Afisati toate numerele n formate din exact k cifre care au proprietatea ca n-1 si n+1 sunt prime.
// Exemplu: k = 2
// Se vor afisa: 12, 18, 30, 42, 60, 72

#include <iostream>
#include <cmath>

void print_other_test_cases();

bool is_prime(int x)
{
	if (x <= 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

void print_numbers_between_two_primes(int k)
{
	int n = pow(10, k - 1);
	int end = pow(10, k);
	while (n < end)
	{
		if (is_prime(n - 1) && is_prime(n + 1))
		{
			std::cout << n << ' ';
		}
		n++;
	}

	std::cout << std::endl;
}

int main()
{
	std::cout << "Please input a natural number.\nk = ";
	int k;
	std::cin >> k;
	if (k < 1 || k > 9)
	{
		std::cout << "Error: Input must be a natural number from this interval: [1,9].";
		return 1;
	}

	print_numbers_between_two_primes(k);

	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	print_numbers_between_two_primes(1);
	print_numbers_between_two_primes(2);
	print_numbers_between_two_primes(3);
	print_numbers_between_two_primes(4);
	print_numbers_between_two_primes(5);
}