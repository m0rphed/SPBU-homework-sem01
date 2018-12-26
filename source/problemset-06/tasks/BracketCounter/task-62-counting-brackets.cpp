#include "../LastInFirstOut.h"
#include "task-62-counting-brackets.h"

#include <iostream>

using namespace std;


bool bracketCounter::isOpening(const char &bracket)
{
	return bracket == '(' || bracket == '[' || bracket == '{';
}


bool bracketCounter::isClosing(const char &bracket)
{
	return bracket == ')' || bracket == ']' || bracket == '}';
}


bool bracketCounter::isSameType(const char &opening, const char &closing)
{
	return (opening == '(' && closing == ')') ||
	       (opening == '[' && closing == ']') ||
	       (opening == '{' && closing == '}');
}


string bracketCounter::getUserInput()
{
	string input;
	
	cout << "Enter a string with a brackets (in one line, please):" << endl;
	getline(cin, input);
	cout << "Fine! Let's check brackets now..." << endl;
	
	return input;
}


// "testing mode" = receive test string as parameter (if testInput is not empty)
pair<bool, string> bracketCounter::checkString(string input)
{
	if (input.empty())
	{
		// "manual mode" = receive string from user (from console)
		input = bracketCounter::getUserInput();
	}
	
	auto *stack = new myStack();
	
	// Set maximum capacity of stack => length of input
	// (In worst case -- every symbol in the input is an opening bracket/brace).
	stack->capacity(input.length());
	
	for (const char &symbol : input)
	{
		if (stack->isEmpty())
		{
			if (isClosing(symbol))
			{
				return make_pair(false, "\nFound closing parentheses/brackets/braces before opening one\n");
			}
			else
			{
				stack->push(symbol);
			}
		}
		else
		{
			if (isOpening(symbol))
			{
				stack->push(symbol);
			}
			else if (isSameType(stack->top(), symbol))
			{
				stack->pop();
			}
			else
			{
				delete stack;
				return make_pair(false, "\nBrackets/braces mismatch!\n");
			}
		}
	}
	
	if (stack->isEmpty())
	{
		delete stack;
		return make_pair(true, "\nAll right!\n");
	}
	
	delete stack;
	return make_pair(false, "\nBrackets/braces are not in balance\n");
}


void bracketCounter::startCounting()
{
	pair<bool, string> result = checkString();
	cout << result.second << endl;
}
