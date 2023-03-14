#include "Rational.h"

Rational::Rational()
{
	nr = 0;
	num = 1;
}

Rational::Rational(int Nr, int Num)
{
	nr = Nr;
	num = Num;
}

int Rational::getNr()
{
	return nr;
}

void Rational::setNr(int Nr)
{
	nr = Nr;
}

int Rational::getNum()
{
	return num;
}

void Rational::setNum(int Num)
{
	num = Num;
}

void Rational::reductie()
{
	int c = cmmdc(nr, num);

	if (c)
	{
		nr /= c;
		num /= c;
	}
}

Rational Rational::operator+(Rational r)
{
	return Rational(nr * r.num + r.nr * num, num * r.num);
}

Rational Rational::operator-(Rational r)
{
	return Rational(nr * r.num - r.nr * num, num * r.num);
}

Rational Rational::operator*(Rational r)
{
	return Rational(nr * r.nr, num * r.num);
}

Rational Rational::operator/(Rational r)
{
	return Rational(nr * r.num, num * r.nr);
}

Rational Rational::operator++()
{
	return Rational(nr + num, num);
}

Rational Rational::operator--()
{
	return Rational(nr - num, num);

}

Rational Rational::operator+(int myNr)
{
	return Rational(nr + myNr * num, num);
}

Rational Rational::operator-(int myNr)
{
	return Rational(nr - myNr * num, num);
}

Rational Rational::operator*(int myNr)
{
	return Rational(nr * myNr, num);
}

Rational Rational::operator/(int myNr)
{
	return Rational(num * myNr, nr);
}

int Rational::cmmdc(int nr, int num)
{
	int r;

	for (; num; r = nr % num, nr = num, num = r);

	return nr;
}

Rational operator+(int myNr, Rational r)
{
	return Rational(r.nr + myNr * r.num, r.num);
}

Rational operator-(int myNr, Rational r)
{
	return Rational(r.nr - myNr * r.num, r.num);
}

Rational operator*(int myNr, Rational r)
{
	return Rational(r.nr * myNr, r.num);
}

Rational operator/(int myNr, Rational r)
{
	return Rational(r.num * myNr, r.nr);
}

Rational operator++(Rational& r, int)
{
	Rational r0 = r;
	r.nr += r.num;
	return r0;
}

Rational operator--(Rational& r, int)
{
	Rational r0 = r;
	r.nr -= r.num;
	return r0;
}

std::ostream& operator<<(std::ostream& fl, Rational r)
{
	if (r.nr == 0)
	{
		return fl << 0 << std::endl;
	}

	if (r.num == 1)
	{
		return fl << r.nr << std::endl;
	}

	return fl << r.nr << "/" << r.num << std::endl;
}

std::istream& operator>>(std::istream& fl, Rational& r)
{
	return fl >> r.nr >> r.num;
}

Rational::~Rational()
{
}