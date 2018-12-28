#pragma once

#include <string>

struct Record
{
	std::string name;
	long phoneNumber = 0;
};

void processData(const std::string &filename, Record *phoneBook, int &size);

void saveData(const std::string &filename, Record *phoneBook, const int &size);

void addRecord(const std::string &newName, const long &newNumber, Record *phoneBook, int &size);

std::string findName(const long &number, const Record *phoneBook, const int &size);

long findNumber(const std::string &name, const Record *phoneBook, const int &size);

void printAll(const Record *phoneBook, const int &size);

void phoneBookUserInterface();
