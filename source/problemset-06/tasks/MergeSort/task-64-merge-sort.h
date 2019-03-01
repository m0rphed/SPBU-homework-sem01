#pragma once
#include "DoublyLinkedList.h"

// Process all data from TXT file and make a list from it
DoublyLinkedList *processData(DoublyLinkedList *list);

// Handle commands from IO
unsigned int handleUserCommands();

void controlFunction(bool isTestingMode = true);

// Sort the list of famous hackers (by name or number)
void mergeSort(DoublyLinkedList *list, bool byName = true);
