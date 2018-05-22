#pragma once

#include "Alchohol.h"


class Beer : public Alchohol
{
private:
    string color;
    string manufacture;
public:
    Beer() : Alchohol()
    {
        this->color = "default";
        this->manufacture = "default";
    }
    Beer(string name,string label,double vol,double alc,string color, string manufacture) : Alchohol(name,label,vol,alc)
    {
        this->color = color;
        this->manufacture = manufacture;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    string getColor() const
    {
        return this->color;
    }
    string getManufacture()
    {
        return this->manufacture;
    }

    void print() const
    {
        Alchohol::print();
        cout<<this->color<<endl;
        cout<<this->manufacture<<endl;
    }

    friend ostream& operator<<(ostream& os,const Beer& beer)
    {

        os<<beer.getName()<<endl;
        os<<beer.getLabel()<<endl;
        os<<beer.getVolume()<<endl;
        os<<beer.getAlc()<<endl;
        os<<beer.color<<endl;
        os<<beer.manufacture<<endl;

        return os;
    }

};
