#pragma once

#include "Drink.h"
#include <vector>

class Bar
{
private:
    vector<Drink*> drinks;
public:
    Bar()
    {
       drinks = vector<Drink*>(0);
    }
    Bar(vector<Drink*> drinks)
    {
        this->drinks = drinks;
    }

    void addDrink(Drink* drink)
    {
        drinks.push_back(drink);
    }

    void removeDrink(size_t index)
    {
        if(index > drinks.size())
        {
            cout<<"Invalid input"<<endl;
        }
        else
        {
            drinks.erase(drinks.begin() + index);
        }
    }

    void print() const
    {
        for(size_t i = 0; i < this->drinks.size(); i++)
        {
            this->drinks[i]->print();
        }
    }
};
