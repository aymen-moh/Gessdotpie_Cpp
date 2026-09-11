#include <iostream>

// i will start my games with the simplest of all: double or nothing (coin flip)
int flip(int balance, int bet){
    srand(time(NULL));
    int num = rand() % 2;
    if(num == 1){ // win
        balance += bet;
    }
    else{// loss
        balance -= bet;
    }
    return balance;


}
int main(){
    int balance = 100;
    int bet;
    std::cout << "You Have $" << balance << ". Enter your bet: ";
    std::cin >> bet;
    balance = flip(balance, bet);
    std::cout << "New balance: $" << balance;
    return 0;

}