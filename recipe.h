#ifndef RECIPE_H
#define RECIPE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <ctype.h>
#include <string>

using namespace std;
//
class recipe{
    private:
      bool purchased;    
      int idealEgg;
      int idealFlour;
      int idealVanilla;
      int idealMilk;
      int idealButter;
      int idealSugar;
      int idealChoco;
      
    public:
        recipe();
        //the ideal amounts of ingredients depends on what cake the player wants to bake: vanilla or chocolate
        void setidealEgg(int);
        int getidealEgg();
    
        void setidealFlour(int);
        int getidealFlour();
    
        void setidealVanilla(int);
        int getidealVanilla();
    
        void setidealMilk(int);
        int getidealMilk();

        void setidealButter(int);
        int getidealButter();
        
        void setidealSugar(int);
        int getidealSugar();
        
        void setidealChoco(int);
        int getidealChoco();
        
        void setpurchased(bool);
        bool getpurchased();
    
        
};

#endif