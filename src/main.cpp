#include <iostream>
#include "overload_operators/String.h"

int main(int argc, char *argv[]){
    // char *x = nullptr;
    // std::cout << *x << std::endl;
    String string = "hello";
    std::cout << string.get_string() << std::endl; // hello
    String s2; 
    std::cout << s2.get_string() << std::endl; // hello
    s2 = "WELCOME TO MY STRING CLASS:)"; 
    std::cout << s2.get_string() << std::endl; // WELCOME TO MY STRING CLASS:) 
    s2 = -s2; 
    s2 = s2 + string;
    std::cout << s2.get_string() << std::endl; // welcome to my string class:)hello
       // string.display();
    std::cout << "enter two strings separated by space: "; 
    String a1, a2;
    std::cin >> a1 >> a2;


    if(a1 == a2) // WELCOME not equal to welcome
        std::cout << a1.get_string() << " equal to " << a2.get_string() << std::endl;
    else
        std::cout << a1.get_string() << " not equal to " << a2.get_string() << std::endl;
    a1 = -a1;
    if(a1 == a2) // welcome equal to welcome
        std::cout << a1.get_string() << " equal to " << a2.get_string() << std::endl;
    else
        std::cout << a1.get_string() << " not equal to " << a2.get_string() << std::endl;
    
    std::cout << string.get_string() << std::endl; // hello
    return 0;
}