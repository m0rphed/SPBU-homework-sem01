#include "../tasks/ReversePolishNotation/task-61-postfix-notation.h"
#include <gtest/gtest.h> // Google Test Framework
#include <vector>
#include <string>

using namespace std;


vector<string> simulateUserInput(const string &input)
{
	cout << "\n\nInput mathematical operation in Reverse Polish Notation:\n" << input << endl;
	
	// create vector of substrings split by space character
	istringstream stream(input);
	vector<string> items{istream_iterator<string>{stream}, istream_iterator<string>{}};
	
	return items;
}


TEST(problemset06, ReversePolishNotation)
{
	// create an instance of calculationStack class.
	auto *calculator = new calculationStack(); // calculator points to nullptr
	
	const string testString = "9 6 - 1 2 + *\n";
	
	// simulate user input and do calculation
	calculator->performCalculations(simulateUserInput(testString));
	
	cout << "\tResult: " << calculator->getResult() << endl;
	ASSERT_EQ(9, calculator->getResult());
}


TEST(problemset06, ReversePolishNotation_test_01)
{
	// create an instance of calculationStack class.
	auto *calculator = new calculationStack();
	
	const string testString = "-5 100 * 2 + 2 *\n";
	
	// simulate user input and do calculation
	vector<string> v = (simulateUserInput(testString));
	calculator->performCalculations(v);
	
	cout << "\tResult: " << calculator->getResult() << endl;
	ASSERT_EQ(-498*2, calculator->getResult());
}