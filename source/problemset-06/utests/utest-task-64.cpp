#include "../tasks/MergeSort/List.h"
#include "../tasks/MergeSort/task-64-merge-sort.h"

#include <iostream>
#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(task64, mergeSortTest)
{
    auto *list = processData("data.txt");
    list->printList();

    mergeSort(list, false);
    list->printList();

    delete list;
    SUCCEED();
}
