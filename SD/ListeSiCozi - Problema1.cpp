// GABRIEL LUICAN
// Problema 1
// Implementarea unei liste dublu inlantuite.
// Sa se implementeze o lista dublu inlantuita cu functionalitatile descris in continuare.
// Se cere utilizarea unei structuri Node care are trei campuri:
//	1. un camp pentru informatie -> int
//  2. si doua campuri de tip pointer la Node pentru legaturile catre elementele precedent si urmator
// Se cere utilizarea unei structuri List care are ca mebri:
//	1. doua variable de tip Node* reprezentand primul respectiv ultimul element din lista
//	2. o variabila de tip int reprezentand numarul de elemente din lista si functiile:
//		a. push_front(key) - adauga cheia key in capul listei (.2p)
//		b. push_back(key) - adauga cheia key la finalul listei (.2p)
//		c. pop_front() - sterge primul element din lista (.2p)
//		d. pop_back() - sterge ultimul element din lista (.2p)
//		e. find(key) - cauta o cheie key lista - returneaza pointer la nodul cu cheia key sau NULL (.2p)
//		f. erase(Node* node) - sterge un element Node din lista (FARA cautare). 
//		   Node-ul trimis ca parametru a fost in prealabil gasit cu find sau identificat prin parcurgerea listei (.2p)
//		g. remove(key) - sterge toate aparitiile cheii key (CU cautare) (.2p) 
//		h. insert(Node* node, int val) - insereaza un element cu cheia val inainte de nodul indicat de Node. (.5p)
//		i. empty() - verifica daca lista e vida (.2p)
//		j. clear() - goleste lista. (.2p)
//		k. print() - afiseaza elementele listei (.2p)
//		l. size() - returneaza numarul de elemente din lista. 
// De asemenea, sa se implementeze urmatoarele functii, care nu fac parte din structura:
//	1. palindrom (List L) - verifica daca lista este palindrom (.5p)
//	2. compare (List L1, List L2) - returneaza 1 daca L1 si L2 sunt identice si 0 altfel (.2p)
// In functia main realizati un meniu cu ajutorul unei instructiuni switch, 
// prin care se ofera optiuni corespunzatoare fiecarei functionalitati,
// precum si o optiune de EXIT.
// Intr-o instruciune while, se citesc si se executa optiuni pana la alegerea optiunea EXIT.
// ATENTIE: Nici o functie nu trebuie sa dea eroare de exectuie, daca se apeleaza pe o lista vida.

#include <iostream>
#include <string>
#include <sstream>
#include "conio.h"

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node(int d, Node* n, Node* p) : data(d), next(n), prev(p)
	{
	}
};

struct List
{
	Node* head;
	Node* tail;
	int listSize;

	List()
	{
		head = NULL;
		tail = NULL;
		listSize = 0;
	}

	void push_front(int key) // adauga cheia 'key' in capul listei(.2p)
	{
		if (head == NULL)
		{
			Node* toInsert = new Node(key, NULL, NULL);
			head = toInsert;
			tail = toInsert;
			listSize++;
			return;
		}

		Node* toInsert = new Node(key, head, NULL);
		head->prev = toInsert;
		head = toInsert;
		listSize++;
	}


	void push_back(int key) // adauga cheia 'key' la finalul listei (.2p)
	{
		if (head == NULL)
		{
			Node* toInsert = new Node(key, NULL, NULL);
			head = toInsert;
			tail = toInsert;
			listSize++;
			return;
		}

		Node* toInsert = new Node(key, NULL, tail);
		tail->next = toInsert;
		tail = toInsert;
		listSize++;
	}

	void pop_front() // sterge primul element din lista (.2p)
	{
		if (head == NULL)
		{
			return;
		}

		Node* firstNode = head;
		head = head->next;
		delete firstNode;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		listSize--;
	}

	void pop_back() // sterge ultimul element din lista (.2p)
	{
		if (head == NULL)
		{
			return;
		}

		if (head->next == NULL)
		{
			head = NULL;
			tail = NULL;
			listSize--;
		}
		else
		{
			Node* temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			Node* lastNode = temp->next;
			temp->next = NULL;
			tail = temp;
			delete lastNode;
			listSize--;
		}
	}

	Node* find(int key) // cauta o cheie key lista - returneaza pointer la nodul cu cheia 'key' sau NULL (.2p)
	{
		Node* toFind = head;

		while (toFind != NULL)
		{
			if (toFind->data == key)
			{
				return toFind;
			}
			toFind = toFind->next;
		}

		return NULL;
	}

