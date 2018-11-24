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
		Node(int value);
	};
	
	class LinkedList
	{
	
	private:
		
		// Destroys list with every element in it
		void deleteList();
		
		// function is private
		void shift();
	
	public:
		
		Node *listHead = nullptr;
		
		// Init class constructor
		LinkedList(int headValue);
		
		virtual ~LinkedList();
		
		// Returns 'true' if given element is the head
		bool isHead(Node *element);
		
		int length();
		
		void insert(int key);
		
		void kill(int key);
		
		void print();
	};
};
