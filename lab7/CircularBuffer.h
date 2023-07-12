#pragma once

template<typename Type>
class CircularBuffer {
    struct Node
    {
        Type data;
        Node* next;
        Node* prev;
        Node()
        {
            next = nullptr;
            prev = nullptr;
        }
    };
private:
    unsigned int size, capacity;
    Node* first, *last;
public:
    class iterator {
    public: 
        Node* ptr;
        // constructor
        iterator();
        iterator(const iterator& i);
        iterator(Node* p);

        // assignment operator
        iterator& operator=(iterator& i);
        iterator& operator+=(const int num);
        iterator& operator-=(const int num);
        Type& operator*();
        Type* operator->();

        // arithmetric operator
        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);
        iterator operator--(int);
        iterator operator+(const int num);
        iterator operator-(const int num);

        // comparision operator
        bool operator==(const iterator& i);
        bool operator!=(const iterator& i);
    };

    CircularBuffer(unsigned int capacity);
    ~CircularBuffer();
    iterator begin();
    iterator end();
    unsigned int getSize();
    unsigned int getCapacity();
    void push_back(Type element);
    void push_front(Type element);
    void pop_back();
    void pop_front();
    void insert(Type element, iterator i);
    void erase(iterator i);
    void resize(unsigned int newSize);
    Type& operator[](unsigned int index);
};