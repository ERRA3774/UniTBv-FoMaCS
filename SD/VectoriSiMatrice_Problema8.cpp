// Problema 8
// Se considera o structura fractie cu campurile:
//		1. numarator
//		2. numitor
// Aceasta structura dispune de:
//		1. o metoda reductie, care reduce fractia (ex: 12/30 devine 2/5)
//		2. functii pentru operatii aritmetice
//		3. functii de comparare
//		4. functie de transformare in numar zecimal (ex: 2/5 = 0.4)
// Sa se citeasca un vector de fractii. 
// Fiecare dintre acestea sa se reduca.
// Sa se sorteze vectorul cat mai eficient si sa se calculeze suma elementelor sale
// Scrieti functii de citire / afisare pentru fractii
// Puncrajul maxim se acorda pentru rezolvarea completa, eleganta si eficienta. (3p)

#include <iostream>
#include <vector>

void testOperators();
void swap(Fractie& a, Fractie& b);
int partition(std::vector<Fractie>& vec, int st, int end);
void quickSort(std::vector<Fractie>& vec, int st, int end);
void afisare(std::vector<Fractie>& vec);
void simplifyElements(std::vector<Fractie>& vec);

struct Fractie
{
	int nr = 0, num = 1;

	// Helper
	int cmmdc(int nr, int num)
	{
		int rest;

		for (; num; rest = nr % num, nr = num, num = rest);

		return nr;
	}

	// Reductie
	void simplify()
	{
		int c = cmmdc(nr, num);

		if (c)
		{
			nr /= c;
			num /= c;
		}
	}

	// Transformare in zecimal
	float toDecimal()
	{
		return (float) nr / num;
	}

	// Functii operatii aritmetice

	Fractie operator +(Fractie r2)
	{
		Fractie r;
		r.nr = nr * r2.num + r2.nr * num;
		r.num = num * r2.num;
		return r;
	}

	Fractie operator ++()
	{
		Fractie r;
		nr = nr + num;
		num = num;
		return r;
	}

	Fractie operator -(Fractie r2)
	{
		Fractie r;
		r.nr = nr * r2.num - r2.nr * num;
		r.num = num * r2.num;
		return r;
	}

	Fractie& operator --()
	{
		Fractie r;
		nr = nr - num;
		num = num;
		return r;
	}

	Fractie operator *(Fractie r2)
	{
		Fractie r;
		r.nr = nr * r2.nr;
		r.num = num * r2.num;
		return r;
	}

	Fractie operator /(Fractie r2)
	{
		Fractie r;
		r.nr = nr * r2.num;
		r.num = num * nr;
		return r;
	}

	Fractie operator +(int x)
	{
		Fractie r;
		r.nr = nr + num * x;
		r.num = num;
		return r;
	}

	Fractie operator -(int x)
	{
		Fractie r;
		r.nr = nr - num * x;
		r.num = num;
		return r;
	}

	Fractie operator *(int x)
	{
		Fractie r;
		r.nr = nr * x;
		r.num = num;
		return r;
	}

	Fractie operator /(int x)
	{
		Fractie r;
		r.nr = num * x;
		r.num = nr * x;
		return r;
	}

	friend Fractie operator +(int x, Fractie r2)
	{
		Fractie r;
		r.nr = r2.nr + r2.num * x;
		r.num = r2.num;
		return r;
	}

	friend Fractie operator -(int x, Fractie r2)
	{
		Fractie r;
		r.nr = r2.nr - r2.num * x;
		r.num = r2.num;
		return r;
	}

	friend Fractie operator *(int x, Fractie r2)
	{
		Fractie r;
		r.nr = r2.nr * x;
		r.num = r2.num;
		return r;
	}

	friend Fractie operator /(int x, Fractie r2)
	{
		Fractie r;
		r.nr = r2.num * x;
		r.num = r2.nr * x;
		return r;
	}

	// Functii de comparare

	bool operator == (Fractie r2)
	{
		return nr * r2.num == num * r2.nr;
	}

	bool operator != (Fractie r2)
	{
		return nr * r2.num != num * r2.nr;
	}

	bool operator <(Fractie r2)
	{
		Fractie r;
		r.nr = nr;
		r.num = num;
		r = r - r2;
		return r.nr * r.num < 0;
	}

	bool operator >(Fractie r2)
	{
		Fractie r;
		r.nr = nr;
		r.num = num;
		r = r - r2;
		return r.nr * r.num > 0;
	}

