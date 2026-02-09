#include <iostream>
#include "merchant.h"
#include<vector>
#include<algorithm>
#include <string>
#include<iomanip>
#include"playerInventory.h"
#include"startMenu.h"

using namespace std;

playerInventory merchant:: displayMerchant(playerInventory inv){
    
        cout << "Welcome to the Merchant!"<<endl;
        cout << "Here you can buy new seeds, and sell your plants!"<<endl;
        cout << "Be on the lookout, sometimes there will be special offers!"<<endl;
        cout << "Sometimes there'll be a bonus for selling or discounts for buying"<<endl;
        cout << "\n";
        const string BLUE = "\033[34m";
        const string RED = "\033[31m";
        const string RESET = "\033[0m";
        string space = "                                         ";

        cout << space << BLUE;
        cout << "         MERCHANT" << endl;
        cout << space << "       —-—————————  " << endl;
        cout << space << " ____/############\\____" << endl;
        cout << space << "/_______   __   _________\\              WHATCHA WANT???"<< endl;
        cout << space << "   |                 |                     YEA BUYIN OR SELLIN?" << endl;
        cout << space << "   |     @       @   |" << endl;
        cout << space << "   |            0    |" << endl;
        cout << space << "   |_________________|           |--^^^--|" << endl;
        cout << space << "           \\\\\\                   (  $$   )" << endl;
        cout << space << " \\\\\\           \\\\\\\\        \\\\\\\\  —------   " << endl;
        cout << space << " \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
        cout << space << "                 \\\\\\\\\\\\" << endl;
        cout << space << "                \\\\\\\\" << endl;
        cout << space << "             \\\\\\\\" << endl;
        cout << space << "     \\\\\\\\\\\\          \\\\\\\\\\\\" << endl;
        cout <<RESET;

        int merchOption;
        cout << "Press 1 to continue"<<endl;
        cout << "Press 2 to exit"<< endl;
        cin >> merchOption;

        if(merchOption == 2){
            cout << "Exiting"<<endl;
            return inv;
        }
        else if(merchOption != 1 && merchOption != 2){
            cout << "Invalid option"<<endl;
        }  

        int buyOrSell;
        if(merchOption == 1){
            cout << "\n";
            cout<<"Would you like to buy or sell?"<<endl;
            cout <<"Press 1 to buy"<<endl;
            cout <<"Press 2 to sell"<<endl;
            cout <<"Press 3 to exit"<<endl;
            cin >> buyOrSell;
            
            if(buyOrSell == 1){
            inv = displayMenuSeeds(inv);
            }
            else if(buyOrSell == 2){
                inv = displayMenuPlants(inv);
            }
            else if(buyOrSell == 3){
                cout << "Exiting"<<endl;
                return inv;
            }
            else if(buyOrSell != 1 && buyOrSell != 2 && buyOrSell != 3){
                cout << "Invalid option"<<endl;
                
            }
        }
         return inv;
    }



double getRandomPrice(double min, double max) {
    double scale = rand() / (double) RAND_MAX;
    return min + scale * (max - min);
}


