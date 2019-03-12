#pragma once

#include "List.h"
#include <string>

// Hash table implementation
class HashTable
{
public:
    // Default constructor
    HashTable() = default;

    // Hash function
    unsigned int hashFunction(const std::string &input);
    // Creates a new hash table
    HashTable *createHashTable(int size)
    {
        HashTable *table = new HashTable;
        table->buckets = new List *[size];
        for (int i = 0; i < size; i++)
        {
            table->buckets[i] = createList();
        }
        table->size = size;
        return table;
    }

    // Deletes a hash table and all its' elements
    void deleteHashTable(HashTable *table);

    // Checks if a key is contained
    bool isContained(HashTable *table, const std::string &key);

    // Increases amount of a key
    void increaseAmountOfKey(HashTable *table, const std::string &key);

    // Adds a new element into the hash table
    void addIntoHashTable(HashTable *table, const std::string &key);

    // Returns amount of a key in the hash table
    int amountOfKey(HashTable *table, const std::string &key);

    // Prints all the elements and its' amount in the hash table
    void printAll(HashTable *table);

    // Returns the maximum amount of elements in a bucket
    int maximum(HashTable *table);

    // Returns the average amount of elements in a bucket
    double average(HashTable *table);

private:
    int size = 0;
    List **buckets = nullptr;
};