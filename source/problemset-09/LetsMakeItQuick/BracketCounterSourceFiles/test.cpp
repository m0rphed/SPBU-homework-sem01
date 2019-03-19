#include "task-62-counting-brackets.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	vector<string> truthyTests = {"{}", "()", "[{()}]", "[](){}", "()()[{}]"};
	for (auto &test : truthyTests)
	{
		pair<bool, string> result = bracketCounter::checkString(test);
		cout << "\n\nTesting: " << test << endl;
		cout << "--> Result: " << result.second << endl;
	}

	vector<string> falsyTests = {"{{}", "()]", ")[]", "[(6+10)]"};

	for (auto &test : falsyTests)
	{
		pair<bool, string> result = bracketCounter::checkString(test);
		cout << "\n\nTesting: " << test << endl;
		cout << "--> Result: " << result.second << endl;
	}

	return 0;
}
