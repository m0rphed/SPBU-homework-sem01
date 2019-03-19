#pragma once

#include "HashTable.h"
#include <string>

std::vector<std::pair<KeyType, int>> countFrequencyOfWords(HashTable *wordsFrequencies, const int &baseSize, const std::string &fileName);
