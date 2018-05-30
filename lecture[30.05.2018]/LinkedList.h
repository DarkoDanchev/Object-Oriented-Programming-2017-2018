#include "List.h"

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
class LinkedList : public List<T>
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t count;

    void copy(const LinkedList& other)
    {
        Node<T>* temp = other.first;
        for(size_t i = 0; i < other.count; i++)
        {
            push_back(temp->data);
            temp = temp->next;
        }

    }
    void destroy()
    {
        while(count > 0)
        {
            this->pop_front();
        }
    }
public:
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    LinkedList(const LinkedList& other)
    {
        copy(other);
    }
    LinkedList& operator=(const LinkedList& other)
    {
        if(this != &other)
        {
            destroy();
            copy(other);
        }

        return *this;
    }
    ~LinkedList()
    {
        destroy();
    }
    void print() const
    {
        Node<T>* temp = first;
        while(temp)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }

    }
    size_t size() const
    {
        return this->count;
    }
    void push_back(T data)
    {
        Node<T>* temp = new Node<T>(data,nullptr);
        if(temp)
        {
            if(this->count == 0)
            {
                this->first = temp;
                this->last = temp;
            }
            else
            {
                this->last->next = temp;
                this->last = temp;
            }

            count++;
        }
    }
    void push_front(T data)
    {
        Node<T>* temp = new Node<T>(data,first);
        first = temp;
        count++;
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
        count--;

    }

    void push(size_t index,T data)
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
        count++;


    }

    T operator[](size_t index) const
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
        count--;
    }
    Node<T>* goToElement(size_t index)
    {
        if(index < 0 || index >= this->count)
        {
            cout<<"Index can't be smaller than 0 or bigger than list length"<<endl;
            return NULL;
        }
        Node<T>* current = this->first;
        for(size_t i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current;
}
    void pop(size_t index)
    {
    if(!this->size() == 0)
    {
        if(index == 0) this->pop_front();
        else
        {
            Node<T>* removed = this->goToElement(index);
            Node<T>* temp = this->goToElement(index-1);

            if(index == this->size()-1) this->last = temp;
            temp->next = removed->next;
            delete removed;
            this->count--;
        }
    }

    }
    /*
        void push();
    */


};
