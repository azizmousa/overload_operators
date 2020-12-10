#include <cstring>
#include <iostream>

#include "overload_operators/String.h"

/*
 * String(char &data)
 * parameterized constructor to initialize the Stirng data
 * make a deep copy
*/
String::String(const char *data):data{nullptr}{
    this->set_string(data);
}
/*
 * String()
 * default constructor 
*/
// String::String(): String{nullptr}{
//     std::cout << "default constructor" << std::endl;    
// }

/*
 * String(const String &string)
 * copy constructor make a deep copy
*/
String::String(const String &string):String{string.get_string()}{
}

/*
 * String(String &&string)
 * move constructor for the rvalue
*/
String::String(String &&string):data{string.data}{
    string.data = nullptr;
}

/*
 * ~String() destructor
*/
String::~String(){
    delete [] this->data;
}

/*
 * const char *get_string()const;
 * return the data pointer
*/
const char *String::get_string()const{
    return (this->data == nullptr)? "":this->data;
}

/*
 * void set_string(const char *data)
 * set char value to the object
*/
void String::set_string(const char *data){
    delete [] this->data;
    int size{0};
    if(data != nullptr) {
        size = std::strlen(data);
        this->data = new char[ size + 1];
        std::strcpy(this->data, data);
    }
    else{
        this->data = nullptr;
    }
}

/*
 * String &String::operator=(const String &string)
 * assigment operator overload that make deep copy 
*/
String &String::operator=(const String &string){
    if(this->data == string.data)
        return *this;
    this->set_string(string.data);
    return *this;
}

/*
 * String &String::operator=(String &&string)
 * assignment operator to move the rvalue
*/
String &String::operator=(String &&string){
    delete [] this->data;
    this->data = string.data;
    string.data = nullptr;
    return *this;
}

/*
 * String String::operator-()
 * overloaded operator to set all chars to lower case
*/
String String::operator-(){
    size_t size = std::strlen(this->data);
    char *temp = new char[size + 1];
    std::strcpy(temp, this->data);
    for(char *c{temp}; c<(temp+size);++c)
        *c = std::tolower(*c);
    String lower{temp};
    delete [] temp;
    return lower;
}

/*
 * String String::operator+(const String &rhs_string)
 * overloaded operator to concatenate to of my strings together
*/
String String::operator+(const String &rhs_string){
    size_t size = std::strlen(this->data) + std::strlen(rhs_string.data);
    char *temp = new char [size +1];
    std::strcpy(temp, std::strcat(this->data, rhs_string.data));
    String conc{temp};
    delete [] temp;
    return conc;
}

/*
 * bool String::operator==(const String &rhs_string)
 * binary operator overloaded to compare between Strings objects
*/
bool String::operator==(const String &rhs_string)const{
    return (std::strcmp(this->data, rhs_string.data) == 0);
}


/*
 * std::ostream&operator<<(std::ostream &out, String &string)
 * insertion operator overload
*/
std::ostream &operator<<(std::ostream &out, const String &string){
    out << string.data;
    return out;
}

/*
 * std::istream &operator>>(std::istream &in, String &string)
 * extraction operator overload
*/
std::istream &operator>>(std::istream &in, String &string){
    size_t buff_size = 2; 
    while(in.peek() == ' ' || in.peek() == '\n'){
        in.ignore(1);
    }
    char *buff = new char[buff_size];
    while(in.peek()!=' ' && in.peek()!='\n'){
        in >> buff;
        string.set_string(buff);
    }
    delete [] buff;
    return in;
}