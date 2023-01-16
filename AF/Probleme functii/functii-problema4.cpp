// Se citeste un numar natural n si un sir  de n perechi de numere
// Determinati si afisati perechea pentru care valoarea cmmdc-ului dintre cele 2 valori este maxima
// Exemplu: n = 3
// 12 10
// 45 35
// 23 74
// Se va afisa perechea 45 35

#include <iostream> 

int gcd(int first, int second)
{
	if (second == 0)
	{
		return first;
	}
	return gcd(second, first % second);
}

void print_pair_with_max_gcd(int n)
{
	int first = 0;
	int second = 0;
	int max_gcd = 0;
	for (int i = 0; i < n; i++)
	{
		int temp_first, temp_second;
		std::cout << "Please input pair " << i + 1 << "." << std::endl;
		std::cin >> temp_first >> temp_second;
		int temp_max_gcd = gcd(temp_first, temp_second);
		if (temp_max_gcd > max_gcd)
		{
			max_gcd = temp_max_gcd;
			first = temp_first;
			second = temp_second;
		}
	}

	std::cout << "The pair with max gcd is: " << first << ' ' << second << std::endl;
}

int main()
{
	std::cout << "Please input a natural number.\nn = ";
	int n;
	std::cin >> n;

	print_pair_with_max_gcd(n);

	return 0;
}