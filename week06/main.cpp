#include "Vector.h"

int main()
{
    Vector<int> arr;
    arr.push_back(15);
    arr.push_back(25);
    arr.push_back(35);
    arr.push_back(45);
    arr.push_back(55);

    arr.print();

    cout<<"Size: "<<arr.size()<<endl;
    return 0;
}
