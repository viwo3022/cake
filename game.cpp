#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <ctype.h>
#include "pantry.h"
#include "player.h"
#include "recipe.h"
#include "game.h"

using namespace std;

game::game(){
    rolledNumber=0;
    
    

}

string game::startGame(string name, int o){
    int Day = Player.getday();          //Gets what day it is from the player class
    string pname;
    if (Player.getday() == 0){          //If the game is equal to zero, that means that the game has not been started yet 
        cout << "Welcome to Cake Story, "<< name << "!"<< endl;
        if (o == 1){ //If the user wants to view the rules,
            
             string input;
             ifstream in;
             in.open("rules.txt");
             while (!in.eof()){ //print the file until it reaches the end of the file
                 in >> input;
                 if (input == "-"){ //when there is a dash (in the ratings.txt) file
                    cout << endl;
                 }
                 else{
                    cout << input<< " "; //print each input with a space in between
                 }
             }
             in.close(); //close the file
             
             cout << "Have fun!" << endl;
             cout << endl;
             Day++; //add +1 to day, showing that the game has started
             // set the day and the player's name
             Player.setday(Day); 
             Player.setPname(name);
             pname = Player.getPname();
             cout<< "Today is Day " << Player.getday() << endl;
             cout << endl;
            return pname;
            
        }
        else if (o == 2){ //If the player chooses not to view the rules 
             cout << "Let the game begin!" << endl;
             Day++; //day = 1 Shows that the game has started
             Player.setday(Day);
             Player.setPname(name);
             pname = Player.getPname();
             cout<< "Today is Day " << Player.getday() << endl;
             cout << endl;
             
             return pname;
         }
        else if (o != 1 || o != 2){ //if their input is not one or two, say that the option is not available
            cout << "Option not available. Please input 1 or 2." << endl;
            //return;
        }
        
    }
    else{ //if the day does not equal zero, then the day has already begun
        cout << "The game has already begun!"<< endl;
        cout << endl;

    }
     
}

int game::rollDice(){
    int rolledNumber=0; //initializes rolled number
    bool rollorno= Player.getdyr(); //variable shows if the user has rolled or not. It is initially set to false and will become true when the user rolls each day
    int Day = Player.getday(); //gets what day it is
    
    if (Day ==32){ //if the day is over 31 (which is the maximum number of days for the game), then end the game.
        cout<< "Cake Story is over! Thank you for playing!"<< endl;
        //deletes all of the contents from the cake log file, so the cakelog text file is empty for the next player's game
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
        exit (0);
        
    }
    
	rolledNumber= (rand() % 6) + 1;
	int dollar = Player.getMoney(); //gets how much money the player has 
	Player.getdyr(); //find out if the player has rolled or not
	
	if (Day == 0){
	    cout << "Game has not been started. Please start the game first!" << endl<< endl;
	    return 0;
	}
	
	if (rollorno == false) { //if the player has not rolled yet
	    switch (rolledNumber){ //switch case with the rolled numbers
	        case 1:
	            //if the player rolls a 1, the player wins 8 dollars 
	            dollar = dollar + 8;
	            cout << "WOW! "<< Player.getPname() << " found $8!\n" << endl;
	            // setting rollorno to true shows that the player has already rolled for the day
	            rollorno = true;
	            Player.setdyr(rollorno);
	            Player.setMoney(dollar);
	            cout << Player.getPname()<< " now has " << "$" <<Player.getMoney() << endl;
	            return 0;
	            
	        case 2:
	            // if the player rolls a 2, the player wins 10 dollars
	            dollar = dollar + 10;
	            cout << "YAY! "<< Player.getPname() << " found $10!\n"<< endl;
	            rollorno = true;
	            Player.setdyr(rollorno);
	             Player.setMoney(dollar);
	            cout << Player.getPname()<< " now has " << "$" <<Player.getMoney() << endl;
	            return 0;
	            
	        case 3:
	            //if the player rolls a 3, the player loses three dollars
	            //if the player has negative money, set the player's money to zero
	            dollar = dollar - 3;
	            if (dollar < 0){
	                dollar = 0;
	            }
	            cout << "Oh no! "<< Player.getPname() << " lost $3.\n" << endl;
	            rollorno = true;
	            Player.setdyr(rollorno);
	             Player.setMoney(dollar);
	            cout << Player.getPname()<< " now has " << "$" <<Player.getMoney() << endl;
	            return 0;
	            
	        case 4:
	            //if the player rolls a 4, the player loses four dollars
	            //if the player has negative money, set the player's money to zero
	            dollar = dollar - 1;
	            if (dollar < 0){
	                dollar = 0;
	            }
	            cout << "Yikes! Someone stole $1 from "<< Player.getPname() << "." << endl<< endl;
	            rollorno = true;
	            Player.setdyr(rollorno);
	            Player.setMoney(dollar);
	            cout << Player.getPname()<< " now has " << "$" <<Player.getMoney() << endl;
	            return 0;
	            
	        case 5:
	            //if the player rolls a five, a player wins 5 dollars and has the option to roll again (so do not set rollorno to true for this case)
	            dollar = dollar + 5;
	            cout << "YAY! "<< Player.getPname() << " found $5!"<< endl;
	            cout << Player.getPname() << " has the option to roll again today! How lucky!" << endl << endl;
	            rollorno = false;
	            Player.setdyr(rollorno);
	            Player.setMoney(dollar);
	            cout << Player.getPname()<< " now has " << "$" <<Player.getMoney() << endl;
	            return 0;
	            
	        case 6:
	            //go to the next day
	            cout << "Oh no! " << Player.getPname() << " fell asleep!\n" << endl;
	            Day++;
	            Player.setday(Day);
	            cout << "Today is Day "<< Player.getday()<< endl;
	            rollorno= false;
	            Player.setdyr(rollorno);
	            return 0;
	    }
	}
	
	else{
	    cout << "You have already rolled today! Come back tomorrow!"<< endl;
	    return 0;
	}
   
}

