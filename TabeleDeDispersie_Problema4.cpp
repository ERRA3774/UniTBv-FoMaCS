// Problema 4
// Concurenti
// Se considera un numar de competitii sportive la care s-au inscris concurenti.
// Pentru fiecare competitie exista o lista cu numele si prenumele concurentilor (pereche de valori de tip std::string)
// Acele liste se citesc dintr-un fisier.
// Sa se scrie o functie care indica persoanele care participa la mai mult de o singura competitie (1p)

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <sstream>
#include "conio.h"

static constexpr auto EXT = ".txt";
static constexpr auto ALL = "All";
static constexpr auto BOXING = "Boxing";
static constexpr auto FENCING = "Fencing";
static constexpr auto GOLF = "Golf";
static constexpr auto SWIMMING = "Swimming";
static constexpr auto MULTIPLE = "Multiple";

static constexpr int KEY_ESC = 27;
static constexpr int KEY_Y = 121;

void initMenu();
void menuMain(std::string username);
void menuCustomize(std::string& username);
void menuBoxing(std::string username, std::list<std::string>& boxing, std::unordered_map<std::string, std::list<std::string>>& map);
void menuGolf(std::string username, std::list<std::string>& golf, std::unordered_map<std::string, std::list<std::string>>& map);
void menuFencing(std::string username, std::list<std::string>& fencing, std::unordered_map<std::string, std::list<std::string>>& map);
void menuSwimming(std::string username, std::list<std::string>& swimming, std::unordered_map<std::string, std::list<std::string>>& map);
void menuAll(std::string username, std::list<std::string>& all, std::unordered_map<std::string, std::list<std::string>>& map);
void menuOutput(std::string username, std::list<std::string>& all, std::unordered_map<std::string, std::list<std::string>>& map);
void menuMultiple(std::string username, std::list<std::string>& multiple, std::unordered_map<std::string, std::list<std::string>>& map);
void menuExit(bool& exit);

std::list<std::string> listOfParticipantsFromFile(std::string path);
void mapParticipants(std::string fileName, std::list<std::string>& list, std::unordered_map<std::string, std::list<std::string>>& map);
std::list<std::string> listOfParticipantsAtMultipleCompetitions(std::list<std::string> list, std::unordered_map<std::string, std::list<std::string>>& map);
void outputCompetition(std::string fileName, std::unordered_map<std::string, std::list<std::string>>& mappedParticipants);
void print(std::unordered_map<std::string, std::list<std::string>>& mappedParticipants);

std::string toString(std::list<std::string> list);

int main()
{
	initMenu();
	return 0;
}

void initMenu()
{
	int option;
	bool exit = false;
	std::string username = "";
	std::string input = "";
	std::string outputFileName = "";

	std::list<std::string> all;
	std::list<std::string> boxing;
	std::list<std::string> golf;
	std::list<std::string> fencing;
	std::list<std::string> swimming;
	std::list<std::string> multiple;

	std::unordered_map<std::string, std::list<std::string>> mappedParticipants;
	do
	{
		option = 0;
		menuMain(username);
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			menuCustomize(username);
			break;
		case 2:
			menuBoxing(username, boxing, mappedParticipants);
			break;
		case 3:
			menuGolf(username, golf, mappedParticipants);
			break;
		case 4:
			menuFencing(username, fencing, mappedParticipants);
			break;
		case 5:
			menuSwimming(username, swimming, mappedParticipants);
			break;
		case 6:
			menuAll(username, all, mappedParticipants);
			break;
		case 7:
			menuOutput(username, all, mappedParticipants);
			break;
		case 8:
			menuMultiple(username, multiple, mappedParticipants);
			break;
		case 9:
			menuExit(exit);
			break;
		}
	} while (!exit);

	return;
}

void menuMain(std::string username)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                1. Customize              |\n"
		<< "\t\t|                2. Boxing                 |\n"
		<< "\t\t|                3. Golf                   |\n"
		<< "\t\t|                4. Fencing                |\n"
		<< "\t\t|                5. Swimming               |\n"
		<< "\t\t|                6. All                    |\n"
		<< "\t\t|                7. Output                 |\n"
		<< "\t\t|                8. Exit                   |\n"
		<< "\t\t+------------------------------------------+\n";
	std::cout << "<" << username << "> ";
	return;
}

void menuCustomize(std::string& username)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Customize                |\n"
		<< "\t\t|            Customize your name           |\n"
		<< "\t\t+------------------------------------------+\n";
	std::cout << "<" << username << "> ";
	std::string newUsername = username;
	std::getline(std::cin, newUsername);
	if (newUsername != username || newUsername != "")
	{
		username = newUsername;
		std::cout << "Name changed successfully." << std::endl;
		std::cout << "Press ESC to continue." << std::endl;
		while (_getch() != KEY_ESC);
	}
	return;
}

