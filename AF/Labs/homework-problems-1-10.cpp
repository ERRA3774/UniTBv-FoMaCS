#include<iostream>
#include<vector>
#include <math.h>

/*1. Se citește un număr natural n și cele n cele n elemente ale unui vector. Să se înlocuiască
elementele de pe pozițiile pare cu cea mai mică cifra din număr iar cele de pe pozițiile impare
cu 0 dacă numărul e prim și cu 1 altfel.
*/

/*int prim(int a) {
	if (a < 2)
		return 0;
	for (int d = 2; d * d <= a; d++)
		if (a % d == 0)
			return 0;
	return 1;
}

int cifra_minima(int a) {
	int minim = 10;
	while(a!=0){
		if (a % 10 < minim)
			minim = a % 10;
		a /= 10;
	}
	return minim;
}

void citire(std::vector<int> &v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void prelucrare(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		if (i % 2 == 0)
		{
			v[i] = cifra_minima(v[i]);
		}
		else
			if (i % 2 == 1 && prim(v[i]))
				v[i] = 0;
			else if (i % 2 == 1 && !prim(v[i]))
				v[i] = 1;
	}
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}
int main() {
	std::vector<int> v;int n;
	std::cin >> n;
	citire(v, n);
	prelucrare(v);
	afisare(v);
}*/

/*2. Se citește un număr natural n și cele n cele n elemente ale unui vector. Să se șteargă din
vector acele elemente care sunt egale cu suma vecinilor săi.
*/

/*
//atentie cod care nu stiu daca merge
void citire(std::vector<int>& v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

int validare(std::vector<int>& v) {
	if (v.size() > 1)
		return 1;
	else
	{
		std::cout << "Dimensiunea vectorului nu este conforma cu cerinta";
		return 0;
	}

}

void prelucrare(std::vector<int>& v) {
	int size = v.size();
	int i = 1;
	for (int j = 1; j < size - 1; j++) {
		if (v[i] == v[i - 1] + v[i+ 1]) {
			v.erase(v.begin() + i);
			size--;
			i++;
		}
	}
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}

int main() {
	int n; std::vector<int> v;
	std::cin >> n;
	citire(v, n);
	if (validare(v))
		prelucrare(v);
	afisare(v);
}*/

/*3. Se citește un număr natural n și cele n cele n elemente ale unui vector. Să se insereze în
vector între oricare două valori vecine suma și produsul acestora.
Obs: Determinarea sumei și a produsului a două numere se va realiza în cadrul unui singure
funcții.*/

/*void citire(std::vector<int>& v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

int validare(std::vector<int>& v) {
	if (v.size() > 1)
		return 1;
	else
	{
		std::cout << "Dimensiunea vectorului nu este conforma cu cerinta";
		return 0;
	}

}
void suma_produs(int a, int b, int& s, int& p)
{
	s = a + b;
	p = a * b;
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}

void inserare(std::vector<int>& v)
{
	int size = v.size();
	int i = 0;
	for (int j = 0; j < size - 1; j++) {
		int s = 0, p = 0;
		suma_produs(v[i], v[i + 1], s, p);
		v.insert(v.begin() + i + 1, s);
		v.insert(v.begin() + i + 2, p);
		afisare(v);
		i = i + 3;
		std::cout << "i=" << i << "\n";
	}
}

int main() {
	int n; std::cin >> n;
	std::vector<int> v;
	citire(v, n);
	if (validare(v))
		inserare(v);
	//afisare(v);
}*/

/*
4. Se citeșc două numere naturale n și k și cele n elemente ale unui vector. Să se deplaseze spre
dreapta elementele vectorilor cu k-poziții. Primele k-elemente ale vectorului vor fi
a) zerorizate iar dimensiunea vectorului va crește k elemente
 Ex: v = [1,2,3,4,5,6,7], k=3 afișare: [0,0,0,1,2,3,4,5,6,7]
b) înlocuite cu ultimele k elemente din vector astfel dimensiunea vectorului nu va suferi
modificări
Ex: v = [1,2,3,4,5,6,7], k=3 afișare: [5,6,7,1,2,3,4]
*/

/*//de verificat cu debugger
void citire(std::vector<int>& v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void inserare(std::vector<int>& v, int k) {
	for (int i = 0; i < k; i++)
	{
		v.insert(v.begin(), 0);
	}
}

void modificare(std::vector<int>& v,int k) {
	for (int j = 0; j < k; j++) {
		int aux = v[0];
		for (int i = 1; i < v.size(); i++) {
			v[i - 1] = v[i];
		}
		v[v.size() - 1] = aux;
	}
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}


int main() {
	int n; std::cout << "n= "; std::cin >> n;
	int k; std::cout << "k= "; std::cin >> k;
	std::vector<int> v;
	citire(v, n);
	//inserare(v, k);
	modificare(v,k);
	afisare(v);
}*/

