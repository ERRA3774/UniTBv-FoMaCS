#include <stdio.h>
#include <float.h>
#include <malloc.h>
#include <stdarg.h> 
#include <string.h>

// MACROS

#define max(a,b) (a > b ? a : b)  
#define sum(a,b) (a + b)
#define avg(a,b) ((a + b) / 2.0f))
#define concat(a,b) (a##b)

// STRUCTS
typedef struct Person Person;

struct Person {
	char name[128];
	char adress[128];
	int age;
};

// DEMOS

void intArrayDemo();
void intArrayDemo2();
void macrosDemo();
void mallocDemo();
void readFromFileDemo();
void structDemo();
void switchDemo();
void variableArgumentsDemo();
void stackDemo();
void charOccuranceDemo();

int maxValBetween(int a, int b);
int maxValInArray(int* arr, int size);
int negativeNumsCountInMatrix(float** a, int m, int n);
int charOccuranceCount(char* string, char ch);

float averageBetween(int a, int b);

double maxValBetweenAll(int numOfArgs, ...);

// IMPLEMENTATIONS

// Stack
typedef struct Stack Stack;

struct Stack {
	char data;
	Stack* next;
} *top;

bool push(char ch);
bool pop();
void print();
