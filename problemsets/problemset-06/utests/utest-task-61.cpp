#include "../tasks/ReversePolishNotation/task-61-postfix-notation.h"
#include <gtest/gtest.h> // Google Test Framework
#include <vector>
#include <string>

using namespace std;


vector<string> handleUserInput(const string &input)
{
	cout << "\nInput mathematical operation in Reverse Polish Notation:\n" << input << endl;
	
	// create vector of substrings split by space character
	istringstream stream(input);
	vector<string> items{istream_iterator<string>{stream}, istream_iterator<string>{}};
	
	return items;
}


TEST(problemset06, ReversePolishTest)
{
	// Create an instance of calculationStack class.
	auto *calculator = new calculationStack(); // calculator points to nullptr
	
	const string testString = "9 6 - 1 2 + *\n";

	// Simulate user input and do calculation
	calculator->performCalculations(handleUserInput(testString));
	
	cout << "Result:\n" << calculator->getResult() << endl;
	ASSERT_EQ(9, calculator->getResult());
}
