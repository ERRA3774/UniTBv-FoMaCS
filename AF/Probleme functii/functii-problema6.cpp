// Sa se afiseze cel mai mic numar care se poate forma cu cifrele lui n
// Fiecare cifra repetandu-se de cate ori se repeta si in n.
// Exemplu:    1204192
// Se va afisa: 112249

#include <iostream>

void print_other_test_cases();

void print_min_number_by_sorting_digits(int n)
{
	int digits[10] = { 0 };
	while (n > 0)
	{
		int d = n % 10;
		digits[d]++;
		n /= 10;
	}

	bool has_zero = true;
	for (int i = 1; i < 10; i++)
	{
		while (digits[i] > 0)
		{
			std::cout << i;
			digits[i]--;
			has_zero = false;
		}
	}
	if (has_zero)
	{
		std::cout << 0;
	}

	std::cout << std::endl;
}

int main() {
	std::cout << "Please input a natural number.\nn = ";
	int n;
	std::cin >> n;

	print_min_number_by_sorting_digits(n);

	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	print_min_number_by_sorting_digits(1204192);
	print_min_number_by_sorting_digits(1000000);
	print_min_number_by_sorting_digits(1020304);
	print_min_number_by_sorting_digits(6543210);
	print_min_number_by_sorting_digits(9876543);
}