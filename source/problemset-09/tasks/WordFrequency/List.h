#pragma once

#include <string>

namespace HashTableList
{
    struct List;

    // Creates a new list
    List *createList();

    // Deletes a list and all its' elements
    void deleteList(List *list);

    // Adds a new element into the list
    List *addToList(List *list, const std::string &key);

    // Checks if a list is empty
    bool isEmpty(List *list);

    // Returns the key of the element
    std::string keyOfElement(List *list);

    // Returns a pointer to the next element
    List *nextOfList(List *list);

    // Returns the number of records in a list
    int getNumberOfRecords(List *list);

    // Prints the list
    void printList(List *list);

    // Increases capacity of the list
    void increaseCapacity(List *list);

    // Returns capacity of the list
    int getCapacity(List *list);
}
