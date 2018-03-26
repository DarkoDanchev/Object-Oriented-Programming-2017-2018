#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Person
{
private:
    char name[256];
    int age;
    double height;
    double weight;
public:
    Person();
    Person(const char* name,int age,double height,double weight);
    const char* getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;
    void setName(const char* name);
    void setAge(int age);
    void setHeight(double height);
    void setWeight(double weight);
    void print() const;
    void write(ofstream& stream)
    {
        stream<<this->name<<endl;
        stream<<this->age<<endl;
        stream<<this->height<<endl;
        stream<<this->weight<<endl;
    }
    void read(ifstream stream)
    {
        stream>>this->name;
        stream>>this->age;
        stream>>this->height;
        stream>>this->weight;
    }
};


