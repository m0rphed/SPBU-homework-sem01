#include "task-10-graph-of-roads.h"
#include <gtest/gtest.h> // Google Test Framework


struct CountryData
{
	std::vector<Vertex *> AllocatesCities;
};


bool allocateNearestCity(Graph *g, CountryData *c)
{
}


void buildWorld(DataInput *dInput, DataOutput *dOutput)
{
	
	Graph *g = newGraph();
	std::vector<CountryData *> countries;
	
	// Registers two way road with length
	for (int i = 0; i < dInput->roads.size(); ++i)
	{
		DataInputPerRoad road = dInput->roads[i];
		Edge *eForward = addEdge(g, road.cityTo, road.cityFrom);
		eForward->roadLength = road.roadLength;
		Edge *eBackward = addEdge(g, road.cityFrom, road.cityTo);
		eBackward->roadLength = road.roadLength;
	}
	
	// Appends capitals for each country
	for (int i = 0; i < dInput->capitalsPerCountry.size(); ++i)
	{
		CountryData *aCountry = new CountryData();
		Vertex *v = getVertex(g, dInput->capitalsPerCountry[i]);
		aCountry->AllocatesCities.push_back(v);
		countries.push_back(aCountry);
		
	}
	
	bool allocatedAnyCity = false;
	do
	{
		for (int j = 0; j < countries.size(); j++)
		{
			if (allocateNearestCity(g, countries[j]))
			{
				allocatedAnyCity = true;
			}
		}
	} while (allocatedAnyCity);
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}