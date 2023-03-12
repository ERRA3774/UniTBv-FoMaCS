#include"iostream"
#include"malloc.h"
#include"conio.h"
#include"string"

using namespace std;

struct test
{
	int x, y, z;
};

int f(int x)		// (f,int)
{
	return x + 1;
}

float f(float x)		// (f,float)
{
	return x * 2;
}

int f(int x, int y)	// (f,int,int)
{
	return x + y;
}

int g(int x, int y = 1, int z = 2)
{
	return x + y + z;
}

//int g(int x, int y, int z)
//{
//	return x + y + z;
//}
//
//int g(int x, int y)
//{
//	int z = 2;
//	return x + y + z;
//}
//
//int g(int x)
//{
//	int y = 1;
//	int z = 2;
//	return x + y + z;
//}
//

inline int h(int x, int y)
{
	//while (x < y)
	//	y -= x;
	return x*y;
}

template<class T>
T next(T x)
{
	//y++;
	return x + 1;
}

//int next(int x)
//{
//	//y++;
//	return x + 1;
//}
//
//double next(double x)
//{
//	//y++;
//	return x + 1;
//}

template<class T>
T min(int n, T* a)
{
	T m = a[0];
	for (int i = 1;i < n;i++)
		if (a[i] < m)
			m = a[i];
	return m;
}

struct punct
{
	float coord_x, coord_y;
};

struct punctcolorat
{
	punct coordonate;
	string culoare;
};

void sort2(int* x, int* y)	// x=&u y=&v
{
	if (*x > *y)
	{
		int aux = *x;
		*x = *y;
		*y = aux;
	}
}

void sort2(int& x, int& y)	// x=u y=v
{
	if (x > y)
	{
		int aux = x;
		x = y;
		y = aux;
	}
}

// input:
// 2 4
// 1 2 3 4
// 5 6 7 8

// output:
// 4
// (1 3 5 7)

void impare(int m, int n, int** a, int& k, int*& v)
{
	k = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] % 2 == 1)
				k++;
	v = new int[k];
	k = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] % 2 == 1)
				v[k++] = a[i][j];
}

struct rational	// r = nr/num
{
	int nr, num;
};

int cmmdc(int a, int b)
{
	int r;
	for (;b;r = a%b, a = b, b = r);
	return a;
}

rational suma(rational r1, rational r2)
{
	rational r;
	r.nr = r1.nr*r2.num + r2.nr*r1.num;
	r.num = r1.num*r2.num;
	int c = cmmdc(r.nr, r.num);
	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}
	return r;
}

rational operator+(rational r1, rational r2)
{
	rational r;
	r.nr = r1.nr*r2.num + r2.nr*r1.num;
	r.num = r1.num*r2.num;
	int c = cmmdc(r.nr, r.num);
	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}
	return r;
}

rational operator-(rational r1, rational r2)
{
	rational r;
	r.nr = r1.nr*r2.num - r2.nr*r1.num;
	r.num = r1.num*r2.num;
	int c = cmmdc(r.nr, r.num);
	if (c)
	{
		r.nr /= c;
		r.num /= c;
	}
	return r;
}

rational operator++(rational& r)	// ++r
{
	r.nr += r.num;
	return r;
}

rational operator++(rational& r, int)	// r++
{
	rational r0 = r;
	r.nr += r.num;
	return r0;
}

// r=r1+r2;
// r=suma(r1,r2);

bool operator==(rational r1, rational r2)	// a/b=c/d
{
	return r1.nr*r2.num == r1.num*r2.nr;
}

bool operator<(rational r1, rational r2)	// r1<r2 <=> r1-r2<0
{
	rational r = r1 - r2;
	return r.nr*r.num < 0;
}

rational operator+(rational r1, int x)
{
	rational r;
	r.nr = r1.nr + r1.num*x;
	r.num = r1.num;
	return r;
}

rational operator+(int x, rational r1)
{
	return r1 + x;
}

// -, *, /, ==, <
// +,-,*,/ (rational,int) (int,rational)
// <=,>=,>,!=,--(post si pre)

void main()
{
	rational r, r1, r2;
	cout << "Primul nr. rational: ";
	cin >> r1.nr >> r1.num;
	cout << "Al doilea nr. rational: ";
	cin >> r2.nr >> r2.num;
	r = r1 + r2;
	++r;
	r++;
	//r = operator+(r1, r2);
	//r = suma(r1, r2);
	cout << "suma: " << r.nr << "/" << r.num << endl;

	//int m, n;
	//cin >> m >> n;

	//int** a = new int*[m];
	//for (int i = 0;i < m;i++)
	//	a[i] = new int[n];

	//for (int i = 0;i < m;i++)
	//	for (int j = 0;j < n;j++)
	//		cin >> a[i][j];

	//int k;
	//int* b;
	//impare(m, n, a, k, b);
	//cout << "impare:" << endl;
	//for (int i = 0;i < k;i++)
	//	cout << b[i] << " ";
	//cout << endl;

	//delete[] b;
	//for (int i = 0;i < m;i++)
	//	delete[] a[i];
	//delete[] a;

	//int a = 1;
	//int& b = a;
	//a++;
	//cout << b << endl;

	//punctcolorat pcolor;
	//float& x = pcolor.coordonate.coord_x;
	////pcolor.coordonate.coord_x = 10;
	//x = 10;
	//pcolor.coordonate.coord_y = 20;
	//pcolor.culoare = "rosu";
	////pcolor.coordonate.coord_x++;
	//x++;

	//int u = 4, v = 1;
	////sort2(&u, &v);
	//sort2(u, v);
	//cout << u << " " << v << endl;

	//f(1);
	//cout << g(4, 5, 6) << endl;
	//cout << g(4, 5) << endl;
	//cout << g(4) << endl;

	//int p = h(2, 5);

	//cout << next(4) << endl;
	//cout << next(4.1) << endl;
	////cout << next((string)"abcd") << endl;

	//int a[4] = { 2,4,1,5 };
	//cout << min(4, a) << endl;

	//double b[4] = { 2.,4.4,1.7,5 };
	//cout << min(4, b) << endl;

	//int* p;
	//int x;
	//p = &x;

	//test t;
	//t.x = 1;
	//t.y = 2;
	//t.z = 3;

	//p = &t.x;

	//cout << *p << endl;
	//cout << *(p+1) << endl;
	//cout << *(p+2) << endl;

	//p = (int*)malloc(sizeof(int));
	//free(p);
	//p = new int;
	//*p = 7;
	//delete p;

	//int m, n;
	//cin >> n;
	//int v[10];
	//p = new int[n];
	//for (int i = 0;i < n;i++)
	//	cin >> p[i];
	//delete[] p;

	//cin >> m >> n;
	//int** a;
	//a = new int*[m];
	//for (int i = 0;i < m;i++)
	//	a[i] = new int[n];

	//for (int i = 0;i < m;i++)
	//	delete[] a[i];
	//delete[] a;

	_getch();
}