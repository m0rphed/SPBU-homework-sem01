#pragma once

#include "LinkedList.h"
#include <string>

// Define type of key
typedef std::string KeyType;

using namespace HashTableComponents;

// Hash table implementation
class HashTable
{
	int size = 0;
	List **buckets = nullptr;

public:
	// Default constructor
	HashTable() = default;

	// Deletes a hash table, causes destruction of every element
	~HashTable();

	// Hash function
	unsigned int hashFunction(const KeyType &input);

	// Creates a new hash table
	explicit HashTable(int size);

	// Returns amount of a keys in the hash table
	int getAmountOfKey(const KeyType &key);

	// Returns the maximum amount of elements in a bucket
	int getMaxAmount();

	// Returns the average amount of elements in a bucket
	double getAverageAmount();

	// Checks if a key is in hash table
	bool contains(const KeyType &key);

	// Increases amount of a keys in hash table
	void increaseAmountOfKeys(const KeyType &key);

	// Adds a new element into the hash table
	void addKey(const KeyType &key);

	// Prints every hash table element with amount
	void printAll();
};