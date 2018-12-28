#include "dataInput.h"
#include "graph.h"
#include <vector>
#include <iostream>
#include <fstream>


DataInput *readDataInputFromFile(const char *filename)
{
	
	DataInput *di = new DataInput();
	std::ifstream input(filename, std::ios::in);
	
	// Во входном файле: n – число городов и m – число дорог
	input >> di->citiesCount;
	input >> di->roadsCount;
	
	for (int i = 0; i < di->roadsCount; ++i)
	{
		DataInputPerRoad *r = new DataInputPerRoad();
		// Далее следуют сами дороги в формате: i j len, i и j – номера городов, len – длина дороги
		input >> r->cityFrom >> r->roadLength >> r->cityTo;
		di->roads.push_back(*r);
	}
	// Далее задано число k – число столиц, далее – k чисел – номера столиц.
	input >> di->countriesCount;
	for (int j = 0; j < di->countriesCount; ++j)
	{
		int cityNumber;
		input >> cityNumber;
		di->capitalsPerCountry.push_back(cityNumber);
	}
	return di;
}