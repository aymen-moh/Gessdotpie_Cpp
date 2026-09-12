#include <iostream>

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
int main(){
    int balance = 100;
    int bet;
    std::string games[] = {"flip"};
    int hlpnum = (sizeof(games)/sizeof(std::string)) + 1;
    int endnum = (sizeof(games)/sizeof(std::string)) + 2;
    std::cout << "Welcome To GessDotPIE!\n\n";
    int selection;
    do{
        std::cout << "What Game Would You Like To Play?\n";
        std::cout << "1. Flip\n";
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

        }
    }while(selection != endnum);
    // i will propably add more later hehe

    return 0;
}