#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
    virtual void push(size_t index,T element) = 0;
    virtual void pop(size_t index) = 0;
    virtual void push_back(T element) = 0;
    virtual void push_front(T element) = 0;
    virtual void pop_back() = 0;
    virtual void pop_front() = 0;
    virtual void print() const = 0;
    virtual T operator[](size_t index) const = 0;
    virtual size_t size() const = 0;
    virtual ~List() {};
};
