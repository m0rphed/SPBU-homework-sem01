#pragma once


// Define class Node <=> represents a node of CircularList
namespace CircularList
{
	class Node
	{
	public:
		int data;
		Node *next;
		
		// Init class constructor
		Node(int value, Node *pointerToNext = nullptr);
	};
	
	class LinkedList
	{
	private:
		
		Node *listHead = nullptr;
	
	public:
		
		// Init class constructor
		LinkedList(int headValue = 0);
		
		virtual ~LinkedList() = default;
		
		bool isHead(Node *element);
		
		int length();
		
		void insert(int key);
		
		void kill(int key);
		
		void printList();
		
		void deleteList();
	};
};
