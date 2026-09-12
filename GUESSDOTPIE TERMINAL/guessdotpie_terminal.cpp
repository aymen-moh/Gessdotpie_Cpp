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
    std::string games[] = {"flip"};
    int hlpnum = (sizeof(games)/sizeof(std::string)) + 1;
    int endnum = (sizeof(games)/sizeof(std::string)) + 2;
    std::cout << "Welcome To GessDotPIE!\n\n";
    std::cout << "What Game Would You Like To Play?\n";
    std::cout << "1. Flip\n";
    std::cout << hlpnum << ". Help\n";
    std::cout << endnum << ". Exit\n";
    // i will propably add more later hehe

    return 0;
}