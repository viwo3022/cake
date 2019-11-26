#include <string>
#ifndef GAME_H
#define GAME_H
#include "recipe.h"
#include "player.h"
#include "pantry.h"

using namespace std;

class game{
    private:
        string name;
        int opt;
        int rolledNumber;
        //int day=0;
        player Player;
        pantry Pantry;
        recipe vanillacake;
        recipe chocolatecake;
        
    public:
        game();
        string startGame(string, int);
        int rollDice();
        int market();
        void showPantry ();
        void showPlayerStats();
        int sleep();
        int bake(); //string parameter inputs what kind of cake the user wants to bake. inputs recipe file
        void cakelog();

};

#endif