#include <iostream>
#include "overload_operators/String.h"

/*
 * String(char &data)
 * parameterized constructor to initialize the Stirng data
 * make a deep copy
*/
String::String(const char *data):data{nullptr}{
    *this->data = *data;
    std::cout << "copy constructor" << std::endl;
}
/*
 * String()
 * default constructor 
*/
String::String(): String{nullptr}{
    
}