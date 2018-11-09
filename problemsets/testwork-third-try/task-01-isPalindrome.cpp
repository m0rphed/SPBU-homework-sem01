#include "task-01-isPalindrome.h"
#include <stdio.h>
#include <string.h> // strlen()

// Проверить, является ли строка палиндромом - то есть, читается ли она одинаково в обоих направлениях.
// Заглавные и строчные буквы считаются разными,
// пробелы должны игнорироваться.
// Пример палиндрома: "я иду с мечем судия".
// Строку можно задать как константу в коде,
// можно сделать ввод с клавиатуры.
// Для определения длины строки можно
// использовать функцию strlen из string.h.


void isPalindrome(char myString[])
{
	int leftIndex = 0;
	int rightIndex = strlen(myString) - 1;
	
	while (rightIndex > leftIndex)
	{
		if (myString[leftIndex] != myString[rightIndex])
		{
			printf("%s => This is not a palindrome\n", myString);
			return;
		}
		leftIndex++;
		rightIndex--;
	}
	printf("%s => This is a palindrome! Hell Yeah!\n", myString);
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


// Lets test it!
int main()
{
	isPalindrome("abba");
	isPalindrome("abbccbba");
	isPalindrome("geeks");
	return 0;
}
