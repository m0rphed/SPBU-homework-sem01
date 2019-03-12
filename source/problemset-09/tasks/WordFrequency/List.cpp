#include "List.h"
#include <iostream>
#include <string>

using namespace std;

struct HashTableList::List
{
    string key;
    List *next;
    int capacity;
};

HashTableList::List *HashTableList::createList()
{
    return nullptr;
}

void HashTableList::deleteList(HashTableList::List *list)
{
    List *temp = list;

    while (temp)
    {
        List *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
}

HashTableList::List *HashTableList::addToList(HashTableList::List *list, const string &key)
{
    List *newList = new List{key, 1, nullptr};

    if (!list)
    {
        list = newList;
    }
    else
    {
        List *temp = list;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newList;
    }

    return list;
}

bool HashTableList::isEmpty(HashTableList::List *list)
{
    return list == nullptr;
}

string HashTableList::keyOfElement(HashTableList::List *list)
{
    return list->key;
}

HashTableList::List *HashTableList::nextOfList(HashTableList::List *list)
{
    List *temp = list->next;
    return temp;
}

int HashTableList::getNumberOfRecords(HashTableList::List *list)
{
    int numberOfRecords = 0;
    List *temp = list;

    while (temp)
    {
        temp = nextOfList(temp);
        ++numberOfRecords;
    }
    return numberOfRecords;
}

void HashTableList::printList(HashTableList::List *list)
{
    List *temp = list;

    while (temp)
    {
        cout << keyOfElement(temp) << " ";
        temp = nextOfList(temp);
    }
}

void HashTableList::increaseCapacity(HashTableList::List *list)
{
    ++list->capacity;
}

int HashTableList::getCapacity(HashTableList::List *list)
{
    return list->capacity;
}
