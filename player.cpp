#include <string>
# include "player.h"

player::player(){
    //declare and initialize variables
    string Pname = "";
    int money = 0;
    int cakePoints=0;
    bool dyr= false;
    int day = 0;
}
//getters and setters...
void player::setMoney(int dollar){
    money = dollar;
}

int player::getMoney(){
    return money;
}

void player::setCakePoints(int CP){
    cakePoints=CP;
}

int player::getCakePoints(){
    return cakePoints;
}

void player:: setPname(string name){
    Pname = name;
}

string player:: getPname(){
    return Pname;
}

void player:: setdyr(bool tof){
    dyr= tof;
}

bool player:: getdyr(){
    return dyr;
}

void player :: setday(int num){
    day = num;
}

int player:: getday(){
    return day;
}