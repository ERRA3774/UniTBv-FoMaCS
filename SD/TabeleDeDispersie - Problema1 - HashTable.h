#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <list>
typedef std::pair<int, int> tIntIntPair;
constexpr int DEFAULT_HASH_TABLE_SIZE = 10;
constexpr float DEFAULT_LOAD_FACTOR = 1.0f;

class HashTable
{
private:
	int hashTableSize;
	std::list<tIntIntPair> *table;
	int hashFunction(int key);
	float loadFactor();
	void rehash();

public:
	HashTable();
	HashTable(std::string path);
	bool empty();
	void insert(int key, int value);
	void remove(int key);
	void print();
	int find(int key);
	int size();
};
