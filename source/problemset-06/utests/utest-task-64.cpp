#include "../tasks/MergeSort/DoublyLinkedList.h"
#include "../tasks/MergeSort/task-64-merge-sort.h"
#include <iostream>
#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(task64, mergeSortTest)
{
    auto *list = new DoublyLinkedList();
    processData(list);
    list->printList();

    mergeSort(list);
    list->printList();
	FAIL();
}
