#include "task-72-parsing-tree.h"

#include <set>

using namespace std;

vector<char> sanitizeInput(const string &input)
{
    set<char> allowedSymbols = {'+', '-', '*', '/', '(', ')'};
    vector<char> result;

    for (char character : input)
    {
        // Check if value not in set
        if (allowedSymbols.find(character) != allowedSymbols.end())
        {
            result.push_back(character);
        }
    }
    return result;
}
