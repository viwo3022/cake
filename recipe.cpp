#include <string>
#include "recipe.h"
recipe::recipe(){
    //decalres and initializes variables
    idealEgg=0;
    idealFlour=0;
    idealVanilla=0;
    idealMilk=0;
    idealButter=0;
    idealSugar=0;
    idealChoco=0;
    purchased = false;
}
//getters and setters...
void recipe::setidealEgg(int egg){
    idealEgg = egg;
}

int recipe::getidealEgg(){
    return idealEgg;
}

void recipe::setidealFlour(int flour){
    idealFlour = flour;
}

int recipe::getidealFlour(){
    return idealFlour;
}
void recipe::setidealVanilla(int v){
    idealVanilla = v;
}

int recipe::getidealVanilla(){
    return idealVanilla;
}
void recipe::setidealMilk(int milk){
    idealMilk = milk;
}

int recipe::getidealMilk(){
    return idealMilk;
}

void recipe::setidealButter(int butter){
    idealButter = butter;
}

int recipe::getidealButter(){
    return idealButter;
}
void recipe::setidealSugar(int sugar){
    idealSugar = sugar;
}

int recipe::getidealSugar(){
    return idealSugar;
}
void recipe::setidealChoco(int choco){
    idealChoco = choco;
}

int recipe::getidealChoco(){
    return idealChoco;
}
void recipe:: setpurchased(bool yon){
    purchased= yon;
    
}
bool recipe:: getpurchased(){
    return purchased;
}



