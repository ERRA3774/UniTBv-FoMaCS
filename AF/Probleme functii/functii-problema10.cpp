// Se citeste un numar natural n > 1000
// Afisati cel mai mare numar care se poate obtine din n prin eliminarea unei singure cifre
// Exeplu: n = 45329
// Rezulta: n = 5329 (e cel mai mare dintre numerele 4532, 4539, 4529, 4329, 5329)

#include <iostream>

void print_other_test_cases();

int max_number_after_removing_one_digit(int n)
{
	if (n <= 1000)
	{
		std::cout << "Error: Your number must be greater than 1000.";
		return 1;
	}
	int div = 1000;
	while (n / div >= 10)
	{
		div *= 10;
	}
	int max = n % div;
	while (div / 10 > 0)
	{
		int temp_max = ((n / div) * (div / 10)) + (n % (div / 10));
		if (max > temp_max) {
			std::cout << max << " > " << temp_max << std::endl;
		}
		if (temp_max > max)
		{
			std::cout << max << " < " << temp_max << std::endl;
			max = temp_max;
		}
		div /= 10;
	}
	std::cout << "The maximum number is: " << max << std::endl;
	std::cout << std::endl;
	return max;
}

int main()
{
	int n;
	std::cout << "Please input a posivite number greater than 1000.\nn = ";
	std::cin >> n;

	max_number_after_removing_one_digit(n);

	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	max_number_after_removing_one_digit(45329);
	max_number_after_removing_one_digit(1001);
	max_number_after_removing_one_digit(12345);
	max_number_after_removing_one_digit(98765);
}