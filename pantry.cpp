#include <string>
#include "pantry.h"

pantry::pantry(){
    //initializes and decalres variables
    int flourCount=0;
    int eggCount=0;
    int vanillaCount=0;
    int milkCount=0;
    int butterCount=0;
    int sugarCount=0;
    int chocoCount=0;
        
}
//getters and setters...
void pantry::setflourCount(int a){
    flourCount=a;
}

int pantry::getflourCount(){
    return flourCount;
}

void pantry::seteggCount(int b){
    eggCount=b;
}

int pantry::geteggCount(){
    return eggCount;
}

void pantry::setvanillaCount(int c){
    vanillaCount=c;
}

int pantry::getvanillaCount(){
    return vanillaCount;
}
void pantry::setmilkCount(int d){
    milkCount=d;
}

int pantry::getmilkCount(){
    return milkCount;
}
void pantry::setbutterCount(int e){
    butterCount=e;
}

int pantry::getbutterCount(){
    return butterCount;
}
void pantry::setsugarCount(int f){
    sugarCount=f;
}

int pantry::getsugarCount(){
    return sugarCount;
}
void pantry::setchocoCount(int g){
    chocoCount=g;
}

int pantry::getchocoCount(){
    return chocoCount;
}