#pragma once

#include "LinkedList.h"
#include <string>
#include <vector>
#include <utility>

// Define type of key
typedef std::string KeyType;

const unsigned int standardBaseSize = 100;
using namespace HashTableComponents;

// Hash table implementation
class HashTable
{
	unsigned int numberOfElements = 0;
	unsigned int baseSize = standardBaseSize;
	List **buckets = new List *[baseSize];

public:
	// Default constructor
	HashTable();

	// Getter-method for baseSize
	unsigned int getBaseSize() const;

	// Getter-method for numberOfElements
	unsigned int getNumberOfElements() const;

	// Deletes a hash table, causes destruction of every element
	~HashTable();

	// Hash function
	unsigned long hashFunction(const KeyType &input, unsigned int divisorRate = standardBaseSize) const;

	// Creates a new hash table
	explicit HashTable(unsigned int newBaseSize);

	// Returns amount of a keys in the hash table
	int getAmountOfKey(const KeyType &key) const;

	// Returns the maximum amount of elements in a bucket
	int getMaxAmount() const;

	// Returns the average amount of elements in a bucket
	double getAverageAmount() const;

	// Checks if a key is in hash table
	bool keyExists(const KeyType &key) const;

	// Increases amount of a keys in bucket which contains key
	void expandBucketByKey(const KeyType &key);

	// Adds a new element into the hash table
	void addKey(const KeyType &key);

	// Prints every hash table element with amount
	void printKeysWithAmount() const;

	// Prints all keys of the hash table
	void printKeys() const;

	// Expands baseSize of hash table and rehashes all keys in it
	HashTable *expandTableAndRehash(unsigned int newBaseSize);

	std::vector<std::pair<KeyType, int>> getVectorRepresentation() const;
};