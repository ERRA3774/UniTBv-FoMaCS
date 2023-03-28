// Problema 3
// Se considera un vector cu *nr* elemente numere naturale din intervalul [30, 80]
// Sa se determine si sa se afiseze elementul care apare de cele mai multe ori. (1p)

#include <iostream>
#include <vector>
#include <algorithm>
#define ASSERT(x,y) (x == y) ? std::cout << "Test Passed!" << std::endl : std::cout << "Test Failed!" << std::endl;

constexpr int INF = 30;
constexpr int SUP = 80;

int elementMaxAparitii(std::vector<int>& vec);
void tests();

int main()
{
	tests();

	std::vector<int> vec{ 1,2,3,4,30,31,32,33,33,33,33,35,36,37,80,81,82,83 };
	ASSERT(elementMaxAparitii(vec), 33);
}

int elementMaxAparitii(std::vector<int>& vec)
{
	if (vec.size() == 0)
	{
		std::cout << "Vectorul nu are elemente." << std::endl;
		return -1;
	}

	if (vec.size() == 1)
	{
		if (vec[0] >= INF && vec[0] <= SUP)
		{
			return vec[0];
		}
		else
		{
			std::cout << "Vectorul nu are elemente cuprinse intre [" << INF << "," << SUP << "]." << std::endl;
			return -1;
		}
	}

	std::sort(vec.begin(), vec.end());

	int indexInf = 0;
	int indexSup = vec.size() - 1;

	while (vec[indexInf] < INF)
	{
		indexInf++;
		if (indexInf == vec.size() - 1 || vec[indexInf] > SUP)
		{
			std::cout << "Vectorul nu are elemente cuprinse intre [" << INF << "," << SUP << "]." << std::endl;
			return -1;
		}
	}

	while (vec[indexSup] > SUP)
	{
		indexSup--;
		if (indexSup == 0 || vec[indexSup] < INF)
		{
			std::cout << "Vectorul nu are elemente cuprinse intre [" << INF << "," << SUP << "]." << std::endl;
			return -1;
		}
	}

	if (indexInf == indexSup)
	{
		return vec[indexInf];
	}

	int indexMax = indexInf;
	int kMax = 0;
	int kTemp = 1;

	for (int i = indexInf; i < indexSup - 1; i++)
	{
		if (vec[i] == vec[i + 1])
		{
			kTemp++;
			if (kTemp > kMax)
			{
				kMax = kTemp;
				indexMax = i;
			}
		}
		else
		{
			kTemp = 1;
		}
	}
	

	return vec[indexMax];
}

void tests()
{
	std::vector<int> underTest1{}; // Nu are elemente
	ASSERT(elementMaxAparitii(underTest1), -1);
	std::vector<int> underTest2{ 30 }; // Are un element din interval
	ASSERT(elementMaxAparitii(underTest2), 30);
	std::vector<int> underTest3{ 1 }; // Are un element din afara intervalului
	ASSERT(elementMaxAparitii(underTest3), -1);
	std::vector<int> underTest4{ 1,2,3,81,82,83 }; // Are doare elemente din afara intervalului
	ASSERT(elementMaxAparitii(underTest4), -1);
	std::vector<int> underTest5{ 3,2,1,30,33,34,35,35,35,36,36,36,83,82,81 }; // Are elemente si din interval si din afara intervalului
	ASSERT(elementMaxAparitii(underTest5), 35);
}
