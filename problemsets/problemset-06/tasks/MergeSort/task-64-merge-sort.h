#include "DoublyLinkedList.h"

#include <iostream>
using namespace std;

DoublyLinkedList *processData(DoublyLinkedList *list);

unsigned int handleUserCommands();

void controlFunction(bool isTestingMode = true);

void mergeSortByName(DoublyLinkedList *list);

void mergeSortByPhone(DoublyLinkedList *list);