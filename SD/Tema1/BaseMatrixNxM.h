#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
Se considera o matrice matr cu nrows linii si ncols coloane, cu ncols < 10, ale
carei elemente sunt numere naturale formate dintr-o singura cifra. Se considera
ca fiecare coloana col reprezinta un numar in baza col+2. Sa se scrie o functie
care plaseaza numerele transformate in baza zece intr-un vector numbers si
returneaza true, daca matricea a fost valid si false altfel. In cazul in care
matricea a fost valida sa se afiseze acest vector de numere. Matricea este valid
daca toate elementele de pe coloana col sunt numere naturale din intervalul
[0, col + 1).
Exemplu: Se considera matricea

1 1 1
1 2 0
0 0 3
1 2 0
0 0 1

Atunci numbers = {26, 141, 305}.
*/

class BaseMatrixNxM {

public:
	BaseMatrixNxM();

	BaseMatrixNxM(vector<vector<int>>);

	bool IsValid();

	void Print();

	void PrintBase10Values();

private:
	void _GenerateBase10Values();

private:
	int _rows;
	int _cols;
	vector<vector<int>> _data;
	vector<int> _base10Values;
	const int _C = 2;
};

static void Demo() {
	BaseMatrixNxM mat({
		{ 1,1,1 },
		{ 1,2,0 },
		{ 0,0,3 },
		{ 1,2,0 },
		{ 0,0,1 }
		});

	mat.Print();
	mat.IsValid();
	mat.PrintBase10Values();
}