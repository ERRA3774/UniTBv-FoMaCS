#include <stdio.h>
#define max(a,b) (a > b ? a : b) // Macro
#define sum(a,b) a + b // Macro
#define alip(a,b) (a##b) // Macro

float medie(int a, int b);
int maxim(int a, int b);

int main()
{
	int firstNumber, secondNumber, max, s;
	float average;

	printf("Pleease input your first number: ");
	scanf("%d", &firstNumber);

	printf("Pleease input your first number: ");
	scanf("%d", &secondNumber);

	average = medie(firstNumber, secondNumber);

	printf("Media aritmetica %d si %d este %f.", firstNumber, secondNumber, average);

	max = maxim(firstNumber, secondNumber) + 1; // 3 > 2 ? 3 : 2 + 1

	s = sum(firstNumber, secondNumber);

	printf("Suma dintre %d si %d si 10 este %d", firstNumber, secondNumber, s);

	return 0;
}

float medie(int a, int b)
{
	float m;

	m = (a + b) / 2.0;

	return m;
}

int maxim(int a, int b)
{
	return a > b ? a : b;
}