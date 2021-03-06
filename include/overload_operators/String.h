#ifndef _A_STRING_H
#define _A_STRING_H

/*
 * String is a class deal with c_syle string
 * and try to simulate the c++ string
*/
class String{

friend std::ostream &operator<<(std::ostream &out, const String &string);
friend std::istream &operator>>(std::istream &in, String &string);

private:
    char *data; // pointer to sequence of characters

public:
    // String(); //default constructor
    String(const char *data=""); // parametarized constructo
    String(const String &string); // copy constructor
    String(String &&data); // move constructor
    ~String(); // the destrcutor

    const char *get_string()const; // data getter
    void set_string(const char *data); //data setter

    String &operator=(const String &data); // assignment operator overload;
    String &operator=(String &&data); //rvalue move operator;
    String operator-(); // uniry operator overload to lowercase all the string
    String operator+(const String &rhs_string); // binary + operator overload to concatenate my strings
    bool operator==(const String &rhs_string)const; // binary operator overload to check if two strings are equals

    void display()const; // display the object content
    int get_size()const; // get the string size
};

#endif // _A_STRING_H