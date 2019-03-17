#include "HashTable.h"
#include <iostream>

using namespace std;

unsigned int HashTable::hashFunction(const KeyType &input)
{
	const int divisor = 25;
	unsigned int result = 0;

	for (auto character : input)
	{
		result = (result + int(character)) % divisor;
	}

	return result;
}

HashTable::HashTable(int size)
{
	buckets = new List *[size];

	for (int i = 0; i < size; ++i)
	{
		buckets[i] = new List();
	}

	this->size = size;
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; ++i)
	{
		// Destructor of implemented linked list would be called here
		delete buckets[i];
	}

	delete[] buckets;
}

int HashTable::getAmountOfKey(const KeyType &key)
{
	auto *current = buckets[hashFunction(key) % size];

	while (current->head->key != key)
	{
		current->head = current->head->next;
	}

	return current->capacity;
}

int HashTable::getMaxAmount()
{
	int maximum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		int amount = 0;
		auto *current = buckets[i];

		while (current)
		{
			current->head = current->head->next;
			amount++;
		}

		if (amount > maximum)
		{
			maximum = amount;
		}
	}

	return maximum;
}

double HashTable::getAverageAmount()
{
	double amountOfElements = 0;
	double amountOfNonEmptyBuckets = 0;

	for (int i = 0; i < size; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		auto *current = buckets[i];

		while (current)
		{
			current->head = current->head->next;
			++amountOfElements;
		}

		++amountOfNonEmptyBuckets;
	}

	return (amountOfElements / amountOfNonEmptyBuckets);
}

bool HashTable::contains(const KeyType &key)
{
	auto *current = buckets[hashFunction(key) % size];

	while (current)
	{
		if (current->head->key == key)
		{
			return true;
		}

		current->head = current->head->next;
	}

	return false;
}

void HashTable::increaseAmountOfKeys(const KeyType &key)
{
	auto *current = buckets[hashFunction(key) % size];

	while (current->head->key != key)
	{
		current->head = current->head->next;
	}

	current->increaseCapacity();
}

void HashTable::addKey(const KeyType &key)
{
	if (!contains(key))
	{
		// (1) should we check amount of buckets here?
		const int hash = hashFunction(key) % size;
		buckets[hash]->addToList(key);
		return;
	}

	// (2) should we throw exception here?
	increaseAmountOfKeys(key);
}

void HashTable::printAll()
{
	for (int i = 0; i < size; ++i)
	{
		if (buckets[i]->isEmpty())
		{
			continue;
		}

		auto *current = buckets[i];
		while (current)
		{
			cout << current->head->key << " " << current->capacity << endl;
			current->head = current->head->next;
		}
	}
}
