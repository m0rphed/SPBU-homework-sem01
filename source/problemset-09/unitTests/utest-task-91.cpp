#include "../tasks/WordFrequency/task-91-count-word-frequency.h" // actual problem solution
#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(task91, wordFrequencyTest)
{
	auto *table = new HashTable(standardBaseSize);
	vector<pair<KeyType, int>> result = countFrequencyOfWords(table, standardBaseSize, "data.txt");
}
