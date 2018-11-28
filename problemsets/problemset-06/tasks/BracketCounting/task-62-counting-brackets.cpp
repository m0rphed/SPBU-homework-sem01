#include "../LastInFirstOut.h"
#include "task-62-counting-brackets.h"


bool bracketCounter::isOpening(const char &bracket)
{
	return bracket == '(' || bracket == '[' || bracket == '{';
}


bool bracketCounter::isClosing(const char &bracket)
{
	return bracket == ')' || bracket == ']' || bracket == '}';
}


bool bracketCounter::isSameType(const char &opening, const char &closing)
{
	return (opening == '(' && closing == ')') ||
	       (opening == '[' && closing == ']') ||
	       (opening == '{' && closing == '}');
}
