#pragma once

#include <string>

namespace HashTableComponents
{
	// List as structure of "ListNodes"
	struct ListNode
	{
		std::string key;
		ListNode *next = nullptr;

		// Default constructor
		ListNode() = default;

		// Creates a new list with specified parameters
		explicit ListNode(const std::string &newKey, ListNode *nextNode = nullptr);
	};


	struct List
	{
		ListNode *head = new ListNode();
		int capacity = 0;

		// Default constructor
		List() = default;

		// Destroys every node in linked list
		~List();

		// List methods:

		// Adds a new element into the list
		void addToList(const std::string &key);

		// Checks if list is empty
		bool isEmpty();

		// Returns the number of elements in a list
		int countElements();

		// Prints the list
		void printList();

		// Increases capacity of the list
		void increaseCapacity();
	};
}
