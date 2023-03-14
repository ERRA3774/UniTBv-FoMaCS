#include "Rational.h"

int main()
{
	Rational r1;
	r1.setNr(7);
	r1.setNum(9);
	std::cout << "r1 = " << r1;

	Rational r2;
	r2.setNr(r1.getNr());
	r2.setNum(r1.getNr());
	std::cout << "r2 = " << r2;

	Rational r3(5, 8);
	std::cout << "r3 = " << r3;

	Rational r4(69696, 136);
	r4.reductie();
	std::cout << "r4 = " << r4;

	Rational r5(8, 9);
	Rational r6(5, 1);
	std::cout << "r5 + r6 = " << r5 + r6;
	std::cout << "r5 - r6 = " << r5 - r6;
	std::cout << "r5 * r6 = " << r5 * r6;
	std::cout << "r5 / r6 = " << r5 / r6;

	Rational r7(2, 7);
	Rational r8(1, 4);
	++r7;
	++r8;
	std::cout << "++r7 = " << r7;
	std::cout << "++r8 = " << r8;
	--r7;
	--r8;
	std::cout << "--r7 = " << r7;
	std::cout << "--r8 = " << r8;

	Rational r9;
	Rational r10;

	r9 = ++r7;
	r10 = r8++;

	std::cout << "r7 = " << r7;
	std::cout << "r8 = " << r8;
	std::cout << "r9 = ++r7 = " << r9;
	std::cout << "r10 = r8++ = " << r10;

	Rational r11(8, 7);
	std::cout << "r11 + 4 = " << r11 + 4;
	std::cout << "3 + r11 = " << 3 + r11;
	std::cout << "r11 - 1 = " << r11 - 1;
	std::cout << "9 - r11 = " << 9 - r11;
	std::cout << "r11 * 4 = " << r11 * 4;
	std::cout << "8 * r11 = " << 8 * r11;
	std::cout << "r11 / 4 = " << r11 / 4;
	std::cout << "7 / r11 = " << 7 / r11;

	Rational r0;
	std::cout << "Input: ";
	std::cin >> r0;
	std::cout << "r0 = " << r0;

	return 0;
}