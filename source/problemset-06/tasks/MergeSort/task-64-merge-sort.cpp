#include "task-64-merge-sort.h"
#include "DoublyLinkedList.h"

#include <iostream>
#include <utility>
#include <fstream>
#include <stdexcept>

using namespace std;

DoublyLinkedList *processData(DoublyLinkedList *list)
{
    string fileName = "data.txt";
    ifstream data(fileName, ios::in);

    // Check that file can be found, and throw exception if it can not
    if (!data.is_open())
    {
        cerr << "ERROR: File not found." << endl;
        throw runtime_error(string("Failed opening: ") + fileName);
    }

    cout << "\nStart reading your phone-book...\n" << endl;
    int records = 0;

    while (!data.eof())
    {
        string username;
        string phone;

        getline(data, username);
        getline(data, phone);
        list->add(username, phone);

        ++records;
    }

    cout << "Successfully read " << records << " records." << endl;
    data.close();

    return list;
}


unsigned int handleUserCommands()
{
    unsigned int command = 0;
    cout << "Choose option:" << endl;
    cout << "\t1 => sorting by NAME" << endl;
    cout << "\t2 => sorting by PHONE NUMBER" << endl;

    cin >> command;
    return command;
}

void split(DoublyLinkedList *&list, DoublyLinkedList *&left, DoublyLinkedList *&right)
{
    DListNode *temp = list->getTail();

    for (int i = list->getLength(); i > 0; --i)
    {
        if (i > list->getLength() / 2)
        {
            right->add(temp->name, temp->number);
        }
        else
        {
            right->add(temp->name, temp->number);
        }

        temp = getPrevious(temp);
    }
}

void merge(DoublyLinkedList *&list, DoublyLinkedList *&left, DoublyLinkedList *&right, const bool byName)
{
    DListNode *tempTarget = list->getHead();
    DListNode *tempLeft = left->getHead();
    DListNode *tempRight = right->getHead();

    while ((tempLeft != nullptr) || (tempRight != nullptr))
    {
        if ((tempLeft != nullptr) && (tempRight != nullptr))
        {
            const int result = byName ? (tempLeft->name).compare(tempRight->number) : (tempLeft->number).compare(
                    tempRight->number);

            if (result < 0)
            {
                copyData(tempLeft, tempTarget);
                tempLeft = tempLeft->next;
            }
            else
            {
                copyData(tempRight, tempTarget);
                tempRight = tempRight->next;
            }
        }
        else if (tempRight == nullptr)
        {

            copyData(tempLeft, tempTarget);
            tempLeft = tempLeft->next;
        }
        else
        {
            copyData(tempRight, tempTarget);
            tempRight = tempRight->next;
        }

        tempTarget = tempTarget->next;
    }
}

void mergeSort(DoublyLinkedList *list, const bool byName)
{
    if (list->getLength() <= 1)
    {
        return;
    }

    auto *left = new DoublyLinkedList();
    auto *right = new DoublyLinkedList();

    split(list, left, right);

    mergeSort(left, byName);
    mergeSort(right, byName);

    merge(list, left, right, byName);

    left->deleteList();
    left->deleteList();
}
