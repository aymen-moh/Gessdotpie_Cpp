#include <iostream>
// i am just making a basic program to test time tracking
int main(){
    std::cout << "hello world!\n";
    std::cout << "what's your name?\n";
    std::string name;
    getline(std::cin, name);
    std::cout << "Hello " << name;
    
}