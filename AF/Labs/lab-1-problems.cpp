/*Intro! Ce variante avem pentru a rezolva: Sa se scrie o functie care returneaza si suma, dar si
produsul a doua numere date ca parametru. Discutie.
*/

/*#include <vector>

using namespace std;

struct Pereche {
	int suma, produs;
};

Pereche suma_produs(int a, int b) {
	Pereche p;
	p.suma = a + b;
	p.produs = a * b;
	return p;
}

void suma_produs(int a, int b, int val[2])//diferenta se face in functie de nr de param sau de tipul or daca sunt diferiti
{
	val[0] = a + b;
	val[1] = a * b;
}

void suma_produs(int a, int b, int& suma, int& produs) {
	suma = a + b;
	produs = a * b;
}

pair<int,int> suma_produs_pair(int a, int b){
pair<int,int> p;
p.first = a + b;
p.second = a * b;
return p;
}

int main() {
	int a, b;
	cin >> a >> b;
	Pereche p = suma_produs(a, b);
	cout << p.suma << " " << p.produs << "\n";

	int v[2];
	suma_produs(a, b, v);
	cout << v[0] << " " << v[1] << "\n";

	int suma, produs;
	suma_produs(a, b, suma, produs);
	cout << suma << " " << produs << "\n";

	pair<int, int> p1;
	p1=suma_produs_pair(a, b);
	cout << p1.first << " " << p1.second << "\n";

	return 0;
}*/

/*8. Se citesc un numar natural n de maxim 3 cifre si o cifra c. Eliminati toate aparitiile cifrei c din
numarul n si afisati numarul astfel obtinut.
Exemplu: n= 2345324, c=2 rezulta numarul 34534*/

/*
int stergere_cifre(int numar, int c) {
	int numar_nou = 0, p=1;
	while (numar) {
		if (numar % 10 != c)
		{
			numar_nou += p * (numar % 10);
			p *= 10;
		}
		numar /= 10;
	}
	return numar_nou;
}

int main() {
	int nr, cifra;
	std::cin >> nr >> cifra;
	while (cifra > 9 || cifra < 0) {
		std::cout << "introduceti o cifra (valida)";
		std::cin >> cifra;
	}
	std::cout<<stergere_cifre(nr, cifra);
	return 0;
}
*/

/*6. Să se afiseze cel mai mic numar care se poate forma cu cifrele lui n, fiecare cifra repetandu-se
de cate ori se repeta si in n.
Exemplu: 1204192 se va afisa: 112249
-pb 6 cu vector de frecventa, contine zerourile la inceput, nu se vad*/

/*
int constructie_numar_mic(int nrinit)
{
	int f[10] = { 0 };
	while (nrinit != 0) {
		f[nrinit % 10]++;
		nrinit = nrinit / 10;
	}
	int nr_nou=0;
	for (int i = 1; i <= 9; i++)
		while (f[i]) {
			nr_nou = nr_nou * 10 + i;
			f[i]--;
		}
	return nr_nou;
}

int main() {
	int nr;
	std::cin >> nr;
	std::cout<<constructie_numar_mic(nr);
	return 0;
}*/

//-tot pb 6 dar constructie cu nr egal cifre cu nr initial

/*
int constr_nr_egal_cifre(int numar)
{
	int cifra_min = 10;
	int fr[10] = { 0 };
	while (numar)
	{fr[numar % 10]++;
	if (numar % 10 != 0 && numar % 10 < cifra_min)
	{
		cifra_min = numar % 10;
	}
	numar /= 10;
	}
	int nr_nou = cifra_min;
	fr[cifra_min]--;
	for (int i = 0; i <= 9; i++) {
		while (fr[i]) {
			nr_nou = nr_nou * 10 + i;
			fr[i]--;
		}
	}
	return nr_nou;
}

int main() {
	int nr;
	std::cin >> nr;
	std::cout << constr_nr_egal_cifre(nr);
	return 0;
}*/

/*10. Se citeste un numar natural n, n>1000. Afisati cel mai mare numar care se pot obtine din n prin
eliminarea unei singure cifre.
Exemplu: din 45329 se obtine 5329 (e cel mai mare dintre numerele 4532 4539 4529 4329
	5329)
var1: taiem pe rand cifrele si comparam nr

var2: caut cifra care in dreapta ei are o cifra mai mare si pe ea o tai, daca nu e asa ceva, e ultima cifra
*/

/*#include <math.h>

int lungime_nr(int numar) {
	int nrcifre = 0;
	{if (numar == 0)
		nrcifre = 1;
	while (numar) { nrcifre++; numar /= 10; }}
	return nrcifre;
}

int eliminare_cifra(int numar, int poz, int nrcifre) {
	int p = pow(10, nrcifre - poz);
	numar = numar/(int)pow(10, nrcifre - poz + 1) * (int)pow(10, nrcifre - poz) + numar%p;
	return numar;
}



int determinare_nr_maxim(int numar) {
	int nrcifre = lungime_nr(numar);
	int maxim = 0;
	for (int i = 1; i <= nrcifre; i++)
	{
		if (eliminare_cifra(numar, i,nrcifre) > maxim)
			maxim = eliminare_cifra(numar, i,nrcifre);
	}
	return maxim;
}
int main() {
	std::cout << determinare_nr_maxim(45329);

}*/

//lab 2 cu alocare dinamica sau vector din stl

/*int palindron(int a) {
	int copy = a;
	int inv=0;
	while (a != 0) {
	inv = inv * 10 + a % 10;
		a /= 10;
	}
	return inv;
}

int cmmdc(int a, int b) {
	while (a != b) {
		int r=a%b;
		a = b;
		b = r;
	}
	return a;
}

bool prim(int a) {
	if (a == 0 || a == 1)
		return 0;
	for (int d = 3; d <= sqrt(a);d+=2&&a>2) {
		if (a % d == 0)
			return 0;
	}
	return 1;
}

//7. Să se verifice daca cifrele lui n sunt in progresie aritmetica. Exemplu: n = 2596 se va afisa:
Cifrele lui 2596 nu sunt in progresie aritmetica.
Exemplu: n=2468 se va afisa: Cifrele lui 2468 sunt in progresie aritmetica.

bool progresie_aritmetica(int a, int b, int c) {
	if (b == (a + c) / 2)
		return 1;
	else
		return 0;
}

//9. Se citesc un numar natural n de maxim 3 cifre si o cifra c. Eliminati toate aparitiile cifrei c din
numarul n si afisati numarul astfel obtinut.
Exemplu: n= 2345324, c=2 rezulta numarul 34534

int nr_cifre(int a) {
	int nr = 0;
	while (a != 0)
	{
		nr++;
		a /= 10;
	}
	return nr;
}

int inversare_cifre(int a) {
	int a2=0;
	int n = nr_cifre(a);
	for (int i =0; i <n; i+=2) {
		if(a!=0) { int c1 = a % 10;
		a /= 10;
		int c2 = a % 10;
		a /= 10;
		a2 = a2 + c1 * (int)(pow(10, (i + 1)))+ c2 * (int)(pow(10, i));
		}
	}
	return a2;
}

int main() {
	int a;
	std::cin >> a;
	std::cout<<inversare_cifre(a);
}
*/
