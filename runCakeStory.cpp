// CSCI1300 Fall 2018
// Author: Vienna Wong
// Recitation: Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/viennawongw/csci1300_viwo3022
// Final Project: Cake Story

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "game.h"
#include "player.h"
#include "recipe.h"
#include "pantry.h"
using namespace std;

//declare variables
string choice;
string name;
game obj;
int o;


 void Menu(){ //displays the menu of options that the user can select in a day
     cout << "What would you like to do today?" << endl<< endl;
     cout << "1. Start the game "<< endl;
     cout << "2. Roll a dice" << endl;
     cout << "3. Go to the market" << endl;
     cout << "4. View Pantry" << endl;
     cout << "5. View Player Stats" << endl;
     cout << "6. Sleep" << endl;
     cout << "7. Bake" << endl;
     cout << "8. View Cake Log" << endl;
     cout << "9. End Game" << endl;
 }



int main()
{

 // to make loop through each player: while player[i].getCakePoints(); is equal to zero.

    while (choice != "9") {
            Menu();
            cin >> choice;
            cin.ignore();

            switch (stoi(choice)) {
                case 1:

                    /////////////////       ADD A USER      /////////////////////////////////////////////////////////
                   cout << "Enter your name: ";
                   getline(cin, name);
                   cin.ignore();

                  cout << "Would you like to view the rules?" << endl << "1. Yes " << endl<< "2. No " << endl;
                   cin >> o;
                   cin.ignore();

                   obj.startGame(name, o);
                        break;


                    //////////////////////////////////////////////////////////////////////////



                case 2:

                    /////////////////////       ROLL DICE       /////////////////////////////////////////////////////
                    obj.rollDice();
                    //////////////////////////////////////////////////////////////////////////

                    break;


                case 3:
                    ///////////////////////////         MARKET  ///////////////////////////////////////////////

                   obj.market();

                    //////////////////////////////////////////////////////////////////////////

                    break;

                case 4:

                    /////////////////////////////       VIEW PANTRY         /////////////////////////////////////////////
                    obj.showPantry();
                    //////////////////////////////////////////////////////////////////////////


                    break;

                case 5:
                    //view player stats function

                    ////////////////////////        PLAYER STATS        //////////////////////////////////////////////////
                obj.showPlayerStats();
                    //////////////////////////////////////////////////////////////////////////

                    break;

                case 6:
                    //sleep function

                    //////////////////////      SLEEP       /////////////////////////////////
                obj.sleep();
                    ////////////////////////////////////////////////////////

                    break;

                case 7:
                    ////////////////////        BAKE        //////////////////////////////////////
                obj.bake();
                  ////////////////////////////////////////////////////

                  break;


                case 8:

                    ////////////////    VIEW CAKE LOG    //////////////////////////////////////////
               obj.cakelog();
                    ////////////////////////////////////////////////////////////

                    break;


                case 9:
                    // quit
                    cout << "The game has ended!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
                    cout<< endl;
            }

     }
        //deletes the contents of the cakelof text file, so they do not impact the next game's cake log
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
    return 0;
}
