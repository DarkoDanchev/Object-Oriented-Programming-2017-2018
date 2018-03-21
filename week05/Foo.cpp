#include "Foo.h"

Foo::Foo(char* name)
{
    strcpy(this->name,name);
}
void Foo::print() const
{
    cout<<this->name<<endl;
}


