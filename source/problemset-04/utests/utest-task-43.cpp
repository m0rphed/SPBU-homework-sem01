#include <gtest/gtest.h> // Google Test Framework
#include "../tasks/task-43-phonebook/task-43-phonebook.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

TEST(problemset04, phonebookTest_NameCheck)
{
    const int fixedSize = 100;
    // Define a all I/O file names
    const string fileName = "phoneBook-data.txt";
    // const string fileNameOut = "phoneBook-output.txt";

    // Create phone book "database" of records
    Record phoneBook[fixedSize];
    int size = 0;
    processData(fileName, phoneBook, size);


    map<long long, string> shakespeareHamletCharacters = {
            {4579012213, "Hamlet"},
            {4557536809, "Claudius"},
            {4552866487, "Gertrude"},
            {4529755912, "The Ghost"},
            {4533705154, "Ophelia"},
            {4530493385, "Horatio"},
            {4510385086, "Rosencrantz"}
    };

    map<long long, string> shakespeareMacbethCharacters = {
            {1234567891, "Duncan"},
            {1244567891, "Lady Macbeth"},
            {1237777891, "Seyton"},
    };

    for (auto const &testCase : shakespeareMacbethCharacters)
    {
        ASSERT_NE(testCase.second, findName(testCase.first, phoneBook, size));
    }

    for (auto const &testCase : shakespeareHamletCharacters)
    {
        ASSERT_EQ(testCase.second, findName(testCase.first, phoneBook, size));
    }
}

TEST(problemset04, phonebookTest_NumberDoNotExistCheck)
{
    const int fixedSize = 100;
    // Define a all I/O file names
    const string fileName = "phoneBook-data.txt";
    // const string fileNameOut = "phoneBook-output.txt";

    // Create phone book "database" of records
    Record phoneBook[fixedSize];
    int size = 0;
    processData(fileName, phoneBook, size);


    vector<string> bunchOfActors = {
            "Robert De Niro",
            "Tom Hanks",
            "Marlon Brando"
    };

    for (auto const &testCase : bunchOfActors)
    {
        ASSERT_EQ(-1, findNumber(testCase, phoneBook, size));
    }
}