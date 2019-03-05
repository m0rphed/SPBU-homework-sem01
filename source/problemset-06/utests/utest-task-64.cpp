#include "../tasks/MergeSort/List.h"
#include "../tasks/MergeSort/task-64-merge-sort.h"

#include <iostream>
#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(task64, mergeSortTest)
{
    auto *list = processData("data.txt");
    list->printList();

    cout << "\nSort by phone number" << endl;
    mergeSort(list, false);
    list->printList();
    saveData(list, "data-by-number.txt");

    cout << "\nSort by name" << endl;
    mergeSort(list);
    list->printList();
    saveData(list, "data-by-name.txt");

    delete list;
    SUCCEED();
}
