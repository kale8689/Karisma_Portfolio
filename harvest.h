#ifndef HARVEST_H
#define HARVEST_H
#include<vector>
#include<string>
#include "plant.h"
using namespace std;

class startMenu;

class harvest{
public:
// function to update all seed images to harvest images
void seedToPlant(vector<string> readVector);
// pick the plotnumber
void harvestingPlants(int plotNumber, vector<string> readVector);
// getter
vector<string> getHarvestPlotStatus(vector<string> readVector);
// tracking vector
vector<string> harvestsTracker(int plotNumber, string seedType, vector<string> readVector);
// planting function but for harvest
void growingSeeds(int plotNumber, string seedType);
// read file
vector<string> readFile(const string fileName);
void turnNumberIncrement();
int getTurnNumber();
private:
int turn =1;
};

#endif