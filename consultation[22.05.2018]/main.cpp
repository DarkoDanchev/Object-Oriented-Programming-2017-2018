#include "Beer.h"
#include "Whiskey.h"
#include "Cola.h"
#include "Bar.h"
#include <vector>

int main()
{

    Beer* b = new Beer("Pirinsko","Pirinsko",2.0,4.4,"svetla","Blagoevgrad");
    Whiskey* w = new Whiskey("Jameson","Jameson",1.0,35.7,10,"J");

    /*Drink d;
    cout<<d<<endl;
    */

    Beer b1("Pirinsko1","Pirinsko1",2.0,4.4,"svetla","Blagoevgrad");
    cout<<b1<<endl;
    vector<Drink*> drinks;

    drinks.push_back(b);
    drinks.push_back(w);

    drinks[0] -> print();
    drinks[1] -> print();

    /*for(size_t i = 0; i < drinks.size(); i++)
    {
        drinks[i] ->print();
    }
    */

    Bar bar;
    bar.addDrink(b);
    bar.addDrink(w);

    bar.print();
    return 0;
}
