#include <iostream>
#include <cmath>
int checkbet(int bet, int balance){
    if(bet < 0){
        return 1;
    }
    else if(bet > balance){
        return 1;
    }
    else if(bet == 0){
        return 0;
    }
    else{
        return 0;
    }
    
}




// i will start my games with the simplest of all: double or nothing (coin flip)
int flip(int balance, int bet){
    while(checkbet(bet, balance) == 1){
        std::cout << "Invalid bet!\n";
        std::cout << "Enter bet\n";
        std::cin >> bet;
    }
    srand(time(NULL));
    int num = rand() % 2;
    if(num == 1){ // win
        balance += bet;
        std::cout << "You Win!\nNew Balance: $" << balance << '\n';
    }
    else{// loss
        balance -= bet;
        std::cout << "You Lost!\nNew Balance: $" << balance << '\n';
    }
    return balance;
}


// AAAAal right fresh start what game should i add next...
// adding rolllllll

int roll(int balance, int bet, double target, int over){
    
    while(checkbet(bet, balance) == 1){
        std::cout << "Invalid bet!\n";
        std::cout << "Enter bet\n";
        std::cin >> bet;
    }

    // i am not going to add this check in a function but if another game needs it i will propable do it
    while(target < 5 or target > 99){
        if(target < 5){
        std::cout << "The target can't be less than five!\n";
        std::cin >> target;
        }
        else if(target < 5){
            std::cout << "The target can't be more than 99!\n";
            std::cin >> target;
        }

    }

    // i have decided it is better to enter the bet here so the main function only calls the funciton <---- nvm
    if(over == 1){ //calculates the multiplier for the over direction
        double mult = 100 / (100 - target);
        srand(time(NULL));
        int rollednum = rand() % 100 + 1;
        if(rollednum > target){
            std::cout << "Rolled: " << rollednum << "!\n";
            int winnings = bet * mult; 
            int np = winnings - bet;
            std::cout << "You Won with a multiplier of x" <<  std::round(mult * 100.0) / 100.0 << "\n";
            balance += np;
            std::cout << "| Winnings: $" << winnings << " | Net profit: $" << np  << " | New balance: $" << balance << " | \n";
        }

        else if(rollednum <= target){
            std::cout << "Rolled: " << rollednum << "!\n";
            int winnings = bet * mult; 
            balance -= bet;
            std::cout << "You lost - balance: $" << balance;
            
            
           
        }
    }
    else if(over == 0){ //calculates the multiplier for the under direction
        double mult = 100 / target;
        srand(time(NULL));
        int rollednum = rand() % 100 + 1;
        if(rollednum < target){
            std::cout << "Rolled: " << rollednum << "!\n";
            int winnings = bet * mult; 
            int np = winnings - bet;
            std::cout << "You Won with a multiplier of x" <<  std::round(mult * 100.0) / 100.0 << "\n";
            balance += np;
            std::cout << "| Winnings: $" << winnings << " | Net profit: $" << np  << " | New balance: $" << balance << " | \n";
        }
        else if(rollednum >= target){
            std::cout << "Rolled: " << rollednum << "!\n";
            int winnings = bet * mult; 
            balance -= bet;
            std::cout << "You lost - balance: $" << balance << '\n';
            
        }
    }
    return balance;
    
    
}

// adding my last game (propably wont be my last game if sfml isnt supported by github codespaces)

int hilo(int balance, int bet){
    while(checkbet(bet, balance) == 1){
        std::cout << "Invalid bet!\n";
        std::cout << "Enter bet\n";
        std::cin >> bet;
    }
    bool lost = false;
    bool cashedout = false;
    do{

        
        srand(time(NULL));
        int randnum = rand() % 13 + 1;
        std::cout << "The number is: \n" << randnum << '\n';
        std::cout << "Over (o) or Under (u) or Cash out (c)? \n";
        std::string choice;
        std::cin >> choice;
        while(choice != "o" and choice != "u" and choice != "c"){
            std::cout << "Enter a valid choice! (o, u, c)";
            std::cin >> choice;
        }
        if(choice == "o"){
            int randnum2 = rand() % 13 + 1;
            double mult = 1;

            if(randnum2 > randnum){
                

                std::cout << "You Won! -- current Multiplier: x" << mult << " -- Potential winningss: " << bet * mult << '\n';
                mult += 0.1;
            }
            else{
                std::cout << "You Lost!\n";
                lost = true;
            }
        }
    }while(!lost and !cashedout);




}   

int main(){// my main code is not currently here because i thought it'd be easier to make my new game
    int balance = 100;
    int bet;
    std::string games[] = {"flip", "roll"};
    int hlpnum = (sizeof(games)/sizeof(std::string)) + 1;
    int endnum = (sizeof(games)/sizeof(std::string)) + 2;
    std::cout << "Welcome To GessDotPIE!\n\n";
    int selection;
    do{
        std::cout << "What Game Would You Like To Play?\n";
        std::cout << "1. Flip\n";
        std::cout << "2. roll\n";
        std::cout << hlpnum << ". Help\n";
        std::cout << endnum << ". Exit\n\n";
        std::cin >> selection;
        switch(selection){
            case 1:
            std::cout << "You Selected Flip!\n";
            std::cout << "Balance: $" << balance << '\n';
            std::cout << "Enter Your Bet Amount: $";
            std::cin >> bet;
            balance = flip(balance, bet);
            break;

            case 2:
            std::cout << "You Selected roll!\n";
            std::cout << "Balance: $" << balance << '\n';
            std::cout << "Enter Your Bet Amount: $";
            std::cin >> bet;
            std::cout << "Enter target: ";
            double target;
            std::cin >> target;
            int over = 2;
            do{
                std::cout << "over or under? ";
                std::string overS; // over string cuz were sending 1 or 0 and it will be int
                std::cin >> overS;
                
                if(overS == "over"){
                    over = 1;
                }
                else if(overS == "under"){
                    over = 0;
                }
            }while(over != 0 and over != 1);
                             
            balance = roll(balance, bet, target, over);
        }
            
    }while(selection != endnum);
    // i will propably add more later hehe
    return 0;
}