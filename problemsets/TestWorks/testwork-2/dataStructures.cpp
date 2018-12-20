#include "dataStructures.h" // include header file

#include <iostream> // cin, cout, endl
#include <locale>   // setlocale(LC_ALL, "Russian")

using namespace std;


int testWorkList::length(Node *head)
{
	int length = 0;
	
	while (head)
	{
		length++;
		head = head->next;
	}
	
	return length;
}


void testWorkList::insert(Node *&head, int data)
{
	auto *newNode = new testWorkList::Node(data, nullptr);
	
	// when list is empty
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	
	if (head->data == 0)
	{
	
	}
	
	// make a copy of head
	auto *current = head;
	
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newNode;
}


void testWorkList::smartDelete(Node *&head, int key)
{
	// previous node of linked list
	testWorkList::Node *previous = nullptr;
	
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
		if (current->data == key)
		{
			if (previous != nullptr)
			{
				previous->next = current->next;
			}
			else // when previous do not exist
			{
				// Case 1: current is the last element in list
				if (testWorkList::length(current) == 1) // => Check if length == 1
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
			
			delete (current);
			return;
		}
		previous = current;
		current = current->next;
	}
	
	cout << "\nОшибка, нет такого элемента!" << endl;
}


void testWorkList::printList(Node *head)
{
	cout << "\t";
	while (head)
	{
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}


void testWorkList::deleteList(Node *&head)
{
	Node *nextNode;
	while (head)
	{
		nextNode = head->next;
		delete (head);
		head = nextNode;
	}
}


void testWorkList::saveList(testWorkList::Node *head, std::ofstream &file)
{
	file << "\t";
	while (head)
	{
		file << head->data << " ";
		head = head->next;
	}
	file << "\n";
}


void testWorkList::updateHead(testWorkList::Node *&head, int newData)
{
	if (testWorkList::length(head) > 1)
	{
		return;
	}
	
	if (!(head->data))
	{
		head->data = newData;
	}
}
