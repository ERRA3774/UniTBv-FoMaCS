// Problema 3
// Se considera doua siruri de caractere citite din fisier
// Sa se scrie o functie care are ca parametri cele doua siruri si care 
// returneaza true daca al doilea este o permutare a primului si false altfel
// Implementati folosind unordered_set

#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <list>

std::vector<std::string> listFromInputFile(std::string path)
{
	std::ifstream fin(path);
	if (!fin.is_open())
	{
		std::cout << "[E] Could not open file" << std::endl;
		exit(1);
	}

	std::vector<std::string> vec;

	while (!fin.eof())
	{
		std::string line;
		std::getline(fin, line);
		vec.emplace_back(line);
	}

	return vec;
}

bool hasEqualCharSet(std::string str1, std::string str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}

	std::unordered_set<char> letters;

	for (char c : str1)
	{
		letters.insert(c);
	}

	for (char c : str2)
	{
		if (letters.find(c) == letters.end())
			return false;
	}

	return true;
}

int main()
{
	std::vector<std::string> lines = listFromInputFile("TabeleDeDispersie_Problema3.txt");
	std::cout << hasEqualCharSet(lines[0], lines[1]);
}
