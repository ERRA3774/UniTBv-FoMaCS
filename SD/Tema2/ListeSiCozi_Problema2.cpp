// Problema 2
// Inversare elemente vector.
// Sa se inverseze elementele unui vector utilizand o stiva
// Primul element se va interschimba cu ultimul, al doilea cu penultimul, etc (1p)

#include <iostream>
#include <stack>
#include <vector>

void reverse(std::vector<int>& vec)
{
	std::stack<int> stk;

	for (int i = 0; i < vec.size(); i++)
	{
		stk.push(vec[i]);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = stk.top();
		stk.pop();
	}
}

void print(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	reverse(vec);

	print(vec);
}