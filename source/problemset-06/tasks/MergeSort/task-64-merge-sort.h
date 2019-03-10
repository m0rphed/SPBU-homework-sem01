#pragma once

#include "List.h"

// Process all data from TXT file and make a list from it
List *processData(const std::string &fileName);

// Handle commands from IO
unsigned int handleUserCommands();

void saveData(List *&list, const std::string &fileName);

// Sort the list of famous hackers (by name or number)
void mergeSort(List *list, bool byName = true);

// Do the sorting and save result
void controlFunction(bool isTestingMode = true);
