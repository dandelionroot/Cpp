/*
    * File Name : String.cpp
    * Version : 0.1
    * Update Date : 2019. 01. 29.
*/

#include <iostream>
#include <cstring>
#include <String.h>
using namespace std;

String::String() {
    this->len = 0;
    this->str = NULL;
}

String::String(const char* s) {
    this->len = strlen(s)+1;
    this->str = new char[this->len];
    strcpy(this->str, s);
}

String::String(const String& copy) {
    this->len = copy.len;
    this->str = new char[this->len];
    strcpy(this->str, copy.str);
}

String::~String() {
    if(this->str != NULL)
        delete []str;
}

String& String::operator= (const String& s) {
    if(this->str != NULL)
        delete []this->str;
    this->len = s.len;
    this->str = new char[this->len];
    strcpy(this->str, s.str);
    return *this;
}

String String::operator+ (const String& s) {
    char* c = new char[this->len+s.len-1];
    strcpy(c, this->str);
    strcat(c, s.str);
    String temp(c);
    delete []c;
    return temp;
}

String& String::operator+= (const String& s) {
    this->len += (s.len-1);
    char* c = new char[this->len];
    strcpy(c, this->str);
    strcat(c, s.str);
    if(this->str != NULL)
        delete []this->str;
    this->str = c;
    return *this;
}

bool String::operator== (const String& s) {
    return strcmp(this->str, s.str) ? false : true;
}

ostream& operator<< (ostream& os, const String& s) {
    return os << s.str;
}

istream& operator>> (istream& is, String& s) {
    char str[100];
    is >> str;
    s = String(str);
    return is;
}
