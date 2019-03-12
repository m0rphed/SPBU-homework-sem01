#include "../tasks/DictionaryOnAVLtree/Dictionary.h"
#include <gtest/gtest.h> // Google Test Framework
#include <vector>
#include <utility>

using namespace std;

TEST(task81, standardTest)
{
    auto *testDictionary = new AVLTree();

    vector<pair<string, string>> testCases = {{"Bart",           "Skateboard"},
                                              {"Lisa",           "Saxophone"},
                                              {"Homer",          "Donuts"},
                                              {"Marge",          "Strange haircut"},
                                              {"Homer",          "Bottle of cheap beer"},
                                              {"Lisa",           "Depressive Russian Literature"},
                                              {"Maggie Simpson", "Her favourite toy"}};

    for (auto const &testCase : testCases)
    {
        testDictionary->add(testCase.first, testCase.second);
    }

    vector<pair<string, string>> expected = {{"Bart",           "Skateboard"},
                                             {"Marge",          "Strange haircut"},
                                             {"Homer",          "Bottle of cheap beer"},
                                             {"Lisa",           "Depressive Russian Literature"},
                                             {"Maggie Simpson", "Her favourite toy"}};

    for (auto const &testCase : expected)
    {
        ASSERT_EQ(testCase.second, testDictionary->findNode(testCase.first));
    }

    // destructor will be called
    delete testDictionary;

}

TEST(taask81, noSuchKeys)
{
    vector<string> notExisted = {"Sherri and Terri", "Nelson", "Ned Flanders", "Seymour Skinner", "Montgomery Burns"};

    auto *testDictionary = new AVLTree();

    vector<pair<string, string>> validCases = {{"Moe Szyslak",   "A grumpy bartender"},
                                               {"Barney Gumble", "One of Homer's friends, a gifted alcoholic"},
                                               {"Homer",         "Likes Donuts"},
                                               {"Ralph Wiggum",  "the weird son of Chief Wiggum."}};

    for (auto const &testCase : validCases)
    {
        testDictionary->add(testCase.first, testCase.second);
    }

    for (auto const &testCase : notExisted)
    {
        ASSERT_FALSE(testDictionary->exists(testCase));
    }

    // destructor will be called
    delete testDictionary;
}
