#pragma once

#include "../LastInFirstOut.h"

#include <string>
#include <vector>


class calculationStack : public myStack
{
public:
	
	// This constructor sets topElement to nullptr
	calculationStack();
	
	// in need to put some value in the stack when initializing it,
	// => use this constructor
	explicit calculationStack(const int & value);
	
	// check if we can perform a basic binary operation
	// '+', '-', '*', '/'
	bool checkStack(std::string operation);
	
	// do addition
	int add();
	
	// do subtraction
	int subtract();
	
	// do multiplication
	int multiply();
	
	// do division
	int divide();
	
	// do all calculations
	void performCalculations(std::vector<std::string> input);
	
	// return result of calculation
	int getResult();

private:
	
	// Field stores result of the calculation
	int result = 0;
};


std::vector<std::string> handleInput(); // transforms user data