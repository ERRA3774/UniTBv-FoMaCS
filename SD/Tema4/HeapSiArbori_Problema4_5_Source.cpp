// Sortare
// Sa se implementeze algoritmul Heap-Sort. Sa se sorteze un vector de numere. (1p)

// Priority Queue
// Implementati o coada de prioritati folosind o structura HeapMax care sa aiba:
// Un camp m_Heap de tip vector de int care sa stocheze elementele cozii sub forma unui heap max
// Structura trebuia sa aiba:
// 1. Insert 
// 2. ExtractMax 
// 3. GetMax 
// 4. SiftUp 
// 5. SiftDown
// In functia main se declare o variabila de tip HeapMax 
// Se foloseste un menu implementat cu ajutorul unei instructiuni switch (2p)

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "conio.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::string;
using std::istringstream;

constexpr int ESC = 27;
constexpr int KEY_Y = 121;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class HeapMax
{
public:
	HeapMax(vector<int>& vec);
	HeapMax(vector<int>& vec, bool sortOnInit);

	int GetMax();
	int GetHeight();

	void Insert(int val);
	int ExtractMax();

	void SiftUp(int i);
	void SiftDown(int i);

	void Sort();
	void Display();

private:
	int Parent(int i);
	int LeftChild(int i);
	int RightChild(int i);

private:
	vector<int> m_Heap;
	int m_Height;
};

HeapMax::HeapMax(vector<int>& vec, bool sortOnInit) :m_Heap(vector<int>()), m_Height(0)
{
	if (sortOnInit)
	{
		Sort();
	}

	for (int i : vec) m_Heap.emplace_back(i);
	m_Height = log2(vec.size());
}

HeapMax::HeapMax(vector<int>& vec) : m_Heap(vector<int>()), m_Height(0)
{
	for (int i : vec)
	{
		m_Heap.emplace_back(i);
		SiftUp(m_Heap.size() - 1);
	}
	m_Height = log2(vec.size());
}

int HeapMax::GetMax()
{
	return m_Heap[0];
}

int HeapMax::GetHeight()
{
	return log2(m_Heap.size());
}

void HeapMax::Insert(int val)
{
	m_Heap.emplace_back(val);
	SiftUp(m_Heap.size() - 1);
}

int HeapMax::ExtractMax()
{
	if (m_Heap.empty()) return -1;

	int toExtract = m_Heap[0];

	m_Heap[0] = m_Heap[m_Heap.size() - 1];
	m_Heap.pop_back();
	SiftDown(0);

	return toExtract;
}

// PRIVATE FUNCTIONS

int HeapMax::Parent(int i)
{
	return (i + 1) / 2;
}

int HeapMax::LeftChild(int i)
{
	return (i * 2) + 1;
}

int HeapMax::RightChild(int i)
{
	return (i + 2) + 2;
}

void HeapMax::SiftUp(int i)
{
	while (i > 0 && m_Heap[Parent(i)] < m_Heap[i])
	{
		swap(m_Heap[Parent(i)], m_Heap[i]);
		SiftUp(Parent(i));
	}
}

void HeapMax::SiftDown(int i)
{
	int imax = i;
	int l = LeftChild(i);
	int r = RightChild(i);

	if (l < m_Heap.size() && m_Heap[l] > m_Heap[imax])
	{
		imax = l;
	}

	if (r < m_Heap.size() && m_Heap[r] > m_Heap[imax])
	{
		imax = r;
	}

	if (i != imax)
	{
		swap(m_Heap[i], m_Heap[imax]);
		SiftDown(imax);
	}
}

void HeapMax::Sort()
{
	int n = m_Heap.size();

	for (int i = n / 2 - 1; i >= 0; i--) SiftDown(i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(m_Heap[0], m_Heap[i]);
		SiftDown(0);
	}
}

void HeapMax::Display()
{
	if (m_Heap.empty()) return;

	if (m_Heap.size() == 1) cout << m_Heap[0] << endl;

	for (int i = 0, k = 0; i <= m_Height; i++)
	{
		cout << "Level " << i << ": ";
		for (int j = 0; j < pow(2, i) && k < m_Heap.size(); j++)
		{
			cout << m_Heap[k++] << " ";
		}
		cout << endl;
	}
}

void MenuMain(string username);
void MenuCustomize(string& username);
void MenuInsert(HeapMax& heapMax);
void MenuGetMax(HeapMax& heapMax);
void MenuExtractMax(HeapMax& heapMax);
void MenuSiftUp(HeapMax& heapMax);
void MenuSiftDown(HeapMax& heapMax);
void MenuSort(HeapMax& heapMax);
void MenuDisplay(HeapMax& heapMax);
void MenuExit(bool& exit);

