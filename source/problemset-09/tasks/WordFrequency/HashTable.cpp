#include "HashTable.h"
#include <iostream>

using namespace std;

unsigned int HashTable::hashFunction(const std::string &input)
{
    const int parameter = 25;
    unsigned int result = 0;
    for (auto character : input)
    {
        result = (result + int(character)) % parameter;
    }
    return result;
}
