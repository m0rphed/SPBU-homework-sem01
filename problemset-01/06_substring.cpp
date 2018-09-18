#include <stdio.h>
#include <string.h> // strstr(), strlen(), strchr()

#define max_size 512

// handles input
void getInput(char *str)
{
	char *newline = nullptr;

	fgets(str, max_size, stdin);

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

	// str — points to the first occurrence of substring in string
	str = strstr(str, subStr);
	while (str)
	{
		counter++;
		str = strstr(str + len, subStr);
	}

	return counter;
}

int main()
{
	char str[max_size];
	char subStr[max_size];

	printf("Enter a string:\n");
	getInput(str);

	printf("Enter a substring to search for:\n");
	getInput(subStr);

	printf("%d", count_substrings(str, subStr));
	return 0;
}