void MenuCustomize(string& username)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Customize                |\n"
		<< "\t\t|            Customize your name           |\n"
		<< "\t\t+------------------------------------------+\n";
	cout << "<" << username << "> ";
	string newUsername = username;
	getline(cin, newUsername);
	if (newUsername != username || newUsername != "")
	{
		username = newUsername;
		cout << "Name changed successfully." << endl;
		cout << "Press ESC to continue." << endl;
		while (_getch() != ESC);
	}
	return;
}

void MenuMain(string username)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                1. Customize              |\n"
		<< "\t\t|                2. Insert()               |\n"
		<< "\t\t|                3. GetMax()               |\n"
		<< "\t\t|                4. ExtractMax()           |\n"
		<< "\t\t|                5. SiftUp()               |\n"
		<< "\t\t|                6. SiftDown()             |\n"
		<< "\t\t|                7. Sort()                 |\n"
		<< "\t\t|                8. Display()              |\n"
		<< "\t\t|                9. Exit                   |\n"
		<< "\t\t+------------------------------------------+\n";
	cout << "<" << username << "> ";
	return;
}

void MenuExit(bool& exit)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|      Are you sure you want to quit?      |\n"
		<< "\t\t|           Press Y to confirm.            |\n"
		<< "\t\t+------------------------------------------+\n";
	if (_getch() == KEY_Y)
	{
		system("cls");
		cout
			<< "\t\t+------------------------------------------+\n"
			<< "\t\t|                 Goodbye                  |\n"
			<< "\t\t+------------------------------------------+\n";
		exit = true;
	}

	return;
}

void MenuInsert(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  Insert                  |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		int val = 0;
		string input = "";
		cout << "Value> ";
		getline(cin, input);
		istringstream(input) >> val;
		heapMax.Insert(val);
		cout << "Press ESC to continue." << endl;
	} while (_getch() != ESC);
	return;
}

void MenuGetMax(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  GetMax                  |\n"
		<< "\t\t+------------------------------------------+\n";
	cout << "The max value is: " << heapMax.GetMax() << endl;
	cout << "Press ESC to continue." << endl;
	while (_getch() != ESC);
	return;
}

void MenuExtractMax(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                ExtractMax                |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		cout << "Extract> " << heapMax.GetMax();
		heapMax.ExtractMax();
		cout << "Press ESC to continue." << endl;
	} while (_getch() != ESC);
	return;
}

void MenuSiftUp(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 SiftUp                   |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		int i = 0;
		string input = "";
		cout << "Index> ";
		getline(cin, input);
		istringstream(input) >> i;
		heapMax.SiftUp(i);
		cout << "Press ESC to continue." << endl;
	} while (_getch() != ESC);
	return;
}

void MenuSiftDown(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                SiftDown                  |\n"
		<< "\t\t+------------------------------------------+\n";
	do {
		int i = 0;
		string input = "";
		cout << "Index> ";
		getline(cin, input);
		istringstream(input) >> i;
		heapMax.SiftDown(i);
		cout << "Press ESC to continue." << endl;
	} while (_getch() != ESC);
	return;
}

void MenuSort(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                  Sort                    |\n"
		<< "\t\t+------------------------------------------+\n";
	cout << "Before: " << endl;
	heapMax.Display();
	heapMax.Sort();
	cout << "After: " << endl;
	heapMax.Display();
	cout << "Press ESC to continue." << endl;
	while (_getch() != ESC);
	return;
}

void MenuDisplay(HeapMax& heapMax)
{
	system("cls");
	cout
		<< "\t\t+------------------------------------------+\n"
		<< "\t\t|                 Display                  |\n"
		<< "\t\t+------------------------------------------+\n";
	heapMax.Display();
	cout << "Press ESC to continue." << endl;
	while (_getch() != ESC);
	return;
}

void InitMenu()
{
	int option = 0;
	bool exit = false;
	bool subMenu = false;
	string username = "";
	string input = "";
	vector<int> vec{ 9,8,7,6,5,4,3,2,1,0, 10, 11, 12, 13, 14 };

	HeapMax heapMax(vec, false);
	do
	{
		MenuMain(username);
		getline(cin, input);
		istringstream(input) >> option;
		switch (option)
		{
		case 1:
			MenuCustomize(username);
			break;

		case 2:
			MenuInsert(heapMax);
			break;

		case 3:
			MenuGetMax(heapMax);
			break;

		case 4:
			MenuExtractMax(heapMax);
			break;

		case 5:
			MenuSiftUp(heapMax);
			break;

		case 6:
			MenuSiftDown(heapMax);
			break;

		case 7:
			MenuSort(heapMax);
			break;

		case 8:
			MenuDisplay(heapMax);
			break;
		case 9:
			MenuExit(exit);
			break;
		}
	} while (!exit);

	return;
}

int main()
{
	InitMenu();
	return EXIT_SUCCESS;
}