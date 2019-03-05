#include "task-64-merge-sort.h"
#include "List.h"

#include <iostream>
#include <utility>
#include <fstream>
#include <stdexcept>

using namespace std;

List *processData(List *list)
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

        list->pushFront(username, phone);

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

void split(List *&list, List *&left, List *&right)
{
    Record *temp = list->getTail();

    for (int i = list->getLength(); i > 0; --i)
    {
        if (i > list->getLength() / 2)
        {
            right->pushFront(temp->name, temp->number);
        }
        else
        {
            right->pushFront(temp->name, temp->number);
        }

        temp = temp->previous;
    }
}

void merge(List *&list, List *&left, List *&right, const bool byName)
{
    Record *tempTarget = list->getHead();
    Record *tempLeft = left->getHead();
    Record *tempRight = right->getHead();

    while (tempLeft || tempRight)
    {
        if (tempLeft && tempRight)
        {
            const int result = byName ? (tempLeft->name).compare(tempRight->number) : (tempLeft->number).compare(
                    tempRight->number);

            if (result < 0)
            {
                tempTarget->name = tempLeft->name;
                tempTarget->number = tempLeft->number;
                tempLeft = tempLeft->next;
            }
            else
            {
                tempTarget->name = tempRight->name;
                tempTarget->number = tempRight->number;
                tempRight = tempRight->next;
            }
        }
        else if (!tempRight)
        {
            tempTarget->name = tempLeft->name;
            tempTarget->number = tempLeft->number;
            tempLeft = tempLeft->next;
        }
        else
        {
            tempTarget->name = tempRight->name;
            tempTarget->number = tempRight->number;
            tempRight = tempRight->next;
        }

        tempTarget = tempTarget->next;
    }
}

void mergeSort(List *list, const bool byName)
{
    if (list->getLength() <= 1)
    {
        return;
    }

    auto *left = new List();
    auto *right = new List();

    split(list, left, right);

    mergeSort(left, byName);
    mergeSort(right, byName);

    merge(list, left, right, byName);

    delete left;
    delete right;
}
