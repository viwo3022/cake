#include <string>
#ifndef player_H
#define player_H
using namespace std;

class player{
    private:
        string Pname;
        int money;
        int cakePoints;
        bool dyr;
        int day;
    public:
        player();
        void setPname(string);
        string getPname();
        // use a get name and a set name
        void startGame(string, int);
        void setMoney(int);
        int getMoney();
        void setCakePoints(int);
        int getCakePoints();
        void setdyr(bool);
        bool getdyr();
        void setday(int);
        int getday();
        
    
        
};

#endif

