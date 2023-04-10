// Implementare tabela de dispersie - liste inlantuite
// Construiti o clasa HashTable(sau HashMap) potrivita care sa includa operatiile: 
// 1. insertie
// 2. cautare
// 3. stergere
// Elementele stocate vor fi de tip (cheie, valoare) -> folositi std::pair
// Rezolvarea coliziunilor se va realiza prin liste inlantuite -> folositi std::list
// Daca factorul de incarcare al tabelei depaseste 1.0 se cere 
// 1. redimensionarea tabelei (aproximativ dublul dimensiunii initiale)
// 2. redistribuirea elementelor in noua tabela (rehashing)
// In functia main 
// 1. cititi dintr-un fisier n elemente de tip pereche (cheie-valoare) (n>20)
// 2. repartizati elementele in tabela, apoi
// 3. permiteti cautarea, adaugarea sau stergerea de elemente (meniu)
// 4. permiteti parcurgerea si afisarea perechilor <cheie, valoare> pentru toate elementele din tabela. (3p)
// +.5p pentru implementarea unei functii de hashing pentru siruri de caractere

#include "HashTable.h"
#include <sstream>
#include "conio.h"
constexpr int ESC = 27;
constexpr int KEY_Y = 121;
void menuMain(std::string username);
void menuCustomize(std::string& username);
void menuEmptyHashTable(HashTable hashTable);
void menuInsertKeyValue(HashTable& hashTable);
void menuRemoveKey(HashTable& hashTable);
void menuFindKey(HashTable hashTable);
void menuPrintHashTable(HashTable hashTable);
void menuSize(HashTable hashTable);
void menuExit(bool& exit);
void initMenuHashTable();

int main()
{
	initMenuHashTable();
	return 0;
}

void initMenuHashTable()
{
	int option = 0;
	bool exit = false;
	bool subMenu = false;
	std::string username = "";
	std::string input = "";
	HashTable hashTable("InputFile.txt");
	do
	{
		menuMain(username);
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			menuCustomize(username);
			break;
		case 2:
			menuEmptyHashTable(hashTable);
			break;
		case 3:
			menuInsertKeyValue(hashTable);
			break;
		case 4:
			menuRemoveKey(hashTable);
			break;
		case 5:
			menuFindKey(hashTable);
			break;
		case 6:
			menuPrintHashTable(hashTable);
			break;
		case 7:
			menuSize(hashTable);
			break;
		case 8:
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
		<< "\t\t|                2. empty()                |\n"
		<< "\t\t|                3. insert()               |\n"
		<< "\t\t|                4. remove()               |\n"
		<< "\t\t|                5. find()                 |\n"
		<< "\t\t|                6. print()                |\n"
		<< "\t\t|                7. size()                 |\n"
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
		while (_getch() != ESC);
	}
	return;
}

void menuEmptyHashTable(HashTable hashTable)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|        Check if your HashTable is        |\n"
		<< "\t\t|                  Empty                   |\n"
		<< "\t\t+------------------------------------------+\n";
	if (hashTable.empty())
	{
		std::cout << "It is empty." << std::endl;
	}
	else
	{
		std::cout << "It is not empty." << std::endl;
	}
	std::cout << "Press ESC to continue." << std::endl;
	while (_getch() != ESC);
	return;
}

void menuInsertKeyValue(HashTable& hashTable)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  Insert                  |\n"
		<< "\t\t|    Key-value pairs into your HashTable   |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		int key = 0;
		int value = 0;
		std::string input = "";
		std::cout << "Key> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> key;
		std::cout << "Value> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> value;
		hashTable.insert(key, value);
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != ESC);
	return;
}

void menuRemoveKey(HashTable& hashTable)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  Remove                  |\n"
		<< "\t\t|        A key from your HashTable         |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		int key = 0;
		std::string input = "";
		std::cout << "Key> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> key;
		hashTable.remove(key);
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != ESC);
	return;
}

void menuFindKey(HashTable hashTable)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  Find                    |\n"
		<< "\t\t|        A key in your HashTable           |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		int key = 0;
		std::string input = "";
		std::cout << "Key> ";
		std::getline(std::cin, input);
		std::istringstream(input) >> key;
		hashTable.find(key);
		std::cout << "Press ESC to continue." << std::endl;
	} while (_getch() != ESC);
	return;
}

void menuPrintHashTable(HashTable hashTable)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  Print                   |\n"
		<< "\t\t| Your key-value pairs from your HashTable |\n"
		<< "\t\t+------------------------------------------+\n";
	hashTable.print();
	std::cout << "Press ESC to continue." << std::endl;
	while (_getch() != ESC);
	return;
}

void menuSize(HashTable hashTable)
{
	system("cls");
	std::cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|     Check the Size of your HashTable     |\n"
		<< "\t\t+------------------------------------------+\n";
	std::cout << "The size of your HashMap is: " << hashTable.size() << std::endl;
	std::cout << "Press ESC to continue." << std::endl;
	while (_getch() != ESC);
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
