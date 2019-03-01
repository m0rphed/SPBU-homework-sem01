#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DListNode *DoublyLinkedList::getHead()
{
    return head;
}

DListNode *DoublyLinkedList::getTail()
{
    return tail;
}

int DoublyLinkedList::getLength()
{
    return length;
}

bool DoublyLinkedList::isEmpty()
{
    return (length == 0);
}

void DoublyLinkedList::add(const string &name, const string &number)
{
    head = new DListNode(name, number, nullptr, head);

    if (isEmpty())
    {
        tail = head;
    }
    else
    {
        head->next->previous = head;
    }

    ++length;
}

void DoublyLinkedList::deleteList()
{
    while (head != tail)
    {
        const DListNode *temp = head;
        head = head->next;
        delete temp;
    }

    delete head;
}

void DoublyLinkedList::printList()
{
    DListNode *temp = this->head;

    while (temp != nullptr)
    {
        cout << temp->name << " | " << temp->number << endl;
        temp = temp->next;
    }
}

void copyData(DListNode *&first, DListNode *&second)
{
    second->name = first->name;
    second->number = first->number;
}

DListNode *getNext(DListNode *current)
{
    return current->next;
}

DListNode *getPrevious(DListNode *current)
{
    return current->previous;
}

string name(DListNode *node)
{
    return node->name;
}

string number(DListNode *node)
{
    return node->number;
}


DListNode::DListNode(const string &name, const string &number, DListNode *previous, DListNode *next)
{
    this->name = name;
    this->number = number;
    this->previous = previous;
    this->next = next;
}
