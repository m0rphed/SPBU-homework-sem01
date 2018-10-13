#include <stdio.h>
#include <math.h>

void compareArrayOfBoolNum(bool *first, bool *second)
{
	
	const int sizeFirst = sizeof(first) / sizeof(bool);
	const int sizeSecond = sizeof(second) / sizeof(bool);
	
	int diff = abs(sizeFirst - sizeSecond);
	
	for (int i = diff; i < sizeFirst; ++i)
	{
		if (first[i] && !second[i])
		{
			printf("First given argument is higher.");
			break;
		}
		else if (!first[i] && second[i])
		{
			printf("Second given argument is lower.");
			break;
		}
	}
}


int main()
{
	int arraySize = 8;
	bool first[8] = {0, 0, 0, 1, 0, 0, 0, 1};
	bool second[8] = {0, 1, 0, 0, 0, 0, 0, 0};
	
	void rebuildAnArray(int decimal)
	{
	
	}
	
	printf("Let's do some tests:\n");
	
	compareArrayOfBoolNum(first, second);
}