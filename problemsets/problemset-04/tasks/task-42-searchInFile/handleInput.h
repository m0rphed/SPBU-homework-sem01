#pragma once

#include <stdio.h>

// Writes all data to an array
bool writeFileToArray(FILE *file, int *array, int size);

// Checks if the file can be opened.
// Warns if any errors occurred
bool getInputFromFile(int *array, int size, const char *pathToFile);