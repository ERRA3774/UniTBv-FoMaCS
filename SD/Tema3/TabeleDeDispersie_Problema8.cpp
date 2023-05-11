// Problema 8 (1.5p)
// Magazine
// Se considera nr_mag magazine
// Fiecare are un numar de produse.
// Sa se verificare care magazin are cele mai multe produse exclusive (nu apar decat in magazinul respectiv).
// Cititi dintr-un fisier in cate un vector de std::string produse pentru fiecare magazin.
// Afisati in final magazinul cu cele mai multe produse exclusive si care sunt aceste produse.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define INFO(x) std::cout << "[I] " << x << std::endl;
#define ERR(x)  std::cout << "[E] " << x << std::endl;

void mapShopItemsFromFile(std::string path, std::unordered_map<std::string, std::vector<std::string>>& shopToItems, std::unordered_map<std::string, std::unordered_set<std::string>>& itemToShops)
{
	std::ifstream fin(path);

	if (!fin.is_open())
	{
		ERR("Could not open file from path. Exiting.");
		exit(1);
	}

	while (!fin.eof())
	{
		bool isDone = false;
		std::string shop;
		std::string item;
		std::getline(fin, shop);
		while (!isDone && std::getline(fin, item))
		{
			if (item != "")
			{
				shopToItems[shop].emplace_back(item);
				itemToShops[item].insert(shop);
			}
			else
			{
				isDone = true;
			}
		}
	}

	return;
}

void printShopMaxExclusiveItems(std::unordered_map<std::string, std::vector<std::string>> shopToItems, std::unordered_map<std::string, std::unordered_set<std::string>> itemToShops)
{
	int max = 0;
	std::string shopMax;
	std::unordered_map<std::string, int> exclusiveItems;

	for (auto& kv : itemToShops)
	{
		if (kv.second.size() == 1)
		{
			std::string shop = *kv.second.begin();
			exclusiveItems[shop]++;
		}
	}

	for (auto& kv : exclusiveItems)
	{
		if (kv.second > max)
		{
			max = kv.second;
			shopMax = kv.first;
		}
	}

	INFO("Shop with most exclusive items: " + shopMax);
	INFO("List of exclusive items: ");
	for (auto& kv : shopToItems[shopMax])
	{
		if (itemToShops[kv].size() == 1)
		{
			INFO(kv);
		}
	}

	return;
}

int main()
{
	std::unordered_map<std::string, std::vector<std::string>> shopToItems;
	std::unordered_map<std::string, std::unordered_set<std::string>> itemToShops;
	mapShopItemsFromFile("Text.txt", shopToItems, itemToShops);
	printShopMaxExclusiveItems(shopToItems, itemToShops);
	return 0;
}
