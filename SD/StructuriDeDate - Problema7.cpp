// Problema 7
// Se citesc dintr-un fisier un numar de elevi
// Fiecare elev are:
//		1. nume -> string
//		2. prenume -> string
//		3. 3 note (numere naturale) -> int
// Se va folosi pentru un elev un tuple cu campurile nume, prenume de tip string si 3 campuri de note de tip int
// Elevii vor fi memorati intr-un obiect de tip std::vector<std::tuple<std::string, std::string, int, int, int>>
// Sa se sorteze vectorul de elevi descrescator dupa medie
// Se vor afisa punand in evidenta elevii cu note mai mici decat 5. (2p)

#include <iostream>
#include <tuple>
#include <vector>
#include <fstream>

#define G(x,y) std::get<x>(y)

typedef std::tuple< std::string, std::string, int, int, int> tStudent;
typedef std::vector<std::tuple<std::string, std::string, int, int, int>> tVector;

std::ostream& operator << (std::ostream& fl, tStudent& s);
std::ostream& operator << (std::ostream& fl, tStudent& s);
tVector vectorOfStudents(std::string path);
void printStudentsByAverageGrade(tVector& students);
int averageGrade(tStudent& s);
void swap(tStudent& a, tStudent& b);
int partition(tVector& students, int st, int end);
void quickSort(tVector& students, int st, int end);

int main()
{
	tVector students = vectorOfStudents("Student.txt");
	printStudentsByAverageGrade(students);
}

void printStudentsByAverageGrade(tVector& students)
{
	quickSort(students, 0, students.size() - 1);
	bool isEmph = false;

	if (averageGrade(students[0]) > 5)
	{
		std::cout << "+-------------------------------------------+" << std::endl;
		std::cout << "+-------------- Medii peste 5 --------------+" << std::endl;
	}

	for (int i = 0; i < students.size(); i++)
	{
		if (averageGrade(students[i]) < 5 && !isEmph)
		{
			std::cout << "+-------------------------------------------+" << std::endl;
			std::cout << "+--------------- Medii sub 5 ---------------+" << std::endl;
			isEmph = true;
		}
		std::cout << students[i] << std::endl;
	}
}


std::ostream& operator << (std::ostream& fl, tStudent& s)
{
	return fl
		<< "|First & last name: " << G(0, s) << ", " << G(1, s) << "\n"
		<< "|Grades: " << G(2, s) << " " << G(3, s) << " " << G(4, s) << "\n"
		<< "|Average grade: " << averageGrade(s) << std::endl;
}

std::istream& operator >> (std::istream& fl, tStudent& s)
{
	return fl
		>> G(0, s)
		>> G(1, s)
		>> G(2, s)
		>> G(3, s)
		>> G(4, s);
}

tVector vectorOfStudents(std::string path)
{
	tStudent s;
	tVector students;
	std::ifstream myFile(path);

	while (!myFile.eof())
	{
		myFile >> s;
		students.push_back(s);
	}

	return students;
}

int averageGrade(tStudent& s)
{
	return (G(2, s) + G(3, s) + G(4, s)) / 3;
}

void swap(tStudent& a, tStudent& b)
{
	tStudent temp = a;
	a = b;
	b = temp;
}

int partition(tVector& students, int st, int end)
{
	tStudent piv = students[end];
	int pos = st - 1;

	for (int i = st; i < end; i++)
	{
		if (averageGrade(piv) <= averageGrade(students[i]))
		{
			swap(students[++pos], students[i]);
		}
	}
	swap(students[pos + 1], students[end]);

	return pos + 1;
}

void quickSort(tVector& students, int st, int end)
{
	if (st < end)
	{
		int piv = partition(students, st, end);
		quickSort(students, st, piv - 1);
		quickSort(students, piv + 1, end);
	}
}
