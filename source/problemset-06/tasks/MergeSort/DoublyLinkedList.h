#pragma once

#include <string>

struct DListNode
{
    std::string name;
    std::string number;
    DListNode *previous = nullptr;
    DListNode *next = nullptr;

    DListNode() = default;

    DListNode(const std::string &name, const std::string &number, DListNode *previous, DListNode *next);
};

class DoublyLinkedList
{
private:
    DListNode *head = nullptr;
    DListNode *tail = nullptr;
    int length = 0;

public:
    // Default constructor
    DoublyLinkedList() = default;

    // Returns pointer to the first element of list
    DListNode *getHead();

    // Returns pointer to the last element of list
    DListNode *getTail();

    // Returns length of the list
    int getLength();

    // Checks the list is empty
    bool isEmpty();

    // Add new element to the list
    void add(const std::string &name, const std::string &number);

    // Delete list completely
    void deleteList();

    // Print all the elements
    void printList();
};

// Copy number and name from source element to target element
void copyData(DListNode *&first, DListNode *&second);

DListNode *getNext(DListNode *current);

DListNode *getPrevious(DListNode *current);

std::string name(DListNode *node);

std::string number(DListNode *node);