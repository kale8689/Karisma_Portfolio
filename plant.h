#ifndef PLANT_H
#define PLANT_H
#include<vector>
#include<string>
using namespace std;

class startMenu;

class plant{
public:
// readfile function
vector<string> readFile(const string fileName);
// show (void) initialized plots no plants function
void resetAllPlotsToEmpty();
// planting function
void plantingSeeds(int plotNumber,string seedType);
// function that only allows person to plant on one plot, keeps running count 
bool plotPlantedTracker(int plotNumber, string seedType);
// resets plot tracker at new turn
void resetPlotPlantedTracker();
// vector tracker to know what plants are in what plot
vector<string> plantsTracker(int plotNumber, string seedType);
// return plantVector
vector<string> getPlotStatus();


private: 
    static int functionplantCount;
    static int plotUsedCount;
    static int usedPlots[10];
    static const int maxPlotsPlant = 10;
    vector<string> plantVector = {"empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty",
    "empty", "empty"};
};
#endif