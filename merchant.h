#include<iostream>
#include"playerInventory.h"
using namespace std;

struct Seeds{
    string name;
    string listing;
    double price;
};


struct Plants{
    string name;
    string plantlisting;
    double plantPrice;

};
class merchant{
    private:
        double totalSoldMoney, totalBoughtMoney;
        double totalSoldInventory, totalBoughtInventory;

        
    
    public:
        playerInventory displayMerchant(playerInventory inv);
        playerInventory displayMenuSeeds(playerInventory inv);
       playerInventory displayMenuPlants(playerInventory inv);

};