	bool operator <=(Fractie r2)
	{
		Fractie r;
		r.nr = nr;
		r.num = num;
		r = r - r2;
		return r.nr * r.num <= 0;
	}

	bool operator >=(Fractie r2)
	{
		Fractie r;
		r.nr = nr;
		r.num = num;
		r = r - r2;
		return r.nr * r.num >= 0;
	}

	// Scriere si afisare
	friend std::ostream& operator <<(std::ostream& fl, Fractie r)
	{
		if (r.nr == 0)
		{
			return fl << 0;
		}

		if (r.num == 1)
		{
			return fl << r.nr;
		}

		return fl << r.nr << "/" << r.num;
	}

	friend std::istream& operator >>(std::istream& fl, Fractie& r)
	{
		return fl >> r.nr >> r.num;
	}
};

int main()
{
	std::vector<Fractie> vec{ {7,9}, {21,27}, {14,18}, {69696, 136}, {8,9},{5,1},{2,7}, {1,4},{1,5},{1,6},{8,7},{10,1},{5,1},{64,72},{8,9} };

	afisare(vec);

	std::cout << "Dupa sortare:" << std::endl;
	quickSort(vec, 0, vec.size() - 1);
	simplifyElements(vec);
	afisare(vec);

	return 0;
}

void swap(Fractie& a, Fractie& b)
{
	Fractie temp = a;
	a = b;
	b = temp;
}

int partition(std::vector<Fractie>& vec, int st, int end)
{
	Fractie piv = vec[end];
	int pos = st - 1;

	for (int i = st; i < end; i++)
	{
		if (piv >= vec[i])
		{
			swap(vec[++pos], vec[i]);
		}
	}
	swap(vec[pos + 1], vec[end]);

	return pos + 1;
}

void quickSort(std::vector<Fractie>& vec, int st, int end)
{
	if (st < end)
	{
		int piv = partition(vec, st, end);
		quickSort(vec, st, piv - 1);
		quickSort(vec, piv + 1, end);
	}
}

void afisare(std::vector<Fractie>& vec)
{
	std::cout << "Vector de fractii:" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Vector de fractii in zecimal:" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i].toDecimal() << " ";
	}
	std::cout << std::endl;
}

void simplifyElements(std::vector<Fractie>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].simplify();
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void testOperators()
{
	Fractie r1;
	r1.nr = 7;
	r1.num = 9;
	std::cout << "r1 = " << r1 << std::endl;

	Fractie r2;
	r2 = r1;
	std::cout << "r2 = " << r2 << std::endl;

	Fractie r3 = r1 + r2;
	std::cout << "r3 = " << r3 << std::endl;

	Fractie r4;
	r4.nr = 69696;
	r4.num = 136;
	r4.simplify();
	std::cout << "r4 = " << r4 << std::endl;

	Fractie r5;
	r5.nr = 8;
	r5.num = 9;
	Fractie r6;
	r6.nr = 5;
	r6.num = 1;
	std::cout << "r5 + r6 = " << r5 + r6 << std::endl;
	std::cout << "r5 - r6 = " << r5 - r6 << std::endl;
	std::cout << "r5 * r6 = " << r5 * r6 << std::endl;
	std::cout << "r5 / r6 = " << r5 / r6 << std::endl;

	Fractie r7;
	r7.nr = 2;
	r7.num = 7;
	Fractie r8;
	r8.nr = 1;
	r8.num = 4;
	++r7;
	++r8;
	std::cout << "++r7 = " << r7 << std::endl;
	std::cout << "++r8 = " << r8 << std::endl;
	--r7;
	--r8;
	std::cout << "--r7 = " << r7 << std::endl;
	std::cout << "--r8 = " << r8 << std::endl;

	Fractie r11;
	r11.nr = 8;
	r11.num = 7;
	std::cout << "r11 + 4 = " << r11 + 4 << std::endl;
	std::cout << "3 + r11 = " << 3 + r11 << std::endl;
	std::cout << "r11 - 1 = " << r11 - 1 << std::endl;
	std::cout << "9 - r11 = " << 9 - r11 << std::endl;
	std::cout << "r11 * 4 = " << r11 * 4 << std::endl;
	std::cout << "8 * r11 = " << 8 * r11 << std::endl;
	std::cout << "r11 / 4 = " << r11 / 4 << std::endl;
	std::cout << "7 / r11 = " << 7 / r11 << std::endl;
}
