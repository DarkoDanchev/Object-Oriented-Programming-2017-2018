#pragma once

#include "Drink.h"

class NonAlchohol : public Drink
{
private:
    bool isCarbonated;
public:
    NonAlchohol() : Drink()
    {
        this->isCarbonated = false;
    }
    NonAlchohol(string name,string label,double vol,bool isCarbonated) : Drink(name,label,vol)
    {
        this->isCarbonated = isCarbonated;
    }
    void setCarbonated(bool isCarbonated)
    {
        this->isCarbonated = isCarbonated;
    }
    bool getCarbonated() const
    {
        return isCarbonated;
    }
    void print () const
    {
        Drink::print();
        cout<<isCarbonated<<endl;
    }
    string getType()
    {
        return "NonAlchohol";
    }
};
