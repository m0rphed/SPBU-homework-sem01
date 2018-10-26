#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readBuffer(vector<string> &mainText, ifstream &myFile)
{
	while (!myFile.eof())
	{
		string textPart;
		myFile >> textPart;
		mainText.push_back(textPart);
	}
}

int main()
{
	ifstream myFile("someText.txt", ios::in);
	
	if (myFile.is_open())
	{
		vector<string> mainText;
		readBuffer(mainText, myFile);
		
		myFile.close();
		
		for (string const &line : mainText)
		{
			unsigned long length = line.length();
			int index = 0;
			
			while (line[index] != ';' && index < length - 1)
			{
				++index;
			}
			
			if (index < length - 1)
			{
				for (int j = index; j < length - 1; ++j)
				{
					cout << line[j];
				}
				cout << endl;
			}
		}
	}
	else
	{
		cout << "No such myFile in the directory" << endl;
		return 1;
	}
	
	return 0;
}