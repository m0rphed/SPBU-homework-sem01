#pragma once


// Define class Node <=> represents a node of CircularList
class Node
{
public:
	int data;
	Node *next;
};


class CircularList
{
public:
	
	int length;
	Node *head;
	
	CircularList();
	
	~CircularList();
	
	void addElement(int data);
	
	void print();
};