void menuBoxing(std::string username, std::list<std::string>& boxing, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Boxing                   |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Upload to Contenst            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			boxing = listOfParticipantsFromFile(BOXING);
			std::cout << toString(boxing) << std::endl;
			break;
		case 2:
			mapParticipants(BOXING, boxing, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}

void menuGolf(std::string username, std::list<std::string>& golf, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Golf                     |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Upload to Contenst            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			golf = listOfParticipantsFromFile(GOLF);
			std::cout << toString(golf) << std::endl;
			break;
		case 2:
			mapParticipants(GOLF, golf, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}

void menuFencing(std::string username, std::list<std::string>& fencing, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Fencing                  |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Upload to Contenst            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			fencing = listOfParticipantsFromFile(FENCING);
			std::cout << toString(fencing) << std::endl;
			break;
		case 2:
			mapParticipants(FENCING, fencing, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}

void menuSwimming(std::string username, std::list<std::string>& swimming, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Swimming                 |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Upload to Contenst            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			swimming = listOfParticipantsFromFile(SWIMMING);
			std::cout << toString(swimming) << std::endl;
			break;
		case 2:
			mapParticipants(SWIMMING, swimming, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}

void menuAll(std::string username, std::list<std::string>& all, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                   All                    |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Upload to Contenst            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			all = listOfParticipantsFromFile(ALL);
			std::cout << toString(all) << std::endl;
			break;
		case 2:
			mapParticipants(ALL, all, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}

void menuOutput(std::string username, std::list<std::string>& all, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Output                   |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Output mapped file            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			all = listOfParticipantsFromFile(ALL);
			std::cout << toString(all) << std::endl;
			break;
		case 2:
			outputCompetition(ALL, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}

void menuMultiple(std::string username, std::list<std::string>& multiple, std::unordered_map<std::string, std::list<std::string>>& map)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Multiple                 |\n"
		<< "\t\t|         1. Check participants            |\n"
		<< "\t\t|         2. Output mapped file            |\n"
		<< "\t\t+------------------------------------------+\n";
	do
	{
		int option = 0;
		std::string input = "";
		std::cout << "<" << username << "> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			multiple = listOfParticipantsAtMultipleCompetitions(multiple, map);
			std::cout << toString(multiple) << std::endl;
			break;
		case 2:
			outputCompetition(MULTIPLE, map);
			break;
		}
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != KEY_ESC);
	return;
}


void menuExit(bool& exit)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|      Are you sure you want to quit?      |\n"
		<< "\t\t|           Press Y to confirm.            |\n"
		<< "\t\t+------------------------------------------+\n";
	if (_getch() == KEY_Y)
	{
		system("cls");
		std::cout
			<< "\t\t+------------------------------------------+\n"
			<< "\t\t|                 Goodbye                  |\n"
			<< "\t\t+------------------------------------------+\n";
		exit = true;
	}
	return;
}

std::list<std::string> listOfParticipantsFromFile(std::string fileName)
{
	std::ifstream fin(fileName + EXT);

	if (!fin.is_open())
	{
		std::cout << "[E] Could not open file." << std::endl;
		exit(1);
	}

	std::list<std::string> list;

	while (!fin.eof())
	{
		std::string line;
		std::getline(fin, line);
		if (line != "")
		{
			std::cout << "[I] Read " << line << std::endl;
			list.emplace_back(line);
		}
	}

	fin.close();

	return list;
}

void mapParticipants(std::string fileName, std::list<std::string>& list, std::unordered_map<std::string, std::list<std::string>>& map)
{
	if (list.empty())
	{
		std::cout << "[I] The list is empty " << std::endl;
		return;
	}

	std::string key = fileName;

	for (auto it = list.begin(); it != list.end(); it++)
	{
		map[fileName].emplace_back(*it);
	}

	return;
}

void outputCompetition(std::string fileName, std::unordered_map<std::string, std::list<std::string>>& mappedParticipants)
{
	if (mappedParticipants.empty())
	{
		std::cout << "[I] The map is empty" << std::endl;
		return;
	}

	fileName = ALL;
	std::ofstream fout(fileName + EXT);

	for (auto& kv : mappedParticipants)
	{
		fout << kv.first << ":" << toString(kv.second) << '\n';
	}
	fout << '\n';
	fout.close();

	return;
}

// TODO
std::list<std::string> listOfParticipantsAtMultipleCompetitions(std::list<std::string> list, std::unordered_map<std::string, std::list<std::string>>& map) 
{
	return list;
}


std::string toString(std::list<std::string> list)
{
	if (list.empty())
	{
		return "[I] The list is empty\n";
	}

	std::string s = "[";

	for (auto it = list.begin(); it != list.end();)
	{
		s += *it;
		if (++it != list.end())
		{
			s += ", ";
		}
		else
		{
			s += "]";
		}
	}
	std::cout << std::endl;
	return s;
}

void print(std::unordered_map<std::string, std::list<std::string>>& mappedParticipants)
{
	for (auto& kv : mappedParticipants)
	{
		std::cout
			<< "Key: " << kv.first << '\n'
			<< "Value: " << toString(kv.second) << '\n'
			<< '\n';
	}
	std::cout << std::endl;
	return;
}