int game::market(){
    //initialize variables
    int quant;
    int item;
    int dep;
    string rec;
    int flour = Pantry.getflourCount();
    int dollar = Player.getMoney();
    int egg = Pantry.geteggCount();
    int vanilla = Pantry.getvanillaCount();
    int milk = Pantry. getmilkCount();
    int butter = Pantry.getbutterCount();
    int sugar = Pantry.getsugarCount();
    int choco= Pantry.getchocoCount();
    
    
    cout << "Welcome to the market! Here is what is on sale for today: "<< endl;
    int Day = Player.getday();
     if (Day ==32){ //game is over
        cout<< "Cake Story is over! Thank you for playing!"<< endl;
        // deletes all of the contents from the cake log file, so the cakelog text file is empty for the next player's game
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
        exit (0);
        
    }
    
    if (Day == 0){
	    cout << "Game has not been started. Please start the game first!" << endl<< endl;
	    return 0;
	}
    //displays how much money the player has
    cout << Player.getPname() <<"'s wallet: $" << Player.getMoney() << endl<< endl; 
    cout << "Welcome! Are you shopping for ingredients or recipes?"<< endl;
    cout << "1. ingredients"<< endl;
    cout << "2. recipes" << endl;
    cout << endl;
    cin >> dep; //customer chooses what department they are shopping at 
     if (dep != 1 || dep != 2){ 
         cout << "Please input 1 or 2."<< endl;
     } 
     
    if (dep==1){ //department 1 is for ingredients
        cout <<    "Item          Price"<< endl;
        cout << endl;
        
        if (Day == 31){ //on the final day, all of the items are on sale
            cout << "Final day! All items are for sale today!"<< endl;
            
            cout << "1. flour            $2 / cup" << endl;
            cout << "2. eggs             $2 / egg" << endl;
            cout << "3. vanilla          $2 / cup" << endl;
            cout << "4. milk             $2 / cup" << endl;
            cout << "5. butter           $2 / egg" << endl;
            cout << "6. sugar            $2 / cup" << endl;
            cout << "7. choco            $2 / cup" << endl;
            cout << "8. leave market" << endl;
            cout << endl;
           
           while (item != 8){ //while the player does not select to leave the shop
                cout << " What would you like to purchase?" << endl;
                cin >> item;
                cin.ignore();
                switch (item){
                    case 1:
                        flour = Pantry.getflourCount();
                        cout << "How much flour would you like to purchase?"<< endl;
                        cin>> quant;
                        //input the quantity of the item that the user wants to purchase
                        cin.ignore(); //throw away the inputs that are already in the input stream (if not, this will cause an error)
                        flour = flour + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){ // if dollar is less than zero, they do not have enough money for their purchase
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            return 0;
                        }
                        else if (dollar >=0){
                            //set the new values of the ingredients and of the funds
                            Pantry.setflourCount(flour);
                            Player.setMoney(dollar);
                            //display the amount of __ ingredient in their pantry and their remaining funds 
                            cout<< Player.getPname() << " now has "<< Pantry.getflourCount() << " cups of flour in the pantry." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                        
                    case 2: 
                        egg = Pantry.geteggCount();
                        cout << "How many eggs would you like to purchase?"<< endl;
                        cin>> quant;
                        cin.ignore();
                        egg = egg + quant;
                        dollar= dollar -(quant*2);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.seteggCount(egg);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.geteggCount() << " eggs." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                        
                    case 3:
                        vanilla = Pantry.getvanillaCount();
                        cout << "How much vanilla would you like to purchase?"<< endl;
                        cin>> quant;
                        cin.ignore();
                        vanilla = vanilla + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Player.setMoney(dollar);
                            Pantry.setvanillaCount(vanilla);
                            cout<< Player.getPname() << " now has "<< Pantry.getvanillaCount() << " tsps of vanilla." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 4:
                        milk = Pantry.getmilkCount();
                        cout << "How much milk would you like to purchase?"<< endl;
                        cin>> quant;
                        cin.ignore();
                        milk = milk + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Player.setMoney(dollar);
                            Pantry.setmilkCount(milk);
                            cout<< Player.getPname() << " now has "<< Pantry.getmilkCount() << " cups of milk." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 5:
                        butter = Pantry.getbutterCount();
                        cout << "How much butter would you like to purchase?"<< endl;
                        cin>> quant;
                        cin.ignore();
                        butter = butter + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Player.setMoney(dollar);
                            Pantry.setbutterCount(milk);
                            cout<< Player.getPname() << " now has "<< Pantry.getbutterCount() << " sticks of butter." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 6:
                        sugar = Pantry.getsugarCount();
                        cout << "How much sugar would you like to purchase?"<< endl;
                        cin>> quant;
                        cin.ignore();
                        sugar = sugar + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Player.setMoney(dollar);
                            Pantry.setsugarCount(sugar);
                            cout<< Player.getPname() << " now has "<< Pantry.getsugarCount() << " cups of sugar." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 7:
                        choco = Pantry.getchocoCount();
                        cout << "How much chocolate would you like to purchase?"<< endl;
                        cin>> quant;
                        cin.ignore();
                        choco = choco + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Player.setMoney(dollar);
                            Pantry.setchocoCount(choco);
                            cout<< Player.getPname() << " now has "<< Pantry.getmilkCount() << " cups of chocolate." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 8:
                        //option to exit the market
                        return 0;
                }
            return 0;
           }
        }
        
        else if (Day % 2 == 0){ //if the day is divisable by two, the market sells the following objects
            cout << "1. flour          $1 / cup" << endl;
            cout << "2. eggs           $2 / egg" << endl;
            cout << "3. milk           $2 / cup" << endl;
            cout << "4. leave market" << endl;
            while (item != 4){
                cout << "What item would you like to purchase?"<< endl;
                cout << endl;
                cin>> item;
                switch (item){
                    case 1:
                        flour = Pantry.getflourCount();
                        cout << "How much flour would you like to purchase?"<< endl;
                        cin>> quant;
                        flour = flour + quant;
                        dollar= dollar -(quant*1);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.setflourCount(flour);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.getflourCount() << "cups of flour in the pantry." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                            
                    case 2:
                        egg = Pantry.geteggCount();
                        cout << "How many eggs would you like to purchase?"<< endl;
                        cin>> quant;
                        egg = egg + quant;
                        dollar= dollar -(quant*2);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.seteggCount(egg);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.geteggCount() << " eggs." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 3:
                        milk = Pantry.getmilkCount();
                        cout << "How much milk would you like to purchase?"<< endl;
                        cin>> quant;
                        milk = milk + quant;
                        dollar= dollar -(quant*2);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.setmilkCount(milk);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.getmilkCount() << " cups of milk." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 4:
                    return 0;
                    break;
                }
                return 0;
            }
        }
        
         else if (Day % 3 == 0 ){ //if the market is divisible by three, It sells the following objects
            cout << "1. vanilla         $3 / tsp" << endl;
            cout << "2. sugar           $1 / egg" << endl;
            cout << "3. choco           $2 / cup" << endl;
            cout << "4. leave market" << endl;
            cout << endl;
            
            while (item != 4){
                cout << "What item would you like to purchase?"<< endl;
                cin>> item;
                
                switch (item){
                    case 1:
                        vanilla = Pantry.getvanillaCount();
                        cout << "How much vanilla would you like to purchase?"<< endl;
                        cin>> quant;
                        vanilla = vanilla + quant;
                        dollar= dollar -(quant*3);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.setvanillaCount(vanilla);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.getvanillaCount() << " tsps of vanilla." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    case 2:
                        sugar = Pantry.getsugarCount();
                        cout << "How much sugar would you like to purchase?"<< endl;
                        cin>> quant;
                        sugar = sugar + quant;
                        dollar= dollar -(quant*1);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.setsugarCount(sugar);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.getsugarCount() << " cups of sugar." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                            
                    case 3:
                        choco = Pantry.getchocoCount();
                        cout << "How much chocolate would you like to purchase?"<< endl;
                        cin>> quant;
                        choco = choco + quant;
                        dollar= dollar -(quant*2);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.setchocoCount(choco);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.getchocoCount() << " cups of chocolate." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                    
                    case 4:
                        return 0;
                }
                return 0;
            }
        }
        
        else { //for any other day, the market sells the following objects
            cout << "1. flour           $2 / cup" << endl;
            cout << "2. eggs            $1 / egg" << endl;
            cout << "3. butter          $2 / tbsp" << endl;
            cout << "4. leave market" << endl;
           
           while (item != 4){ 
                cout << "What item would you like to purchase?"<< endl;
                cout << endl;
                cin>> item;
                switch (item){
                    case 1:
                        flour = Pantry.getflourCount();
                        cout << "How much flour would you like to purchase?"<< endl;
                        cin>> quant;
                        flour = flour + quant;
                        dollar= dollar -(quant*2);
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.setflourCount(flour);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.getflourCount() << "cups of flour in the pantry." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                            
                    case 2:
                        egg = Pantry.geteggCount();
                        cout << "How many eggs would you like to purchase?"<< endl;
                        cin>> quant;
                        egg = egg + quant;
                        dollar= dollar -(quant*1);
                        
                        if (dollar < 0){
                            cout << "Insuffiecient funds! Have a great day!"<< endl;
                            break;
                        }
                        else if (dollar >=0){
                            Pantry.seteggCount(egg);
                            Player.setMoney(dollar);
                            cout<< Player.getPname() << " now has "<< Pantry.geteggCount() << " eggs." << endl;
                            cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                            break;
                        }
                        
                    case 3:
                       butter = Pantry.getbutterCount();
                            cout << "How much butter would you like to purchase?"<< endl;
                            cin>> quant;
                            butter = butter + quant;
                            dollar= dollar -(quant*2);
                            if (dollar < 0){
                                cout << "Insuffiecient funds! Have a great day!"<< endl;
                                break;
                            }
                            else if (dollar >=0){
                                Player.setMoney(dollar);
                                Pantry.setbutterCount(butter);
                                cout<< Player.getPname() << " now has "<< Pantry.getbutterCount() << " sticks of butter." << endl;
                                cout<< "Remaining funds: $"<< Player.getMoney()<< endl; 
                                break;
                            }
                    case 4:
                        break;
                }
                return 0;
            }
        }
    }
    
    //////////////////////////  onto department 2 : recipes     //////////////////////////////////
    
     if (dep ==2){ //sells two recipes: a recipe for vanilla cake and for chocolate cake
        cout << "Which recipe would you like to purchase?"<< endl;
        cout << "1. Vanila Cake          $15"<< endl;
        cout << "Vanilla cake is cheaper less ingredients to bake and can result in many cake points! " << endl;
        cout << endl;
        cout << "2. Chocolate Cake       $20"  << endl;
        cout << "Chocolate Cake uses more ingredients, but will give you more cake points than vanilla cake!"<< endl;
        cout << endl;
        cout << "3. Leave market " << endl;
        
        cin >> rec;
      
        bool boughtyet;
        if (rec == "1"){ //the user chooses to purchase vanilla cake recipe
            boughtyet = vanillacake.getpurchased(); //if they have already bought the recipe, they cannot buy it again
            if (boughtyet==true){
                cout << "You have already bought this recipe!"<< endl;
                return 0;
            }
            if (boughtyet==false){ // if they have not bought this recipe, purchase the recipe
               
                dollar = dollar - 15;
                
                if (dollar < 0){ 
                    cout << "Insuffiecient funds!"<< endl;
                    return -1;
                }
                if (dollar >0){ //set recipe values
                    Player.setMoney(dollar);
                    vanillacake.setidealEgg(1);
                    vanillacake.setidealFlour(1);
                    vanillacake.setidealVanilla(1);
                    vanillacake.setidealMilk(1);
                    vanillacake.setidealButter(1);
                    vanillacake.setidealSugar(1);
                    vanillacake.setidealChoco(0);
                    boughtyet==true;
                    vanillacake.setpurchased(true);
                    cout << "Thank you for your purchase!"<< endl;
                return 0;
                }
        }
    }
        
        if (rec=="2"){ //if they choose to buy chocolate cake
            boughtyet= chocolatecake.getpurchased();
            if (boughtyet==true){
                cout << "You have already bought this recipe!"<< endl;
                return 0;
            }
           
                
            if (boughtyet==false){
                
                dollar = dollar - 20;
                
                 if (dollar < 0){
                    cout << "Insuffiecient funds!"<< endl;
                    return -1;
                }
                if (dollar >0){
                Player.setMoney(dollar);
                chocolatecake.setidealEgg(2);
                chocolatecake.setidealFlour(2);
                chocolatecake.setidealVanilla(2);
                chocolatecake.setidealMilk(2);
                chocolatecake.setidealButter(2);
                chocolatecake.setidealSugar(2);
                chocolatecake.setidealChoco(2);
                boughtyet==true;
                chocolatecake.setpurchased(true);
                cout << "Thank you for your purchase!"<< endl;
                return 0;
                }
        }
    }
    if (rec == "3"){ //exit the market
        cout << "Thank you for coming in!"<< endl;
        return 0;
    }
    else{
        cout << "Input not available" << endl;
    }
}  
}


