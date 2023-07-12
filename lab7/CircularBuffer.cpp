#include "CircularBuffer.h"
#include <iostream>

template<typename Type> 
CircularBuffer<Type>::iterator::iterator(){
    ptr = nullptr;
}

template<typename Type>
CircularBuffer<Type>::iterator::iterator(const iterator& i){
    this->ptr = i.ptr;
}

template<typename Type>
CircularBuffer<Type>::iterator::iterator(Node* p){
    this->ptr = p;
}

template<typename Type>
typename CircularBuffer<Type>::iterator& CircularBuffer<Type>::iterator::operator=(iterator& i){
    this->ptr = i.ptr;
    return *this;
}

template<typename Type>
typename CircularBuffer<Type>::iterator& CircularBuffer<Type>::iterator::operator+=(const int num){
    for (int i = 0; i < num; i++){
        this->ptr = this->ptr->next;
    }
    return *this;
}

template<typename Type>
typename CircularBuffer<Type>::iterator& CircularBuffer<Type>::iterator::operator-=(const int num){
    for (int i = 0; i < num; i++){
        this->ptr = this->ptr->prev;
    }
    return *this;
}

template<typename Type>
Type& CircularBuffer<Type>::iterator::operator*(){
    return ptr->data;
}

template<typename Type>
Type* CircularBuffer<Type>::iterator::operator->(){
    return &ptr->data;
}

template<typename Type>
typename CircularBuffer<Type>::iterator CircularBuffer<Type>::iterator::operator++(int){
    iterator tmp = *this;
    this->ptr = this->ptr->next;
    return tmp;
    
}

template<typename Type>
typename CircularBuffer<Type>::iterator CircularBuffer<Type>::iterator::operator--(int){
    iterator tmp = *this;
    this->ptr = this->ptr->prev;
    return tmp;
    
}

template<typename Type>
typename CircularBuffer<Type>::iterator& CircularBuffer<Type>::iterator::operator++(){
    this->ptr = this->ptr->next;
    return *this;
}

template<typename Type>
typename CircularBuffer<Type>::iterator& CircularBuffer<Type>::iterator::operator--(){
    this->ptr = this->ptr->prev;
    return *this;
}

template<typename Type>
typename CircularBuffer<Type>::iterator CircularBuffer<Type>::iterator::operator+(const int num){
    iterator temp = *this;
    temp += num;
    return temp;
}

template<typename Type>
typename CircularBuffer<Type>::iterator CircularBuffer<Type>::iterator::operator-(const int num){
    iterator temp = *this;
    temp -= num;
    return temp;
} 

template<typename Type>
bool CircularBuffer<Type>::iterator::operator==(const iterator& i){
    return this->ptr == i.ptr;
}

template<typename Type>
bool CircularBuffer<Type>::iterator::operator!=(const iterator& i){
    return this->ptr != i.ptr;
}

template<typename Type>
CircularBuffer<Type>::CircularBuffer(unsigned int capacity){
    this->size = 0;
    this->capacity = (capacity == 0 ? 1 : capacity);
    first = new Node();
    Node* current = first;
    for (int i = 1; i < capacity; i++){
        Node* p = new Node();
        current->next = p;
        p->prev = current;
        current = p;
    }
    current->next = first;
    first->prev = current;
    last = first;
}

template<typename Type>
CircularBuffer<Type>::~CircularBuffer(){
    Node* begin = first;
    Node* end = first->prev;
    int count = 1;
    while (begin != end){
        Node* temp = begin;
        begin = begin->next;
        delete temp;
        count++;
    }
    delete end;
    std::cout << "done";
}

template<typename Type>
typename CircularBuffer<Type>::iterator CircularBuffer<Type>::begin(){
    return iterator(first);
}

template<typename Type>
typename CircularBuffer<Type>::iterator CircularBuffer<Type>::end(){
    return iterator(last);
}

template<typename Type>
unsigned int CircularBuffer<Type>::getSize(){
    return size;
}

template<typename Type>
unsigned int CircularBuffer<Type>::getCapacity(){
    return capacity;
}

template<typename Type>
void CircularBuffer<Type>::push_back(Type element){
    if (last == first && size == 0){
        last->data = element;
        size++;
    }
    else {
        if (last->next == first) first = first->next;
        last = last->next;
        last->data = element;
        size++;
        if (size > capacity) size = capacity;
    }
}

template<typename Type>
void CircularBuffer<Type>::push_front(Type element){
    if (last == first && size == 0){
        first->data = element;
        size++;
    }
    else {
        if (first->prev == last) last = last->prev;
        first = first->prev;
        first->data = element;
        size++;
        if (size > capacity) size = capacity;
    }
}

template<typename Type>
void CircularBuffer<Type>::pop_back(){
    if (size == 0) return;
    if (size == 1){
        size--;
        return;
    }
    last = last->prev;
    size--;
}

template<typename Type>
void CircularBuffer<Type>::pop_front(){
    if (size == 0) return;
    if (size == 1){
        size--;
        return;
    }
    first = first->next;
    size--;
}

template<typename Type>
void CircularBuffer<Type>::insert(Type element, iterator i){
    if (i == begin()){
        push_front(element);
        return;
    }
    if (i == end() + 1){
        push_back(element);
        return;
    }
    iterator tmp = end();
    do {
        tmp.ptr->next->data = tmp.ptr->data;
        tmp--;
    } while (tmp != i - 1);
    i.ptr->data = element;
    last = last->next;
    if (last == first) first = first->next;
    size++;
    if (size > capacity) size = capacity;
}

template<typename Type>
void CircularBuffer<Type>::erase(iterator i){
    if (size == 0) return;
    if (i == begin()){
        pop_front();
        return;
    }
    iterator tmp = i;
    while(tmp != end()) {
        tmp.ptr->data = tmp.ptr->next->data;
        tmp++;
    }
    if (last != first) last = last->prev;
    size--;
}

template<typename Type>
void CircularBuffer<Type>::resize(unsigned int newSize){
    if (newSize == capacity || newSize == 0) return;
    if (newSize < capacity){
        Node* endptr = first;
        bool found = false;
        for (int i = 1; i < newSize; i++){
            if (endptr == last) found = true;
            endptr = endptr->next;
        }
        if (!found) last = endptr;
        Node* p = endptr->next;
        while (p != first)
        {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
        endptr->next = first;
        first->prev = endptr;
        capacity = newSize;
        if (size > capacity) size = capacity;
    }
    else {
        Node* endptr = first->prev;
        for (int i = capacity; i < newSize; i++){
            Node* p = new Node();
            p->prev = endptr;
            endptr->next = p;
            endptr = p; 
        }
        endptr->next = first;
        first->prev = endptr;
        capacity = newSize;
    }
}

template<typename Type>
Type& CircularBuffer<Type>::operator[](unsigned int index){
    Node* p = first;
    for (int i = 0; i < index; i++){
        p = p->next;
    }
    return p->data;
}
