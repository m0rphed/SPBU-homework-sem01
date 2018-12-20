#include "handleInput.h"

#include <stdio.h>  // puts(), perror(), fcanf()


bool writeFileToArray(FILE *file, int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		// Case: length of the file < size of the array
		if (feof(file))
		{
			return false;
		}
		
		// write all integer data to the array
		fscanf(file, "%d", &array[i]);
	}
	
	return true;
}


bool getInputFromFile(int *array, const int size, const char *pathToFile)
{
	FILE *filePointer = fopen(pathToFile, "r");
	
	
	if (!filePointer)
	{
		perror("ERROR: Error opening file.\n");
		return false;
	}
	else
	{
		if (!writeFileToArray(filePointer, array, size))
		{
			perror("ERROR: End-of-File reached.\n");
			return false;
		}
		
		// Safely close the file
		// when all data was written to the array
		fclose(filePointer);
	}
	
	puts("\n\nAll data was read successfully.\n");
}