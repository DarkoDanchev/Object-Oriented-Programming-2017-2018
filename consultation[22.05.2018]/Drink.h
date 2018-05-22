#pragma once

#include <iostream>


using namespace std;

class Drink
{
private:
    string name;
    string label;
    double vol;
public:
    Drink()
    {
        this-> name = "Drink";
        this->label = "Default";
        this->vol = 1.0;
    }
    Drink(string name,string label,double vol)
    {
        this->name = name;
        this->label = label;
        this->vol = vol;
    }
    string getName() const
    {
        return this->name;
    }
    string getLabel() const
    {
        return this->label;
    }
    double getVolume() const
    {
        return this->vol;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setLabel(string label)
    {
        this->label = label;
    }
    void setVolume(double vol)
    {
        this->vol = vol;
    }

    virtual void print() const
    {
        cout<<this->name<<endl;
        cout<<this->label<<endl;
        cout<<this->vol<<endl;
    }

    friend ostream& operator<<(ostream& os, const Drink& drink)
    {
        os<<drink.name<<endl;
        os<<drink.label<<endl;
        os<<drink.vol<<endl;

        return os;
    }

    virtual string getType() = 0;
    virtual string getManufacture() = 0;
};
