#include <iostream>
#include "startMenu.h"
#include"playerInventory.h"
#include "merchant.h"
#include "plant.h"
#include "harvest.h"

// calling the harvest class
harvest grown;
// calling the plant class
plant garden;
// calling startMenu class
startMenu menu;
//Calling merchant class
merchant merchantMenu;
//Calling player inventory class
playerInventory inventory;

void inGameMenuOption(){
    
    string space = "                                         ";
    cout << "\n\n\n\n";
    cout << "********************************************************" << endl;
    cout << " ^w^w^w^w^w^w^  DEBT HARVESTOR MAIN MENU  ^w^w^w^w^w^w^w" << endl;
    cout << "********************************************************" << endl;
    cout << "Your current debt is: $"<<inventory.getDebt() << endl;
    cout << "Saved Money is: $"<<inventory.getSavings() << endl;
    cout << "Turn: " << grown.getTurnNumber() << "/10" << endl;
    cout << "********************************************************" << endl;
    cout << "Press 1 to open inventory" << endl;
    cout << "Press 2 to talk to merchant" << endl;
    cout << "Press 3 to plant" << endl;
    cout << "Press 4 to harvest" << endl;
    cout << "Press 5 to end your turn" << endl;
    cout << "Press 6 to quit" << endl;
    cout << "********************************************************" << endl;

    int option = 0;
        cin >> option;
        switch(option){
            case 1:
                //Inventory()
                inventory.displayInventoryMenu();
                break;
            case 2:
                //Merchant()
                // inventory equalled into merchant function to update values
                inventory = merchantMenu.displayMerchant(inventory);
                break;
            case 3:
                //planting();
                char choice;
                do {
//////////////////////////////////////////////////////////////////////
            int plotNumber;
            string seedType;
            int riceSeed = 0, pineappleSeed = 0, bananaSeed = 0, dragonSeed = 0, grapeSeed = 0;
            string Rice = "Rice", Banana = "Banana", Grape = "Grape", Pineapple = "Pineapple", Dragonfruit = "Dragonfruit";

            cout << "What plot do you want to plant?" << endl;
            cin >> plotNumber;
             if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 10.\n";
                return;
             }
            else if(plotNumber < 0 || plotNumber > 10){
                cout << "Invalid plot number, pick from 1 -10." << endl;
                return;
            }
            

            cout << "What seeds do you want to plant?" << endl;
            cin >> seedType;

            if (seedType == "rice") {
                riceSeed = inventory.getSeeds(Rice);
                if(riceSeed <= 0){
                    cout << "You do not have enough rice seeds." << endl;
                }
            else{ 
                    seedType += "Seed.txt";
                    // makes sure you cannot plot in a plot twice
                    if(garden.plotPlantedTracker(plotNumber, seedType) == true){
                    // prints out plots
                    garden.plantingSeeds(plotNumber, seedType);
                    inventory.loseSeeds(Rice, 1);
                    cout << "You have planted a rice seed in plot " << plotNumber << endl;
                    // puts what plants in an array
                    garden.plantsTracker(plotNumber, seedType);
                    }
                }
            }
            else if (seedType == "banana") {
                bananaSeed = inventory.getSeeds(Banana);
                if(bananaSeed <= 0){
                    cout << "You do not have enough banana seeds." << endl;
                    return;
                }
                else{ 
                    seedType += "Seed.txt";
                    if(garden.plotPlantedTracker(plotNumber, seedType) == true){
                    garden.plantingSeeds(plotNumber, seedType);
                    inventory.loseSeeds(Banana, 1);
                    cout << "You have planted a banana seed in plot " << plotNumber << endl;
                    garden.plantsTracker(plotNumber, seedType);
                    }
                }
            }
            else if (seedType == "grape") {
                grapeSeed = inventory.getSeeds(Grape);
                if(grapeSeed <= 0){
                    cout << "You do not have enough grape seeds." << endl;
                    return;
                }
                else{ 
                    seedType += "Seed.txt";
                    if(garden.plotPlantedTracker(plotNumber, seedType) == true){
                    garden.plantingSeeds(plotNumber, seedType);
                    inventory.loseSeeds(Grape, 1);
                    cout << "You have planted a grape seed in plot " << plotNumber << endl;
                    garden.plantsTracker(plotNumber, seedType);
                    }
                }
            }
            else if (seedType == "pineapple") {
                pineappleSeed = inventory.getSeeds(Pineapple);
                if(pineappleSeed <= 0){
                    cout << "You do not have enough pineapple seeds." << endl;
                    return;
                }
                else{ 
                    seedType += "Seed.txt";
                    if(garden.plotPlantedTracker(plotNumber, seedType) == true){
                    garden.plantingSeeds(plotNumber, seedType);
                    inventory.loseSeeds(Pineapple, 1);
                    cout << "You have planted a banana seed in plot " << plotNumber << endl;
                    garden.plantsTracker(plotNumber, seedType);
                    }
                }
            }
            else if (seedType == "dragonfruit") {
                dragonSeed = inventory.getSeeds(Dragonfruit);
                if(dragonSeed <= 0){
                    cout << "You do not have enough dragonfruit seeds." << endl;
                    return;
                }
            else{ 
                    seedType += "Seed.txt";
                    if(garden.plotPlantedTracker(plotNumber, seedType) == true){
                    garden.plantingSeeds(plotNumber, seedType);
                    inventory.loseSeeds(Dragonfruit, 1);
                    cout << "You have planted a dragonfruit seed in plot " << plotNumber << endl;
                    garden.plantsTracker(plotNumber, seedType);
                    }
                }
            }
            else {
                cout << "Invalid seed type! Type 'rice' or 'dragonfruit' or 'pineapple' or 'grape' or 'banana'" << endl;
            }
            if(riceSeed == 0 && pineappleSeed == 0 && dragonSeed == 0 && bananaSeed == 0 && grapeSeed == 0){
                cout << "You have no seeds to plant. No more planting for you!" << endl;
            }
/////////////////////////////////////////////////////////////////////
                    cout << "Plant again this turn? (y/n): ";
                    cin >> choice;
                    while (choice != 'y' && choice != 'n') {
                    cout << "Invalid input. Please enter 'y' or 'n': ";
                    cin >> choice;
                }
                } while (choice == 'y');
                break;
            case 4:{
                // harvesting():
                // if turn 1, make it so this feature cannot be accessed
                char choice;
                int plotNumber = 0;
                int turn = 0;
                turn = grown.getTurnNumber();
                do{
                    if(turn==1){
                    cout << "Your crops are still seeds! You need to end the turn for them to grow." << endl;
                    return;
                    }
                    else{
                    string empty = "empty";
                    cout << "What plot do you want to harvest?" << endl;
                    cin >> plotNumber;
                    if (cin.fail()) {
                    cin.clear(); // Clear error flags
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a number between 1 and 10.\n";
                        return;
                    }
                    // reads vector from plant class and stores in readVector
                    vector<string> readVector = garden.getPlotStatus();
                    // harvestingPlants function to change plots
                    grown.harvestingPlants(plotNumber, readVector);
                    // anything harvested is then updated in inventory
                    inventory.addPlants(readVector, plotNumber);
                    // updates what was harvested to empty in the readVector
                    garden.plantsTracker(plotNumber, empty);
                    }
                } while (choice == 'y');
                break; }
            case 5:{
                //end turn();
                //when ending your turn, the seeds will turn into crops, so I put the grow function here
                vector<string> readVector = garden.getPlotStatus(); // from plant
                grown.getHarvestPlotStatus(readVector);
                vector<string> seedToPlantVector = grown.getHarvestPlotStatus(readVector);
                grown.seedToPlant(seedToPlantVector);
                int turn = 1;
                grown.turnNumberIncrement();
                garden.resetPlotPlantedTracker();
                break;}
            case 6:
                cout << "Quitting Game." << endl;
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }

}

