#pragma once
#include "HeapSiArbori_Problema1_Expression.h"
#include <map>
#include <sstream>

using std::cin;
using std::map;
using std::stringstream;

class SyntaxTree
{
public:
	struct Node
	{
		char info;
		Node* left;
		Node* right;

		Node(char ch, Node* l, Node* r) : info(ch), left(l), right(r) {}
	};

	SyntaxTree();
	SyntaxTree(Expression expr);

	void Evaluate();
	void Display();

private:
	double EvaluateNode(Node* curr);
	void CalculateHeight(Node* curr, int level);
	void PrintNode(Node* curr, string format, bool isLast);

private:
	Node* m_Root;
	int m_Size;
	int m_Height;
	map<char, double> variables;
};

