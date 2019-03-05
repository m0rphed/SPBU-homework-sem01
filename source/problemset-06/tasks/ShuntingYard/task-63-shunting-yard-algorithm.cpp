#include "task-63-shunting-yard-algorithm.h"

#include <string>
#include <iostream>

using namespace std;


bool isOperator(const char &operand)
{
	return ((operand == '+') || (operand == '-') || (operand == '*') || (operand == '/'));
}


int priority(const char &operand)
{
	switch (operand)
	{
		case '+':
		case '-':
			return 1;
		
		case '*':
		case '/':
			return 2;
		
		default:
			return 0;
	}
}

string toPostfix(const string &infix)
{
	auto *stack = new myStack();
	
	// Set stack capacity
	stack->capacity(infix.size());
	
	string postfix;
	
	for (const auto &symbol : infix)
	{
		if (isdigit(symbol))
		{
			// All numbers are pushed to the postfix (output string)
			// when they are read.
			postfix.insert(postfix.end(), symbol);
			postfix += " ";
		}
		else if (isOperator(symbol))
		{
			while ((!stack->isEmpty()) && isOperator(stack->top()) && priority(stack->top()) >= priority(symbol))
			{
				postfix.insert(postfix.end(), stack->pop());
				postfix += " ";
			}
			stack->push(symbol);
		}
		else if (symbol == '(')
		{
			// Push opening parenthesis/spaces
			stack->push(symbol);
		}
		else if (symbol == ')')
		{
			// Pop every symbol inside parenthesises
			// and push it to the postfix (output string)
			while (stack->top() != '(')
			{
				postfix.insert(postfix.end(), stack->pop());
				postfix += " ";
			}
			
			// Pop '('
			stack->pop();
		}
	}
	
	// At the end of reading the expression,
	// pop all operators off the stack and onto the postfix (output string).
	while (!stack->isEmpty())
	{
		postfix.insert(postfix.end(), stack->pop());
	}
	
	delete stack;
	return postfix;
}

void handleIO(string infix)
{
	
	if (infix.empty())
	{
		cout << "Enter arithmetical expression in infix form:";
		getline(cin, infix);
		cout << endl;
	}
	else
	{
		cout << "\nExpression in infix form:\n\t" << infix << endl;
	}
	
	cout << "\nExpression in postfix form (reverse polish notation):\n\t" << toPostfix(infix) << endl;
	cout << endl;
}
