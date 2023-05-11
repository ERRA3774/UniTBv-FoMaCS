// Problema 5
// Subsiruri de suma data
// Scrie un program care:
//	1. citeste Nr elemente numere narutare dintr-un fisier
//	2. le plaseaza intr-un vector Numere
// Avand acest vector, se permit oricate citiri a unei valor k (intr-un do-while)
// Pentru fiecare k se afisaza toate perechile de indici (start, stop (start <= stop) pentru care subsirul Numere[start] + Numere[start + 1] + ... + Numere[stop] = k;
// Rezolvati problema in mod eficient, folosind unordered_map (1.5p)

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "conio.h"

std::vector<int> numbersFromFile(std::string path);
std::vector<std::pair<int, int>> indexesSubarraysEqualTarget(std::vector<int> vec, int target);
std::string toString(std::vector<std::pair<int, int>> vec);

int main()
{
	std::vector<int> vec = numbersFromFile("TabeleDeDispersie_Problema5.txt");
	std::cout << "Press ESC to exit." << std::endl;
	int target = 0;

	do 
	{
		std::string input = "";
		std::cout << "<target> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> target;
		std::cout << toString(indexesSubarraysEqualTarget(vec, target)) << std::endl;
	} while (_getch() != 27);
	return 0;
}

std::vector<int> numbersFromFile(std::string path)
{
	std::ifstream fin(path);
	if (!fin.is_open())
	{
		std::cout << "Could not open file." << std::endl;
		exit(1);
	}

	std::vector<int> vec;
	while (!fin.eof())
	{
		int a;
		fin >> a;
		vec.emplace_back(a);
	}

	fin.close();

	return vec;
}

std::vector<std::pair<int,int>> indexesSubarraysEqualTarget(std::vector<int> vec, int target)
{
	if (vec.size() == 0)
	{
		std::cout << "[I] The vector is empty" << std::endl;
		return { {-1,-1} };
	}

	std::vector<std::pair<int, int>> indexes;
	std::unordered_map<int, int> map;
	int runningSum = 0;
	int start = 0;
	int stop = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		runningSum += vec[i];

		if (runningSum == target)
		{
			stop = i;
			indexes.emplace_back(std::make_pair(start, stop));
		}

		if (map.find(runningSum - target) != map.end())
		{
			start = map[runningSum - target] + 1;
			stop = i;
			indexes.emplace_back(std::make_pair(start, stop));
		}

		map[runningSum] = i;
	}

	return indexes;
}

std::string toString(std::vector<std::pair<int,int>> vec)
{
	if (vec.empty())
	{
		return "[I] The vector is empty.\n";
	}

	std::string s = "[";

	for (auto& p : vec)
	{
		s += "{" + std::to_string(p.first) + "," + std::to_string(p.second) + "}";
	}
	s += "]";

	return s;
}
