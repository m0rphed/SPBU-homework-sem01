#pragma once

#include <utility>

namespace bitwise
{
	class Number
	{
	public:
		
		Number() = default;
		
		explicit Number(const int &value);
		
		~Number();
		
		int getDecimal();
		
		bool *getBinary();;
		
		int checkLength();
		
		void setLength(const int &value);
		
		void setDecimal(const int &value);
		
		void setBinary(bool *pointerToArray);
		
		void generateDecimal();
		
		void generateBinary();
		
		void printBinary();
		
		void shiftBits(const int &n);
	
	private:
		// Decimal representation of number
		int decimalValue = 0;
		
		int arrayLength = 0;
		
		// Binary representation of number
		bool *bitArray = nullptr;
	};
	
	void updateBitArray(Number *first, Number *second);
	
	void sumTwoBinaryNumbers(Number *first, Number *second, Number *sum);
	
	std::pair<int, int> handleUserInput();
	
	void performOperations(bool testingMode = false, int firstValue = 0, int secondValue = 0);
}
