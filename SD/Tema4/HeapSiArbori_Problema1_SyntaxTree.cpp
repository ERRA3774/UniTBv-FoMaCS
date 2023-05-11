#include "HeapSiArbori_Problema1_SyntaxTree.h"

SyntaxTree::SyntaxTree() : m_Root(nullptr), m_Size(0), m_Height(0)
{
}

SyntaxTree::SyntaxTree(Expression expr) : m_Root(nullptr), m_Size(0), m_Height(0)
{
	stack<Node*> nodes;
	string postfix = expr.GetExpression();

	for (char ch : postfix)
	{
		if (IsDigit(ch) || IsVariable(ch))
		{
			if (IsVariable(ch)) variables[ch] = 0.0;

			Node* var = new Node(ch, nullptr, nullptr);
			nodes.push(var);
			m_Size++;
		}
		else
		{
			Node* right = nodes.top();
			nodes.pop();
			Node* left = nodes.top();
			nodes.pop();

			Node* parent = new Node(ch, left, right);
			nodes.push(parent);
		}
	}

	m_Root = nodes.top();
	CalculateHeight(m_Root, 1);
}

void SyntaxTree::Evaluate()
{
	if (!variables.empty())
	{
		for (auto& var : variables)
		{
			string input;
			double x;
			cout << var.first << " = ";
			getline(cin, input);
			stringstream(input) >> x;
			var.second = x;
		}
	}

	cout << "The result is: " << EvaluateNode(m_Root) << endl;
}

double SyntaxTree::EvaluateNode(Node* curr)
{
	if (curr == nullptr) return 0.0;

	if (variables.find(curr->info) != variables.end())
	{
		return variables[curr->info];
	}

	if (curr->left == nullptr && curr->right == nullptr)
	{
		return curr->info - '0';
	}

	double l = EvaluateNode(curr->left);
	double r = EvaluateNode(curr->right);

	switch (curr->info)
	{
	case '+':
		return l + r;

	case '-':
		return l - r;

	case '*':
		return l * r;

	case '/':
		return l / r;

	case '^':
		return pow(l, r);

	default:
		return 0;
	}
}

void SyntaxTree::Display()
{
	PrintNode(m_Root, "", false);
}

// PRIVATE FUNCTIONS

void SyntaxTree::CalculateHeight(Node* curr, int level)
{
	if (curr == nullptr) return;

	if (level > m_Height)
	{
		m_Height = level;
	}

	CalculateHeight(curr->right, level + 1);
	CalculateHeight(curr->left, level + 1);
}

void SyntaxTree::PrintNode(Node* curr, string format, bool isLast)
{
	if (curr == nullptr) return;

	cout << format;

	if (curr == m_Root)
	{
		cout << "Root: ";
		format += "      ";
	}
	else if (isLast)
	{
		cout << " +---";
		format += "     ";
	}
	else
	{
		cout << " +---";
		format += " |    ";
	}

	cout << '(' << curr->info << ')' << endl;

	PrintNode(curr->right, format, curr->left == nullptr);
	PrintNode(curr->left, format, true);
}
