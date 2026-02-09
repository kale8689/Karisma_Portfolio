#include<iostream>
#include<vector>
#include<algorithm>
#include"playerInventory.h"
#include<string>

using namespace std;


void playerInventory:: displayInventoryMenu(){
    
    //Need fucntion call that recieves data from merchant including buy or sell
    //Needs to have getters and setters that modify the player income everytime this fucntion gets called
    //need function call that gets and sets every type of plant and seed 
    //Needs some day function that always increments by +1 whenever 5 is clicked inside the in game menu function
    //use this day function to dteermine what to print out from the harvest fucntion
    
    cout << "Welcome to your inventory!"<<endl;
    cout << "\n\n\n";
    cout <<"Your current amount saved is $"<<savings<<endl;
    cout <<"Your current debt is "<<playerDebt<<endl;
    cout << "Here's a list of your current plants and seeds"<<endl;
    cout <<"You have "<<riceSeeds<<" rice seeds."<<endl;
    cout <<"You have "<<dragonSeeds<<" dragonfruit seeds."<<endl;
    cout <<"You have "<<pineappleSeeds<<" pineapple seeds."<<endl;
    cout <<"You have "<<bananaSeeds<<" banana seeds."<<endl;
    cout <<"You have "<<grapeSeeds<<" grape seeds."<<endl;
    cout <<"You have "<<ricePlants<<" rice plants."<<endl;
    cout <<"You have "<<dragonPlants<<" dragonfruit plants."<<endl;
    cout <<"You have "<<pineapplePlants<<" pineapple plants."<<endl;
    cout <<"You have "<<bananaPlants<<" banana plants."<<endl;
    cout <<"You have "<<grapePlants<<" grape plants."<<endl;
}

void playerInventory::addSeeds(string seedName, int quantity) {
        if (seedName == "Rice") {
            riceSeeds += quantity;
        } else if (seedName == "Dragonfruit") {
            dragonSeeds += quantity;
        } else if (seedName == "Pineapple") {
            pineappleSeeds += quantity;
        } else if (seedName == "Banana") {
            bananaSeeds += quantity;
        } else if (seedName == "Grape") {
            grapeSeeds += quantity;
        }
    }

void playerInventory::losePlants(string plantName, int quantity) {
        if (plantName == "Rice") {
            ricePlants -= quantity;
        } else if (plantName== "Dragonfruit") {
            dragonPlants -= quantity;
        } else if (plantName == "Pineapple") {
            pineapplePlants -= quantity;
        } else if (plantName == "Banana") {
            bananaPlants -= quantity;
        } else if (plantName == "Grape") {
            grapePlants -= quantity;
        }
    }

void playerInventory::addPlants(vector<string> readVectorPlant, int i) {   
    if (readVectorPlant[i-1] == "riceSeed.txt") {
            ricePlants += 1;
        } else if (readVectorPlant[i-1]== "dragonfruitSeed.txt") {
            dragonPlants += 1;
        } else if (readVectorPlant[i-1] == "pineappleSeed.txt") {
            pineapplePlants += 1;
        } else if (readVectorPlant[i-1] == "bananaSeed.txt") {
            bananaPlants += 1;
        } else if (readVectorPlant[i-1] == "grapeSeed.txt") {
            grapePlants += 1;
        }
    }

void playerInventory::loseSeeds(string seedName, int quantity) {
        if (seedName == "Rice") {
            riceSeeds -= quantity;
        } else if (seedName == "Dragonfruit") {
            dragonSeeds -= quantity;
        } else if (seedName == "Pineapple") {
            pineappleSeeds -= quantity;
        } else if (seedName == "Banana") {
            bananaSeeds -= quantity;
        } else if (seedName == "Grape") {
            grapeSeeds -= quantity;
        }
    }


int playerInventory::getPlant(string plantName) {
    if (plantName == "Rice") return ricePlants;
    else if (plantName == "Dragonfruit") return dragonPlants;
    else if (plantName == "Pineapple") return pineapplePlants;
    else if (plantName == "Banana") return bananaPlants;
    else if (plantName == "Grape") return grapePlants;
    else return 0;
}

int playerInventory::getSeeds(string seedName) {
    if (seedName == "Rice") return riceSeeds;
    else if (seedName == "Dragonfruit") return dragonSeeds;
    else if (seedName == "Pineapple") return pineappleSeeds;
    else if (seedName == "Banana") return bananaSeeds;
    else if (seedName == "Grape") return grapeSeeds;
    else return 0;
}


void playerInventory::setSavings(double newAmount){
    savings = newAmount;
}

void playerInventory::subtractfromSavings(double amount){
    savings-=amount;
}

void playerInventory::addtoSavings(double amount){
    savings+=amount;
}


double playerInventory::getSavings(){
    return savings;
}

double playerInventory::getDebt(){
    return playerDebt;
}