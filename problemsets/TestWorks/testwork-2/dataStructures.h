#pragma once

#include <fstream>

namespace testWorkList
{
	// Let's define type of a single node
	// in linked list
	struct Node
	{
		int data;
		Node *next;
		
		Node(int value, Node *pinterToNext) : data(value), next(pinterToNext)
		{
		}
	};
	
	// Func. to gets length of list
	int length(Node *head);
	
	void updateHead(Node *&head, int newData);
	
	// Inserts element, doesn't break the order of the items in the list
	void insert(Node *&head, int data);
	
	// Deletes element with value = <data>
	void smartDelete(Node *&head, int key);
	
	// Prints the whole list
	void printList(Node *head);
	
	// Destroys list recursively
	void deleteList(Node *&head);
	
	void saveList(Node *head, std::ofstream &file);
}
