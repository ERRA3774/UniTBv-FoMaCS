// Problema 6 (1.5p)
// Suma nula:
// Se considera 4 vectori de numere A, B, C, D de lungime cel mult 500 fiecare.
// Sa se determine toate cvadruplurile de indici i, j, k, l pentru care:
// A[i] + B[j] + C[k] + D[l] = 0.
// Ce complexitate are algoritmul? -> O(n^2)
// Care este cea mai buna complexitate pe care o puteti obtine? -> O(n^2)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <conio.h>

std::vector<std::tuple<int, int, int, int>> nullSumIndexes(std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> D)
{
	std::vector<std::tuple<int, int, int, int>> indexes{};
	std::unordered_map<int, std::vector<std::pair<int, int>>> map{};

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			int sum = A[i] + B[j];
			map[sum].emplace_back(std::make_pair(i, j));
		}
	}

	for (int k = 0; k < C.size(); k++)
	{
		for (int l = 0; l < D.size(); l++)
		{
			int sum = -(C[k] + D[l]);
			if (map.find(sum) != map.end())
			{
				int i = map[sum].data()->first;
				int j = map[sum].data()->second;
				indexes.emplace_back(std::make_tuple(i, j, k, l));
			}
		}
	}

	return indexes;
}

void printIndexes(std::vector<std::tuple<int, int, int, int>> vec)
{
	for (auto& el : vec)
	{
		std::cout
			<< "A[" << std::get<0>(el) << "]" << " + "
			<< "B[" << std::get<1>(el) << "]" << " + "
			<< "C[" << std::get<2>(el) << "]" << " + "
			<< "D[" << std::get<3>(el) << "]" << " = 0" 
			<< "\n------------------------------------" << std::endl;
	}
	return;
}

int main()
{
	std::vector<int> A{ 87, 61, 24, 83, 32, 93, 66, 81, 72, 47, 85, 45, 70, 84, 68, 74, 57, 71, 92, 93 };
	std::vector<int> B{ 66, 20, 38, 98, 96, 32, 23, 29, 82, 23, 67, 71, 75, 95, 77, 51, 89, 97, 84, 56 };
	std::vector<int> C{ -49, -23, -36, -24, -97, -66, -27, -93, -72, -81, -48, -43, -38, -37, -85, -74, -78, -92, -59, -60 };
	std::vector<int> D{ -23, -13, -25, -18, -11, -88, -66, -82, -26, -70, -35, -52, -31, -53, -83, -30, -72, -90, -69, -26 };

	std::vector<std::tuple<int, int, int, int>> indexes = nullSumIndexes(A, B, C, D);

	printIndexes(indexes);
	
	while (_getch() != 27);
}
