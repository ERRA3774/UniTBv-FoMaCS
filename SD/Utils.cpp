#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

using std::ifstream;
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::pair;
using std::make_pair;

struct Node
{
	char data;
	Node* left;
	Node* right;

	Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

void PreorderTraversal(Node* node)
{
	if (node == nullptr) return;

	cout << node->data << " ";
	PreorderTraversal(node->left);
	PreorderTraversal(node->right);
}

void InorderTraversal(Node* node)
{
	if (node == nullptr) return;

	InorderTraversal(node->left);
	cout << node->data << " ";
	InorderTraversal(node->right);
}

void PostorderTraversal(Node* node)
{
	if (node == nullptr) return;

	PostorderTraversal(node->left);
	PostorderTraversal(node->right);
	cout << node->data << " ";
}

void LevelTraversal(Node* node)
{
	if (node == nullptr) return;

	queue<Node*> queue;
	queue.push(node);

	while (!queue.empty())
	{
		Node* curr = queue.front();	
		queue.pop();

		cout << curr->data << " ";
		if (curr->left != nullptr) queue.push(curr->left);		
		if (curr->right != nullptr) queue.push(curr->right);
	}
}

int Depth(Node* node, char ch)
{
	if (node == nullptr) return -1;

	queue<pair<Node*, int>> queue;
	queue.push(make_pair(node, 0));

	while (!queue.empty()) {
		pair<Node*, int> curr = queue.front();
		queue.pop();

		if (curr.first->data == ch) {
			return curr.second;
		}

		if (curr.first->left != nullptr) queue.push(make_pair(curr.first->left, curr.second + 1));


		if (curr.first->right != nullptr) queue.push(make_pair(curr.first->right, curr.second + 1));
	}

	return -1;
}


void DepthFirst(Node* node)
{
	if (node == nullptr) return;

	stack<Node*> stack;
	stack.push(node);

	while (!stack.empty())
	{
		Node* curr = stack.top();
		stack.pop();

		cout << curr->data << " ";
		if (curr->right != nullptr) stack.push(curr->right);

		if (curr->left != nullptr) stack.push(curr->left);
	}
}

void BreadthFirst(Node* node)
{
	if (node == nullptr) return;

	queue<Node*> queue;
	queue.push(node);

	while (!queue.empty())
	{
		Node* curr = queue.front();
		queue.pop();

		cout << curr->data << " ";
		if (curr->left != nullptr) queue.push(curr->left);

		if (curr->right != nullptr) queue.push(curr->right);
	}
}

void RecursiveDepthFirst(Node* node)
{
	if (node == nullptr) return;

	cout << node->data << " ";
	RecursiveDepthFirst(node->left);
	RecursiveDepthFirst(node->right);
}

bool Find(Node* node)
{
	if (node == nullptr) return false;

	queue<Node*> queue;
	queue.push(node);

	while (!queue.empty())
	{
		Node* curr = queue.front();
		queue.pop();

		if (curr == node) return true;

		if (curr->left != nullptr) queue.push(curr->left);

		if (curr->right != nullptr) queue.push(curr->right);
	}

	return false;
}

bool Find(Node* node, char target)
{
	if (node == nullptr) return false;

	queue<Node*> queue;
	queue.push(node);

	while (!queue.empty())
	{
		Node* curr = queue.front();
		queue.pop();

		if (curr->data == target) return true;

		if (curr->left != nullptr) queue.push(curr->left);

		if (curr->right != nullptr) queue.push(curr->right);
	}

	return false;
}

bool RecursiveFind(Node* node)
{
	if (node == nullptr) return false;

	if (node) return true;

	return RecursiveFind(node->left) || RecursiveFind(node->right);
}

bool RecursiveFind(Node* node, char target)
{
	if (node == nullptr) return false;

	if (node->data == target) return true;

	return RecursiveFind(node->left, target) || RecursiveFind(node->right, target);
}

double TreeSum(Node* node)
{
	if (node == nullptr) return 0;

	double sum = 0;
	queue<Node*> queue;
	queue.push(node);

	while (!queue.empty())
	{
		Node* curr = queue.front();
		queue.pop();
		sum += curr->data;

		if (curr->left != nullptr) queue.push(curr->left);

		if (curr->right != nullptr) queue.push(curr->right);
	}
}

double RecursiveTreeSum(Node* node)
{
	if (node == nullptr) return 0;
	return node->data + RecursiveTreeSum(node->left) + RecursiveTreeSum(node->right);
}

int RecursiveMin(Node* node)
{
	if (node == nullptr) return INFINITY;

	return std::min(RecursiveMin(node->left), RecursiveMin(node->right));
}

int RecursivePathSum(Node* node)
{
	if (node == nullptr) return -INFINITY;

	if (node->left == nullptr && node->right == nullptr) return node->data;

	int maxVal = std::max(RecursivePathSum(node->left), RecursivePathSum(node->right));

	return node->data + maxVal;
}

double MinBredthFirst(Node* node)
{
	if (node == nullptr) return -INFINITY;

	double min = node->data;
	queue<Node*> queue;
	queue.push(node);
	while (!queue.empty())
	{
		Node* curr = queue.front();
		queue.pop();

		if (curr->data < min) min = curr->data;

		if (curr->left != nullptr) queue.push(curr->left);

		if (curr->right != nullptr) queue.push(curr->right);
	}
}

double MinDepthFirst(Node* node)
{
	if (node == nullptr) return -1;

	double min = node->data;
	stack<Node*> stack;
	stack.push(node);
	while (!stack.empty())
	{
		Node* curr = stack.top();
		stack.pop();

		if (curr->data < min) min = curr->data;

		if (curr->left != nullptr) stack.push(curr->left);

		if (curr->right != nullptr) stack.push(curr->right);
	}
}
