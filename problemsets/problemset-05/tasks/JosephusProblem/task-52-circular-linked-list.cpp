#include "task-52-circular-linked-list.h"

#include <iostream>
#include <exception>

using namespace std;


//"Считалочка" – отряд из 41-го сикария, защищавший галилейскую крепость Массада,
//не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян.
//Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего,
//		пока не погибнут все.
//Самоубийство – тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить.
//Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу,
//		чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам.
//В нашем случае участвует n воинов и убивают каждого m-го.
//Требуется определить номер k начальной позиции воина, который должен будет остаться последним.
//Считать с помощью циклического списка.


CircularList::Node::Node(int value, CircularList::Node *pointerToNext)
{
	data = value;
	next = pointerToNext;
}


CircularList::LinkedList::LinkedList(int headValue)
{
	listHead = new Node(headValue, listHead);
}


bool CircularList::LinkedList::isHead(CircularList::Node *element)
{
	return (listHead == element);
}


int CircularList::LinkedList::length()
{
	int counter = 0;
	if (listHead == nullptr)
	{
		cout << "Circular list is empty (or do not exist)." << endl;
		return counter;
	}
	
	auto *current = listHead->next;
	
	do
	{
		++counter;
		current = current->next;
		
	} while (!isHead(current));
	
	return counter;
}


void CircularList::LinkedList::insert(const int key)
{
	Node *newElement = new CircularList::Node(key, listHead);
	
	// make a copy of listHead and listHead->next
	auto *current = listHead->next;
	auto *previous = listHead;
	
	while (!isHead(current))
	{
		previous = current;
		current = current->next;
	}
	
	previous->next = newElement;
}


void CircularList::LinkedList::kill(int key)
{
	while (!isHead(current))
	{
		cout << current->data << "-->";
		current = current->next;
	}
}


void CircularList::LinkedList::printList()
{
	cout << listHead->data << "-->";
	
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		cout << current->data << "-->";
		current = current->next;
	}
	
	cout << "head" << endl;
}


void CircularList::LinkedList::deleteList()
{
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		auto *temp = current;
		current = current->next;
		
		try
		{
			delete temp;
		} catch (exception &message)
		{
			cerr << message.what() << endl;
			throw "ERROR: Trying to delete an object that does not exist.\n";
		}
	}
}
