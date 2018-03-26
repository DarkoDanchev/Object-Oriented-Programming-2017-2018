
#include "Population.h"

int main()
{
    Person p1;
    Person p2("gosho",22,1.90,90.0);
    p1.print();
    p2.print();

    Population p;
    p.add(p1);
    p.add(p2);
    p.write();
    return 0;
}
