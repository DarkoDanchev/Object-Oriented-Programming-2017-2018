#include "String.h"

void String::copy(const String& other)
{
    this->value = new char[strlen(other.value) + 1];
    strcpy(this->value,other.value);
    //this->length = other.length;
}
void String::erase()
{
    delete [] value;
    //delete length;
}

String::String()
{
    this->value = new char[1];
    strcpy(this->value,"");
}
String::String(const char* value)
{
    this->value = new char[strlen(value) + 1];
    strcpy(this->value,value);
}
String::String(const String& other)
{
    this->copy(other);
}
String& String::operator=(const String& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

void String::print() const
{
    cout<<this->value<<endl;
}

String::~String()
{
    this->erase();
}