int main(){

// initialzing all the values before the start of game
    garden.resetAllPlotsToEmpty();
    garden.resetPlotPlantedTracker();

// starting up the game use g++ -std=c++17 harvest.cpp plant.cpp startMenu.cpp playerInventory.cpp merchant.cpp driver.cpp
// and ./a.out
// .\driver.cpp .\merchant.cpp .\playerInventory.cpp .\plant.cpp .\harvest.cpp .\startMenu.cpp
// start menu should be a big do while 
    menu.displayMenu();
    int turn = 0;
    turn = grown.getTurnNumber();
    do{
    inGameMenuOption();

    if((inventory.getDebt() > inventory.getSavings()) && grown.getTurnNumber() == 10){
        const string RED = "\033[31m";
    
    cout << "\n\n\n\n\n\n\n";
    cout << RED;
    cout << R"(
                        ▒█░░▒█ ▒█▀▀▀█ ▒█░▒█ 　 ▒█░░░ ▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▀▀ █ █ 
                        ▒█▄▄▄█ ▒█░░▒█ ▒█░▒█ 　 ▒█░░░ ▒█░░▒█ ░▀▀▀▄▄ ▒█▀▀▀ ▀ ▀ 
                        ░░▒█░░ ▒█▄▄▄█ ░▀▄▄▀ 　 ▒█▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ ▒█▄▄▄ ▄ ▄ 

▀▀█▀▀ █▀▀█ 　 ▒█▀▀█ ▒█▀▀█ ▀█▀ ▒█▀▀▀█ ▒█▀▀▀█ ▒█▄░▒█ 　 ▒█░░▒█ ▀█▀ ▀▀█▀▀ ▒█░▒█ 　 ▒█░░▒█ ▒█▀▀▀█ ▒█░▒█ █ █ 
░▒█░░ █░░█ 　 ▒█▄▄█ ▒█▄▄▀ ▒█░ ░▀▀▀▄▄ ▒█░░▒█ ▒█▒█▒█ 　 ▒█▒█▒█ ▒█░ ░▒█░░ ▒█▀▀█ 　 ▒█▄▄▄█ ▒█░░▒█ ▒█░▒█ ▀ ▀ 
░▒█░░ ▀▀▀▀ 　 ▒█░░░ ▒█░▒█ ▄█▄ ▒█▄▄▄█ ▒█▄▄▄█ ▒█░░▀█ 　 ▒█▄▀▄█ ▄█▄ ░▒█░░ ▒█░▒█ 　 ░░▒█░░ ▒█▄▄▄█ ░▀▄▄▀ ▄ ▄)" <<endl;








    cout << "                                            LOAN SHARK" << endl;
    cout << "                                            _________" << endl;
    cout << "                                       |                |" << endl;
    cout << "                                       |                |" << endl;
    cout << "                                   _ __|                |____                     WHERE'S MY MONEY???" << endl;
    cout << "                                    |—-----------------------|" << endl;
    cout << "                                      |   \\            /  |" << endl;
    cout << "                                      |  |_|       |_|     |" << endl;
    cout << "                                      |         w          |" << endl;
    cout << "                                      |____________________|" << endl;
    cout << "          \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                \\\\\\s\\\\\\             \\\\\\\\\\\\\\\\ ----" << endl;
    cout << "                  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ -----" << endl;
    cout << "                         \\\\\\\\\\\\\\\\\\           ||||||                  \\\\\\\\\\\\\\\\\\" << endl;
    cout << "                     \\\\\\\\\\\\\\\\\\                ||||                           \\\\\\\\\\\\\\" << endl;
    cout << "              \\\\\\\\\\\\\\                         ||||                               \\\\\\\\\\\\\\ -----" << endl;
    cout << "                     \\\\\\\\\\                _ __|||____                                     \\\\\\\\\\" << endl;
    cout << "                         M               _|              |_                                     M" << endl;


    break;
    }


    else if((inventory.getDebt() < inventory.getSavings()) && grown.getTurnNumber() == 10){
        cout << R"(
                ██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗██╗██╗  
                ╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║██║██║  
                ░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║██║██║  
                ░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║╚═╝╚═╝  
                ░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║██╗██╗  
                ░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝╚═╝  

                ██████╗░███████╗██████╗░████████╗  ███████╗██████╗░███████╗███████╗██╗██╗
                ██╔══██╗██╔════╝██╔══██╗╚══██╔══╝  ██╔════╝██╔══██╗██╔════╝██╔════╝██║██║
                ██║░░██║█████╗░░██████╦╝░░░██║░░░  █████╗░░██████╔╝█████╗░░█████╗░░██║██║
                ██║░░██║██╔══╝░░██╔══██╗░░░██║░░░  ██╔══╝░░██╔══██╗██╔══╝░░██╔══╝░░╚═╝╚═╝
                ██████╔╝███████╗██████╦╝░░░██║░░░  ██║░░░░░██║░░██║███████╗███████╗██╗██╗
                ╚═════╝░╚══════╝╚═════╝░░░░╚═╝░░░  ╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚══════╝╚═╝╚═╝)"<<endl;
                break;
    }

    }while(turn != 10);

}

