#include <string>
#ifndef PANTRY_H
#define PANTRY_H
using namespace std;

class pantry{
    private:
     
        int flourCount;
        int eggCount;
        int vanillaCount;
        int milkCount;
        int butterCount;
        int sugarCount;
        int chocoCount;
        
    public:
        pantry();
        //pantry(string, string); //player and string associated with the a specific ingredient
       
        void setflourCount(int);
        int getflourCount();
    
        void seteggCount(int);
        int geteggCount();
    
        void setvanillaCount(int);
        int getvanillaCount();

        void setmilkCount(int);
        int getmilkCount();
        
        void setbutterCount(int);
        int getbutterCount();
        
        void setsugarCount(int);
        int getsugarCount();
        
        void setchocoCount(int);
        int getchocoCount();
};

#endif