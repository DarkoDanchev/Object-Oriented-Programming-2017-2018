#pragma once

#include "Drink.h"

class Alchohol : public Drink
{
private:
    double alc;
public:
    Alchohol() : Drink()
    {
        this->alc = 0;
    }
    Alchohol(string name,string label,double vol,double alc) : Drink(name,label,vol)
    {
        this->alc = alc;
    }
    void setAlc(double alc)
    {
        this->alc = alc;
    }
    double getAlc() const
    {
        return this->alc;
    }
    string getType()
    {
        return "Alchohol";
    }

    void print() const
    {
        Drink::print();
        cout<<this->alc<<endl;
    }

    friend ostream& operator<<(ostream& os,const Alchohol& alchohol)
    {

        os<<alchohol.getName()<<endl;
        os<<alchohol.getLabel()<<endl;
        os<<alchohol.getVolume()<<endl;
        os<<alchohol.alc<<endl;
        return os;
    }


};
