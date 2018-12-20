#include "dataStructures/LinkedList.h"
#include "bossFight-task01.h"

#include <iostream>
#include <locale>

// Написать программу, которая ВВОДИТ с клавиатуры набор целых чисел
// (в любом порядке, конец — число 0),
// и ВЫВОДЯЩУЮ числа из этого набора в порядке возрастания и без повторений,
// с указанием того, сколько каждое число раз встретилось в этом наборе.

// My Notes:
// Буду решать с помщью связного списка, с добавлением не нарушаеющего порядок
// *фиксировать для каждого узла количество повторений
using namespace std;

void handleNumbers()
{
	
	int number = 1;
	setlocale(LC_ALL, "Russian");
	cout << "Введите числа ('0' -- признак конца):" << endl;
	
	LinkedList *myList = new LinkedList();
	
	while (number != 0)
	{
		cin >> number;
		myList->smartInsert(number);
	}
	
	myList->smartPrint();
	
	cout << "Ввод завершён" << endl;
}


int main()
{
	cout << "Manual test" << endl;
	handleNumbers();
}