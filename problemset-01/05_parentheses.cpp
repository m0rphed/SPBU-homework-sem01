#include <stdio.h>
#include <string.h> // strchr()

const int maxSize = 512;

// handles input
void getInput(char *str)
{
	char *newline = nullptr;

	// using fgets() instead of gets() to avoid buffer overflow
	fgets(str, maxSize, stdin);

	// using 'newline' as a pointer to '\n'
	if ((newline = strchr(str, '\n')) != nullptr)
		// indicate the end of user's input with '\0'
		*newline = '\0';
}

int main()
{
	int flag = 0;
	char str[maxSize];

	printf("Enter the string with the parentheses for the test:\n");
	getInput(str);

	int i = 0;
	while (str[i] != '\0' && flag >= 0)
	{
		if (str[i] == '(')
			flag++;

		if (str[i] == ')')
			flag--;
		i++;
	}

	if (flag == 0)
	{
		printf("Your input is OK!\n");
	}
	else
	{
		printf("Invalid input\n");
	}
	return 0;
}