	void erase(Node* node) // sterge un element Node din lista (.2p)
	{
		if (head == NULL || node == NULL)
		{
			return;
		}

		if (node == head)
		{
			head = head->next;
		}

		if (node->next != NULL)
		{
			node->next->prev = node->prev;
		}

		if (node->prev != NULL)
		{
			node->prev->next = node->next;
		}

		delete node;
		listSize--;
	}

	void remove(int key) // sterge toate aparitiile cheii 'key' (.2p) 
	{
		Node* toDelete;
		while (head != NULL && head->data == key)
		{
			toDelete = head;
			head = head->next;
			delete toDelete;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			listSize--;
		}

		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->data == key)
			{
				toDelete = temp->next;
				temp->next = temp->next->next;
				if (temp->next != NULL)
				{
					temp->next->prev = temp;
				}
				delete toDelete;
			}
			else
			{
				temp = temp->next;
			}
			listSize--;
		}
	}

	void insert(Node* node, int val) // insereaza un element cu cheia 'val' inainte de nodul indicat de node (.5p)
	{
		if (node == NULL)
		{
			Node* toInsert = new Node(val, NULL, NULL);
			head = toInsert;
			tail = toInsert;
			listSize++;
			return;
		}

		Node* toInsert = new Node(val, NULL, NULL);
		if (node == head)
		{
			toInsert->next = head;
			head->prev = toInsert;
			head = toInsert;
			listSize++;
			return;
		}

		if (node == tail)
		{
			toInsert->next = tail;
			toInsert->prev = tail->prev;
			tail->prev = toInsert;
			toInsert->prev->next = toInsert;
			listSize++;
			return;
		}

		Node* temp = head;
		while (temp->next != node)
		{
			temp = temp->next;
		}

		toInsert->prev = temp;
		toInsert->next = temp->next;
		temp->next = toInsert;
		toInsert->next->prev = toInsert;
		listSize++;
		std::cout << "Temp == head" << std::endl;
	}

	bool empty() // verifica daca lista e vida (.2p)
	{
		return head == NULL;
	}

	void clear() // goleste lista (.2p)
	{
		Node* toDelete = head;
		while (head)
		{
			toDelete = head;
			head = head->next;
			delete toDelete;
		}
		listSize = 0;
	}

	void print() // afiseaza elementele listei (.2p)
	{
		Node* toPrint = head;
		while (toPrint)
		{
			std::cout << toPrint->data;
			if (toPrint->next)
			{
				std::cout << " -> ";
			}
			toPrint = toPrint->next;
		}
		std::cout << std::endl;
	}

	int size() // returneaza numarul de elemente din lista 
	{
		return listSize;
	}
};

bool palindrome(List& L) // verifica daca lista este palindrom(.5p)
{
	Node* left = L.head;

	if (left == NULL)
	{
		return 0;
	}

	Node* right = L.tail;

	while (left != right)
	{
		if (left->data != right->data)
		{
			return 0;
		}
		left = left->next;
		right = right->prev;
	}

	return 1;
}

