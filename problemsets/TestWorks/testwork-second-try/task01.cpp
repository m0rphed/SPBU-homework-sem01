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

int findMaxSum(int *array, const int size)
{
	int temp = 0;
	int maxSum = 0;
	
	// find maxSum of Array
	for (int i = 0; i < size; ++i)
	{
		temp = sumOfDigit(array[i]);
		if (temp >= maxSum)
		{
			maxSum = temp;
		}
	}
	
	return maxSum;
}


int main()
{
	int const size = 10;
	int maxSum = 0;
	
	int arrayOfMaximums[size] = {};
	int testArray[size] = {};
	
	// Input data for test
	for (auto &item : testArray)
	{
		std::cin >> item;
	}
	
	// next line pls!
	std::cout << std::endl;
	
	maxSum = findMaxSum(testArray, size);
	
	
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (sumOfDigit(testArray[i]) == maxSum)
		{
			arrayOfMaximums[index] = testArray[i];
			++index;
		}
		
	}
	
	
	// Output
	for (auto item : arrayOfMaximums)
	{
		if (item == 0)
		{
			break;
		}
		std::cout << item << " ";
	}
	
	return 0;
}
