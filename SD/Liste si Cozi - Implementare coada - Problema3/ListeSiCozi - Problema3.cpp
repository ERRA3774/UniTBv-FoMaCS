// Problema 3
// Implementare coada
// Sa se implementeze o coada utilizand liste inlantuite.
// Va trebuie:
// O structura node cu doua campuri
// 1. Un camp pentru informatie de tipul cerut de problema curenta
// 2. Un camp de tip pointer la node pentru legatura la elementul urmator
// O structura Queue cu 
// 1. doua campuri de tip pointer la nod, pentru primul si ultimul element initializate cu NULL
// 2. un camp nr_elem de tip int - numarul de elemente din coada
// 3. functia push(elem) - pune elem la sfarsitul cozii
// 4. functia pop - elimina elementul de la inceputul cozii
// 5. functiile front() si back() returneaza primul respectiv ultimul element din coada
// 6. functia empty() - verifica daca coada este vida
// 7. functia clear() - goleste coada
// 8. functia size() - returneaza numarul de elemente din coada
// Aceasta coada va fi utilizata in urmatoarea problema:
// La un examen se pot prezenta candidati pe durata a doua zile
// In fiecare zi timpul alocat pentru examinare este de t ore (t <= 6)
// La examen se inscriu n candidati.
// Se citesc din fisier t, n precum si candidatiii cu numele (de tip std::string)
// Ei vor fi introdusi intr-o coada, de unde vor fi extrasi pe rand pentru examinare
// Pentru fiecare candidat care este la rand, se genereaza o durata aleatorie cu o valoare intre 5 minute si 15 minute
// In momentul in care timpul t s-a terminat, deci se incheie prima zi de evaluare, 
// candidatii care au ramas in coada vor fi extrasi pe rand si trecuti intr-un fisier de iesire care va reprezenta lista candidatilor pentru ziua a doua de examinare
// Punctajul pentru problema: 1p pentru implementarea cozii + 1p pentru rezolvarea problemei.
// Folositi nume semnificative pentru variabilele folosite ( chiar si daca in enunt s-a folosit denumir precum t si n)

#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <ctime>

struct Node
{
	std::string data;
	Node* next;

	Node(std::string d, Node* n) : data(d), next(n) {}
};

struct Queue
{
	Node* head;
	Node* tail;
	int qSize;

	Queue()
	{
		head = NULL;
		tail = NULL;
		qSize = 0;
	}

	void push(std::string student)
	{
		if (head == NULL)
		{
			Node* n = new Node(student, NULL);
			head = n;
			tail = n;
			qSize++;
			return;
		}

		Node* n = new Node(student, NULL);
		n->next = NULL;
		tail->next = n;
		tail = n;
		qSize++;
	}

	void pop()
	{
		if (head == NULL)
		{
			return;
		}

		Node* firstNode = head;
		head = head->next;
		delete firstNode;
		qSize--;
	}

	Node* front()
	{
		return head != NULL ? head : NULL;
	}

	Node* back()
	{
		return  tail != NULL ? tail : NULL;
	}

	bool empty()
	{
		return head == NULL;
	}

	void clear()
	{
		Node* toDelete = head;
		while (head)
		{
			toDelete = head;
			head = head->next;
			delete toDelete;
		}
		qSize = 0;
	}

	void print()
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

	int size()
	{
		return qSize;
	}
};

Queue input(std::string path, int& numberOfStudents, int& examinationTime)
{
	Queue queue;

	std::ifstream fin(path);
	if (!fin.is_open())
	{
		std::cout << "Could not open file!" << std::endl;
		exit(1);
	}

	fin >> numberOfStudents >> examinationTime;

	for (int i = 0; i < numberOfStudents; i++)
	{
		std::string name;
		fin >> name;
		queue.push(name);
	}

	fin.close();

	return queue;
}

Queue examinare(Queue& students, int numberOfStudents, int examinationTime)
{
	examinationTime *= 60;
	srand(time(NULL));

	Queue remainingStudents;

	while (!students.empty() && examinationTime > 0)
	{
		std::string name = students.front()->data;
		students.pop();
		int examinationTimePerStudent = rand() % 11 + 5;

		if (examinationTimePerStudent <= examinationTime)
		{
			examinationTime -= examinationTimePerStudent;
			std::cout << "Finished evaluation of student: " << name << std::endl;
			std::cout << "Time taken: " << examinationTimePerStudent << " minutes. " << std::endl;
			std::cout << "Time left: " << examinationTime << " minutes." << std::endl;
		}
		else 
		{
			std::cout << name << " will be evaluated tomorrow." << std::endl;
			remainingStudents.push(name);
		}
	}

	return remainingStudents;
}

void output(Queue& queue, std::string path)
{
	std::ofstream output(path); 
	int size = queue.size();

	for (int i = 0; i < size; i++)
	{
		std::string name = queue.front()->data;
		output << name << '\n';
		queue.pop();
	}

	output.close();
}

int main()
{
	int numberOfStudents;
	int examinationTime;

	Queue students = input("Input.txt", numberOfStudents, examinationTime);
	Queue remainingStudents = examinare(students, numberOfStudents, examinationTime);
	output(remainingStudents, "Output.txt");

	return 0;
}