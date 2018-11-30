#include "../tasks/BracketCounter/task-62-counting-brackets.h"

#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(problemset06, bracketCounterTest)
{
	
	vector<string> goodTests = {"{}", "()", "[]"};
	for (auto &test : goodTests)
	{
		pair<bool, string> result = bracketCounter::checkString(test);
		ASSERT_TRUE(result.first);
		cout << result.second << endl;
	}
	
	vector<string> badTests = {"{{}", "()]", ")[]", "[(6+10)]"};
	
	for (auto &test : badTests)
	{
		pair<bool, string> result = bracketCounter::checkString(test);
		ASSERT_FALSE(result.first);
		cout << result.second << endl;
	}
}
