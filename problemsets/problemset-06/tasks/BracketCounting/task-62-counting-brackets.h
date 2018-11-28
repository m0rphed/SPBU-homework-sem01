#pragma once


namespace bracketCounter
{
	bool isOpening(const char &bracket);
	
	bool isClosing(const char &bracket);
	
	bool isSameType(const char &opening, const char &closing);
}