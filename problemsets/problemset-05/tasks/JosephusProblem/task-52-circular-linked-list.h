#pragma once

namespace CircularList
{
	// Define class Node <=> represents a node of CircularList
	class Node
	{
	public:
		
		int data;
		Node *next;
		
		// Init class constructor
		explicit Node(int value);
	};
	
	class LinkedList
	{
		// Destroys list with every element in it
		void deleteList();
		
		// function is private
		void shift();
	
	public:
		
		Node *listHead = nullptr;
		
		// Init class constructor
		explicit LinkedList(int headValue);
		
		virtual ~LinkedList();
		
		// Returns 'true' if given element is the head
		bool isHead(Node *element);
		
		int length();
		
		void insert(int key);
		
		void kill(int key);
		
		void print();
	};
};
