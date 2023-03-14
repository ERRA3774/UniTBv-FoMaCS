#pragma once
#include <iostream>

class Rational
{
private:
	int nr, num;
	int cmmdc(int nr, int num);							// helper
public:
	Rational();
	Rational(int Nr, int Num);
	int getNr();
	int getNum();
	void setNr(int Nr);
	void setNum(int Num);
	void reductie();

	Rational operator+(Rational r);						// r1 + r2
	Rational operator-(Rational r);						// r1 - r2
	Rational operator*(Rational r);						// r1 * r2
	Rational operator/(Rational r);						// r1 / r2

	Rational operator++();								// ++r
	Rational operator--();								// --r

	Rational operator+(int myNr);						// r + c
	Rational operator-(int myNr);						// r - c
	Rational operator*(int myNr);						// r * c
	Rational operator/(int myNr);						// r / c

	friend Rational operator+(int myNr, Rational r);	// c + r
	friend Rational operator-(int myNr, Rational r);	// c - r
	friend Rational operator*(int myNr, Rational r);	// c * r
	friend Rational operator/(int myNr, Rational r);	// c / r

	friend Rational operator++(Rational& r, int);		// r++
	friend Rational operator--(Rational& r, int);		// r--

	friend std::ostream& operator<<(std::ostream& fl, Rational r);
	friend std::istream& operator>>(std::istream& fl, Rational& r);

	~Rational();
};