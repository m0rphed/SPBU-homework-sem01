#include <stdio.h>
#include <string.h> // strncmp(), strlen(), strchr()

const int maxSize = 512;

// handles input
void getInput(char *str)
{
	char *newline = nullptr;

	fgets(str, maxSize, stdin);

	// using 'newline' as a pointer to '\n'
	if ((newline = strchr(str, '\n')) != nullptr)
		// indicate the end of user's input with '\0'
		*newline = '\0';
}

// returns count of occurrences of 'subStr' in 'str'
int count_substrings(char *str, char *subStr)
{
	int len = strlen(subStr);

	// avoid empty lines
	if (len == 0)
		return 0;

	int counter = 0;

	while (*str != '\0')
	{
		// strncmp() returns an integral value indicating successful or unsuccessful matching of strings.
		// The value = 0 if contents of both strings are equal.
		// !(strncmp()) gives '1' if matching was successful

		if (!strncmp(str, subStr, len))
			counter++;

		str++;
	}

	return counter;
}

int main()
{
	char str[maxSize];
	char subStr[maxSize];

	printf("Enter a string:\n");
	getInput(str);

	printf("Enter a substring to search for:\n");
	getInput(subStr);

	printf("%d", count_substrings(str, subStr));
	return 0;
}
