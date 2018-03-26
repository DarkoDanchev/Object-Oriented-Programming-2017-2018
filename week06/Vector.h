#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Vector
{
private:
    T* value;
    size_t count; //unsigned int
    size_t capacity;
    void copy(const Vector&);
    void erase();
    void resize();
public:
    Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    ~Vector();
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
    void pop(size_t index);
    Vector& operator+=(const Vector&);
    Vector operator+(const Vector&);
    T operator[](size_t index) const
    {
        return this->value[index];
    }
    int operator[](T element) const
    {
        for(size_t i = 0; i < this->count; i++)
        {
            if(element == this->value[i])
            {
                return i;
            }
        }

        return -1;
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
void Vector<T>::copy(const Vector<T>& other)
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
void Vector<T>::erase()
{
    delete [] this->value;
}

template <typename T>
void Vector<T>::resize()
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
Vector<T>::Vector()
{
    this->capacity = 8;
    this->count = 0;
    this->value = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    this->copy(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    this->erase();
}
