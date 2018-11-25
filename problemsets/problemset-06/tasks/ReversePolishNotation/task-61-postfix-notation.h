#pragma once

#include "../LastInFirstOut.h"

#include <string>
#include <vector>


class calculationStack : public myStack
{
	int result = 0;
	
public:
	
	// This constructor sets topElement to nullptr
	calculationStack();
	
	// In need tho put some value in the stack when initializing it,
	// => use this constructor
	explicit calculationStack(const int & value);
	
	// Check if we can perform a basic binary operation
	// '+', '-', '*', '/'
	bool checkStack(std::string operation);
	
	// Do addition
	int add();
	
	// Do subtraction
	int subtract();
	
	// Do multiplication
	int multiply();
	
	// Do division
	int divide();
	
	// Do all calculations
	void performCalculations(std::vector<std::string> input);
	
	// Return result of calculation
	int getResult();
};


std::vector<std::string> handleInput(); // transforms user data