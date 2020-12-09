#include <iostream>
#include "overload_operators/String.h"

int main(int argc, char *argv[]){
    String string = "hello";
    std::cout << string.get_string() << std::endl;
    String s2{string}; 
    std::cout << s2.get_string() << std::endl;
    s2 = "welcome to my string:)";
    std::cout << s2.get_string() << std::endl;
    s2 = string;
    std::cout << s2.get_string() << std::endl;
    // string.display();
    std::cout << string.get_string() << std::endl;
    return 0;
}