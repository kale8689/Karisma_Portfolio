#include <iostream>
#include "startMenu.h"
#include "plant.h"
#include "harvest.h"

int main(){

// calling the harvest class
harvest grown;
// calling the plant class
plant garden;
// calling startMenu class
startMenu menu;

// initialzing all the values before the start of game
garden.resetAllPlotsToEmpty();
garden.resetPlotPlantedTracker();

// starting up the game use g++ -std=c++17 harvest.cpp plant.cpp startMenu.cpp testPlay.cpp and ./a.out
menu.displayMenu();
}




/*// g++ harvest.cpp plant.cpp testPlay.cpp
harvest harvesting;
plant myGarden;
//harvesting.harvestInterface();
//harvesting.seedToPlant(myGarden);
myGarden.initializedPlots();
*/


// g++ plant.cpp testPlay.cpp
/*plant planting;
    char choice;
do {
    planting.plantInterface();
    cout << "Plant again this turn? (y/n): ";
    cin >> choice;
} while (choice == 'y'); */

/*planting.initializedPlots();
int plotNumber = 0;
string seedType = "";
            cout << "What plot do you want to plant?" << endl;
            cin >> plotNumber;
            cout << "What seeds you want to plant?" << endl;
            cin >> seedType;
            seedType = seedType + ".txt";
            planting.plantingSeeds(plotNumber, seedType);


/*code to start the menu // g++ startMenu.cpp testPlay.cpp
startMenu menu;
menu.displayMenu();
return 0;
*/

/* code to display art // g++ art.cpp testPlay.cpp
    art pee;
    pee.pineapplePlant();
    pee.grapePlant();
*/

//code to open the inventory // g++ inventory.cpp testPlay.cpp
//invent.initializeDefault();
//invent.addQuantity("Pineapple Seeds", 3);
//invent.saveInventory();
/*Inventory invent;
invent.initializeDefault();
invent.addQuantity("Rice_Seeds", 10);
invent.addQuantity("Pineapple_Seeds", 3);
invent.openInventory();
invent.saveInventory();

code to start the menu // g++ startMenu.cpp testPlay.cpp
startMenu menu;
menu.displayMenu();
return 0;
*/

