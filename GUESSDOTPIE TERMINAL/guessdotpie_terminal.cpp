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
            int np = -bet;
            std::cout << "You lost - balance: $" << balance;
            balance += np;
            
           
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



int main(){// my main code is not currently here because i thought it'd be easier to make my new game
    std::cout << roll(100, 100, 70, 0);

    return 0;
}