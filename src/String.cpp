#include <cstring>
#include <iostream>

#include "overload_operators/String.h"

/*
 * String(char &data)
 * parameterized constructor to initialize the Stirng data
 * make a deep copy
*/
String::String(const char *data):data{nullptr}{
    this->data = new char[std::strlen(data) + 1];    
    std::strcpy(this->data, data);
    std::cout << "char parameterized constructor" << std::endl;
}
/*
 * String()
 * default constructor 
*/
String::String(): String{nullptr}{
    std::cout << "default constructor" << std::endl;    
}

/*
 * String(const String &string)
 * copy constructor make a deep copy
*/
String::String(const String &string):String{string.get_string()}{
   std::cout << "copy constructor" << std::endl;
}

/*
 * String(String &&string)
 * move constructor for the rvalue
*/
String::String(String &&string):data{string.data}{
    string.data = nullptr;
    std::cout << "move constructor" << std::endl;
}

/*
 * ~String() destructor
*/
String::~String(){
    delete [] this;
    std::cout << "the object " << this->data << " deleted" << std::endl;
}

/*
 * const char *get_string()const;
 * return the data pointer
*/
const char *String::get_string()const{
    return this->data;
}

