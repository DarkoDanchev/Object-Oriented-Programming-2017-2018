#pragma once

#include "Alchohol.h"

class Whiskey : public Alchohol
{
private:
    size_t age;
    string manufacture;
public:
    Whiskey() : Alchohol()
    {
        this->age = 1;
        this->manufacture = "default";
    }
    Whiskey(string name,string label,double vol,double alc,size_t age, string manufacture) : Alchohol(name,label,vol,alc)
    {
        this->age = age;
        this->manufacture = manufacture;
    }

    size_t getAge() const
    {
        return this->age;
    }
    string getManufacture()
    {
        return this->manufacture;
    }

    void print() const
    {
        Alchohol::print();
        cout<<this->age<<endl;
        cout<<this->manufacture<<endl;
    }
};
