#include "harvest.h"
#include "plant.h"
#include "startMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> harvest::harvestsTracker(int plotNumber, string seedType, vector<string> readVector){
    // they pick plot 1, and rice. If no error cases show up. Then "plot1" = "rice"
    if (plotNumber >= 1 && plotNumber <= readVector.size()) {
        readVector[plotNumber - 1] = seedType;
    } 
    // to check if plantVector is working correctly 
    return readVector;
}

vector<string> harvest::getHarvestPlotStatus(vector<string> readVector){
  /* for (int i = 0; i < 9; i++){
        cout << readVector[i] << ", ";
    }
    cout << readVector[9] << ", " << endl;    */
    return readVector;
}

void harvest::harvestingPlants(int plotNumber, vector<string> readVector) {

    if (readVector[plotNumber-1] == "empty"){
        cout << "There is nothing to harvest." << endl;
        return;
    }

    string seedType = readVector[plotNumber-1];
    // removing Seed.txt  
    size_t pos = seedType.find("Seed.txt");
    if (pos != string::npos) {
        seedType = seedType.substr(0, pos);  // removes "Seed.txt"
    }
    cout << "You are harvesting plot " << plotNumber << " and now you have 1 " << seedType << endl;


    // or statments of all different seed types
    if (readVector[plotNumber-1] == "riceSeed.txt" || readVector[plotNumber-1] == "grapeSeed.txt" ||
        readVector[plotNumber-1] == "pineappleSeed.txt" || readVector[plotNumber-1] == "dragonfruitSeed.txt"
        || readVector[plotNumber-1] == "bananaSeed.txt"){
        // if plotNumber == 1 then "emptyPlotOne.txt" for all ten plots
        if(plotNumber == 1){
        growingSeeds(plotNumber, "emptyPlotOne.txt"); // Modify that plant object
        }
        else if(plotNumber == 2) growingSeeds(plotNumber, "emptyPlotTwo.txt");
        else if(plotNumber == 3) growingSeeds(plotNumber, "emptyPlotThree.txt");
        else if(plotNumber == 4) growingSeeds(plotNumber, "emptyPlotFour.txt");
        else if(plotNumber == 5) growingSeeds(plotNumber, "emptyPlotFive.txt");
        else if(plotNumber == 6) growingSeeds(plotNumber, "emptyPlotSix.txt");
        else if(plotNumber == 7) growingSeeds(plotNumber, "emptyPlotSeven.txt");
        else if(plotNumber == 8) growingSeeds(plotNumber, "emptyPlotEight.txt");
        else if(plotNumber == 9) growingSeeds(plotNumber, "emptyPlotNine.txt");
        else if(plotNumber == 10) growingSeeds(plotNumber, "emptyPlotTen.txt");
    }
    readVector[plotNumber - 1] = "empty";
}

void harvest::seedToPlant(vector<string> readVector){
    // for loop or read the plot 1 - 10 files using plantVector
    // if have seed files in them turn them into plant files
    // if do not have seed files leave them alone

    int plotNumber = 0;
    for(int i = 0; i < readVector.size(); i++){
        if(readVector[i] == "riceSeed.txt"){
            growingSeeds(i+1, "ricePlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(readVector[i] == "grapeSeed.txt"){
            growingSeeds(i+1, "grapePlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(readVector[i] == "bananaSeed.txt"){
            growingSeeds(i+1, "bananaPlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(readVector[i] == "pineappleSeed.txt"){
            growingSeeds(i+1, "pineapplePlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(readVector[i] == "dragonfruitSeed.txt"){
            growingSeeds(i+1, "dragonfruitPlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
    }
    cout << "Everything has grown! Look at your beautiful garden ~" << endl;
}

void harvest::growingSeeds(int plotNumber, string seedType){
    // initialize file names
    string fileNameOne = "PlotOne.txt", fileNameTwo = "PlotTwo.txt", fileNameThree = "PlotThree.txt",
    fileNameFour = "PlotFour.txt", fileNameFive = "PlotFive.txt", fileNameSix = "PlotSix.txt",
    fileNameSeven = "PlotSeven.txt", fileNameEight = "PlotEight.txt", fileNameNine = "PlotNine.txt",
    fileNameTen = "PlotTen.txt";

    // read the seedType file contents
    vector<string> seedData = readFile(seedType);
    if (seedData.empty()) {
        cerr << "Syntax error, please write your seedType like 'rice or 'pineapple' " << endl;
        return;
    }

    // write to the correct plot file based on plotNumber
    ofstream outFile;
    if(plotNumber == 1){
        outFile.open(fileNameOne);
    }
    else if(plotNumber == 2){
        outFile.open(fileNameTwo);
    }
    else if(plotNumber == 3){
        outFile.open(fileNameThree);
    }
    else if(plotNumber == 4){
        outFile.open(fileNameFour);
    }
    else if(plotNumber == 5){
        outFile.open(fileNameFive);
    }
    else if(plotNumber == 6){
        outFile.open(fileNameSix);
    }
    else if(plotNumber == 7){
        outFile.open(fileNameSeven);
    }
    else if(plotNumber == 8){
        outFile.open(fileNameEight);
    }
    else if(plotNumber == 9){
        outFile.open(fileNameNine);
    }
    else if(plotNumber == 10){
        outFile.open(fileNameTen);
    }
    else {
        cerr << "Invalid plot number. Please write a correct one." << endl;
        return;
    }

    if (!outFile.is_open()) {
        cerr << "Failed to open plot file for writing." << endl;
        return;
    }

    // write the seed data to the selected plot
    for (const string line : seedData) {
        outFile << line << endl;
    }
    outFile.close();

    // read from all the files again to display the updated plots
    vector<string> plot1 = readFile(fileNameOne);
    vector<string> plot2 = readFile(fileNameTwo);
    vector<string> plot3 = readFile(fileNameThree);
    vector<string> plot4 = readFile(fileNameFour);
    vector<string> plot5 = readFile(fileNameFive);
    // next row
    vector<string> plot6 = readFile(fileNameSix);
    vector<string> plot7 = readFile(fileNameSeven);
    vector<string> plot8 = readFile(fileNameEight);
    vector<string> plot9 = readFile(fileNameNine);
    vector<string> plot10 = readFile(fileNameTen);
    
    if (plot1.empty() || plot2.empty() || plot3.empty() || plot4.empty() || plot5.empty() ||
        plot6.empty() || plot7.empty() || plot8.empty() || plot9.empty() || plot10.empty()) {
        cerr << "One of the files is empty or failed to read." << endl;
    }

    // print plots next to each other
    for(int i = 0; i < plot1.size(); i++){
        printf("%s %s %s %s %s\n", plot1[i].c_str(), plot2[i].c_str(), plot3[i].c_str(), plot4[i].c_str(), plot5[i].c_str());
    }
    for(int i = 0; i < plot6.size(); i++){
        printf("%s %s %s %s %s\n", plot6[i].c_str(), plot7[i].c_str(), plot8[i].c_str(), plot9[i].c_str(), plot10[i].c_str());
    }  
}

vector<string> harvest::readFile(const string fileName){
    ifstream file(fileName);
    vector<string> contents;

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << fileName << endl;
        return contents;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            istringstream iss(line);
            string tmp;
            iss >> tmp;
            contents.push_back(tmp);
        }
    }
    return contents;
}

void harvest::turnNumberIncrement(){
        turn++;
}

int harvest::getTurnNumber(){
    return turn;
}