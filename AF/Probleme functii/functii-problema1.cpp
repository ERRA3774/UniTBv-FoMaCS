// Se citeste un numar natural n.
// Afisati toate perechile de numere de la 1 la n care au proprietatea ca au aceeasi suma a cifrelor

#include <iostream>

void print_other_test_cases();

int read_number() {
	int n;

	do {
		std::cout << "Please input a natural number.\nn = ";
		std::cin >> n;
		if (n < 1)
		{
			std::cout << "Error: Input must be a positive natural number." << std::endl;
		}
	} while (n < 1);

	return n;
}

int sum_of_digits(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void print_pairs_with_same_sum_of_digits(int n)
{
	int sum;

	for (int i = 1; i <= n; i++)
	{
		sum = sum_of_digits(i);
		if (sum != i)
		{
			std::cout << "(" << sum << ", " << i << ")" << std::endl;
		}
	}

	std::cout << std::endl;
}

int main()
{
	int n = read_number();
	print_pairs_with_same_sum_of_digits(n);

	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	print_pairs_with_same_sum_of_digits(15);
	print_pairs_with_same_sum_of_digits(20);
	print_pairs_with_same_sum_of_digits(100);
}