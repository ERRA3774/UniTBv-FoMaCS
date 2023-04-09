#include "HashTable.h"

HashTable::HashTable()
{
	hashTableSize = DEFAULT_HASH_TABLE_SIZE;
	table = new std::list<tIntIntPair>[hashTableSize];
}

HashTable::HashTable(std::string path)
{
	std::ifstream fin(path);

	if (!fin.is_open())
	{
		std::cout << "[I] Could not open file." << std::endl;
		exit(1);
	}

	int n;
	fin >> n;
	hashTableSize = n;
	table = new std::list<tIntIntPair>[hashTableSize];

	for (int i = 0; i < n; i++)
	{
		int key;
		int value;
		fin >> key >> value;
		insert(key, value);
	}

	fin.close();
}

float HashTable::loadFactor()
{
	return (float)size() / hashTableSize;
}

int HashTable::hashFunction(int key)
{
	return key % hashTableSize;
}

void HashTable::rehash()
{
	int newHashTableSize = hashTableSize * 2;
	std::list<tIntIntPair>* temp = new std::list<tIntIntPair>[newHashTableSize];

	for (int i = 0; i < hashTableSize; i++)
	{
		for (auto it = table[i].begin(); it != table[i].end(); it++)
		{
			int hashValue = hashFunction(it->first);
			auto& cell = temp[hashValue];
			cell.emplace_back(it->first, it->second);
		}
	}

	hashTableSize = newHashTableSize;
	table = temp;
	delete[] temp;

	return;
}

bool HashTable::empty()
{
	int sum = 0;

	for (int i = 0; i < hashTableSize; i++)
	{
		sum += table[i].size();
	}

	if (sum == 0)
	{
		return true;
	}
	return false;
}

void HashTable::insert(int key, int value)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	bool keyExists = false;

	if (loadFactor() >= DEFAULT_LOAD_FACTOR)
	{
		std::cout << "[I] Load Factor exceeds " << DEFAULT_LOAD_FACTOR << ". Rehashing" << std::endl;
		rehash();
	}

	for (auto it = begin(cell); it != end(cell); it++)
	{
		if (it->first == key)
		{
			keyExists = true;
			std::cout << "[I] Replaced " << it->second << " with " << value << std::endl;
			it->second = value;
			break;
		}
	}

	if (!keyExists)
	{
		std::cout << "[I] Inserted Key: " << key << " Value: " << value << std::endl;
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::remove(int key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	bool keyExists = false;

	for (auto it = begin(cell); it != end(cell); it++)
	{
		if (it->first == key)
		{
			keyExists = true;
			std::cout << "[I] Removed " << key << std::endl;
			it = cell.erase(it);
			break;
		}
	}

	if (!keyExists)
	{
		std::cout << "[I] " << key << " not found." << std::endl;
	}

	return;
}

void HashTable::print()
{
	for (int i = 0; i < hashTableSize; i++)
	{
		if (table[i].size() == 0) continue;

		auto it = table[i].begin();
		for (; it != table[i].end(); it++)
		{
			std::cout << "[I] Key: " << it->first << " Value: " << it->second << std::endl;
		}
	}
	return;
}


int HashTable::find(int key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	bool keyExists = false;

	for (auto it = begin(cell); it != end(cell); it++)
	{
		if (it->first == key)
		{
			keyExists = true;
			std::cout << "[I] Found " << key << std::endl;
			return it->second;
		}
	}

	if (!keyExists)
	{
		std::cout << "[I] " << key << " not found." << std::endl;
	}

	return -1;
}

int HashTable::size()
{
	int size = 0;

	for (int i = 0; i < hashTableSize; i++)
	{
		size += table[i].size();
	}

	return size;
}