void game::showPantry(){
    //gets the day to make sure the game has already been started and to make sure that the game has not already ended
    int Day = Player.getday();
    
     if (Day ==32){
        cout<< "Cake Story is over! Thank you for playing!"<< endl;
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
        exit (0);
        
    }
    
    if (Day == 0){
	    cout << "Game has not been started. Please start the game first!" << endl<< endl;
	    return;
	}
    if (Day != 0){
        //display how much of each item the player has in their pantry
        cout << Player.getPname()<< "'s pantry:\n"<< endl;
        cout << "Eggs: "<< Pantry.geteggCount() << " eggs"<< endl;
        cout << "Vanilla: "<< Pantry.getvanillaCount()<< " tsps" << endl;
        cout << "Milk: "<< Pantry.getmilkCount()<< " cups" << endl;
        cout << "Butter: "<< Pantry.getbutterCount()<< " cups" << endl;
        cout << "Sugar: "<< Pantry.getsugarCount()<< " cups" << endl;
        cout << "Choco: "<< Pantry.getchocoCount()<< " cups" << endl;
        cout << "Flour: " << Pantry.getflourCount()<< " cups\n" << endl;
        
        return;
        
    }
}

void game::showPlayerStats(){
    int Day= Player.getday();
     if (Day ==32){
        cout<< "Cake Story is over! Thank you for playing!"<< endl;
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
        exit (0);
        
    }
    
	if (Day == 0){
	    cout << "Game has not been started. Please start the game first!" << endl<< endl;
	    return;
	}
	if (Day!=0){
	    //print the player's name, money, cake points, and what day it is
        cout << "Player name: " << Player.getPname() << endl;
        cout << "Money: $ " << Player.getMoney()<< endl;
        cout << "Cake Points: " << Player.getCakePoints()<< endl;
        cout << "Day: " << Player.getday()<< endl;
        return;
    }
}

    

