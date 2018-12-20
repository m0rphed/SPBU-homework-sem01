#include "task-64-merge-sort.h"
#include "DoublyLinkedList.h"

#include <iostream>
using namespace std;

void processData()
{
	// 1 open file with data
	// 2 check that everything is ok
	// 3-a read all string data "имя - номер телефона"
	// 3-b write all to myDoublyLinkedList with
	//      Node {
	//              name: "имя",
	//              phoneNumber : "+79818212598"
	//           }
	
	// let user decide what to use as a KEY for sorting
	// something like: cin >> choice;
	//                  if choce == 1 => name
	// 					if choce == 2 => phoneNumber
	
	// mergeSort(myDoublyLinkedList)
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
	auto *leftHalf = list->sliceList(0, mid);
	auto *rightHalf = list->sliceList(mid, list->getLength());
	
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
			list->setNodeAt(k, leftHalf->getNodeAt(i));
			++i;
		}
		else
		{
			list->setNodeAt(k, rightHalf->getNodeAt(j));
			++j;
		}
		++k;
	}
	
	while (i < leftHalf->getLength())
	{
		list->setNodeAt(k, leftHalf->getNodeAt(i));
		++i;
		++k;
	}
	
	while (j < rightHalf->getLength())
	{
		list->setNodeAt(k, rightHalf->getNodeAt(j));
		++j;
		++k;
	}
	
	cout << "Merging ";
	list->print();
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
	auto *leftHalf = list->sliceList(0, mid);
	auto *rightHalf = list->sliceList(mid, list->getLength());
	
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
			list->setNodeAt(k, leftHalf->getNodeAt(i));
			++i;
		}
		else
		{
			list->setNodeAt(k, rightHalf->getNodeAt(j));
			++j;
		}
		++k;
	}
	
	while (i < leftHalf->getLength())
	{
		list->setNodeAt(k, leftHalf->getNodeAt(i));
		++i;
		++k;
	}
	
	while (j < rightHalf->getLength())
	{
		list->setNodeAt(k, rightHalf->getNodeAt(j));
		++j;
		++k;
	}
	
	cout << "Merging ";
	list->print();
}
