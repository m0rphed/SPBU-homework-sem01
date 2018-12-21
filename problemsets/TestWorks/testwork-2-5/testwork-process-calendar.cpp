#include "testwork-process-calendar.h"
#include <stdexcept>
#include <iostream>

using namespace std;

void *processData(string inputFile, LinkedList *myList)
{
	using namespace std;
	ifstream input(inputFile, ios::in);
	
	// Check that file can be found, and throw exception if it can not
	if (!input.is_open())
	{
		cerr << "ERROR: File not found." << endl;
		throw runtime_error(string("Failed opening: ") + inputFile);
	}
	
	cout << "\nStart reading your data...\n" << endl;
	int counter = 0;
	
	while (!input.eof())
	{
		string line;
		
		getline(input, line);
		
		myList->smartInsert(line);
		
		++counter;
	}
	cout << "Successfully read " << counter << " lines." << endl;
	
	input.close();
}
