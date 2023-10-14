#pragma once

#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

class VectorOperations {

public:
	VectorOperations();
	VectorOperations(vector<int>);
	VectorOperations(vector<pair<int, int>>);
	VectorOperations(vector<Point>);
	VectorOperations(vector<Rectangle>);

	// Numim perechea (x,y) pereche ordonata daca x < y
	// a) Sa se verifice daca un vector contine doar perechi ordonate (care satisfac conditia de mai sus. (0.5p)
	// b) Sa se verifice daca oricare x din prima jumatate a vectorului formeaza o pereche ordonata cu oricare y din cea de-a doua jumatate. (1p)
	bool IsSortedA();
	bool IsSortedB();

	// Sa se verifice si sa se afiseze daca un vector este superior sau inferior
	// Un vector este superior daca acesta contine mai multe elemente cu valoarea mai mare decat media aritmetica a intregului vector si inferior altfel. (1p)
	bool IsSuperior();

	// Se considera un vector cu nr elemente numere naturale din intervalul [30, 80]
	// Sa se determine si sa se afiseze elementul care apare de cele mai multe ori. (1p)
	int MostFrequentNum(const int, const int);

	// Se considera un vector V cu *nr* elemente numere naturale.
	// Sa se construiasca un al doilea vector W, care contine fiecare element din V, care are in componenta doar cifre impare, duplicandu-le (1p)
	// Exemplu: V = [1, 2, 5, 13, 27, 3, 57] -> W = [1, 1, 5, 5, 13, 13, 3, 3, 57, 57]
	vector<int> OddsRepeated(int);

	// Un numar de baza b este retinut intr-un std::pair<int, int> ce contine valoarea si baza de numeratie in care acesta este reprezentat
	// Se citesc mai multe astfel de numere reprezentate in baze diferite.
	// Sa se determine perechile de valori egale (1.5p)
	// Exemplu: pair1.first = 10, pair1.second = 8 pair2.first = 2 pair2.second = 1000 -> pair1 == pair2
	unordered_map<int, vector<pair<int, int>>> EqualPairs();

private:
	bool _HasOnlyOddDigits(int);
	bool _IsValid(pair<int, int>);
	int _Base10Val(pair<int, int>);

private:
	vector<int> _nums;
	vector<pair<int, int>> _pairs;
};