/*
5. Se dă un vector v cu n elemente. Să se elimine din vector elementul de cu indicele de poziție
p (citit de la tastatură) iar p să se insereze la începutul vectorului. Să se afișeze noul vector.
Ex: 2 51 2 91 3 cu p = 3, afiseaza 3 2 51 2 3
*/

/*//pb5
void citire(std::vector<int>& v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void prelucrare(std::vector<int>& v, int p) {
			v.erase(v.begin() + p);
			v.insert(v.begin(), p);
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}

int main() {
	int n; std::vector<int> v;
	int p;
	std::cout << "n= "; std::cin >> n;
	std::cout << "p= "; std::cin >> p;
	citire(v, n);
	prelucrare(v, p);
	afisare(v);
}*/


/*
7. Se citește un număr natural n și n medii (numere reale cu doua zecimale cu valori cuprinse
intre 1 şi 10). Să se afişeze o statistică a mediilor astfel: numărul de medii cuprinse în
intervalul [1,2], numărul de medii cuprinse în intervalul (2,3], …, numărul de medii cuprinse
în intervalul (9,10].
*/

/*
void citire(std::vector<float>& v, int n) {
	float x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void afisare_statistica(std::vector<float> v, std::vector<int> fr) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= 1 && v[i] <= 2)
			fr[0]++;
		else if (v[i] > 2 && v[i] <= 3)
			fr[1]++;
		else if (v[i] > 3 && v[i] <= 4)
			fr[2]++;
		else if (v[i] > 4 && v[i] <= 5)
			fr[3]++;
		else if (v[i] > 5 && v[i] <= 6)
			fr[4]++;
		else if (v[i] > 6 && v[i] <= 7)
			fr[5]++;
		else if (v[i] > 7 && v[i] <= 8)
			fr[6]++;
		else if (v[i] > 8 && v[i] <= 9)
			fr[7]++;
		else if (v[i] > 9 && v[i] <= 10)
			fr[8]++;
	}
	for (int i = 0; i < 9; i++) {
		std::cout << "Medii intre " << i + 1 << " si " << i + 2 << " sunt in numar de: " << fr[i] << "\n";
	}
}

int main() {
	int n; std::cin >> n;
	std::vector<float> v;
	citire(v, n);
	std::vector<int> fr = { 0,0,0,0,0,0,0,0,0 };
	afisare_statistica(v, fr);
	//afisare(v);
}*/

/*
8. Un număr natural se reţine într-un vector (număr mare), astfel încât fiecare componentă a
vectorului conţine câte o cifră a numărului. Să se înmulţească numărul cu un număr între 1 şi
9 (random generat).
*/

/*
void citire(std::vector<int>& v, int n) {
	int x;
	for (int i = 1; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void prelucrare(std::vector<int>& v, int x){
	int size = v.size();
	int memory = 0, memory2 = 0;
	memory = (v[size - 1] * x - (v[size - 1] * x) % 10) / 10;
	v[size - 1] = (v[size - 1] * x) % 10;
	for (int i = size - 2; i >= 0; i--) {
		memory2 = (v[i] * x - (v[i] * x) % 10) / 10;
		v[i] = (v[i] * x) % 10+memory;
		memory = memory2;
	}
	if (memory != 0 && v[0] == 0) {
		v.insert(v.begin(), memory);
	}
}

int generare() {
	return rand() % 10 + 1;
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}

int main() {
	int n; std::cin >> n;
	std::vector<int> v;
	citire(v, n);
	//std::cout << generare();
	prelucrare(v, generare());
	afisare(v);
}
*/

/*6. Se citeșc două numere naturale n și m și doi vectori crescători de lungime n, respectiv m. Să
se creeze și să se afișeze vectorul ordonat crescător obținut prin reuniunea celor doi vector.
Ex: v1 = [1,2,5,10,13,20] v2 = [1,6,7,9,15,25], afisare: [1,1,2,5,6,7,9,10,13,15,20,25]
*/

/*
void citire(std::vector<int>& v, int n) {
	int x;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}
}

void interclasare(std::vector<int> a, std::vector<int> b, std::vector<int>& c) {
	int i = 0, j = 0;
	int a1 = a.size();
	int b1 = b.size();
	while (i < a1 && j < b1) {
		if (a[i] < b[j]) {
			c.push_back(a[i]);
			i++;
		}
		else {
			c.push_back(b[j]);
			j++;
		}
	}
	while (i < a1) {
		c.push_back(a[i]);
		i++;
	}

	while (j < b1) {
		c.push_back(b[j]);
		j++;
	}
}

void afisare(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
}

int main() {
	int m, n; std::cin >> n >> m;
	std::vector<int> a, b, c;
	citire(a, n);
	citire(b, m);
	interclasare(a, b, c);
	afisare(c);
}
*/