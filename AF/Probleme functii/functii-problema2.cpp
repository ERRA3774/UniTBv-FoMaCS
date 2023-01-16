// Se citeste un numar natural n si apoi n numere naturale
// Afisati cate dintre numerele citite au rasturnatul egla cu primul numar citit
// Exemplu: n = 7
// 213 78 132 30 132 8 132 -> se va afisa 3

#include <iostream>

int read_number() 
{
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

int read_first_number()
{
	int first;

	std::cout << "first = ";
	std::cin >> first;

	return first;
}

bool has_same_digits(int first, int x)
{
	int digit_count[10] = { 0 };
	while (first > 0)
	{
		digit_count[first % 10]++;
		first /= 10;
	}
	while (x > 0)
	{
		digit_count[x % 10]--;
		x /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digit_count[i] != 0)
		{
			return false;
		}
	}
	return true;
}

void numbers_equal_to_the_reversed_of_first(int n, int first)
{
	int count = 0;
	std::cout << "Please input " << n - 1 << " numbers." << std::endl;
	for (int i = 1; i < n; i++)
	{
		int x;
		std::cin >> x;
		if (has_same_digits(first, x))
		{
			count++;
		}
	}

	std::cout << count << " number/s equal to the reversed of " << first << std::endl;
}

int main()
{
	int n = read_number();
	int first = read_first_number();

	numbers_equal_to_the_reversed_of_first(n, first);

	return 0;
}