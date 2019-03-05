#include "task-61-postfix-notation.h"
#include "../LastInFirstOut.h"

#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>


calculationStack::calculationStack()
{
	topElement = nullptr;
	
	// Set capacity for calculationStack: maxCapacity = 3,
	// because we always work with binary operations
	//   -> every time we need to perform more than one arithmetic operation,
	//   -> there are tree elements in the stack:
	//     => [newValue_2 --> newValue_1 --> lastCalculatedResult]
	
	if (this->capacity() != 3)
	{
		this->capacity(3);
	}
}


// in need tho put some value in the stack when initializing it,
// => use this constructor
calculationStack::calculationStack(const int &value)
{
	topElement->setData(value);
	topElement->setNext(nullptr);
	
	if (this->capacity() != 3)
	{
		this->capacity(3);
	}
}


bool calculationStack::checkStack(std::string operation)
{
	if (this->getSize() < 2)
	{
		std::cout << "ERROR: Can't perform operation: " << operation << std::endl;
		return false;
	}
	return true;
}


void calculationStack::add()
{
	int result = this->pop() + this->pop();
	this->push(result);
}


void calculationStack::subtract()
{
	int secondOperand = this->pop();
	int result = this->pop() - secondOperand;
	this->push(result);
}


void calculationStack::multiply()
{
	int result = this->pop() * this->pop();
	this->push(result);
}


void calculationStack::divide()
{
	int secondOperand = this->pop();
	int result = this->pop() / secondOperand;
	this->push(result);
}


void calculationStack::performCalculations(std::vector<std::string> input)
{
	using namespace std;
	
	for (const string &substring : input)
	{
		// Check if substring is an integer
		if (!(substring.empty()) && (isdigit(substring[0]) || isdigit(substring[1])))
		{
			this->push(stoi(substring));
			continue;
		}
		
		if (substring == "+")
		{
			// do addition if it is possible
			if (checkStack("addition"))
			{
				this->add();
			}
			continue;
		}
		
		if (substring == "-")
		{
			// do subtraction if it is possible
			if (checkStack("subtraction"))
			{
				this->subtract();
			}
			continue;
		}
		
		if (substring == "*")
		{
			// do multiplication if it is possible
			if (checkStack("multiplication"))
			{
				this->multiply();
			}
			continue;
		}
		
		if (substring == "/")
		{
			// do division if it is possible
			if (checkStack("division"))
			{
				this->divide();
			}
			continue;
		}
	}
	
	this->result = this->top();
}


int calculationStack::getResult()
{
	return this->result;
}


std::vector<std::string> handleInput()
{
	using namespace std;
	
	string input;
	cout << "\nInput mathematical operation in Reverse Polish Notation:" << endl;
	
	// save user input to the string
	getline(cin, input);
	
	// create vector of substrings split by
	istringstream stream(input);
	vector<string> items{istream_iterator<string>{stream}, istream_iterator<string>{}};
	
	return items;
}


int manualTestingFunction()
{
	using namespace std;
	
	// Create an instance of calculationStack class.
	auto *calculator = new calculationStack(); // calculator points to nullptr
	
	calculator->performCalculations(handleInput());
	cout << calculator->getResult();
	return 0;
}