#pragma once

#include "NonAlchohol.h"

class Cola : public NonAlchohol
{
private:
    string manufacture;
public:
    Cola() : NonAlchohol()
    {
        this->manufacture = "default";
    }
    Cola(string name,string label,double vol,string manufacture) : NonAlchohol(name,label,vol,true)
    {
        this->manufacture = manufacture;
    }
    string getManufacture()
    {
        return this->manufacture;
    }

    void print() const
    {
        NonAlchohol::print();
        cout<<this->manufacture<<endl;
    }
};
