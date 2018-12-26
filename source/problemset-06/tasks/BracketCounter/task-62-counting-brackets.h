#pragma once

#include <string>
#include <utility>

namespace bracketCounter
{
	bool isOpening(const char &bracket);
	
	bool isClosing(const char &bracket);
	
	bool isSameType(const char &opening, const char &closing);
	
	std::string getUserInput();
	
	std::pair<bool, std::string> checkString(std::string input = "");
	
	void startCounting();
}