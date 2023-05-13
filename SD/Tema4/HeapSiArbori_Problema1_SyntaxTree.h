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
		char data;
		Node* left;
		Node* right;

		Node(char d) : data(d), left(nullptr), right(nullptr) {}
		Node(char d, Node* l, Node* r) : data(d), left(l), right(r) {}
	};

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

