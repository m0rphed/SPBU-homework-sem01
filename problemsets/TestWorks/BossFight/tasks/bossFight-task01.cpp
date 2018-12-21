#include "../dataStructures/LinkedList.h"
#include "bossFight-task01.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <string>

using namespace std;

BinarySearchTree *processData(BinarySearchTree *myTree)
{
	string fileName = "data.txt";
	ifstream data(fileName, ios::in);
	
	// Check that file can be found, and throw exception if it can not
	if (!data.is_open())
	{
		cerr << "ERROR: File not found." << endl;
		throw runtime_error(string("Failed opening: ") + fileName);
	}
	
	cout << "\nStart reading your phone-book...\n" << endl;
	int counter = 0;
	
	while (!data.eof())
	{
		string line;
		
		getline(data, line);
		myTree->insert(line);
		
		++counter;
	}
	
	cout << "Successfully read " << counter << " lines." << endl;
	data.close();
	
	return myTree;
}
