/*Ambele in mod eficient*/
/*Se da un vector sortat crescator pana la un punct apoi descrescator. Sa se determine eficient elementul maxim  din vector.*/

#include<iostream>
#include<vector>

int cautare_binara_it(std::vector<int> vect)
{
	int st = 0, dr = vect.size() - 1;
	int mijl = (st + dr) / 2;
	int max = vect[mijl];
	if (vect.size() == 1 || (vect.size() >= 2 && vect[1] < vect[0]))
		return vect[0];
	if (vect.size() >= 2 && vect[vect.size() - 1] > vect[vect.size() - 2])
		return vect[vect.size() - 1];
	while (dr - st >= 1)
	{
		if (vect[mijl + 1] > vect[mijl])
		{
			max = vect[mijl + 1];
			st = mijl + 1;
		}
		else
			if (vect[mijl - 1] > vect[mijl])
			{
				max = vect[mijl - 1];
				dr = mijl - 1;
			}
			else
			{
				max = vect[mijl];
				break;
			}
		mijl = (st + dr) / 2;
	}
	return max;
}

/*Se da un vector ce contine valori de 0 si 1 si cu mentiunea ca toate valorile de 0 sunt inaintea celor de 1 in vector. Sa se detrmine eficient nr de valori de 1 si de 0 din vector.*/


int maxim2(std::vector<int> vect)
{
	int st = 0, dr = vect.size() - 1;
	int mijl = (st + dr) / 2;
	if (vect[st] == 1) return st;
	if (vect[dr] == 0) return -1;
	while (st <= dr)
	{
		mijl = (st + dr) / 2;
		if (vect[mijl] == 1 && vect[mijl - 1] == 0)
			return mijl;
		if (vect[mijl] == 0)
			st = mijl + 1;
		else
			if (vect[mijl] == 1 && vect[mijl - 1] != 0)
				dr = mijl - 1;
	}
}

int main()
{
	std::vector<int> vect = {17,16,13,9};
	std::cout << cautare_binara_it(vect);
	/*if (maxim2(vect) != -1)
		std::cout << maxim2(vect) << " valori de 0 si " << vect.size() - maxim2(vect) << " valori de 1";
	else
		std::cout << vect.size() << " valori de 0 si nicio valoare de 1";*/
}