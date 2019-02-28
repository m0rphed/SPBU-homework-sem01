#pragma once

#include "../LastInFirstOut.h"
#include <string>

bool isOperator(const char &operand);

int priority(const char &operand);

std::string toPostfix(const std::string &infix);

void handleIO(std::string infix = "");