#include "LinkedListFixture.h"

#include "../tasks/LinkedList/task-51-linked-list.h" // Testing LinkedList

#include <iostream>  // Printing error messages
#include <locale>    // Printing Russian messages in console
#include <exception> // Handling errors by using exceptions

using namespace std;


// Special test fixture method
// Inserts all values from param: <array> to the linked list.
void ListFixture::insertTestValues(int *array, const int size)
{
	// First value in list have been already set in Test Fixture constructor
	// (default value list->data = 0).
	// We need to replace it with the first element of the array
	listHead->data = array[0];
	
	for (int i = 1; i < size; ++i)
	{
		LinkedList::smartInsert(listHead, array[i]);
	}
}


// Test fixture method
::testing::AssertionResult ListFixture::checkList(int *array, const int size)
{
	if (LinkedList::length(listHead) != size)
	{
		throw length_error("\n\tERROR: Length of linked list doesn't match size of test-array.\n");
	}
	
	// copy listHead
	auto *currentNode = listHead;
	
	for (int i = 0; i < size; ++i)
	{
		if (currentNode->data != array[i])
		{
			cout << "ERROR: Error matching testing array." << endl;
			return ::testing::AssertionFailure();
		}
		
		currentNode = currentNode->next;
	}
	
	return ::testing::AssertionSuccess();
}


// Test fixture method
void ListFixture::simulateDialogLoop(int *commands, int length)
{
	// Enable Russian in console -- we always test startDialogLoop() in Russian
	setlocale(LC_ALL, "Russian");
	
	// index of testing array
	int index = 0;
	
	while (index < length)
	{
		cout << "Полученная команда: " << commands[index] << " <=> ";
		
		// Imitation of the dialog mode
		switch (commands[index])
		{
			case 0:
				cout << "< Выход >\n" << endl;
				return;
			
			case 1: // 1 - Add value to the sorted list
				try
				{
					++index;
					commands[index];
				} catch (exception &message)
				{
					cout << message.what() << endl;
					throw "ОШИБКА: Выход за границы тестовой последовательности.\n";
				}
				
				cout << "Добавление значения в список.\n\tПолученное значение: " << commands[index] << endl;
				
				// First value in list have been already set in Test Fixture constructor
				// (default value list->data = 0).
				// We need to replace it with the test value.
				if (LinkedList::length(listHead) == 1 && listHead->data == 0)
				{
					listHead->data = commands[index];
				}
				else
				{
					LinkedList::smartInsert(listHead, commands[index]);
				}
				
				break;
			
			case 2: // 2 – Delete value from list
				try
				{
					++index;
					commands[index];
				} catch (exception &message)
				{
					cout << message.what() << endl;
					throw "ОШИБКА: Выход за границы тестовой последовательности.\n";
				}
				
				cout << "Удаление значения из списка.\n\tПолученное значение: " << commands[index] << endl;
				
				// Special case: last element in the list
				if (LinkedList::length(listHead) == 1)
				{
					cout << "Удален последнего элемента\n\tЛист пуст." << endl;
					cout << "Тестирование завершено." << endl;
					// No need to do:
					//     LinkedList::deleteList(listHead);
					// listHead would be destroyed in destructor ListFixture::TearDown() automatically;
					
					return;
				}
				else
				{
					LinkedList::smartDelete(listHead, commands[index]);
				}
				
				break;
			
			case 3: // 3 – Print the whole list
				cout << "Печать списка..." << endl;
				LinkedList::printList(listHead);
				break;
			
			default:
				cout << "Неверная команда!" << endl;
		}
		
		// increment index
		++index;
	}
}