int game::sleep(){
    // sleep lets the player skip to the next day
    int Day= Player.getday();
    bool ron= Player.getdyr();
    if (Day == 0){
	    cout << "Game has not been started. Please start the game first!" << endl<< endl;
	    return -1;
    }
    cout << "Have a good night!"<< endl;
    ron = false; //new day, so the player should be able to roll again
    Player.setdyr(ron);
    Day++;
    
    if (Day ==32){
        cout<< "Cake Story is over! Thank you for playing!"<< endl;
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
        exit (0);
    }
    
    Player.setday(Day); // set the day and display what day it is
    cout << "Today is day "<< Player.getday()<< endl << endl;
    return Day;
    // end the user's turn
}

int game::bake(){
    //declare variables
    int choice;
    string in;
    int flour=0;
    int egg=0;
    int vanilla=0;
    int butter=0;
    int sugar=0;
    int choco=0;
    int milk=0;
    int Day = Player.getday();
    int pfl = Pantry.getflourCount();
    int peg = Pantry.geteggCount();
    int pva = Pantry.getvanillaCount();
    int pmi = Pantry.getmilkCount();
    int pbu = Pantry.getbutterCount();
    int psu = Pantry.getsugarCount();
    int pch = Pantry.getchocoCount();
    int points = Player.getCakePoints();
    
     if (Day ==32){
        cout<< "Cake Story is over! Thank you for playing!"<< endl;
        ofstream of;
        of.open("cakelog.txt", ofstream::out | ofstream::trunc);
        of.close();
        exit (0);
        
    }
    
    if (Day == 0){
	    cout << "Game has not been started. Please start the game first!" << endl<< endl;
	    //return -1;
	}
    
    cout << "What kind of cake do you want to bake?"<< endl<< endl;
    cout << "1. Vanilla cake \n" << endl;
    cout << "2. Chocolate cake \n" << endl;
    getline(cin,in);
   //checks to make sure that the user input is an integer. if not, it prompts the user for an integer
    for (int i=0; i< 1; i++){
        if (isalpha(in[i]) != 0){ //only need to check the value at in[0] because if the first index is not 1 or 2, the input should be invalid
        cout << "Please input 1 or 2" << endl;
        //return -1;
        }
    }
   choice = stoi(in); //changes the user inpur from a string to an integer
   if (choice != 1 && choice !=2 ){
       cout << "Option unavailable! Please input 1 or 2"<< endl;
       //return 0;
   }
   if (choice ==1 ){
       //if player has chosen to bake a vanilla cake,
       if (vanillacake.getpurchased() == false){
           cout << "You don't know the recipe for vanilla cake"<< endl;
           return -1;
       }
       
       flour = vanillacake.getidealFlour();
       egg = vanillacake.getidealEgg();
       vanilla = vanillacake.getidealVanilla();
       butter = vanillacake.getidealButter();
       sugar = vanillacake.getidealSugar();
       choco = vanillacake.getidealChoco();
       
       
       
       if (pfl<1 || peg < 1 || pva < 1 || pmi < 1 || pbu < 1|| psu<1 || pch < 0){ //check to see if the player has the ingredients to bake the cake
        //for debug:
        //   cout << pfl << " flour"<< endl;
        //   cout << peg << " egg" << endl;
        //   cout << pva << " vanilla" << endl;
        //   cout << pmi << " milk" << endl;
        //   cout << pbu << " butter" << endl;
        //   cout << pch << " choco"<< endl;
        //   cout << psu << " sugar" << endl;
        //if not, it prints that the user does not have enough ingredients
           
           cout << "You don't have enough ingredients!\n" << endl;
           return 0;
       }
       else{
           cout << "Let's get baking!\n"<< endl;
           cout << "You have baked a vanilla cake!\n " << endl;
           
           //subtracts the ingredient amount in the pantry from the ingredient amount in the recipe and gives the user 10 cake points
           pfl = pfl - 1;
           peg = peg - 1;
           pva = pva - 1;
           pmi = pmi - 1;
           pbu = pbu - 1;
           psu = psu - 1;
          // pch = pch - 1;
           Pantry.setflourCount(pfl);
           Pantry.seteggCount(peg);
           Pantry.setvanillaCount(pva);
           Pantry.setmilkCount(pmi);
           Pantry.setbutterCount(pbu);
           Pantry.setsugarCount(psu);
           Pantry.setchocoCount(pch);
           points = points + 10;
           Player.setCakePoints(points);
           
           // writes the date that the cake was bake, what kind of cake, and the amount of cake points earned in a cake log text file
            fstream out;
            out.open ("cakelog.txt", fstream::in | fstream::out | fstream::app);
            out<<"Day "<< Player.getday() << " - Baked a vanilla cake - 10 points"<< endl;
            out.close();
           
           return points;
       }
       
       
   }
    if (choice ==2){ //user decides to bake a chocolate cake
       
       if (chocolatecake.getpurchased()==false ){
           cout << "You don't know the recipe for chocolate cake!"<< endl;
           return -1;
       }
       
       flour = chocolatecake.getidealFlour();
       egg = chocolatecake.getidealEgg();
       vanilla = chocolatecake.getidealVanilla();
       butter = chocolatecake.getidealButter();
       sugar = chocolatecake.getidealSugar();
       choco = chocolatecake.getidealChoco();
       
      
       
       if (pfl<2 || peg < 2 || pva < 2 || pmi < 2 || pbu < 2|| psu<2 || pch < 2){
           cout << "You don't have enough ingredients!\n" << endl;
        //   cout << pfl << " flour"<< endl;
        //   cout << peg << " egg" << endl;
        //   cout << pva << " vanilla" << endl;
        //   cout << pmi << " milk" << endl;
        //   cout << pbu << " butter" << endl;
        //   cout << pch << " choco"<< endl;
        //   cout << psu << " sugar" << endl;
       }
       else{
           cout << "Let's get baking!\n"<< endl;
           cout << "You have baked a chocolate cake!\n " << endl;
           pfl = pfl - 2;
           peg = peg - 2;
           pva = pva - 2;
           pmi = pmi - 2;
           pbu = pbu - 2;
           psu = psu - 2;
           pch = pch - 2;
           Pantry.setflourCount(pfl);
           Pantry.seteggCount(peg);
           Pantry.setvanillaCount(pva);
           Pantry.setmilkCount(pmi);
           Pantry.setbutterCount(pbu);
           Pantry.setsugarCount(psu);
           Pantry.setchocoCount(pch);
           points = points + 22;
           Player.setCakePoints(points);
           
           ofstream out ("cakelog.txt", ios::app);
           out << "Day "<< Player.getday()<< " - Baked a chocolate cake - 22 points" << endl<<endl;
           out.close();
           
           return points;
       }
       
    } 
}

 void game::cakelog(){
    cout << "Cake Log:"<< endl;
    //prints the contents in the cake log, so the user can see the list of cakes they have baked during the game
   string input;
   ifstream in;
   in.open("cakelog.txt");
   while (getline(in, input)){
       cout<< input<< endl;
       cout << endl;
   }
}
 





