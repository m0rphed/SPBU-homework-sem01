#include "task02.h"

#include "dataStructures.h"
#include <iostream>

// Задача:
// Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
// 0 - выйти
// 1 - добавить значение в заданную позицию в двусвязный список
// 2 - удалить значение в заданной позиции из списка
// 3 - распечатать список
// Позиции задаются целыми числами, 0 соответствует голове списка.


void doublyLinkedListInterface(DoublyLinkedList *myList)
{
	using namespace std;
	int command = 0;
	ElementType value;
	
	// Start dialog mode loop
	do
	{   // index in doubly linked list
		int position = 0;
		
		// For NonRussianHackers "Введите команду" <=> "Enter a command"
		cout << "Введите команду: ";
		cin >> command;
		cout << endl;
		
		// The dialog mode provides the following operations:
		switch (command)
		{
			case 0:
				cout << "< Выход >" << endl;
				break;
			
			case 1: // 1 - Add value (to position) to the sorted list
				cout << "Добавление значения в список.\n\tВведите значение: ";
				cin >> value;
				
				cout << "\n\tЗадайте позицию для добавления элемента: ";
				cin >> position;
				
				myList->addTo(position, value);
				cout << endl;
				break;
			
			case 2: // 2 – Delete value (from position) from list
				cout << "Удаление значения из списка.\n\tВведите значение:";
				cin >> value;
				
				cout << "\n\tЗадайте позицию для удаления элемента: ";
				cin >> position;
				
				myList->removeFrom(position);
				cout << endl;
				break;
			
			case 3: // 3 – Print the whole list
				cout << "Печать списка..." << endl;
				myList->print();
				break;
			
			default:
				cout << "Неверная команда!" << endl;
		}
		
	} while (command != 0);
}
