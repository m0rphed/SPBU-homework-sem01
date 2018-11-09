#include "task-01-isPalindrome.h"

// For C version
#include <stdio.h>  // printf()
#include <string.h> // strlen()
#include <locale.h> // allow Russian in console

// For C++ version`
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// Проверить, является ли строка палиндромом - то есть, читается ли она одинаково в обоих направлениях.
// Заглавные и строчные буквы считаются разными,
// пробелы должны игнорироваться.
// Пример палиндрома: "я иду с мечем судия".
// Строку можно задать как константу в коде,
// можно сделать ввод с клавиатуры.
// Для определения длины строки можно
// использовать функцию strlen из string.h.


bool isPalindrome(char myString[])
{
	int leftIndex = 0;
	int rightIndex = strlen(myString) - 1;
	
	while (rightIndex > leftIndex)
	{
		if (myString[leftIndex] != myString[rightIndex])
		{
			printf("\n\t%s => This is not a palindrome\n", myString);
			return false;
		}
		leftIndex++;
		rightIndex--;
	}
	printf("\n\t%s => This is a palindrome! Hell Yeah!\n", myString);
	return true;
}


// Can't stop H8ing pointers, but OK :/
void sanitizeString(char *myString)
{
	char *leftIterator = myString;
	char *rightIterator = myString;
	do
	{
		*leftIterator = *rightIterator;
		if (*leftIterator != ' ')
		{
			leftIterator++;
		}
		
	} while (*rightIterator++ != 0);
}


// C++ version
bool isPalindromeCpp(string &myString)
{
	// sanitize string with the help of iterator
	string::iterator endingPosition = remove(myString.begin(), myString.end(), ' ');
	myString.erase(endingPosition, myString.end());
	
	if (equal(myString.begin(), myString.begin() + myString.size() / 2, myString.rbegin()))
	{
		return true;
	}
	
	return false;
}
