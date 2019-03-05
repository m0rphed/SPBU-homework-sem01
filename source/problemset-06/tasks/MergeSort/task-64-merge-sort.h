#pragma once
#include "List.h"

// Process all data from TXT file and make a list from it
List *processData(List *list);

// Handle commands from IO
unsigned int handleUserCommands();

void controlFunction(bool isTestingMode = true);

// Sort the list of famous hackers (by name or number)
void mergeSort(List *list, bool byName = true);
