// Arbore sintactic
// Se citeste dintr-un fisier o expresie aritmetica formata din:
// 1. numere 
// 2. variabile 
// 3. operatori de baza (+, -, *, /) si paranteze
// Exemplu: (3+1)*7
// Exemplu: 4+x*((5-1+2)*3+2*(y-1))
// a) Sa se construiasca un arbore sintactic corespunzator expreisei. (2p)
// b) Sa se afiseze Arborele pe niveluri. (0.5p)
// c) Sa se evalueze expresia. Pentru variabile sa se ceara in mod repetat vari de tip double. (2p)

#include "HeapSiArbori_Problema1_SyntaxTree.h"
#include "conio.h"

int main()
{
	Expression expr("HeapSiArbori_Problema1.txt");

	SyntaxTree tree(expr);

	tree.Display();

	cout << "Press ESC to exit." << endl;
	do
	{
		tree.Evaluate();

	} while (_getch() != 27);

	return EXIT_SUCCESS;
}
