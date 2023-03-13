#include "Punct.h"

int main()
{
	Punct p0;
	p0.init(0, 0);
	std::cout << "Punctul p0: " << p0 << std::endl;

	Punct p1(1,2);
	std::cout << "Punctul p1: " << p1 << std::endl;

	Punct p2(0,0);
	p2.setX(2);
	p2.setY(3);
	std::cout << "Punctul p2: " << p2 << std::endl;

	Punct p3 = p1 + p2;
	std::cout << "Norma lui " << p3 << " = " << !p3 << std::endl;

	Punct p4(2, 5);
	std::cout << "p4 = ";
	std::cin >> p4;
	std::cout << "p4: " << p4 << std::endl;

	Punct p5(4, 6);
	Punct p6(7, 8);
	std::cout << "Distanta dintre " << p5 << " si " << p6 << " = " << p5.dist(p6)<< std::endl;

	Punct p7(2, 6);
	std::cout << p7 << " amplificat cu 3 = " << p7.amplif(3) << std::endl;

	Punct p8(5,6);
	Punct p9(2, 8);
	std::cout << "Suma dintre " << p8 << "si" << p9 << " = " << p8 + p9 << std::endl;
	std::cout << "Diferenta dintre " << p8 << "si" << p9 << " = " << p8 - p9 << std::endl;
	std::cout << "Produsul dintre " << p8 << "si" << p9 << " = " << p8 * p9 << std::endl;

	Punct* p_unu;
	p_unu = new Punct;
	Punct* p_doi = new Punct(1, 7);
	Punct p_trei = p_doi->amplif(2);
	std::cout << "Punct: " << p_trei.getX() << " " << p_trei.getY() << std::endl;
	delete p_unu;
	delete p_doi;

	return 0;
}