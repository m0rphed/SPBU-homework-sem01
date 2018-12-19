#include "../tasks/BracketCounter/task-62-counting-brackets.h"

#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(problemset06, bracketCounterTest)
{
	vector<string> truthyTests = {"{}", "()", "[{()}]", "[](){}", "()()[{}]"};
	for (auto &test : truthyTests)
	{
		pair<bool, string> result = bracketCounter::checkString(test);
		ASSERT_TRUE(result.first);
		cout << "\n\nTesting: " << test << endl;
		cout << "--> Result: " << result.second << endl;
	}
	
	vector<string> falsyTests = {"{{}", "()]", ")[]", "[(6+10)]"};
	
	for (auto &test : falsyTests)
	{
		pair<bool, string> result = bracketCounter::checkString(test);
		ASSERT_FALSE(result.first);
		cout << "\n\nTesting: " << test << endl;
		cout << "--> Result: " << result.second << endl;
	}
}
