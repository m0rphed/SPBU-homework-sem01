#include "bossFight-task01.h"
#include "dataStructures/LinkedList.h"
#include <iostream>
#include <locale>

// Написать программу, которая ВВОДИТ с клавиатуры набор целых чисел
// (в любом порядке, конец — число 0),
// и ВЫВОДЯЩУЮ числа из этого набора в порядке возрастания и без повторений,
// с указанием того, сколько каждое число раз встретилось в этом наборе.

// My Notes:
// Буду решать с помщью связного списка, с добавлением не нарушаеющего порядок
// *фиксировать для каждого узла количество повторений


void handleNumbers()
{
	using namespace std;
	int number = 1;
	setlocale(LC_ALL, "Russian");
	cout << "Введите числа ('0' -- признак конца):" << endl;
	
	auto *myList = new LinkedList();
	
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