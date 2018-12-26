#include "task01.h"
#include "dataStructures.h"

#include <fstream>
#include <iostream>

using namespace std;

void handleIO()
{
	auto *myList = new MyLinkedList();
	ifstream incomingData("f.txt", ios::in);
	
	if (incomingData.is_open())
	{
		cout << "\nStart reading your data...\n" << endl;
		string myWord;
		
		while (incomingData >> myWord)
		{
			int number = stoi(myWord);
			myList->insert(number);
		}
		
		cout << "Before REVERSING the list:" << endl;
		myList->printList();
		
		cout << "After reversing the list:" << endl;
		myList->reverse();
		myList->printList();
	}
	else
	{
		cout << "ERROR: File not found :(" << endl;
	}
}

int main()
{
	handleIO();
	return 0;
}