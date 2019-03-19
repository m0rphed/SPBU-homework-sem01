#include "HashTable.h"
#include <iostream>

using namespace std;

unsigned long HashTable::hashFunction(const KeyType &input, const unsigned int divisorRate) const
{
	unsigned long hashSum = 0;

	for (auto &character : input)
	{
		hashSum = hashSum + int(character);
	}

	return hashSum % divisorRate;
}

HashTable::HashTable(unsigned int newBaseSize)
{
	buckets = new List *[newBaseSize];

	for (int i = 0; i < newBaseSize; ++i)
	{
		buckets[i] = new List();
	}

	baseSize = newBaseSize;
}

HashTable::~HashTable()
{
	for (int i = 0; i < baseSize; ++i)
	{
		// Destructor of implemented linked list would be called here
		delete buckets[i];
	}

	delete[] buckets;
}

int HashTable::getAmountOfKey(const KeyType &key) const
{
	auto *current = buckets[hashFunction(key)];

	// case: if no such key
	if (!keyExists(key))
	{
		return 0;
	}

	while (key != current->head->key)
	{
		current->head = current->head->next;
	}

	return current->capacity;
}

int HashTable::getMaxAmount() const
{
	int maximum = 0;

	for (int i = 0; i < baseSize; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		int amount = 0;
		auto *current = buckets[i]->head;

		while (current)
		{
			current = current->next;
			amount++;
		}

		if (amount > maximum)
		{
			maximum = amount;
		}
	}

	return maximum;
}

double HashTable::getAverageAmount() const
{
	double amountOfElements = 0;
	double amountOfNonEmptyBuckets = 0;

	for (int i = 0; i < baseSize; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		auto *current = buckets[i]->head;

		while (current)
		{
			current = current->next;
			++amountOfElements;
		}

		++amountOfNonEmptyBuckets;
	}

	return (amountOfElements / amountOfNonEmptyBuckets);
}

bool HashTable::keyExists(const KeyType &key) const
{
	if (numberOfElements == 0)
	{
		return false;
	}

	auto *current = buckets[hashFunction(key)]->head;

	while (current)
	{
		if (key == current->key)
		{
			return true;
		}

		current = current->next;
	}

	return false;
}

void HashTable::expandBucketByKey(const KeyType &key)
{
	auto *current = buckets[hashFunction(key)];
	current->increaseCapacity();
}

void HashTable::addKey(const KeyType &key)
{
	// if key is character a space or empty string -> ignore it
	if (key.empty() || key == " ")
	{
		return;
	}

	// if no keys in the hash table
	if (numberOfElements == 0)
	{
		buckets[hashFunction(key)]->addToList(key);
		++numberOfElements;
		return;
	}

	// if key does not exist in the hash table -> add it to the hash table
	if (!keyExists(key))
	{
		buckets[hashFunction(key)]->addToList(key);
		++numberOfElements;
		return;
	}

	// if key exists in the hash table -> increase capacity of the bucket
	expandBucketByKey(key);
}

void HashTable::printKeysWithAmount() const
{
	cout << "\n All elements of hash table (key, amount):" << endl;

	for (int i = 0; i < baseSize; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		auto *current = buckets[i]->head;
		auto capacityOfBucket = buckets[i]->capacity;

		while (current)
		{
			cout << current->key << " : " << capacityOfBucket << endl;
			current = current->next;
		}
	}
}

void HashTable::printKeys() const
{
	cout << "\n All keys in hash table:" << endl;

	for (int i = 0; i < baseSize; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		auto *current = buckets[i]->head;

		while (current)
		{
			cout << current->key << ", ";
			current = current->next;
		}

		cout << endl;
	}
}

HashTable *HashTable::expandTableAndRehash(const unsigned int newBaseSize)
{
	auto *newHashTable = new HashTable(newBaseSize);

	for (int i = 0; i < baseSize; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		// Get copy of list pointer
		auto *current = buckets[i]->head;

		while (current)
		{
			KeyType key = current->key;

			// Add key from current hash table to the new hash table
			newHashTable->buckets[hashFunction(key, newBaseSize)]->addToList(key);
			current = current->next;
		}
	}

	// delete current hash table
	delete this;

	// return pointer to the new hash table
	return newHashTable;
}

unsigned int HashTable::getBaseSize() const
{
	return baseSize;
}

unsigned int HashTable::getNumberOfElements() const
{
	return numberOfElements;
}

vector<pair<KeyType, int>> HashTable::getVectorRepresentation() const
{
	vector<pair<KeyType, int>> resultVector = {};

	for (unsigned int i = 0; i < baseSize; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		// Get copy of capacity value
		auto capacityOfBucket = buckets[i]->capacity;

		// Get copy of list pointer
		auto *current = buckets[i]->head;

		while (current)
		{
			resultVector.emplace_back(current->key, capacityOfBucket);
			current = current->next;
		}
	}

	// return vector of pairs <key, capacity>
	return resultVector;
}

HashTable::HashTable()
{
	this->baseSize = standardBaseSize;
	this->buckets = new List *[baseSize];

	for (int i = 0; i < baseSize; ++i)
	{
		this->buckets[i] = new List();
	}

	this->numberOfElements = 0;
}
