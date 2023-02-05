#include <stdio.h>
#include <malloc.h>

typedef struct Node Node;

struct Node
{
	char data;
	Node* next;
} *top = NULL;

void push(char c)
{
	Node* t;
	t = (Node*)malloc(sizeof(Node));
	if (t == NULL)
	{
		printf("Stiva este plina.\n");
	}
	else
	{
		t->data = c;
		t->next = top;
		top = t;
		printf("Am introdus elementul %c.\n", c);
	}
}

char pop()
{
	Node* t;
	char c = -1;
	if (top == NULL)
	{
		printf("Stiva este goala.\n");
	}
	else
	{
		t = top;
		top = top->next;
		c = t->data;
		printf("Am scos elementul %c.\n", c);
		free(t);
	}
	return c;
}

void display()
{
	Node* p;
	p = top;
	printf("| ");
	while (p != NULL)
	{
		printf(" %c ", p->data);
		p = p->next;
	}
	printf(" |");
	printf("\n");
}

void alegeOptiuni(int* op)
{
	char c;
	switch (*op)
	{
	case 1:
	{
		printf("Introduceti un caracter:\n");
		scanf("%c", &c);
		getchar();
		push(c);
	}
	break;
	case 2:
	{
		pop();
	}
	break;
	case 3:
	{
		display();
	}
	break;
	case 0:
	{
		break;
	}
	default:
	{
		printf("Introduceti 1, 2, 3, sau 0.\n");
	}
	}
}

int main()
{
	char c;
	int op = -1;
	do {
		printf("Introduceti optiunea dvs:\n");
		printf("1 pt adaugare in stiva:\n");
		printf("2 pt scoatere din stiva:\n");
		printf("3 pt afisarea stivei:\n");
		printf("0 pt iesire din program:\n");
		scanf("%d", &op);
		getchar();
		alegeOptiuni(&op);
	} while (op != 0);

	return 0;
}