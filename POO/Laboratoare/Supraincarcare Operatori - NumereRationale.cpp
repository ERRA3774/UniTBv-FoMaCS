// Supraincarcare operatori
#include <iostream>

struct rational // r = nr/num
{
	int nr, num;
};

int cmmdc(int a, int b)
{
	int r;

	for (; b; r = a % b, a = b, b = r);

	return a;
}

rational suma(rational& r1, rational& r2)
{
	rational r;
	r.nr = r1.nr * r2.num + r2.nr * r1.num;
	r.num = r1.num * r2.num;
	int c = cmmdc(r.nr, r.num);

	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}
	return r;
}

rational operator+(rational& r1, rational& r2) // r = r1 + r2; === r = suma(r1,r2);
{
	rational r;
	r.nr = r1.nr * r2.num + r2.nr * r1.num;
	r.num = r1.num * r2.num;
	int c = cmmdc(r.nr, r.num);

	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}
	return r;
}

rational operator++(rational& r) // ++r
{
	r.nr += r.num;
	return r;
}

rational operator++(rational& r, int) // r++
{
	rational r0 = r;
	r.nr += r.num;
	return r0;
}

rational operator-(rational& r1, rational& r2) // r = r1 - r2;
{
	rational r;
	r.nr = r1.nr * r2.num - r2.nr * r1.num;
	r.num = r1.num * r2.num;
	int c = cmmdc(r.nr, r.num);

	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}

	return r;
}

rational operator--(rational& r) // --r
{
	r.nr -= r.num;
	return r;
}

rational operator--(rational& r, int) // r--
{
	rational r0 = r;
	r.nr -= r.num;
	return r0;
}

rational operator*(rational& r1, rational& r2) // r = r1 * r2;
{
	rational r;
	r.nr = r1.nr * r2.nr;
	r.num = r1.num * r2.num;
	int c = cmmdc(r.nr, r.num);

	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}

	return r;
}

rational operator/(rational& r1, rational& r2) // r = r1 / r2;
{
	rational r;
	r.nr = r1.nr * r2.num;
	r.num = r1.num * r2.nr;
	int c = cmmdc(r.nr, r.num);

	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}

	return r;
}

bool operator==(rational& r1, rational& r2) // r1 == r2;
{
	rational r = r1 - r2;
	return r.nr * r.num == 0;
}

bool operator!=(rational& r1, rational& r2) // r1 != r2;
{
	rational r = r1 - r2;
	return r.nr * r.num != 0;
}

bool operator<(rational& r1, rational& r2) // r1 < r2;
{
	rational r = r1 - r2;
	return r.nr * r.num < 0;
}

bool operator>(rational& r1, rational& r2) // r1 > r2;
{
	rational r = r1 - r2;
	return r.nr * r.num > 0;
}

bool operator>=(rational& r1, rational& r2) // r1 >= r2
{
	rational r = r1 - r2;
	return r.nr * r.num > 0 || r.nr * r.num == 0;
}

bool operator<=(rational& r1, rational& r2) // r1 <= r2
{
	rational r = r1 - r2;
	return r.nr * r.num < 0 || r.nr * r.num == 0;
}

rational operator+(rational& r1, int& x) // rational + int
{
	rational r;
	r.nr = r1.nr + r1.num * x;
	r.num = r1.num;
	return r;
}

rational operator+(int& x, rational& r1) // int + rational
{
	return r1 + x; // rational + int
}

int main()
{
	rational r, r1, r2;
	std::cout << "Primul nr rational: ";
	std::cin >> r1.nr >> r1.num;
	std::cout << "Al doilear nr rational: ";
	std::cin >> r2.nr >> r2.num;

	r = r1 + r2;
	std::cout << "suma: " << r.nr << "/" << r.num << std::endl;

	r = r1 - r2;
	std::cout << "scaderea: " << r.nr << "/" << r.num << std::endl;

	r = r1 * r2;
	std::cout << "inmultire: " << r.nr << "/" << r.num << std::endl;

	r = r1 / r2;
	std::cout << "impartire: " << r.nr << "/" << r.num << std::endl;

	r1 == r2
		? std::cout << "egalitate: " << r1.nr << "/" << r1.num << " == " << r2.nr << "/" << r2.num << std::endl
		: std::cout << "inegalitate " << r1.nr << "/" << r1.num << " != " << r2.nr << "/" << r2.num << std::endl;

	r1 != r2
		? std::cout << "inegalitate: " << r1.nr << "/" << r1.num << " != " << r2.nr << "/" << r2.num << std::endl
		: std::cout << "egalitate: " << r1.nr << "/" << r1.num << " == " << r2.nr << "/" << r2.num << std::endl;

	if (r1 < r2)
	{
		std::cout << "mai mic: " << r1.nr << "/" << r1.num << " < " << r2.nr << "/" << r2.num << std::endl;
	}
	else if (r1 > r2)
	{
		std::cout << "mai mare: " << r1.nr << "/" << r1.num << " > " << r2.nr << "/" << r2.num << std::endl;
	}
	else
	{
		std::cout << "egal: " << r1.nr << "/" << r1.num << " == " << r2.nr << "/" << r2.num << std::endl;
	}

	r1 <= r2
		? std::cout << "mai mic: " << r1.nr << "/" << r1.num << " < " << r2.nr << "/" << r2.num << std::endl
		: std::cout << "egal: " << r1.nr << "/" << r1.num << " == " << r2.nr << "/" << r2.num << std::endl;

	r1 >= r2
		? std::cout << "mai mare: " << r1.nr << "/" << r1.num << " > " << r2.nr << "/" << r2.num << std::endl
		: std::cout << "egal: " << r1.nr << "/" << r1.num << " == " << r2.nr << "/" << r2.num << std::endl;

	r--;
	std::cout << "scaderea: " << r.nr << "/" << r.num << std::endl;

	--r;
	std::cout << "scaderea: " << r.nr << "/" << r.num << std::endl;
}