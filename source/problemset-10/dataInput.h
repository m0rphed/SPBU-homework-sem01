#pragma once

#include <vector>

struct DataInputPerRoad
{
	int cityFrom;
	int cityTo;
	int roadLength;
};

struct DataInput
{
	int countriesCount;
	int roadsCount;
	int citiesCount;
	std::vector<DataInputPerRoad> roads;
	std::vector<int> capitalsPerCountry;
};

DataInput *readDataInputFromFile(const char *filename);
