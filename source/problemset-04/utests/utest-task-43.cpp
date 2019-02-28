#include <gtest/gtest.h> // Google Test Framework
#include "../tasks/task-43-phonebook/task-43-phonebook.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

TEST(task43_phonebook, nameCheck)
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


TEST(task43_phonebook, numbersDoNotExistCheck)
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


TEST(task43_phonebook, checkAddingNewNumber)
{
    const int fixedSize = 100;
    // Define a all I/O file names
    const string fileName = "phoneBook-data.txt";
    const string fileNameOfCopy = "phoneBook-output.txt";

    // Create phone book "database" of records
    Record phoneBook[fixedSize];
    int size = 0;
    processData(fileName, phoneBook, size);

    // Old characters
    map<long long, string> shakespeareHamletCharacters = {
            {4579012213, "Hamlet"},
            {4557536809, "Claudius"},
            {4552866487, "Gertrude"},
            {4529755912, "The Ghost"},
            {4533705154, "Ophelia"},
            {4530493385, "Horatio"},
            {4510385086, "Rosencrantz"}
    };

    // New characters
    map<long long, string> recordsToAdd = {
            {7771235523, "Batman"},
            {8100019191, "Gandalf"},
            {8100019191, "You Shall Not Pass"}, // will not be added to phone book (same phone number)
            {8109919191, "Winnie-the-Pooh"},
    };

    // Add all new characters (new records) to phone book
    for(auto const &record : recordsToAdd)
    {
        addRecord(record.second, record.first, phoneBook, size);
    }

    // Save all
    saveData(fileNameOfCopy, phoneBook, size);

    // Process new patched phone book
    Record phoneBookPatch[fixedSize];
    size = 0;
    processData(fileNameOfCopy, phoneBookPatch, size);

    // Check all new characters
    for (auto const &testCase : recordsToAdd)
    {
        ASSERT_EQ(testCase.second, findName(testCase.first, phoneBookPatch, size));
    }

    // Check all old characters
    for (auto const &testCase : shakespeareHamletCharacters)
    {
        ASSERT_EQ(testCase.second, findName(testCase.first, phoneBookPatch, size));
    }
}