playerInventory merchant:: displayMenuSeeds(playerInventory inv){
    
    srand(time(0));
    double total = 0;
    double cost =0;
    char continueBuy;


    do {
        vector<Seeds> seedlisting{
            {"Pineapple", "The price of pineapple seeds is: ", getRandomPrice(300, 600)},
            {"Grape", "The price of grape seeds is: ", getRandomPrice(400, 850)},
            {"Dragonfruit", "The price of dragonfruit seeds is: ", getRandomPrice(1000, 3000)},
            {"Rice", "The price of rice seeds is: ", getRandomPrice(10, 300)},
            {"Banana", "The price of banana seeds is: ", getRandomPrice(200, 400)}
            
        };

        // Bubble sort 
        for (int i = 0; i < seedlisting.size(); i++) {
            for (int j = 0; j < seedlisting.size() - 1; j++) {
                if (seedlisting[j].price < seedlisting[j + 1].price) {
                    swap(seedlisting[j], seedlisting[j + 1]);
                }
            }
        }

        cout << fixed << setprecision(2);
        for (const auto &seed : seedlisting) {
        cout << seed.listing << seed.price << endl;
    }

    //Asks for index of the listing you want to buy
        cout << "Enter the index (0-4) of which seed you want to buy: ";
        int index;
        cin >> index;
        cout<<"\n";

        if (index >= 0 && index < static_cast<int>(seedlisting.size())) {
            Seeds selectedSeed = seedlisting[index];

            cout << "Enter how many you want to buy: ";
            int quantity;
            cin >> quantity;
    
            while (cin.fail() || quantity < 0) {
            cin.clear(); // clear error flag
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input. Please enter a positive number: ";
            cin >> quantity;
        }

            double cost = selectedSeed.price * quantity;
        
        //Error check if not enough money
        if (cost > inv.getSavings()) {
        cout << "Insufficient funds! You need $" << cost << " but only have $" << inv.getSavings() << endl;
        }   else {
        cout << "You've bought " << quantity << " " << selectedSeed.name << " seeds for $" << cost << endl;

        total += cost;

        //Access inventory functions
        inv.subtractfromSavings(cost);  // only subtract after checking
        inv.addSeeds(selectedSeed.name, quantity);  // update inventory

         cout << "Purchase successful! Remaining savings: $" 
         << inv.getSavings() << endl;
         }
        }
        else {
        cout << "Invalid index! Please enter a number between 0 and 4." << endl;
        }

        cout << "Buy another? (y for yes, n for no): ";
        cin >> continueBuy;
        // Loop until valid input
                while (continueBuy != 'y' && continueBuy != 'n') {
                    cout << "Invalid input. Please enter 'y' or 'n': ";
                    cin >> continueBuy;
                }
    } while (continueBuy == 'y');

    cout << "Total spent: $" << total << endl;

    //Returns copied instance of inventory 
    return inv;

}

playerInventory merchant:: displayMenuPlants(playerInventory inv){
    
    srand(time(0));
    double total = 0;
    double cost =0;
    char continueBuy;



    do {
        vector<Plants> plantlisting{
        {"Pineapple","The sell price of pineapple is: ",getRandomPrice(1,2500)},
        {"Grape","The sell price of grape is: ",getRandomPrice(1,4000)},
        {"Dragonfruit","The sell price of dragonfruit is: ",getRandomPrice(1,9000)},
        {"Rice","The sell price of rice is: ",getRandomPrice(1,1000)},
        {"Banana","The sell price of banana is: ",getRandomPrice(1,2000)},
        
    };
    
      // Bubble sort 
        for (int i = 0; i < plantlisting.size(); i++) {
            for (int j = 0; j < plantlisting.size() - 1; j++) {
                if (plantlisting[j].plantPrice < plantlisting[j + 1].plantPrice) {
                    swap(plantlisting[j], plantlisting[j + 1]);
                }
            }
        }

        cout << fixed << setprecision(2);

    for(const auto &plant : plantlisting){
        cout << plant.plantlisting << plant.plantPrice<<endl;
    }


    //Same as seed block but for plants
    cout << "Enter the index (0-4) of which plant you want to sell: ";
        int index;
        cin >> index;
        cout<<"\n";

        if (index >= 0 && index < static_cast<int>(plantlisting.size())) {
            Plants selectedPlants = plantlisting[index];

            

            cout << "Enter how many you want to sell: ";
            int quantity;
            cin >> quantity;
    
    //Uses getter function to confirm number of plants
            int currentOwned = inv.getPlant(selectedPlants.name);

            if (quantity <= 0) {
                cout << "Invalid amount." << endl;
            }

            else if(quantity > currentOwned){
                cout << "You don't have enough " << selectedPlants.name 
                << " plants to sell. You only have " << currentOwned << "." << endl;
            }

            else{

            cout << "You've sold " << quantity << " " << selectedPlants.name
                 << " plants for $" << selectedPlants.plantPrice * quantity << endl;

            total += selectedPlants.plantPrice * quantity;

            //Uses inventory member functions to update values
            inv.addtoSavings(total); 
            inv.losePlants(selectedPlants.name, quantity);
            cout << "Sale successful! Remaining savings: $" << inv.getSavings() << endl;
            }

        }
        else {
        cout << "Invalid index! Please enter a number between 0 and 4." << endl;
        }

        cout << "sell another? (y for yes, n for no): ";
        cin >> continueBuy;
        while (continueBuy != 'y' && continueBuy != 'n') {
                            cout << "Invalid input. Please enter 'y' or 'n': ";
                            cin >> continueBuy;
                        }
    } while (continueBuy == 'y');

    cout << "Total earned: $" << total << endl;
    //Sends inventory values back
    return inv;


}






