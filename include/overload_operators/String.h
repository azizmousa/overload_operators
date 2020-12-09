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
    String(char &data); // parametarized constructo (copy constructor)
    String(char &&data); // move constructor
    ~String(); // the distrcutor

    char *get_srting()const; // data getter
    void set_string(char *data); //data setter

    String &operator=(String &data); // assignment operator overload;
    String &operator=(String &&data); //rvalue move operator;
};

#endif // _STRING_H