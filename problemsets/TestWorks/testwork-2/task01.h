#pragma once

#include "dataStructures.h"
#include <fstream>
#include <string>

// Даны числа a и b.
// За один просмотр файла f, элементами которого являются целые числа,
// и без использования дополнительных файлов переписать его элементы в файл g так,
// чтобы первоначально были записаны все числа,
// меньше заданного a, затем все числа из отрезка [a,b],
// затем все остальные.
// Взаимный порядок в каждой из групп должен быть сохранен,
// предположений о количестве элементов делать нельзя
// (пользоваться контейнерами из стандартной библиотеки – тоже).

namespace task01
{
	void processData(std::ifstream &file, int a, int b, testWorkList::Node *lower, testWorkList::Node *inSection, testWorkList::Node *higher);
	
	void letsListSomeData(const int &a, const int &b);
}