bool compare(List& L1, List& L2) // returneaza 1 daca L1 si L2 sunt identice si 0 altfel (.2p)
{
	Node* head1 = L1.head;
	Node* head2 = L2.head;

	if (head1 == NULL && head2 == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	while (head1 != NULL)
	{
		if (head1->data != head2->data)
		{
			return 0;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	return 1;
}

void printMenu()
{
	std::cout
		<< "+----------------------------+" << '\n'
		<< "|        1. Rename list      |" << '\n'
		<< "|        2. Select list      |" << '\n'
		<< "|        3. push_back()      |" << '\n'
		<< "|        4. push_front()     |" << '\n'
		<< "|        5. pop_back()       |" << '\n'
		<< "|        6. pop_front()      |" << '\n'
		<< "|        7. find()           |" << '\n'
		<< "|        8. erase()          |" << '\n'
		<< "|        9. remove()         |" << '\n'
		<< "|       10. insert()         |" << '\n'
		<< "|       11. empty()          |" << '\n'
		<< "|       12. clear()          |" << '\n'
		<< "|       13. print()          |" << '\n'
		<< "|       14. size()           |" << '\n'
		<< "|       99. EXIT             |" << '\n'
		<< "+----------------------------+" << '\n';
}
int main()
{
	const int ESC = 27;
	bool exit = false;
	bool subMenu = false;
	int data;
	int option;
	int nodeData;
	int selected = 1;
	std::string input;
	std::string nodeInput = "";
	std::string listName= "";
	std::string list2Name = "unnamed";
	std::string list1Name = "unnamed";
	List list;
	List list1;
	List list2;
	list = list1;
	listName = list1Name;

	do {
		system("cls");
		printMenu();
		std::cout << listName << ">";
		std::getline(std::cin, input);
		std::istringstream(input) >> option;
		switch (option)
		{
		case 1:
			system("cls");
			std::cout << "Rename your list" << std::endl;
			std::cout << listName << ">";
			std::getline(std::cin, listName);
			if (selected == 1)
			{
				list1Name = listName;
			}
			else
			{
				list2Name = listName;
			}
			break;

		case 2:
			subMenu = true;
			system("cls");
			std::cout << "Select a list " << std::endl;
			std::cout << list1Name; 
			list1.print();
			std::cout << list2Name; 
			list2.print();
			do {
				std::cout << listName << ">";
				std::getline(std::cin, input);
				std::istringstream(input) >> data;
				if (data == 1)
				{
					list = list1;
					listName = list1Name;
					selected = 1;
				}
				else if (data == 2)
				{
					list = list2;
					listName = list2Name;
					selected = 2;
				}
				std::cout << "Press ESC to return." << std::endl;
				if (_getch() == ESC) {
					subMenu = false;
				}
			} while (subMenu);
			break;

		case 3:
			subMenu = true;
			system("cls");
			do {
				std::cout << "push_back()> ";
				std::getline(std::cin, input);
				std::istringstream(input) >> data;
				list.push_back(data);
				list.print();
				std::cout << "Press ESC now to return." << std::endl;
				if (_getch() == ESC) {
					subMenu = false;
				}
			} while (subMenu);
			break;

		case 4:
			subMenu = true;
			system("cls");
			std::cout << "Press ESC to exit" << std::endl;
			do {
				std::cout << "push_front()> ";
				std::getline(std::cin, input);
				std::istringstream(input) >> data;
				list.push_front(data);
				list.print();
				std::cout << "Press ESC now to return." << std::endl;
				if (_getch() == ESC) {
					subMenu = false;
				}
			} while (subMenu);
			break;

		case 5:
			subMenu = true;
			system("cls");
			std::cout << "Press ESC to exit" << std::endl;
			do {
				std::cout << "pop_back()> ";
				list.pop_back();
				list.print();
				std::cout << "Press ESC now to return." << std::endl;
				if (_getch() == ESC) {
					subMenu = false;
				}
			} while (subMenu);
			break;

		case 6:
			subMenu = true;
			system("cls");
			std::cout << "pop_front()> ";
			do {
				std::cout << "pop_back()> ";
				list.pop_front();
				list.print();
				std::cout << "Press ESC now to return." << std::endl;
				if (_getch() == ESC) {
					subMenu = false;
				}
			} while (subMenu);
			break;

		case 7:
			system("cls");
			std::cout << "find()> ";
			std::getline(std::cin, input);
			std::istringstream(input) >> data;
			std::cout << list.find(data);
			_getch();
			break;

		case 8:
			system("cls");
			std::cout << "erase()> ";
			std::getline(std::cin, input);
			std::istringstream(input) >> data;
			list.erase(list.find(data));
			_getch();
			break;

		case 9:
			system("cls");
			list.print();
			std::cout << "remove()> ";
			std::getline(std::cin, input);
			std::istringstream(input) >> data;
			list.remove(data);
			_getch();
			break;

		case 10:
			subMenu = true;
			system("cls");
			list.print();
			std::cout << "Press ESC to exit" << std::endl;
			do {
				std::cout << "insert()> Node:";
				std::getline(std::cin, nodeInput);
				std::istringstream(nodeInput) >> nodeData;
				std::cout << "insert()> toInsert:";
				std::getline(std::cin, input);
				std::istringstream(input) >> data;
				list.insert(list.find(nodeData), data);
				list.print();
				std::cout << "Press ESC now to return." << std::endl;
				if (_getch() == ESC) {
					subMenu = false;
				}
			} while (subMenu);
			break;

		case 11:
			system("cls");
			std::cout << "empty()> ";
			list.print();
			list.empty();
			_getch();
			break;

		case 12:
			system("cls");
			list.print();
			std::cout << "clear()> ";
			list.clear();
			_getch();
			break;

		case 13:
			system("cls");
			std::cout << "print()> " << listName;
			list.print();
			_getch();
			break;

		case 14:
			system("cls");
			std::cout << "size()> "  << listName << list.size();
			_getch();
			break;

		case 15:
			system("cls");
			std::cout << "palindrome()> " << palindrome(list);
			_getch();
			break;

		case 16:
			system("cls");
			std::cout << "compare()> " << compare(list, list2);
			_getch();
			break;

		case 99:
			system("cls");
			std::cout << "Goodbye!" << std::endl;
			exit = true;
			break;
		}
	} while (!exit);

	return 0;
}