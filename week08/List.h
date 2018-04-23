#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& data, Node<T>* next)
    {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class List
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;

    void copy(const List& other)
    {
        Node<T>* temp = other.first;
        for(size_t i = 0; i < other.size; i++)
        {
            push_back(temp->data);
            temp = temp->next;
        }

    }
    void destroy()
    {
        while(size > 0)
        {
            this->pop_front();
        }
    }
public:
    List()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    List(const List& other)
    {
        copy(other);
    }
    List& operator=(const List& other)
    {
        if(this != &other)
        {
            destroy();
            copy(other);
        }

        return *this;
    }
    ~List()
    {
        destroy();
    }

    void push_back(T data)
    {
        Node<T>* temp = new Node<T>(data,nullptr);
        if(temp)
        {
            if(this->size == 0)
            {
                this->first = temp;
                this->last = temp;
            }
            else
            {
                this->last->next = temp;
                this->last = temp;
            }

            size++;
        }
    }
    void push_front(T data)
    {
        Node<T>* temp = new Node<T>(data,first);
        first = temp;
    }
    void pop_back()
    {
        Node<T>* temp = last;
        Node<T>* start = first;
        while(start->next != last)
        {
            start = start->next;
        }
        last = start;
        delete temp;
        size--;

    }

    void push(T data, int index)
    {
        Node<T>* temp2 = first;
        Node<T>* temp = new Node<T>(data, nullptr);
        while(index != 0)
        {
            temp2 = temp2->next;
            index--;
        }
        temp->next = temp2->next;
        temp2->next = temp;


    }

    T get(int index)
    {
        Node<T>* temp = first;
        for(int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void pop_front()
    {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
        size--;
    }
    /*
        void push();
    */


};


