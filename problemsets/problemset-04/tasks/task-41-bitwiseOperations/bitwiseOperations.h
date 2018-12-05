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
	
	void sumBinaryNumbers(bitwise::Number *first, bitwise::Number *second, bitwise::Number *sum);
	
	int performOperations(bool testingMode = false, int firstValue = 0, int secondValue = 0);
}
