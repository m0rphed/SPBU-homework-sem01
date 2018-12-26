#include "task-01-isPalindrome.h"

// For C version
#include <stdio.h>  // printf()
#include <string.h> // strlen()

// For C++ version
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


void sanitizeString(char *myString)
{
	for (char *stringCopy = myString; *stringCopy; ++stringCopy)
	{
		// if current char is space <=> ' '
		if (*stringCopy != ' ')
		{
			// rewrite current character
			*myString++ = *stringCopy; // Yeah.. I know, that it is pointer arithmetic!
		}
	}
	
	// set last character to '\0'
	*myString = 0; // 0 <=> '\0'
}


// C version
bool isPalindrome(char *myString)
{
	sanitizeString(myString);
	unsigned int leftIndex = 0;
	unsigned int rightIndex = strlen(myString) - 1;
	
	while (rightIndex > leftIndex)
	{
		if (myString[leftIndex] != myString[rightIndex])
		{
			printf("\n\t%s => This is not a palindrome\n", myString);
			return false;
		}
		++leftIndex;
		--rightIndex;
	}
	
	printf("\n\t%s => This is a palindrome! Hell Yeah!\n", myString);
	
	return true;
}


// C++ version
bool isPalindrome(string &myString)
{
	// sanitize string with the help of iterator
	string::iterator endingPosition = remove(myString.begin(), myString.end(), ' ');
	myString.erase(endingPosition, myString.end());
	
	return equal(myString.begin(), myString.begin() + myString.size() / 2, myString.rbegin());
}
