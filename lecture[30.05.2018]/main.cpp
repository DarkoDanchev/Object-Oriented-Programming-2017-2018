#include "ArrayList.h"
#include "LinkedList.h"

void printListDetails(List<int>* lst)
{
    lst->print();
    cout<<lst->size();
}
int main()
{

    List<int>* lst1 = new ArrayList<int>();
    ArrayList<int> arr;
    LinkedList<int> lst;

    arr.push_back(5);
    lst.push_back(18);

    arr.print();
    lst.print();

    lst1->push_back(15);

    lst1->push_back(18);

    lst1->print();

    printListDetails(&lst);
    printListDetails(&arr);
    return 0;
}
