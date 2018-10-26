#include <iostream>

//1)  В массиве целых чисел найти число,
//    сумма цифр которого была бы наибольшей.
//    Если таких чисел несколько, вывести на экран все эти числа.

int sumOfDigit(int number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}


int main()
{
	int const size = 10;
	int tempSum = 0;
	int maxSum = 0;
	
	int arrayOfMaximums[size] = {};
	
	int testArray[size] = {};
	
	for (auto &item : testArray)
	{
		std::cin >> item;
	}
	
	std::cout << std::endl;
	
	// find maxSum of Array
	for (auto item : testArray)
	{
		tempSum = sumOfDigit(item);
		if (tempSum > maxSum)
		{
			maxSum = tempSum;
		}
	}
	
	int index = 0;
	
	for(int i = 0; i < size; ++i)
	{
		if (sumOfDigit(testArray[i]) == maxSum)
		{
			arrayOfMaximums[index] = testArray[i];
			++index;
		}
		
	}
	
	for (auto item : arrayOfMaximums)
	{
		std::cout << item << " ";
	}
	
	return 0;
}
