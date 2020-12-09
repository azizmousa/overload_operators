#ifndef _STRING_H
#define _STRING_H

/*
 * String is a class deal with c_syle string
 * and try to simulate the c++ string
*/
class String{

private:
    char *data; // pointer to sequence of characters

public:
    String(); //default constructor
    String(const char *data); // parametarized constructo (copy constructor)
    String(const String &&data); // move constructor
    ~String(); // the distrcutor

    const char *get_srting()const; // data getter
    void set_string(char *data); //data setter

    String &operator=(const String &data); // assignment operator overload;
    String &operator=(String &&data); //rvalue move operator;

    void display()const; // display the object content
    int get_size()const; // get the string size
};

#endif // _STRING_H