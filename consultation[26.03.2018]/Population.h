#pragma once
#include "Person.h"

class Population
{
private:
    Person* persons;
    size_t size;
    size_t capacity;
    void copy(const Population& other)
    {
        this->persons = new Person[other.capacity];
        for(size_t i = 0; i < other.size; i++)
        {
            this->persons[i] = other.persons[i];
        }
        this->size = other.size;
        this->capacity = other.capacity;
    }
    void erase()
    {
        delete [] this->persons;
    }
    void resize()
    {
        this->capacity=this->capacity*2;
        Person* tmp = new Person[this->capacity];
        for(size_t i=0; i<this->size;i++){
            tmp[i]=this->persons[i];

        }
        delete[] this->persons;
        this->persons=tmp;

    }
public:
    Population()
    {
        this->capacity = 8;
        this->size = 0;
        this->persons = new Person[this->capacity];
    }
    Population(const Population& other)
    {
        this->copy(other);
    }
    Population& operator=(const Population& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }

        return *this;
    }
    ~Population()
    {
        this->erase();
    }
    void add(Person person)
    {
        if(this->size >= this->capacity)
        {
            this->resize();
        }
        this->persons[this->size] = person;
        ++this->size;

    }
    void remove()
    {
        this->size--;
    }
    void print() const
    {
        for(size_t i = 0; i < size; i++)
        {
            persons[i].print();
        }
    }
    void printAboveHeight(double height)
    {
        for(size_t i = 0 ; i < size; i++)
        {
            if(persons[i].getHeight() >= height)
            {
                persons[i].print();
            }
        }
    }
    void printWithName(const char* name)
    {
        for(size_t i = 0 ; i < size; i++)
        {
            if(strcmp(persons[i].getName(),name) == 0)
            {
                persons[i].print();
            }
        }
    }
    void write()
    {
        ofstream stream("population.txt");
        if(stream.is_open())
        {
            for(size_t i = 0; i < size; i++)
            {
                this->persons[i].write(stream);
            }
            stream.close();
        }
    }
    void read()
    {
        ifstream stream("population.txt");
        if(stream.is_open())
        {
            for(size_t i = 0; i < size; i++)
            {
                this->persons[i].read(stream);
            }
            stream.close();
        }
    }
};
