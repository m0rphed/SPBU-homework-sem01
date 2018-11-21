#pragma once


namespace LinkedList
{
	// Defines type of a single node
	// in linked list
	struct Node
	{
		int data;
		Node *next;
		
		Node(int value, Node *pinterToNext) : data(value), next(pinterToNext)
		{
		}
	};
	
	// Func. to get length of list
	int length(Node *head);
	
	// Shifts linked list, insert new element at the head
	void shift(Node *&head, int value);
	
	// Inserts element, doesn't break the order of the items in the list
	void smartInsert(Node *&head, int data);
	
	// Delete element with value = <data>
	void smartDelete(Node *&head, int data);
	
	// I was not asked to do this function,
	// so it is not a part of the task.
	// Func. reverse whole list
	void reverse(Node *&head);
	
	// Prints the whole list
	void printList(Node *head);
	
	// Destroys list recursively
	void deleteList(Node *&head);
	
	// Handles dialog interface
	void startDialogLoop(Node *&head);
}
