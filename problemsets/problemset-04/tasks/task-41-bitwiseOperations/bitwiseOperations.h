#pragma once

#include <utility>

// Namespace bitwise encapsulates solution
namespace bitwise
{
	struct Number
	{
		int decimalValue;
		bool *arrayOfBits;
		
		// Constructor setting structure parameters explicitly
		explicit Number(const int &value = 0, bool *pointer = nullptr);
		
		void generateBinary();
		
		int generateDecimal();
		
		int getActualLength();
		
		void printBinary();
	};
	
	std::pair<int, int> handleUserInput();
	
	void sumBinaryNumbers(Number *first, Number *second, Number *sum);
	
	int performOperations(bool testingMode = false, int firstValue = 0, int secondValue = 0);
}
