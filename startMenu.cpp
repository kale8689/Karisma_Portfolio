#include <iostream>
using namespace std;
#include "startMenu.h"
#include "plant.h"
#include "harvest.h"
#include <string>

void startMenu::displayMenu(){
        menuOptions();
        int option = 0;
        cin >> option;

        switch(option){
            case 1:
                startGame();
                break;
            case 2:
                cout << "Quitting Game." << endl;
                return;
            default:
                cout << "Invalid Choice" << endl;
        }
}

void startMenu::menuOptions(){
    string space = "                                                 ";
    cout << space << "\n\n\n\n\n\n" << endl;
    cout << space << R"(

                        ·▄▄▄▄  ▄▄▄ .▄▄▄▄· ▄▄▄▄▄     ▄ .▄ ▄▄▄· ▄▄▄   ▌ ▐·▄▄▄ ..▄▄ ·▄▄▄▄▄      ▄▄▄  
                        ██▪ ██ ▀▄.▀·▐█ ▀█▪•██      ██▪▐█▐█ ▀█ ▀▄ █·▪█·█▌▀▄.▀·▐█ ▀.•██  ▪     ▀▄ █·
                        ▐█· ▐█▌▐▀▀▪▄▐█▀▀█▄ ▐█.▪    ██▀▐█▄█▀▀█ ▐▀▀▄ ▐█▐█•▐▀▀▪▄▄▀▀▀█▄▐█.▪ ▄█▀▄ ▐▀▀▄ 
                        ██. ██ ▐█▄▄▌██▄▪▐█ ▐█▌·    ██▌▐▀▐█ ▪▐▌▐█•█▌ ███ ▐█▄▄▌▐█▄▪▐█▐█▌·▐█▌.▐▌▐█•█▌
                        ▀▀▀▀▀•  ▀▀▀ ·▀▀▀▀  ▀▀▀     ▀▀▀ · ▀  ▀ .▀  ▀. ▀   ▀▀▀  ▀▀▀▀ ▀▀▀  ▀█▄▀▪.▀  ▀

)" << endl;
    cout << space << R"(\|/ \|/ START MENU \|/ \|/)" << endl;
    cout << space << "Press 1 to start the game" << endl;
    cout << space << "Press 2 to quit the game" << endl;
    cout << space << "Enter choice: " << endl;
    cout << space << "\n\n\n\n\n\n" << endl;
}


void startMenu::startGame(){
    // start game story
    cout << "Game is starting..." << endl;
    string space = "                                                 ";
    //cout << space << "\n\n\n\n\n\n\n\n" << endl;
    cout << R"(                    _
                                 _(_)_                                              wWWWw        _
           @@@@                 (_)@(_)        vVVVv          _          @@@@       (___)      _(_)_
          @@()@@      wWWWw       (_)\         (___)        _(_)_       @@()@@        Y       (_)@(_)
           @@@@       (___)          `|/         Y         (_)@(_)       @@@@        \|/        (_)\
            /           Y            \|         \|/         /(_)         \|           |/           |
         \ |          \ |/            | /      \ | /       \|/            |/         \|           \|/
         \\|//        \\|///       \\\|//     \\\|///      \|///       \\\|//       \\|//       \\\|// 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^)" << endl;
    cout << "Once upon a time... in 2025... you went to college to major in Anthroplogy." << "\n" << endl;
    cout << "After four years of hardwork and dedication you were ready to go into the job market" << "\n" << endl;
    cout << "However, you realized you had no idea what anthroplogists did, and neither did the current job market" <<"\n" << endl;
    cout << "Then you checked your student loans and saw you were $100,000 in debt!" << "\n" <<endl;
    cout << "And if you didn't pay it off in ten turns, the loan sharks will send you to prison camp." << "\n" <<endl;
    cout << "So you picked up a hoe, went back to your home state of Iowa, and started farming." << "\n" <<endl;

    //tutorial turn 1
    cout << "Back at home you found 10 empty plots that you inherited from your grandparents" << "\n" <<endl;
    cout << "As well as a parting gift of 5 rice seeds, as your grandparents are in Cabo." << "\n" <<endl;
    cout << "You have a total of ten turns in this game. This turn you will plant all 5 of your seeds" << "\n" <<endl;
    cout << "Then you will have to end your turn. On the next turn, your crops will be ready to harvest." << "\n" <<endl;
    cout << "There's an indicator to keep track of your money as well as what turn it is." << "\n" <<endl;

    cout<< "Press any character to continue" << endl;
    char anycharacter;
    cin >> anycharacter;

    cout << R"(

                                            YOUR GARDEN
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~plot~one~~~~~~~ ~~~~~plot~two~~~~~~~ ~~~~plot~three~~~~~~ ~~~~~plot~four~~~~~~ ~~~~~plot~five~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~plot~seven~~~~~ ~~~~~plot~seven~~~~~ ~~~~plot~eight~~~~~~ ~~~~~plot~nine~~~~~~ ~~~~~plot~ten~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~)" << endl;

    //tutorial turn 2
    cout << "Afterwards you will want to harvest your crops. Then, you will talk to the merchant." << "\n" <<endl;
    cout << "When talking to the merchant, you can sell your crops, and then buy more seeds to plant." << "\n" <<endl;
    cout << "The merchants' prices are different everytime, so predicting what seeds to buy can be difficult." << "\n" <<endl;

}


