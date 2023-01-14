#include <stdio.h>
#include <malloc.h>

struct tpers
{
	char nume[50];
	char adresa[100];
	int varsta;
};

typedef struct tpers tpers;

int main()
{
	//tpers pers;
	tpers* p;

	p = (tpers*)malloc(sizeof(tpers));

	if (p == NULL)
	{
		printf("Memorie insuficienta.");
		return 1;
	}

	printf("Nume: ");
	//gets(pers.nume);
	scanf("%s", &p->nume); // Fara spatii

	printf("Adresa: ");
	//gets(pers.adresa);
	scanf("%s", &p->adresa); // Fara spatii

	printf("Varsta: ");
	//scanf("%d", &pers.varsta);
	scanf("%d", &p->varsta); // Fara spatii

	puts("Am citit: ");
	//printf("Nume: %s\nAdresa: %s\nVarsta:%d\n", pers.nume, pers.adresa, pers.varsta);
	printf("Nume: %s\nAdresa: %s\nVarsta:%d\n", p->nume, p->adresa, p->varsta);

	free(p);

	return 0;
}