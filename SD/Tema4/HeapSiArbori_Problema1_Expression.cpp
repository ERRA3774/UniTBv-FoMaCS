#include "HeapSiArbori_Problema1_Expression.h"

Expression::Expression(string path) : m_Expression("")
{
	ifstream fin(path);

	if (!fin.is_open())
	{
		cout << "[INFO] Could not open file from " << path << "." << endl;
		return;
	}

	string infix;
	getline(fin, infix);

	string postfix;
	stack<char> operators;

	if (infix.length() < 3)
	{
		cout << "[INFO] Input expression is not valid." << endl;
		return;
	}

	for (char ch : infix)
	{
		if (ch == ' ') continue;

		if (IsDigit(ch) || IsVariable(ch))
		{
			postfix += ch;
		}
		else if (ch == '(')
		{
			operators.push(ch);
		}
		else if (ch == ')')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else
		{
			while (!operators.empty() && operators.top() != '(' && Precedence(ch) <= Precedence(operators.top()))
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.push(ch);
		}
	}

	while (!operators.empty())
	{
		postfix += operators.top();
		operators.pop();
	}

	m_Expression = postfix;
}

string Expression::GetExpression()
{
	return m_Expression;
}

bool IsDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool IsOperator(char ch)
{
	return
		ch == '^' ||
		ch == '*' ||
		ch == '/' ||
		ch == '+' ||
		ch == '-';
}

bool IsVariable(char ch)
{
	ch = tolower(ch);

	return ch >= 'a' && ch <= 'z';
}

int Precedence(char op)
{
	switch (op)
	{
	case '^':
		return 3;

	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;

	default:
		return 0;
	}
}