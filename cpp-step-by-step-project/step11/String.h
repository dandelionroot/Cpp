/*
    * File Name : String.h
    * Version : 0.1
    * Update Date : 2019. 01. 29.
*/

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String
{
private:
    char* str;
    int len;
public:
    String();
    String(const char* s);
    String(const String& copy);
    ~String();
    String& operator= (const String& s);
    String operator+ (const String& s);
    String& operator+= (const String& s);
    bool operator== (const String& s);
    friend ostream& operator<< (ostream& os, const String& s);
    friend istream& operator>> (istream& is, String& s);
};

#endif
