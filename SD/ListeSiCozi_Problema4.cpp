// Problema 4
// Parantezare corecta
// Se da un sir de paranteze deschise si inchise de tip
// ( ) [ ] { }
// Sa se verifice da sirul este corect.
// Folositi o stiva std::stack pentru rezolvare
// Exemplu: 
// sirul [()()] este corect
// sirul ([]) nu este corect
// sirul ()] nu este corect

#include <iostream>
#include <stack>
#define ASSERT(x,y) (x == y) ? std::cout << "Test Passed!" << std::endl : std::cout << "Test Failed!"<< std::endl;

void tests();
bool hasValidParenthesis(std::string s);

int main()
{
	tests();
}

bool hasValidParenthesis(std::string s)
{
	if (s.length() == 0 || s.length() % 2 == 1)
	{
		return false;
	}

	std::stack<char> p;

	for (int i = 0; i < s.length(); i++)
	{
		if (p.empty())
		{
			p.push(s[i]);
		}
		else if ((p.top() == '(' && (s[i] == '[' || s[i] == '{')) || (p.top() == '[' && s[i] == '{') || (p.top() == '{' && s[i] == '('))
		{
			return false;
		}
		else if ((p.top() == '(' && s[i] == ')') || (p.top() == '[' && s[i] == ']') || (p.top() == '{' && s[i] == '}'))
		{
			p.pop();
		}
		else
		{
			p.push(s[i]);
		}
	}

	return p.empty();
}

void tests()
{
	std::string s0 = "{{[[()()]]}}{}";
	ASSERT(hasValidParenthesis(s0), true);

	std::string s1 = "([{}])";
	ASSERT(hasValidParenthesis(s1), false);

	std::string s2 = "()]";
	ASSERT(hasValidParenthesis(s2), false);

	std::string s3 = "[()]{}{[()()][()]}";
	ASSERT(hasValidParenthesis(s3), true);

	std::string s4 = "[()]{}{[({})([])]()}";
	ASSERT(hasValidParenthesis(s4), false);
}