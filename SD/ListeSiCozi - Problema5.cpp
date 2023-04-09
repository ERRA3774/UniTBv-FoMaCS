// Problema 5
// Simularea unei stive prin doua cozi
// Parantezare corecta
// Se da un sir de paranteze deschise si inchise de tip
// ( ) [ ] { }
// Sa se verifice da sirul este corect.
// Folositi o stiva std::stack pentru rezolvare
// Exemplu: 
// sirul [()()] este corect
// sirul ([]) nu este corect
// sirul ()] nu este corect
// Rezolvati problema parantezarii simuland functionalitatea stivei cu ajutorul a doua cozi
// Puteti folosi queue din STL
// Cerinta: definirea unei structuri stiva care in interior sa dispuna drept containere de 
// doua elemente de tip queue 
// si de functii de tip push si pop
// care apeleaaza insa doar operatiiile corespunzatoare ale cozilor din structura
// Elementele care se intorc in stiva vor fi stocate in cozile de care dispune stiva
// Explicitati intr-un comentariu complexitatea operatiilor de adaugare si extragere din stiva dvs. (1p)

#include <iostream>
#include <queue>
#define ASSERT(x,y) (x == y) ? std::cout << "Test Passed!" << std::endl : std::cout << "Test Failed!"<< std::endl;

void tests();

struct Stack
{
	std::queue<char> q1;
	std::queue<char> q2;

	void push(char c)
	{
		q2.push(c);

		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}

		std::queue<char> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		if (q1.empty())
		{
			return;
		}
		q1.pop();
	}

	char top()
	{
		if (q1.empty())
		{
			return -1;
		}
		return q1.front();
	}

	bool empty()
	{
		return q1.empty();
	}

	int size()
	{
		return q1.size();
	}
};

bool hasValidParenthesis(std::string s)
{
	if (s.length() == 0 || s.length() % 2 == 1)
	{
		return false;
	}

	Stack p;

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

int main()
{
	tests();
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
