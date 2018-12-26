#pragma once

#include "../LastInFirstOut.h"
#include <string>

using namespace std;

bool isOperator(const char &operand);

int priority(const char &operand);

string toPostfix(const string &infix);

void handleIO(string infix = "");