#include "task-51-linked-list.h" // include header file

#include <iostream> // cin, cout, endl
#include <locale>   // setlocale(LC_ALL, "Russian")

using namespace std;


int LinkedList::length(Node *head)
{
	int length = 0;
	
	while (head)
	{
		length++;
		head = head->next;
	}
	
	return length;
}


void LinkedList::shift(Node *&head, int data)
{
	auto *newNode = new LinkedList::Node(0, nullptr);
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}


void LinkedList::insert(Node *&head, int data)
{
	auto *newNode = new LinkedList::Node(0, nullptr);
	newNode->data = data;
	
	// previous node of linked list
	LinkedList::Node *previous = nullptr;
	
	// when list is empty
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	
	// make a copy of head
	auto *current = head;
	
	while (current != nullptr)
	{
		// What if we found proper place to insert a new node?
		// --> So, insert the new node BEFORE higher or equal node
		// (no need to go through all equal elements -- trust me, it is good point. I googled it!).
		if (current->data >= data)
		{
			newNode->next = current;
			
			if (previous != nullptr)
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
}


void LinkedList::smartDelete(Node *&head, int data)
{
	// previous node of linked list
	LinkedList::Node *previous = nullptr;
	
	// when list is empty
	if (head == nullptr)
	{
		// "List is already empty, there is nothing to delete here!"
		cout << "Лист уже пуст, нечего тут удалять!" << endl;
		return;
	}
	
	// make a copy of head
	auto *current = head;
	
	while (current != nullptr)
	{
		if (current->data == data)
		{
			if (previous != nullptr)
			{
				previous->next = current->next;
			}
			else // when previous do not exist
			{
				// Case 1: current is the last element in list
				if (LinkedList::length(current) == 1) // => Check if length == 1
				{
					// Then, the list should be empty
					head = nullptr;
					cout << "Удалён последний элемент." << endl;
				}
				else
				{
					head = current->next;
				}
			};
			
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}
	
	cout << "\nОшибка, нет такого элемента!" << endl;
}


// I like reversing things
void LinkedList::reverse(Node *&head)
{
	if (head == nullptr || (head && (head->next == nullptr)))
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


void LinkedList::printList(Node *head)
{
	cout << "\t";
	while (head)
	{
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}


void LinkedList::deleteList(Node *&head)
{
	Node *nextNode;
	while (head)
	{
		nextNode = head->next;
		delete (head);
		head = nextNode;
	}
}


void LinkedList::startDialogLoop(Node *&head)
{
	int key = 0;
	int value = 0;
	
	// Start dialog mode loop
	do
	{
		// For NonRussianHackers "Введите команду" <=> "Enter a command"
		cout << "Введите команду: ";
		cin >> key;
		cout << endl;
		
		// The dialog mode provides the following operations:
		switch (key)
		{
			case 0:
				cout << "< Выход >" << endl;
				break;
			
			case 1: // 1 - Add value to the sorted list
				cout << "Добавление значения в список.\n\tВведите значение: ";
				cin >> value;
				LinkedList::insert(head, value);
				cout << endl;
				break;
			
			case 2: // 2 – Delete value from list
				cout << "Удаление значения из списка.\n\tВведите значение:";
				cin >> value;
				LinkedList::smartDelete(head, value);
				cout << endl;
				break;
			
			case 3: // 3 – Print the whole list
				cout << "Печать списка..." << endl;
				LinkedList::printList(head);
				break;
			
			default:
				cout << "Неверная команда!" << endl;
		}
		
	} while (key != 0);
}
<<<<<<< HEAD:problemsets/problemset-05/tasks/task-51-linked-list.cpp


int polynomial()
{
	setlocale(LC_ALL, "Russian");
	LinkedList::Node *list = nullptr;
	startDialogLoop(list);
	
	// test testWorkList::length() function
	cout << "\nДлина списка: " << LinkedList::length(list) << endl;
	LinkedList::printList(list);
	
	// test testWorkList::shift() function
	cout << "Добавим 100 в начало" << endl;
	LinkedList::shift(list, 100);
	LinkedList::printList(list);
	
	// test testWorkList::reverse() function
	cout << "Развернём лист:" << endl;
	LinkedList::reverse(list);
	LinkedList::printList(list);
	
	LinkedList::deleteList(list);
	return 0;
}
=======
>>>>>>> master:problemsets/problemset-05/tasks/LinkedList/task-51-linked-list.cpp
