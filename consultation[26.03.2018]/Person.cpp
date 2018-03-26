#include "Person.h"

Person::Person()
{
    strcpy(this->name,"pesho");
    this->age = 18;
    this->height = 1.80;
    this->weight = 80.0;
}
Person::Person(const char* name,int age,double height,double weight)
{
    strcpy(this->name,name);
    this->age = age;
    this->height = height;
    this->weight = weight;
}

const char* Person::getName() const
{
    return this->name;
}
int Person::getAge() const
{
    return this->age;
}
double Person::getHeight() const
{
    return this->height;
}
double Person::getWeight() const
{
    return this->weight;
}
void Person::setName(const char* name)
{
    strcpy(this->name,name);
}
void Person::setAge(int age)
{
    this->age = age;
}
void Person::setHeight(double height)
{
    this->height = height;
}
void Person::setWeight(double weight)
{
    this->weight = weight;
}
void Person::print() const
{
    cout<<"Name: "<<this->name<<endl;
    cout<<"Age: "<<this->age<<endl;
    cout<<"Height: "<<this->age<<endl;
    cout<<"Weight: "<<this->weight<<endl;
}

