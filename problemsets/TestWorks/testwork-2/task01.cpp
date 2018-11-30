#include "task01.h"
#include "dataStructures.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void task01::processData(ifstream &file, const int a, const int b,
                         testWorkList::Node *lower, testWorkList::Node *inSection, testWorkList::Node *higher)
{
	if (file.is_open())
	{
		cout << "\nStart reading...\n" << endl;
		
		string myWord;
		while (file >> myWord)
		{
			cout << myWord << " ";
			
			int number = stoi(myWord);
			if (number < a)
			{
				testWorkList::insert(lower, number);
			}
			else if (number > b)
			{
				testWorkList::insert(higher, number);
			}
			else
			{
				testWorkList::insert(inSection, number);
			}
		}
		
		file.close();
	}
	else
	{
		cout << "\nNo such file in the directory\n" << endl;
		return;
	}
	
}


void task01::letsListSomeData(const int &a, const int &b)
{
	auto *lower = new testWorkList::Node(0, nullptr);
	auto *inSection = new testWorkList::Node(0, nullptr);
	auto *higher = new testWorkList::Node(0, nullptr);
	
	ifstream incoming("f.txt", ios::in);
	
	processData(incoming, a, b, lower, inSection, higher);
	
	ofstream output;
	output.open("g.txt");
	
	testWorkList::saveList(lower, output);
	testWorkList::printList(lower);
	
	testWorkList::saveList(inSection, output);
	testWorkList::printList(inSection);
	
	testWorkList::saveList(higher, output);
	testWorkList::printList(higher);
	output.close();
	
	delete lower;
	delete inSection;
	delete higher;
}
