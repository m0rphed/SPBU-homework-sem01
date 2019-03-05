#include "DoublyLinkedList.h"
#include "../../../problemset-06/tasks/MergeSort/DoublyLinkedList.h"


typedef int ListValueType;

using namespace std;

ListNode::ListNode(const ListValueType &value, ListNode *pointerPrevious = nullptr, ListNode *pointerNext = nullptr)
{
	data = value;
	previous = pointerPrevious;
	next = pointerNext;
}


ListNode::ListNode() : data(0), previous(nullptr), next(nullptr)
{
}

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}


void DoublyLinkedList::destroyList()
{
	while (head != nullptr)
	{
		ListNode *pointerToNext = head;
		head = head->next;
		delete pointerToNext;
	}
	tail = nullptr;
}


DoublyLinkedList::~DoublyLinkedList()
{
	destroyList();
}


ListNode *DoublyLinkedList::getHead()
{
	return this->head;
}


ListNode *DoublyLinkedList::getTail()
{
	return this->tail;
}


int DoublyLinkedList::getLength()
{
	return this->length;
}


ListNode *DoublyLinkedList::getNodeAt(const int &position)
{
	if (position < 0)
	{
		return head;
	}
	
	if (position >= 0 && position < length)
	{
		if (position > length / 2)
		{
			auto *current = tail;
			for (int i = length; i > position; --i)
			{
				current = current->previous;
			}
			return current;
		}
		
		auto *currentNode = head;
		for (int i = 0; i < position; ++i)
		{
			currentNode = currentNode->next;
		}
		return currentNode;
	}
	
	if (position >= length)
	{
		return nullptr;
	}
}


void DoublyLinkedList::addTo(const int &position, const ListValueType &value)
{
	if (length == 0)
	{
		head = tail = new ListNode(value);
	}
	else
	{
		auto *next = this->getNodeAt(position);
		
		if (!next)
		{
			tail->next = new ListNode(value, tail);
			tail = tail->next;
		}
		else if (next == head)
		{
			head = new ListNode(value, next->previous, next);
			head->next->previous = head;
		}
		else
		{
			next->previous = new ListNode(value, next->previous, next);
			if (next->previous->previous != nullptr)
			{
				next->previous->previous->next = next->previous;
			}
		}
	}
	++length;
}


void DoublyLinkedList::addToEnd(const ListValueType &value)
{
	addTo(length, value);
}


void DoublyLinkedList::removeFrom(const int &position)
{
	if (length == 0)
	{
		return;
	}
	if (position <= 0)
	{
		auto *temp = head;
		head = temp->next;
		
		if (!head)
		{
			tail = nullptr;
		}
		else
		{
			head->previous = nullptr;
		}
		delete temp;
	}
	else if (position >= length - 1)
	{
		auto *temp = tail;
		tail = temp->previous;
		if (!tail)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		delete temp;
	}
	else
	{
		ListNode *temp = getNodeAt(position);
		temp->next->previous = temp->previous;
		temp->previous->next = temp->next;
		delete temp;
	}
	--length;
}


void DoublyLinkedList::print()
{
	using namespace std;
	
	if (length == 0)
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		cout << "[" << length << "]: {";
		auto *temp = head;
		
		while (temp)
		{
			cout << temp->data;
			if (temp->next)
			{
				cout << ", ";
			}
			temp = temp->next;
		}
		cout << "}" << endl;
	}
}


void DoublyLinkedList::printReverse()
{
	using namespace std;
	
	if (length == 0)
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		cout << "[" << length << "]: {";
		auto *temp = tail;
		
		while (temp)
		{
			cout << temp->data;
			if (temp->previous)
			{
				cout << ", ";
			}
			temp = temp->previous;
		}
		cout << "}" << endl;
	}
}
