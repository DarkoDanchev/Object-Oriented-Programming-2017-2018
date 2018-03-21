#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* value;
    //int length;
    void copy(const String& other);
    void erase();
public:
    String();
    String(const char* value);
    String(const String& other);
    String& operator=(const String& other);
    //String& operator=(const char* value);
    void print() const;

   ~String();


};

//String a,String a = b
