#pragma once

#include "List.h"

template <typename T>
class ArrayList : public List<T>
{
private:
    T* value;
    size_t count; //unsigned int
    size_t capacity;
    void copy(const ArrayList&);
    void erase();
    void resize();
public:
    ArrayList();
    ArrayList(const ArrayList&);
    ArrayList& operator=(const ArrayList&);
    ~ArrayList();
    void push_back(T element)
    {
        if(this->count >= this->capacity)
        {
            this->resize();
        }
        this->value[this->count++] = element;
        //this->count++;
        //++a a++
    }
    void push_front(T element)
    {
        this->push(0,element);
    }
    void push(size_t index,T element)
    {
        this->count++;

        for(int i = this->count; i > index + 1; i--)
        {
            this->value[i] = this->value[i - 1];
        }

        this->value[index] = element;
    }

    void pop_back()
    {
        this->count--;
    }
    void pop_front()
    {
        T temp = this->value[1];
        for(size_t i = 0; i < this->count - 1; i++)
        {
            this->value[i] = temp;
            temp = this->value[i+1];
        }
        this->count--;
    }
    void pop(size_t index)
    {
        for(size_t i = index; i < this->size() - 1; i++)
        {
            this->value[i] = this->value[i+1];
        }

        this->count--;
    }
    T operator[](size_t index) const
    {
        return this->value[index];
    }
    void print() const
    {
        for(size_t i = 0; i < this->count; i++)
        {
            cout<<this->value[i]<<endl;
        }
    }
    size_t size() const
    {
        return this->count;
    }
};

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& other)
{
    this->value = new T[other.capacity];
    for(size_t i = 0; i < other.count; i++)
    {
        this->value[i] = other.value[i];
    }
    this->count = other.count;
    this->capacity = other.capacity;
}

template <typename T>
void ArrayList<T>::erase()
{
    delete [] this->value;
}

template <typename T>
void ArrayList<T>::resize()
{
    this->capacity = 2*this->capacity + 1;
    T* temp = new T[this->capacity];
    for(size_t i = 0;i < this->count; i++)
    {
        temp[i] = this->value[i];
    }
    this->erase();

    value = temp;
}

template <typename T>
ArrayList<T>::ArrayList()
{
    this->capacity = 8;
    this->count = 0;
    this->value = new T[this->capacity];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& other)
{
    this->copy(other);
}
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    this->erase();
}
