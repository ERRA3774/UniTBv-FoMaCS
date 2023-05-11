// Problema 6
// Se considera un vector de n puncte. 
// Fiecare punct este un element de tipul unei structuri cu doua campuri, reprezentand coordonate spatiale (x, y).
// Sa se afiseze perechile de 4 puncte care pot forma un dreptunghi.
// Daca nu exista astfel de pereche se va afisa un mesaj corespunzator. (2p)

#include <iostream>
#include <vector>
#define LOG(x, y) std::cout <<"[D] " << x << " " << y << std::endl;

void problema6();
float distantaPuncte(Punct A, Punct B);
bool esteDreptunghi(Punct A, Punct B, Punct C, Punct D);

struct Punct
{
	int x;
	int y;
};

int main()
{
	problema6();
}

void problema6()
{
	std::vector<Punct> puncte{ {-6,3}, {1,0}, {0,6}, {5,5}, {1,1}, {2,2}, {-4,-1}, {0,0}, {0,1}, {3,3} };
	bool existaDreptunghi = false;

	if (puncte.size() < 4)
	{
		std::cout << "Vectorul nu are suficiente puncte." << std::endl;
		return;
	}

	for (int i = 0; i < puncte.size() - 3; i++)
	{
		for (int j = i + 1; j < puncte.size() - 2; j++)
		{
			for (int k = j + 1; k < puncte.size() - 1; k++)
			{
				for (int l = k + 1; l < puncte.size(); l++)
				{
					if (esteDreptunghi(puncte[i], puncte[j], puncte[k], puncte[l]))
					{
						std::cout
							<< "(" << puncte[i].x << "," << puncte[i].y << "), "
							<< "(" << puncte[j].x << "," << puncte[j].y << "), "
							<< "(" << puncte[k].x << "," << puncte[k].y << "), "
							<< "(" << puncte[l].x << "," << puncte[l].y << ")" << std::endl;
						existaDreptunghi = true;
					}
				}
			}
		}
	}

	if (!existaDreptunghi)
	{
		std::cout << "Nu exista perechi de puncte care pot forma un dreptunghi." << std::endl;
	}

}

// sqrt((x1 - x2) * (x1-x2) + (y1 - y2) * (y1 - y2))
float distantaPuncte(Punct A, Punct B)
{
	float dist;

	dist = ((A.x - B.x) * (A.x - B.x)) + ((A.y - B.y) * (A.y - B.y));

	return sqrt(dist);
}

// AB == CD && AD == DB && AC == BD
bool esteDreptunghi(Punct A, Punct B, Punct C, Punct D)
{
	return
		distantaPuncte(A, B) == distantaPuncte(C, D) &&
		distantaPuncte(A, D) == distantaPuncte(B, C) &&
		distantaPuncte(A, C) == distantaPuncte(B, D);
}
