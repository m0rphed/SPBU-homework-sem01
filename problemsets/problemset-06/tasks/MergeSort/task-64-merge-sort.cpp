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
		list->append(username, phone);
		
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


void controlFunction(bool isTestingMode)
{
	auto *list = new DoublyLinkedList();
	
	processData(list);
	
	if (isTestingMode)
	{
		mergeSortByName(list);
		list->print();
		return;
	}
	else
	{
		int command = handleUserCommands();
		switch (command)
		{
			case 1:
				mergeSortByName(list);
				list->print();
				return;
			
			case 2:
				mergeSortByPhone(list);
				list->print();
				return;
			
			default:
				cout << "No such command! \n\t--> Exiting" << endl;
				break;
		}
	}
	delete list;
}


void mergeSortByName(DoublyLinkedList *list)
{
	cout << "Splitting ";
	list->print();
	
	if (list->getLength() == 1)
	{
		return;
	}
	
	int mid = list->getLength() / 2;
	auto *leftHalf = list->getSubList(0, mid);
	auto *rightHalf = list->getSubList(mid, list->getLength());
	
	mergeSortByName(leftHalf);
	mergeSortByName(rightHalf);
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	// MERGING
	while (i < leftHalf->getLength() && j < rightHalf->getLength())
	{
		if ((leftHalf->getNodeAt(i))->name < (rightHalf->getNodeAt(j))->name)
		{
			list->resetNode(k, leftHalf->getNodeAt(i));
			++i;
		}
		else
		{
			list->resetNode(k, rightHalf->getNodeAt(j));
			++j;
		}
		++k;
	}
	
	while (i < leftHalf->getLength())
	{
		list->resetNode(k, leftHalf->getNodeAt(i));
		++i;
		++k;
	}
	
	while (j < rightHalf->getLength())
	{
		list->resetNode(k, rightHalf->getNodeAt(j));
		++j;
		++k;
	}

	delete leftHalf;
	delete rightHalf;
}


void mergeSortByPhone(DoublyLinkedList *list)
{
	cout << "Splitting ";
	list->print();
	
	if (list->getLength() == 1)
	{
		return;
	}
	
	int mid = list->getLength() / 2;
	auto *leftHalf = list->getSubList(0, mid);
	auto *rightHalf = list->getSubList(mid, list->getLength());
  
	mergeSortByName(leftHalf);
	mergeSortByName(rightHalf);
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	// MERGING
	while (i < leftHalf->getLength() && j < rightHalf->getLength())
	{
		if ((leftHalf->getNodeAt(i))->phone < (rightHalf->getNodeAt(j))->phone)
		{
			list->resetNode(k, leftHalf->getNodeAt(i));
			++i;
		}
		else
		{

			list->resetNode(k, rightHalf->getNodeAt(j));
			++j;
		}
		++k;
	}
	
	while (i < leftHalf->getLength())
	{
		list->resetNode(k, leftHalf->getNodeAt(i));
		++i;
		++k;
	}
	
	while (j < rightHalf->getLength())
	{
		list->resetNode(k, rightHalf->getNodeAt(j));
		++j;
		++k;
	}
	
	cout << "Merging ";
	list->print();
	delete leftHalf;
	delete rightHalf;
}
