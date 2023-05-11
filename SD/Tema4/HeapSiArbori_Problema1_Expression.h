#pragma once
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::ifstream;

class Expression
{
public:
	Expression(string path);

	string GetExpression();

private:
	string m_Expression;
};

bool IsDigit(char ch);
bool IsOperator(char ch);
bool IsVariable(char ch);
int Precedence(char op);