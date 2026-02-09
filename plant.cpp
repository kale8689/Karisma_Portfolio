#include "plant.h"
#include "startMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> plant::plantsTracker(int plotNumber, string seedType){
    // they pick plot 1, and rice. If no error cases show up. Then "plot1" = "rice"
    if (plotNumber >= 1 && plotNumber <= plantVector.size()) {
        plantVector[plotNumber - 1] = seedType;
    } 
    
    // to check if plantVector is working correctly 
    return plantVector;
}

vector<string> plant::getPlotStatus(){
   // for (int i = 0; i < 9; i++){
     //   cout << plantVector[i] << ", ";
    //}
    //cout << plantVector[9] << ", " << endl;    
    return plantVector;
}


vector<string> plant::readFile(const string fileName){
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

void plant::resetAllPlotsToEmpty() {
    string sourceFile, targetFile;
    for (int i = 1; i <= 10; i++) {
        if(i == 1){
            sourceFile = "emptyPlotOne.txt";
            targetFile = "PlotOne.txt";
        }
        else if(i == 2){
            sourceFile = "emptyPlotTwo.txt";
            targetFile = "PlotTwo.txt";
        }
        else if(i == 3){
            sourceFile = "emptyPlotThree.txt";
            targetFile = "PlotThree.txt";
        }
        else if(i == 4){
            sourceFile = "emptyPlotFour.txt";
            targetFile = "PlotFour.txt";
        }
        else if(i == 5){
            sourceFile = "emptyPlotFive.txt";
            targetFile = "PlotFive.txt";
        }
        else if(i == 6){
            sourceFile = "emptyPlotSix.txt";
            targetFile = "PlotSix.txt";
        }
        else if(i == 7){
            sourceFile = "emptyPlotSeven.txt";
            targetFile = "PlotSeven.txt";
        }
        else if(i == 8){
            sourceFile = "emptyPlotEight.txt";
            targetFile = "PlotEight.txt";
        }
        else if(i == 9){
            sourceFile = "emptyPlotNine.txt";
            targetFile = "PlotNine.txt";
        }
        else if(i == 10){
            sourceFile = "emptyPlotTen.txt";
            targetFile = "PlotTen.txt";
        }

        vector<string> emptyContent = readFile(sourceFile);

        ofstream outFile(targetFile);
        for (const string line : emptyContent) {
            outFile << line << endl;
        }
        outFile.close();
        // resets plantsVector
        plantsTracker(i, "empty");  
    }
}

void plant::plantingSeeds(int plotNumber, string seedType){
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

// static to keep the value after function calls multiple times
int plant::functionplantCount = 0;
// Tracks how many unique plots have been stored
int plant::plotUsedCount = 0;
//static int usedPlots[10];  // Stores up to 10 unique plot numbers
int plant::usedPlots[10] = {0};

bool plant::plotPlantedTracker(int plotNumber, string seedType){ 

    // Check if plotNumber is already used
    for (int i = 0; i < plotUsedCount; i++) {
        if (usedPlots[i] == plotNumber) {
            cout << "Plot " << plotNumber << " has already been used this turn.\n";
            return false;
        }
    }
    if (functionplantCount >= maxPlotsPlant) {
        cout << "You’ve already planted 10 seeds this turn. Wait for the next turn.\n";
        return false;
    }
        
    // Add new plot to usedPlots array
    usedPlots[plotUsedCount] = plotNumber;
    plotUsedCount++;
    functionplantCount++;

    return true;
}

void plant::resetPlotPlantedTracker(){
    functionplantCount = 0;
    plotUsedCount = 0;
    for (int i = 0; i < maxPlotsPlant; i++) {
        usedPlots[i] = 0;
    }
}














