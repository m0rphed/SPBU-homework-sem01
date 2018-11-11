#include <string>
#include <fstream>
#include <vector>
#include <iostream>


using namespace std;


void readBuffer(vector<string> &captured, ifstream &file)
{
	while (!file.eof())
	{
		string buffer;
		getline(file, buffer);
		captured.push_back(buffer);
	}
}


void findComments(vector<string> const &captured, vector<string> &output)
{
	for (string const &line : captured)
	{
		if (line.find(';') != string::npos)
		{
			size_t pos = line.find(';');
			output.push_back(line.substr(pos));
		}
		
	}
	
}


void printOutput(vector<string> const &output)
{
	for (string const &str : output)
	{
		cout << str << endl;
	}
}


int main()
{
	ifstream file("textFile.txt", ios::in);
	
	if (file.is_open())
	{
		vector<string> captured;
		vector<string> output;
		
		readBuffer(captured, file);
		file.close();
		
		findComments(captured, output);
		printOutput(output);
	}
	else
	{
		cout << "No such file in the directory" << endl;
		return 1;
	}
	
	return 0;
}