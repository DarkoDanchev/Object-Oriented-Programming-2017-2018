#include <iostream>
#include <cstring>

using namespace std;

class Human
{
private:
    char* name;
    int age;
    void copy(const Human& other)
    {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name,other.name);
        this->age = other.age;
    }
    void erase()
    {
        delete [] this->name;
    }
public:
    Human()
    {
        this->name = new char[1];
        strcpy(this->name,"");
        this->age = 18;
    }
    Human(const char* name,int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,name);
        this->age = age;
    }
    Human(const Human& other)
    {
        copy(other);
    }
    Human& operator=(const Human& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }

        return *this;
    }
    void print() const
    {
        cout<<"Name: "<<this->name<<endl;
        cout<<"Age: "<<this->age<<endl;
    }

    ~Human()
    {
        erase();
    }
};
class Student : public Human
{
private:
    char* fn;
    void copy(const Student& other)
    {
        this->fn = new char[strlen(other.fn) + 1];
        strcpy(this->fn,other.fn);
    }
    void erase()
    {
        delete [] this->fn;
    }
public:
    Student() : Human()
    {
       this->fn = new char[1];
       strcpy(this->fn,"");
    }
    Student(char* name,int age,char* fn) : Human(name,age)
    {
        this->fn = new char[strlen(fn) + 1];
        strcpy(this->fn,fn);
    }
    Student(const Student& other) : Human(other)
    {
        this->copy(other);
    }
    Student& operator=(const Student& other)
    {
        if(this != &other)
        {
            Human::operator=(other);
            this->erase();
            this->copy(other);
        }

        return *this;
    }
    ~Student()
    {
        this->erase();
    }
    void print() const
    {
        Human::print();
        cout<<"FN: "<<this->fn<<endl;
    }

};
class Kolo : public Human
{
private:
    double womanRating;
public:
    Kolo(char* name,int age,double womanRating) : Human(name,age)
    {
        this->womanRating = womanRating;
    }
    void printKolo()
    {
        this->print();
        cout<<"Rating: "<<this->womanRating<<endl;
    }
    void friendZoned()
    {
        this->womanRating = -1;
    }
};

int main()
{
    Kolo k1 = Kolo("Kolo1",18,2000);
    k1.print();
    Kolo k2 = Kolo("Kolo2",21,30000);
    k2.print();

    return 0;
}
