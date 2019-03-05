#include "task-71-userInterface.h"
#include <iostream>

#include "Set.h" // Using implementation of set

using namespace std;

int getValueFromKeyboard()
{
	int value = 0;
	cout << "Enter a value:" << endl;
	cin >> value;
	return value;
}


void addValue(Set *mySet)
{
	if (!mySet->addValue(getValueFromKeyboard()))
	{
		cout << "Can't add value. Value is already in the set." << endl;
	}
	else
	{
		cout << "Value successfully added to the set." << endl;
	}
}


void removeValue(Set *mySet)
{
	if (!mySet->removeValue(getValueFromKeyboard()))
	{
		cout << "Can't remove value. No such value in the set." << endl;
	}
	else
	{
		cout << "Value successfully removed from the set." << endl;
	}
}


void checkValue(const Set *mySet)
{
	if (mySet->contains(getValueFromKeyboard()))
	{
		cout << "The value is in the set." << endl;
	}
	else
	{
		cout << "No such value in the set." << endl;
	}
}


void userInterface(Set *mySet)
{
	int command = 0;
	
	do
	{
		cout << "\nChoose option:" << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Add value to the set" << endl;
		cout << "2 - Delete value from the set" << endl;
		cout << "3 - Check if value is in the set" << endl;
		cout << "4 - Print elements in ascending order" << endl;
		cout << "5 - Print elements in descending order\n" << endl;
		
		cout << "Enter command:" << endl;
		cin >> command;
		
		switch (command)
		{
			case 0:
				cout << "Exit." << endl;
				break;
			
			case 1:
				addValue(mySet);
				break;
			
			case 2:
				removeValue(mySet);
				break;
			
			case 3:
				checkValue(mySet);
				break;
			
			case 4:
				cout << "Printing in ascending order:" << endl;
				mySet->print(mySet->ascendingOrder());
				cout << endl << endl;
				break;
			
			case 5:
				cout << "Printing in descending order:" << endl;
				mySet->print(mySet->descendingOrder());
				cout << endl << endl;
				break;
			
			default:
				cout << "No such command!\nEnter command again: " << command << endl;
				cin >> command;
		}
	} while (command != 0);
}
