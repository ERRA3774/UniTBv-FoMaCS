// Se citeste un numar natural n si n medii (numere reale cu doua zecimale cu valori cuprinse intre 1 si 10
// Sa se afiseze o statistica a mediilor astfel:
// - numarul de medii cuprinse intre intervalul [1,2]
// - numarul de medii cuprinse intre intervalul [2,3]
// - ...
// - numarul de medii cuprinse intre intervalul [9,10]

#include <iostream>
#include <vector>
#include <algorithm>

void print_tests();
void citire_vector(std::vector<float>& vec);
void afisare_statistica(std::vector<float>& vec);

int main()
{
	print_tests();
	
	std::vector<float> vec;
	citire_vector(vec);
	afisare_statistica(vec);
}

void citire_vector(std::vector<float>& vec)
{
	int n;
	std::cout << "Introduceti un numar natural.\nn = ";
	std::cin >> n;
	vec.resize(n);

	std::cout << "Introduceti " << n << " medii." <<std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cin >> vec[i];
	}
}

void afisare_statistica(std::vector<float>& vec)
{
	for (int i = 1; i < 10; i++)
	{
		int count = 0;
		for (float number : vec)
		{
			if (number > i && number <= i + 1)
			{
				count++;
			}
		}
		std::cout << "In intervalul [" << i << ", " << i + 1 << "] sunt " << count << " medii." << std::endl;
	}
}

void print_tests()
{
	std::vector<float> vec0
	{
		8.31,	3.00,	1.56,	9.72,	1.77,
		8.02,	6.06,	6.01,   7.00,   9.43,
		8.58,	9.41,	8.14,   8.86,   6.77,
		3.45,	1.12,	6.32,   6.86,   9.31,
		5.99,	2.60,   7.04,   2.10,	6.02,
		5.62,	6.99,	8.13,   8.61,   7.84,
		1.70,	2.80,	9.61,   3.86,   5.57,
		5.13,	6.34,	2.42,   2.66,   2.13,
		1.73,	2.27,	9.80,	6.40,   3.69,
		9.50,   2.04,	3.50,	9.10,   7.03,
		4.37,	6.91,	1.82,   4.93,   3.42,
		9.23,	5.00,	5.92,   5.37,   6.92,
		1.21,	8.42,	9.51,   7.12,   9.20,
		5.99,	6.99,	5.73,   5.40,   5.38
	};

	afisare_statistica(vec0);

}
