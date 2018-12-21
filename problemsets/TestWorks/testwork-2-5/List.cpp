#include "List.h"

typedef string ElementType;

Node::Node() : data(0), next(nullptr)
{
}


Node::Node(ElementType &value) : data(value), next(nullptr)
{
}


LinkedList::LinkedList()
{
	head = nullptr;
	length = 0;
}


LinkedList::LinkedList(ElementType *arrayOfElements, const int &size)
{
	if (size == 0)
	{
		return;
	}
	
	head = new Node(arrayOfElements[0]);
	auto *headCopy = head;
	
	for (int i = 1; i < size; ++i)
	{
		headCopy->next = new Node(arrayOfElements[i]);
		headCopy = headCopy->next;
	}
	
	length = size;
}


LinkedList::~LinkedList()
{
	destroyList();
}


int LinkedList::countNodes()
{
	auto *headCopy = head;
	int counter = 0;
	
	while (headCopy)
	{
		++counter;
		headCopy = headCopy->next;
	}
	
	return counter;
}


int LinkedList::getLength()
{
	return length;
}


void LinkedList::shift(const ElementType &data)
{
	auto *newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	++length;
}


void LinkedList::smartInsert(const ElementType &data)
{
	auto *newNode = new Node();
	newNode->data = data;
	
	// previous node of linked list
	Node *previous = nullptr;
	
	// when list is empty
	if (!head)
	{
		head = newNode;
		++length;
		return;
	}
	
	// make a copy of head
	auto *current = head;
	
	while (current)
	{
		// What if we found proper place to insert a new node?
		// --> So, insert the new node BEFORE higher or equal node
		// (no need to go through all equal elements -- trust me, it is good point. I googled it!).
		if (current->data >= data)
		{
			newNode->next = current;
			
			if (previous)
			{
				previous->next = newNode;
			}
			else // when previous do not exist
			{
				head = newNode;
			};
			return;
		}
		
		previous = current;
		current = current->next;
	}
	
	previous->next = newNode;
	++length;
}


void LinkedList::smartDelete(const ElementType &data)
{
	// previous node of linked list
	Node *previous = nullptr;
	
	// when list is empty
	if (!head)
	{
		// "List is already empty, there is nothing to delete here!"
		cout << "Лист уже пуст, нечего тут удалять!" << endl;
		return;
	}
	
	// make a copy of head
	auto *current = head;
	
	while (current)
	{
		if (current->data == data)
		{
			if (previous)
			{
				previous->next = current->next;
			}
			else // when previous do not exist
			{
				// Case: current is the last element in list
				if (length == 1) // => Check if length == 1
				{
					// Then, the list should be empty
					delete head;
					head = nullptr;
					cout << "Удалён последний элемент." << endl;
					length = 0;
					return;
				}
				else
				{
					head = current->next;
				}
			}
			
			delete current;
			--length;
			return;
		}
		
		previous = current;
		current = current->next;
	}
	
	cout << "\nОшибка, нет такого элемента!" << endl;
}


// I like reversing things
void LinkedList::reverse()
{
	if (!head || (!(head->next) && head))
	{
		return;
	}
	
	Node *newHead = nullptr;
	Node *nextNode = nullptr;
	
	while (head)
	{
		nextNode = head->next;
		head->next = newHead;
		newHead = head;
		head = nextNode;
	}
	head = newHead;
}


void LinkedList::printList()
{
	auto *headCopy = head;
	cout << "\t";
	while (headCopy)
	{
		cout << headCopy->data << "-->";
		headCopy = headCopy->next;
	}
	cout << "null" << endl;
}


void LinkedList::destroyList()
{
	Node *nextNode;
	while (head)
	{
		nextNode = head->next;
		delete (head);
		head = nextNode;
	}
	length = 0;
}


void LinkedList::linkedListInterface()
{
	int command = 0;
	ElementType value;
	
	// Start dialog mode loop
	do
	{
		// For NonRussianHackers "Введите команду" <=> "Enter a command"
		cout << "Введите команду: ";
		cin >> command;
		cout << endl;
		
		// The dialog mode provides the following operations:
		switch (command)
		{
			case 0:
				cout << "< Выход >" << endl;
				break;
			
			case 1: // 1 - Add value to the sorted list
				cout << "Добавление значения в список.\n\tВведите значение: ";
				cin >> value;
				LinkedList::smartInsert(value);
				cout << endl;
				break;
			
			case 2: // 2 – Delete value from list
				cout << "Удаление значения из списка.\n\tВведите значение:";
				cin >> value;
				LinkedList::smartDelete(value);
				cout << endl;
				break;
			
			case 3: // 3 – Print the whole list
				cout << "Печать списка..." << endl;
				LinkedList::printList();
				break;
			
			default:
				cout << "Неверная команда!" << endl;
		}
		
	} while (command != 0);
}
