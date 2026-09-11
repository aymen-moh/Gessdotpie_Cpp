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



}
int main(){
    

}