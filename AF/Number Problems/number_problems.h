#include <iostream>
#include <vector>

// Se citeste un numar natural n.
// Afisati toate perechile de numere de la 1 la n care au proprietatea ca au aceeasi suma a cifrelor
void PrintDigitsSumPair(int n);

// Se citeste un numar natural n si apoi n numere naturale
// Afisati cate dintre numerele citite au rasturnatul egal cu primul numar citit
// Exemplu: n = 7
// 213 78 132 30 132 8 132 -> se va afisa 3
void PrintCountOfNumsEqualToFirstReversed(int n, std::vector<int> vec);

// Se citesc 2 numere naturale a si b
// Calculati cate numere palindrom sunt din intervalul [a,b]
// Palindrom: 12321, 111
// Exemplu: a = 100, b = 200
// Se va afisa 101, 111, 121, 131, 141, 151, 161, 171, 181, 191
void PrintPalindromesBetween(int a, int b);

// Se citeste un numar natural n si un sir  de n perechi de numere
// Determinati si afisati perechea pentru care valoarea cmmdc-ului dintre cele 2 valori este maxima
// Exemplu: n = 3
// 12 10
// 45 35
// 23 74
// Se va afisa perechea 45 35
void PrintMaxGcdPair(int n, std::vector<std::pair<int, int>> vec{});

// Se citeste un numar natural k din intervalul [1,9]
// Afisati toate numerele n formate din exact k cifre care au proprietatea ca n-1 si n+1 sunt prime.
// Exemplu: k = 2
// Se vor afisa: 12, 18, 30, 42, 60, 72
void PrintTwinPrimesBetween(int k);

// Sa se afiseze cel mai mic numar care se poate forma cu cifrele lui n
// Fiecare cifra repetandu-se de cate ori se repeta si in n.
// Exemplu:    1204192
// Se va afisa: 112249
void PrintMinified(int num);

// Sa se verifice daca cifrele lui n sunt in progresie aritmetica
// Exemplu n = 2596
// Se va afisa: Cifrele lui 2596 nu sunt in progresie aritmetica
// Exemplu n = 2468
// Se va afisa: Cifrele lui 2468 sunt in progresie aritmetica
bool DigitsInArithmeticProgression(int num);

// Se citesc un numar natural n de maxim 3 cifre si o cifra c
// Eliminati toate aparitiile cifrei c din numarul n si afisati numarul obtinut
// Exemplu: n = 2345324 
//          c =       2
// Rezulta        34534
void EraseOcurrances(int num, int digit);

// Se citeste un numar natural n cu numar par de cifre
// Calculati si afisati numarul obtinut din n 
// inversand cifra unitatilor cu a zecilor
// cea a sutelor cu cea a miilor, etc
// Exemplu: n = 123456
// Rezulta: n = 214365
void SwapDigitsPositions(int num);

// Se citeste un numar natural n > 1000
// Afisati cel mai mare numar care se poate obtine din n prin eliminarea unei singure cifre
// Exeplu: n = 45329
// Rezulta: n = 5329 (e cel mai mare dintre numerele 4532, 4539, 4529, 4329, 5329)
void PrintMaxNumberAfterErasingDigit(int num);

int DigitsSum(int num);

int Reversed(int num);

bool IsPalindrome(int num);

int Gcd(int a, int b);

int Gcd(int a, int b, bool recursive);

bool IsPrime(int num);