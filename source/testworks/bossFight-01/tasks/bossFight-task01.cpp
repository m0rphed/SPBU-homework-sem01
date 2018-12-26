#include "bossFight-task01.h"

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include <gtest/gtest.h> // Google Test Framework

using namespace std;

void writeToFile(ofstream &output, BinarySearchTree *myTree)
{
	// Backup stream buffers of std::cout and std::cin
	streambuf *streamBufferCout = cout.rdbuf();
	
	// Get the stream buffer of the file
	streambuf *streamBufferFile = output.rdbuf();
	
	// Redirect std::cout to file
	cout.rdbuf(streamBufferFile);
	
	myTree->inOrder();
	
	// Redirect back
	cout.rdbuf(streamBufferCout);
	
	cout << "Data was written to file." << endl;
}


void *processData(string inputFile, string outputFile, BinarySearchTree *myTree)
{
	ifstream input(inputFile, ios::in);
	ofstream output(outputFile);
	
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
		
		pair<bool, TreeNode *> found = myTree->search(line);
		
		if (found.first)
		{
			continue;
		}
		else
		{
			myTree->insert(line);
		}
		++counter;
	}
	cout << "Successfully read " << counter << " lines." << endl;
	
	// write all gathered data to output
	writeToFile(output, myTree);
	
	input.close();
	return myTree;
}


int main()
{
	string inputName = "data.txt";
	string outputName = "output.txt";
	
	auto *tree = new BinarySearchTree();
	
	processData(inputName, outputName, tree);
}