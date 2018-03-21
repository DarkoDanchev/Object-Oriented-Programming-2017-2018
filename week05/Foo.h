#pragma once
#include<iostream>
#include<cstring>

using namespace std;
class Foo
{
private:
    char name[256];
public:
    Foo(char*);
    void print() const;
};
